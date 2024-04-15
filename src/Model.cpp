#include "../include/Model.h"

Model::Model()
{
}
Model::Model(std::string dbFileName) {
    this->dbFileName = dbFileName;
}

Model::~Model()
{
}

//Getters
std::string Model::getDBName() const
{
    return this->dbFileName;
}

//Setters
void Model::setDBName(std::string& name)
{
    this->dbFileName = name;
}

bool Model::addDatabase(std::string dbFileName) {
    try
    {
        this->db = new SQLite::Database(dbFileName, SQLITE_OPEN_READWRITE|SQLITE_OPEN_CREATE);
    }
    catch (std::exception& e)
    {
        std::cout << "exception: " << e.what() << std::endl;
        return false;
    }
    return true;
}



bool Model::addNewUser(User& user) {
    std::string login = user.getUsername();
    if (!hasUserWithLogin(login))
    {
        UserRole role = user.getUserRoleId();
        std::string pass = user.getPassword();
        try {
            SQLite::Statement query(*db, "INSERT INTO USER(user_role_id, login, password) VALUES(?, ?, ?)");
            query.bind(1, role);
            query.bind(2, login);
            query.bind(3, pass);
            query.exec();
        }
        catch (std::exception& e)
        {
            std::cout << "exception: " << e.what() << std::endl;
            return false;
        }
        return true;
    }
    return false;
}
bool Model::hasUser(User& user) {
    UserRole role = user.getUserRoleId();
    std::string pass = user.getPassword();
    std::string login = user.getUsername();
    try {
        SQLite::Statement query(*db, "SELECT user_id FROM USER WHERE user_role_id = ? AND login = ? AND password = ?");
        query.bind(1, role);
        query.bind(2, login);
        query.bind(3, pass);
        int count = 0;
        while (query.executeStep())
        {
            count++;
        }
        if (count == 0)
            return false;
    }
    catch (std::exception& e)
    {
        std::cout << "exception: " << e.what() << std::endl;
        return false;
    }
    return true;
}
bool Model::hasUserWithLogin(std::string login)
{
    try {
        SQLite::Statement query(*db, "SELECT user_id FROM USER WHERE login = ?");
        query.bind(1, login);
        int count = 0;
        while (query.executeStep())
        {
            count++;
        }
        if (count == 0)
            return false;
    }
    catch (std::exception& e)
    {
        std::cout << "exception: " << e.what() << std::endl;
        return false;
    }
    return true;
}
bool Model::canBuyCD(int CDCode) {
    try {
        SQLite::Statement query(*db, "SELECT CD_id FROM CD WHERE CD_id = ?");
        query.bind(1, CDCode);
        int count = 0;
        while (query.executeStep())
        {
            count++;
        }
        if (count == 0)
            return false;
    }
    catch (std::exception& e)
    {
        std::cout << "exception: " << e.what() << std::endl;
        return false;
    }
    return true;
}

bool Model::canBuyCD(int CDCode, int quantity)
{
    try {
        SQLite::Statement query(*db, "SELECT amount_in_stock FROM CD WHERE CD_id = ?");
        query.bind(1, CDCode);
        int count = 0;
        int amount = 0;
        while (query.executeStep())
        {
            count++;
            amount = query.getColumn(0);
        }
        if (count == 0 || quantity > amount)
            return false;
    }
    catch (std::exception& e)
    {
        std::cout << "exception: " << e.what() << std::endl;
        return false;
    }
    return true;
}
bool Model::buyCD(const std::vector<Operation>& operations)
{
    const std::vector<Operation> ops = operations;
    return false;
}

std::vector<CD> Model::availableCDsInfo() {
    std::vector<CD> result;
    try {
        SQLite::Statement query(*db, "SELECT CD_id, manufacture_year, manufacturer, amount_in_stock, price FROM CD WHERE amount_in_stock > 0");
        while (query.executeStep())
        {
            CD cd;
            cd.setCDCode(query.getColumn(0));
            cd.setManufactureYear(query.getColumn(1));
            std::string manufacturer = query.getColumn(2);
            cd.setManufacturer(manufacturer);
            cd.setAmounInStock(query.getColumn(3));
            cd.setPrice(query.getColumn(4));
            result.push_back(cd);
        }
    }
    catch (std::exception& e)
    {
        std::cout << "exception: " << e.what() << std::endl;
    }
    return result;
}
int Model::getBestSellingCDId()
{
    int id = 0;
    try {
        SQLite::Statement query(*db, "SELECT cd_id, SUM(quantity) AS sum FROM OPERATION_CDs INNER JOIN OPERATION ON OPERATION.operation_id = OPERATION_CDs.operation_id WHERE operation_type_id = 1 GROUP BY cd_id ORDER BY sum DESC LIMIT 1");
        while (query.executeStep())
        {
            id = query.getColumn(0);
        }
    }
    catch (std::exception& e)
    {
        std::cout << "exception: " << e.what() << std::endl;
    }
    return id;
}

CD Model::bestSellingCDInfo() {
    CD cd;
    try {
        
        SQLite::Statement query(*db, "SELECT CD_id, manufacture_year, manufacturer, amount_in_stock, price FROM CD WHERE CD_id = ?");
        query.bind(1, getBestSellingCDId());
        while (query.executeStep())
        {
            cd.setCDCode(query.getColumn(0));
            cd.setManufactureYear(query.getColumn(1));
            std::string manufacturer = query.getColumn(2);
            cd.setManufacturer(manufacturer);
            cd.setAmounInStock(query.getColumn(3));
            cd.setPrice(query.getColumn(4));
        }

    }
    catch (std::exception& e)
    {
        std::cout << "exception: " << e.what() << std::endl;
    }

    return cd;
}
int Model::getMostPopularSingerSoldCDsAmount() {

    return 0;
}
bool Model::isDateInPeriod(const std::string& date, const std::string& startDate, const std::string& endDate)
{   
    std::istringstream iss(date);
    std::tm tm{};
    iss >> std::get_time(&tm, "%Y-%m-%d");
    if (iss.fail()) {
        return false;
    }

    std::istringstream iss_start(startDate);
    std::tm tm_start{};
    iss_start >> std::get_time(&tm_start, "%Y-%m-%d");
    if (iss_start.fail()) {
        return false;
    }

    std::istringstream iss_end(endDate);
    std::tm tm_end{};
    iss_end >> std::get_time(&tm_end, "%Y-%m-%d");
    if (iss_end.fail()) {
        return false;
    }

    std::chrono::system_clock::time_point date_tp = std::chrono::system_clock::from_time_t(std::mktime(&tm));
    std::chrono::system_clock::time_point start_tp = std::chrono::system_clock::from_time_t(std::mktime(&tm_start));
    std::chrono::system_clock::time_point end_tp = std::chrono::system_clock::from_time_t(std::mktime(&tm_end));

    return (date_tp >= start_tp && date_tp <= end_tp);
}

int Model::getSoldCDsAmount(int CDCode, std::string startPeriod, std::string endPeriod) {
    try {
        SQLite::Statement query(*db, "SELECT quantity, date FROM OPERATION_CDs INNER JOIN OPERATION ON OPERATION.operation_id = OPERATION_CDs.operation_id WHERE operation_type_id = 1 AND CD_id = ?");
        query.bind(1, CDCode);
        int count = 0;
        int amount = 0;
        std::string queryDate;
        while (query.executeStep())
        {
            amount = query.getColumn(0);
            const char* date = query.getColumn(1);
            queryDate = date;
            if (isDateInPeriod(queryDate, startPeriod, endPeriod))
            {
                count += amount;
            }
        }
        return count;
    }
    catch (std::exception& e)
    {
        std::cout << "exception: " << e.what() << std::endl;
        return -1;
    }
    return 0;
}
std::vector<std::vector<std::string>> Model::getSoldAndLeftCDSortedDescDiff() {
    // Returns vector of vectors <CD_code, sold_amount, amount_in_stock, difference_between_amount_in_stock_and_sold>
    std::vector<std::vector<std::string>> result;
    std::vector<std::string> temp;
    std::string longQuery = "SELECT CD.CD_id, SUM(quantity) - amount_in_stock AS sold, amount_in_stock, ABS(2 * amount_in_stock - SUM(quantity)) AS diff";
    longQuery += " FROM OPERATION_CDs INNER JOIN OPERATION ON OPERATION.operation_id = OPERATION_CDs.operation_id";
    longQuery += " INNER JOIN CD ON CD.CD_id = OPERATION_CDs.CD_id";
    longQuery += " WHERE operation_type_id = 2 GROUP BY CD.CD_id ORDER BY diff DESC";
    try {
        SQLite::Statement query(*db, longQuery.c_str());
        int code = 0;
        int sold = 0;
        int inStock = 0;
        int diff = 0;
        while (query.executeStep())
        {
            code = query.getColumn(0);
            sold = query.getColumn(1);
            inStock = query.getColumn(2);
            diff = query.getColumn(3);
            temp.push_back(std::to_string(code));
            temp.push_back(std::to_string(sold));
            temp.push_back(std::to_string(inStock));
            temp.push_back(std::to_string(diff));
            result.push_back(temp);
            temp.clear();
        }
    }
    catch (std::exception& e)
    {
        std::cout << "exception: " << e.what() << std::endl;
    }
    return result;
}
std::vector<std::string> Model::getSoldCDsNumberAndProfitByEachAuthor() {
    std::vector<std::string> result;
    return result;
}
bool Model::addCD(int CDCode, int quantity) {
    int code = CDCode;
    int newQuantity = quantity;

    return false;
}
std::vector<std::vector<std::string>> Model::getReceivedAndSoldCDAmountByEachCD(std::string startPeriod, std::string endPeriod) {
    std::string start = startPeriod;
    std::string end = endPeriod;
    std::vector<std::vector<std::string>> result;
    return result;
}
std::vector<std::vector<std::string>> Model::getSoldCDsAmountAndProfit(int CDCode, std::string startPeriod, std::string endPeriod) {
    int code = CDCode;
    std::string start = startPeriod;
    std::string end = endPeriod;
    std::vector<std::vector<std::string>> result;
    return result;
}
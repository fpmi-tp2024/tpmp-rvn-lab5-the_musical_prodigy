#include "../../include/Model/Model.h"

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
        this->db = new SQLite::Database(dbFileName, SQLITE_OPEN_READWRITE | SQLITE_OPEN_CREATE);
    }
    catch (std::exception& e)
    {
        std::cout << "exception: " << e.what() << std::endl;
        return false;
    }
    return true;
}



bool Model::addNewUser(const User& user) {
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
bool Model::hasUser(const User& user) {
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
        return -1;
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
    std::string longQuery = "SELECT performer_id, SUM(quantity) AS amount FROM (SELECT DISTINCT PERFORMER.performer_id, CD_code, OPERATION.operation_type_id, quantity, price FROM PERFORMER";
    longQuery += " INNER JOIN m2m_MUSICAL_COMPOSITION_PERFORMER ON m2m_MUSICAL_COMPOSITION_PERFORMER.performer_id = PERFORMER.performer_id";
    longQuery += " INNER JOIN m2m_MUSICAL_COMPOSITION_CD ON m2m_MUSICAL_COMPOSITION_CD.composition_id = m2m_MUSICAL_COMPOSITION_PERFORMER.composition_id";
    longQuery += " INNER JOIN OPERATION_CDs ON OPERATION_CDs.CD_id = m2m_MUSICAL_COMPOSITION_CD.CD_code";
    longQuery += " INNER JOIN OPERATION ON OPERATION.operation_id = OPERATION_CDs.operation_id";
    longQuery += " INNER JOIN CD on CD.CD_id = OPERATION_CDs.CD_id";
    longQuery += " WHERE operation_type_id = 1) AS table1 GROUP BY performer_id ORDER BY amount DESC, performer_id LIMIT 1";
    int sold = 0;
    try {
        SQLite::Statement query(*db, longQuery);

        while (query.executeStep())
        {
            sold = query.getColumn(1);
        }
    }
    catch (std::exception& e)
    {
        std::cout << "exception: " << e.what() << std::endl;
        return -1;
    }
    return sold;
}

int Model::getSoldCDsAmount(int CDCode, std::string startPeriod, std::string endPeriod) {
    std::vector<std::vector<int>> result = getSoldAmount(startPeriod, endPeriod);
    for (int i = 0; i < result.size(); i++)
    {
        if (result[i][0] == CDCode)
            return result[i][1];
    }
    return -1;
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
        SQLite::Statement query(*db, longQuery);
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

std::vector<std::vector<std::string>> Model::getSoldCDsNumberAndProfitByEachAuthor() {
    // Returns vector of vectors <author, sold_amount, profit>
    std::vector<std::vector<std::string>> result;
    std::vector<std::string> temp;
    std::string longQuery = "SELECT name, SUM(quantity), SUM(quantity)*price FROM (SELECT DISTINCT name , CD_code, OPERATION.operation_type_id, quantity, price FROM AUTHOR";
    longQuery += " INNER JOIN m2m_MUSICAL_COMPOSITION_AUTHOR ON m2m_MUSICAL_COMPOSITION_AUTHOR.author_id = AUTHOR.author_id";
    longQuery += " INNER JOIN m2m_MUSICAL_COMPOSITION_CD ON m2m_MUSICAL_COMPOSITION_CD.composition_id = m2m_MUSICAL_COMPOSITION_AUTHOR.composition_id";
    longQuery += " INNER JOIN OPERATION_CDs ON OPERATION_CDs.CD_id = m2m_MUSICAL_COMPOSITION_CD.CD_code";
    longQuery += " INNER JOIN OPERATION ON OPERATION.operation_id = OPERATION_CDs.operation_id";
    longQuery += " INNER JOIN CD on CD.CD_id = OPERATION_CDs.CD_id";
    longQuery += " WHERE operation_type_id = 1) AS table1 GROUP BY name";
    try {
        SQLite::Statement query(*db, longQuery.c_str());
        int sold = 0;
        double profit = 0;
        while (query.executeStep())
        {
            std::string authorName = query.getColumn(0);
            sold = query.getColumn(1);
            profit = query.getColumn(2);
            temp.push_back(authorName);
            temp.push_back(std::to_string(sold));
            temp.push_back(std::to_string(profit));
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

std::vector<std::vector<int>> Model::getSoldAmount(const std::string& startDate, const std::string& endDate)
{
    std::vector<std::vector<int>>result;
    std::vector<int> temp;
    try {
        std::string longQuery = "SELECT CD_id, SUM(quantity) FROM OPERATION INNER JOIN OPERATION_CDs";
        longQuery += " ON OPERATION.operation_id = OPERATION_CDs.operation_id WHERE date BETWEEN ? AND ? AND operation_type_id = 1 GROUP BY CD_id ORDER BY CD_id";
        SQLite::Statement query(*db, longQuery);
        query.bind(1, startDate);
        query.bind(2, endDate);
        int amount = 0;
        int id = 0;
        while (query.executeStep())
        {
            id = query.getColumn(0);
            amount = query.getColumn(1);
            temp.push_back(id);
            temp.push_back(amount);
            result.push_back(temp);
            temp.clear();
        }
        return result;
    }
    catch (std::exception& e)
    {
        std::cout << "exception: " << e.what() << std::endl;
        return result;
    }
    return result;
}

std::vector<int> Model::getReceivedAmount(const std::string& startDate, const std::string& endDate)
{
    std::vector<int>result;
    try {
        std::string longQuery = "SELECT CD_id, SUM(quantity) FROM OPERATION INNER JOIN OPERATION_CDs";
        longQuery += " ON OPERATION.operation_id = OPERATION_CDs.operation_id WHERE date BETWEEN ? AND ? AND operation_type_id = 2 GROUP BY CD_id ORDER BY CD_id";
        SQLite::Statement query(*db, longQuery);
        query.bind(1, startDate);
        query.bind(2, endDate);
        int amount = 0;
        while (query.executeStep())
        {
            amount = query.getColumn(1);
            result.push_back(amount);
        }
        return result;
    }
    catch (std::exception& e)
    {
        std::cout << "exception: " << e.what() << std::endl;
        return result;
    }
    return result;
}

std::vector<std::vector<int>> Model::getReceivedAndSoldCDAmountByEachCD(std::string startPeriod, std::string endPeriod) {
    //returns 3 columns: CD_id, Sold amount, Received amount
    std::vector<std::vector<int>> result = getSoldAmount(startPeriod, endPeriod);
    std::vector<int> received = getReceivedAmount(startPeriod, endPeriod);
    for (int i = 0; i < result.size(); i++)
    {
        result[i].push_back(received[i]);
    }
    return result;
}

std::vector<double> Model::getSoldCDsAmountAndProfit(int CDCode, std::string startPeriod, std::string endPeriod) {
    //returns <profit, amount_of_sold_CDs>
    std::vector<double> result;
    try {
        std::string longQuery = "SELECT SUM(price * quantity), SUM(quantity) FROM OPERATION_CDs INNER JOIN CD ON CD.CD_id = OPERATION_CDs.CD_id";
        longQuery += " INNER JOIN OPERATION ON OPERATION.operation_id = OPERATION_CDs.operation_id WHERE CD.CD_id = ? AND operation_type_id = 1";
        longQuery += " AND date BETWEEN ? AND ?";
        SQLite::Statement query(*db, longQuery);
        query.bind(1, CDCode);
        query.bind(2, startPeriod);
        query.bind(3, endPeriod);
        double amount = 0;
        double profit = 0;
        while (query.executeStep())
        {
            profit = query.getColumn(0);
            amount = query.getColumn(1);
            result.push_back(profit);
            result.push_back(amount);
        }
        return result;
    }
    catch (std::exception& e)
    {
        std::cout << "exception: " << e.what() << std::endl;
        return result;
    }
    return result;
}

bool Model::addOrBuyCD(const std::vector<Operation>& operations)
{
    std::string operationDate;
    OperationCode operationCode;
    int CDCode;
    int numberOfCDs;
    int delta = 0;
    std::string insertOperationQuery = "INSERT INTO OPERATION(operation_type_id, date) VALUES(?, ?)";
    std::string insertOperationCDQuery = "INSERT INTO OPERATION_CDs(CD_id, quantity) VALUES(?, ?)";
    std::string updateAmountQuery = "UPDATE CD SET amount_in_stock = amount_in_stock + ? WHERE CD_id = ?";
    for (int i = 0; i < operations.size(); i++)
    {
        operationCode = operations[i].getOperationCode();
        CDCode = operations[i].getCDCode();
        numberOfCDs = operations[i].getNumberOfCDs();
        if (!canBuyCD(CDCode) || (operationCode == OperationCode::SELL && !canBuyCD(CDCode, numberOfCDs)))
        {
            return false;
        }
    }
    for (int i = 0; i < operations.size(); i++)
    {
        operationDate = operations[i].getOperationDate();
        operationCode = operations[i].getOperationCode();
        CDCode = operations[i].getCDCode();
        numberOfCDs = operations[i].getNumberOfCDs();

        if (operationCode == OperationCode::SELL)
            delta = -numberOfCDs;
        else if (operationCode == OperationCode::RECEIVE)
            delta = numberOfCDs;
        try {
            SQLite::Statement queryInsertOperation(*db, insertOperationQuery);
            SQLite::Statement queryInsertOperationCD(*db, insertOperationCDQuery);
            SQLite::Statement queryUpdateAmount(*db, updateAmountQuery);
            queryInsertOperation.bind(1, (int)operationCode);
            queryInsertOperation.bind(2, operationDate);
            queryInsertOperationCD.bind(1, CDCode);
            queryInsertOperationCD.bind(2, numberOfCDs);
            queryUpdateAmount.bind(1, delta);
            queryUpdateAmount.bind(2, CDCode);
            queryInsertOperation.exec();
            queryInsertOperationCD.exec();
            queryUpdateAmount.exec();
        }
        catch (std::exception& e)
        {
            std::cout << "exception: " << e.what() << std::endl;
            return false;
        }
    }
    return true;
}
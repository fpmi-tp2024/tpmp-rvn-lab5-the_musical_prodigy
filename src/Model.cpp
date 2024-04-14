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
bool Model::canBuyCD(int CDCode, int quantity)
{
    int code = CDCode;
    int newQuantity = quantity;
    return false;
}
bool Model::buyCD(const std::vector<Operation>& operations)
{
    const std::vector<Operation> ops = operations;
    return false;
}

std::vector<CD> Model::availableCDsInfo() {
    std::vector<CD> result;
    return result;
}
CD Model::bestSellingCDInfo() {
    CD cd;
    return cd;
}
int Model::getMostPopularSingerSoldCDsAmount() {
    return 0;
}
int Model::getSoldCDsAmount(int CDCode, std::string startPeriod, std::string endPeriod) {
    int code = CDCode;
    std::string start = startPeriod;
    std::string end = endPeriod;
    return 0;
}
std::vector<std::vector<std::string>> Model::getSoldAndLeftCDSortedDescDiff() {
    std::vector<std::vector<std::string>> result;
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
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
        SQLite::Database    db(dbFileName, SQLITE_OPEN_READONLY);

        SQLite::Statement   query(db, "SELECT * FROM AUTHOR");

        while (query.executeStep())
        {
            int         id = query.getColumn(0);
            const char* value = query.getColumn(1);
            std::cout << "row: " << id << ", " << value << std::endl;
        }
    }
    catch (std::exception& e)
    {
        std::cout << "exception: " << e.what() << std::endl;
        return false;
    }
    return true;
}



bool Model::addNewUser(User& user) {
    User newUser = user;
    return false;
}
bool Model::hasUser(User& user) {
    User newUser = user;
    return false;
}
bool Model::hasUserWithLogin(std::string login)
{
    std::string newLogin = login;
    return false;
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
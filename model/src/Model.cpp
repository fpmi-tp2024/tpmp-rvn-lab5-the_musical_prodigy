#include "../include/Model.h"

Model::Model()
{
}
Model::Model(std::string dbFileName){
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

bool Model::addDatabase(std::string dbFileName){
    
}
bool Model::addNewUser(User& user){

}
bool Model::hasUser(User& user){

}
bool Model::hasUserWithLogin(std::string login)
{

}
bool Model::buyCD(int CDCode, int quantity){

}
std::vector<CD> Model::availableCDsInfo(){

}
CD Model::bestSellingCDInfo(){

}
int Model::getMostPopularSingerSoldCDsAmount(){

}
int Model::getSoldCDsAmount(int CDCode, std::string startPeriod, std::string endPeriod){

}
std::vector<std::vector<std::string>> Model::getSoldAndLeftCDSortedDescDiff(){

}
std::vector<std::string> Model::getSoldCDsNumberAndProfitByEachAuthor(){

}
bool Model::addCD(int CDCode, int quantity){

}
std::vector<std::vector<std::string>> Model::getReceivedAndSoldCDAmountByEachCD(std::string startPeriod, std::string endPeriod){

}
std::vector<std::vector<std::string>> Model::getSoldCDsAmountAndProfit(int CDCode, std::string startPeriod, std::string endPeriod){

}
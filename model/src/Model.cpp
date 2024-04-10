#include "../include/Model.h"

Model::Model()
{
}
Model::Model(std::string dbFileName){
    
}
Model::~Model()
{
}
bool Model::addDatabase(std::string dbFileName){

}
bool Model::addNewUser(User* user){

}
bool Model::hasUser(User* user){


}
bool Model::buyCD(int CDCode, int quantity){

}
std::vector<CD*> Model::availableCDsInfo(){

}
std::vector<CD*> Model::bestSellingCDsInfo(){

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
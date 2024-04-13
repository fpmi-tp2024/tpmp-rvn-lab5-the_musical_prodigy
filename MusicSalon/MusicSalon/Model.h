#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "User.h"
#include "CD.h"
#include "Operation.h"
class Model
{
private:
    std::string dbFileName;
public:
    Model() {}
    Model(std::string dbFileName)
    {
        dbFileName = dbFileName;
    }
    ~Model() {}
    //std::string getDBName() const;
    //void setDBName(std::string& name);
    bool addDatabase(std::string dbFileName)
    {
        return true;
    }
    bool addNewUser(const User& user)
    {
        return true;
    }
    bool hasUser(const User& user)
    {
        return true;
    }
    bool hasUserWithLogin(std::string login)
    {
        return true;
    }
    bool canBuyCD(int CDCode)
    {
        return true;
    }
    bool canBuyCD(int CDCode, int quantity)
    {
        return true;
    }
    bool buyCD(const std::vector<Operation>& operations)
    {
        return true;
    }
    std::vector<CD> availableCDsInfo()
    {
        return std::vector<CD>({ CD() });
    }
    CD bestSellingCDInfo()
    {
        return CD();
    }
    int getMostPopularSingerSoldCDsAmount()
    {
        return 3;
    }
    int getSoldCDsAmount(int CDCode, std::string startPeriod, std::string endPeriod)
    {
        return 4;
    }
    /*std::vector<std::vector<std::string>> getSoldAndLeftCDSortedDescDiff();
    std::vector<std::string> getSoldCDsNumberAndProfitByEachAuthor();
    bool addCD(int CDCode, int quantity);
    std::vector<std::vector<std::string>> getReceivedAndSoldCDAmountByEachCD(std::string startPeriod, std::string endPeriod);
    std::vector<std::vector<std::string>> getSoldCDsAmountAndProfit(int CDCode, std::string startPeriod, std::string endPeriod);*/
};


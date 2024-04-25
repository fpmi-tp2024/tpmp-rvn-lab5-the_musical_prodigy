#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <chrono>
#include <sstream>
#include <iomanip>
//#include "libs/sqlite3.h"
//#include "libs/sqlite3.c"
#include <sqlite3.h>
#include <SQLiteCpp/SQLiteCpp.h>
#include "User.h"
#include "CD.h"
#include "Operation.h"
class Model
{
private:
    std::string dbFileName;
    SQLite::Database* db = nullptr;
    int getBestSellingCDId();
    std::vector<int> getReceivedAmount(const std::string& startDate, const std::string& endDate);
    std::vector<std::vector<int>> getSoldAmount(const std::string& startDate, const std::string& endDate);
public:
    Model();
    Model(std::string dbFileName);
    ~Model();
    std::string getDBName() const;
    void setDBName(std::string& name);
    bool addDatabase(std::string dbFileName);
    bool addNewUser(const User& user);
    bool hasUser(const User& user);
    bool hasUserWithLogin(std::string login);
    bool canBuyCD(int CDCode, int quantity);
    bool canBuyCD(int CDCode);
    std::vector<CD> availableCDsInfo();
    CD bestSellingCDInfo();
    int getMostPopularSingerSoldCDsAmount();
    int getSoldCDsAmount(int CDCode, std::string startPeriod, std::string endPeriod);
    std::vector<std::vector<std::string>> getSoldAndLeftCDSortedDescDiff();
    std::vector<std::vector<std::string>> getSoldCDsNumberAndProfitByEachAuthor();
    bool addOrBuyCD(const std::vector<Operation>& operations);
    std::vector<std::vector<int>> getReceivedAndSoldCDAmountByEachCD(std::string startPeriod, std::string endPeriod);
    std::vector<double> getSoldCDsAmountAndProfit(int CDCode, std::string startPeriod, std::string endPeriod);
};



/*#pragma once
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
    bool addOrBuyCD(const std::vector<Operation>& operations)
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
    // Returns vector of vectors <CD_code, sold_amount, amount_in_stock, difference_between_amount_in_stock_and_sold>
    std::vector<std::vector<std::string>> getSoldAndLeftCDSortedDescDiff() {
        return std::vector<std::vector<std::string>>({ {"1", "2", "3", "1"}, {"2", "5", "10", "5"} });
    }
    // Returns vector of vectors <author, sold_amount, profit>
    std::vector<std::vector<std::string>> getSoldCDsNumberAndProfitByEachAuthor()
    {
        return std::vector<std::vector<std::string>>({ {"aaa", "12", "200"}, {"bbb", "33", "300"} });
    }
    //returns 3 columns: CD_id, Sold amount, Received amount
    std::vector<std::vector<int>> getReceivedAndSoldCDAmountByEachCD(std::string startPeriod, std::string endPeriod)
    {
        return std::vector<std::vector<int>>({ {1, 2, 3}, {4222222, 522222, 622222222} });
    }
    //returns <profit, amount_of_sold_CDs>
    std::vector<double> getSoldCDsAmountAndProfit(int CDCode, std::string startPeriod, std::string endPeriod)
    {
        return std::vector<double>({ 300000000, 6000 });
    }
    

    //bool addCD(int CDCode, int quantity);
    
};*/


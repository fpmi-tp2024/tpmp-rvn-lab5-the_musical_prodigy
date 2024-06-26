//MariaGorelik

#pragma once

#include "../Model/Model.h"
#include "../Model/User.h"
#include "../Model/CD.h"
#include <string>
#include <vector>

class Controller
{
private:
	Model* _model;
public:
	Controller();
	~Controller();
	bool addModel(std::string dbFileName);
	bool LoginAlreadyExists(std::string login);
	bool signUp(const User& user);
	bool signIn(const User& user);
	std::vector<CD> getAvailableCDsInfo();
	CD getBestSellingCDInfo();
	int getMostPopularSingerSoldCDsAmount();
	int getSoldCDsAmount(int CD_code, std::string startPeriod, std::string endPeriod);
	bool canBuyCD(int CD_code);
	bool canBuyCD(int CD_code, int quantity);
	bool buyCD(const std::vector<Operation>& operations);
	std::vector<std::vector<std::string>> getSoldAndLeftCDAmountSortedDescDiff();
	std::vector<std::vector<std::string>> getSoldCDsNumberAndProfitByEachAuthor();
	std::vector<std::vector<int>> getReceivedAndSoldCDAmountByEachCD(std::string startPeriod, std::string endPeriod);
	std::vector<double> getSoldCDsAmountAndProfit(int CDCode, std::string startPeriod, std::string endPeriod);
	bool addCD(const std::vector<Operation>& operations);
};
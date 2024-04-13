//MariaGorelik

#pragma once

#include "Model.h"
#include "User.h"
#include "CD.h"
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
	bool checkLoginIfAlreadyExist(std::string login);
	bool signUp(const User& user);
	bool signIn(const User& user);
	std::vector<CD> getAvailableCDsInfo();
	CD getBestSellingCDInfo();
	int getMostPopularSingerSoldCDsAmount();
	int getSoldCDsAmount(int CD_code, std::string startPeriod, std::string endPeriod);
	bool canBuyCD(int CD_code);
	bool canBuyCD(int CD_code, int quantity);
	bool buyCD(const std::vector<Operation>& operations);
};
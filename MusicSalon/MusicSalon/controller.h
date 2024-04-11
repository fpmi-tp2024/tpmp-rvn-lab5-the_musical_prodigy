//MariaGorelik

#pragma once

#include "model.h"
#include "user.h"
#iinclude "CD.h"
#include <string>
#include <vector>

class Controller
{
private:
	Model* _model;
	std::string _dbFileName;

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
};
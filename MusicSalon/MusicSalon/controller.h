//MariaGorelik

#pragma once

#include "model.h"
#include "user.h"
#include <string>

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
	bool signUp(User* user);
	bool signIn();
};
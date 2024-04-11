//MariaGorelik

#pragma once

#include "controller.h"
#include "command.h"
#include "user.h"
#include "CD.h"
#include "MusicalComposition"
#include <iostream>
#include <string>
#include <unordered_map>

class View
{
private:
	Controller* _controller;
	std::string _dbFileName;
	User* _user;
	std::unordered_map < std::string, Command*> _startMenuCommands;
	std::unordered_map <std::string, Command*> _customerMenuCommands;
	std::unordered_map<std::string, Command*> _adminMenuCommands;
	void addStartMenuCommands();
	void addCustomerMenuCommands();
	void addAdminMenuCommands();
public:
	View();
	~View();
	Controller* getController();
	bool addController(std::string dbFileName);
	void printGreeting();
	void printStartMenu();
	void setUser(User* user);
	void printComposition(MusicalComposition* composition);
	void printCD(CD* cd);
	void start();
};


//MariaGorelik

#pragma once

#include "controller.h"
#include "command.h"
#include "user.h"
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
	std::unordered_map <std::string, Command*> _customerMenu;
	std::unordered_map<std::string, Command*> _admitMenu;
	void addStartMenuCommands();
public:
	View();
	~View();
	Controller* getController();
	bool addController(std::string dbFileName);
	void printGreeting();
	void printStartMenu();
	void setUser(User* user);
	void start();
};


//MariaGorelik

#pragma once

#include "controller.h"
#include "command.h"
#include "User.h"
#include "CD.h"
#include "MusicalComposition.h"
#include "Operation.h"
#include "command.h"
#include <iostream>
#include <string>
#include <unordered_map>
#include <regex>
#include <chrono>
#include <ctime>
#include <iomanip>

class Command;

class View
{
private:
	Controller* _controller;
	User* _user;
	static const std::string quitCommand;
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
	void addController(Controller* controller);
	void printGreeting();
	void printStartMenu();
	void printCustomerMenu();
	void printAdminMenu();
	void printComposition(const MusicalComposition& composition);
	void printCD(const CD& cd);
	bool isCorrectCDCode(const std::string& str);
	//bool isCorrectCDsAmount(const std::string& amount);
	bool isValidDate(const std::string& dateStr);
	int compareDates(const std::string& date1, const std::string& date2);
	std::string getCurrentDate();
	void start();
	friend class SignUpCommand;
	friend class SignInCommand;
	friend class LogOutCommand;
};


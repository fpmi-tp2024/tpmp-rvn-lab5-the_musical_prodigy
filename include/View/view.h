//MariaGorelik

#pragma once

#include "../Controller/controller.h"
#include "command.h"
#include "../Model/User.h"
#include "../Model/CD.h"
#include "../Model/MusicalComposition.h"
#include "../Model/Operation.h"
#include <iostream>
#include <string>
#include <unordered_map>
#include <regex>
#include <chrono>
#include <ctime>
#include <cstdio>
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
	std::string hashPassword(const std::string& password) const;
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
	bool isCorrectCDcodeAndAmount(const std::string& input);
	bool isValidDate(const std::string& dateStr);
	int compareDates(const std::string& date1, const std::string& date2);
	std::string getCurrentDate();
	UserRole getUserRole() const;
	void start();
	friend class SignUpCommand;
	friend class SignInCommand;
	friend class LogOutCommand;
};


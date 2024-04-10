//MariaGorelik

#pragma once

#include "controller.h"
#include <iostream>
#include <string>

class Command
{
private:
	Controller* _controller;
	std::string _description;
public:
	Command(Controller* controller);
	~Command();
	virtual void execute() = 0;
	virtual void setDescription(std::string description);
	virtual std::string getDescription();
};

class SignUpCommand : public Command
{
private:
	std::string enterLogin();
public:
	SignUpCommand(Controller* controller);
	~SignUpCommand();
	virtual void execute();
};

class SignInCommand : public Command
{
public:
	SignInCommand(Controller* controller);
	SignInCommand();
	virtual void execute();
};





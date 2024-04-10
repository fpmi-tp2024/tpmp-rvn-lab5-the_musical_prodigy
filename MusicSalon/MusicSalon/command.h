//MariaGorelik

#pragma once

#include "view.h"
#include <iostream>
#include <string>

class Command
{
protected:
	View* _view;
	Controller* _controller;
	std::string _description;
public:
	Command();
	Command(View* view, Controller* controller);
	~Command();
	virtual void execute() = 0;
	void setDescription(std::string description);
	std::string getDescription();
};

class SignUpCommand : public Command
{
private:
	std::string enterLogin();
	std::string enterPassword();
public:
	SignUpCommand(View* view, Controller* controller);
	~SignUpCommand();
    void execute() override;
};

class SignInCommand : public Command
{
public:
	SignInCommand(View* view, Controller* controller);
	SignInCommand();
	void execute() override;
};





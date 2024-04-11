//MariaGorelik

#pragma once

#include "view.h"
#include <iostream>
#include <string>
#include <vector>

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

class AuthorizationCommand : public Command
{
protected:
	std::string enterLogin();
	std::string enterPassword();
public:
	AuthorizationCommand(View* view, Controller* controller);
	~AuthorizationCommand();
	virtual void execute() = 0;
};

class SignUpCommand : public AuthorizationCommand
{
public:
	SignUpCommand(View* view, Controller* controller);
	~SignUpCommand();
    void execute() override;
};

class SignInCommand : public AuthorizationCommand
{
public:
	SignInCommand(View* view, Controller* controller);
	~SignInCommand();
	void execute() override;
};

class AvailableCDsInfoCommand : public Command
{
	AvailableCDsInfoCommand(View* view, Controller* controller);
	~AvailableCDsInfoCommand();
	void execute() override;
};

class BestSellingCDInfoCommand : public Command
{
	BestSellingCDInfoCommand(View* view, Controller* controller);
	~BestSellingCDInfoCommand();
	void execute() override;
};

class MostPopularSingerSoldCDsAmountCommand : public Command
{
	MostPopularSingerSoldCDsAmountCommand(View* view, Controller* controller);
	~MostPopularSingerSoldCDsAmountCommand();
	void execute() override;
};



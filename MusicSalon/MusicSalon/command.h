//MariaGorelik

//ToDo: add printMenu commands

#pragma once

#include "view.h"
#include <iostream>
#include <string>
#include <vector>
#include <sstream>


class Command
{
protected:
	View* _view;
	Controller* _controller;
	std::string _description;
	static const std::string endCommand;
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

class LogOutCommand : public Command
{
public:
	LogOutCommand(View* view, Controller* controller);
	~LogOutCommand();
	void execute() override;
};

class QuitCommand : public Command
{
public:
	QuitCommand(View* view, Controller* controller);
	~QuitCommand();
	void execute() override;
};

class AvailableCDsInfoCommand : public Command
{
public:
	AvailableCDsInfoCommand(View* view, Controller* controller);
	~AvailableCDsInfoCommand();
	void execute() override;
};

class BestSellingCDInfoCommand : public Command
{
public:
	BestSellingCDInfoCommand(View* view, Controller* controller);
	~BestSellingCDInfoCommand();
	void execute() override;
};

class MostPopularSingerSoldCDsAmountCommand : public Command
{
public:
	MostPopularSingerSoldCDsAmountCommand(View* view, Controller* controller);
	~MostPopularSingerSoldCDsAmountCommand();
	void execute() override;
};

class GetSoldCDsAmountByCDCodeAndTimePeriodCommand : public Command
{
public:
	GetSoldCDsAmountByCDCodeAndTimePeriodCommand(View* view, Controller* controller);
	~GetSoldCDsAmountByCDCodeAndTimePeriodCommand();
	void execute() override;
};

class BuyCDCommand : public Command
{
private:
	static const std::string endBuyCommand;
	std::vector<std::pair<int, int>> orders;
	bool isCorrectCDcodeAndAmount(const std::string& input);
	void printOrders();
public:
	BuyCDCommand(View* view, Controller* controller);
	~BuyCDCommand();
	void execute() override;
};



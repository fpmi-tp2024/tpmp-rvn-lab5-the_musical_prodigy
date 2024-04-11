//MariaGorelik

#include "command.h"

//Command

const std::string Command::endCommand = "q";

Command::Command()
{

}

Command::Command(View* view, Controller* controller)
{
	this->_view = view;
	this->_controller = controller;
}

Command::~Command()
{

}

void Command::setDescription(std::string description)
{
	this->_description = description;
}

std::string Command::getDescription()
{
	return this->_description;
}

//AuthorizationCommand

AuthorizationCommand::AuthorizationCommand(View* view, Controller* controller) : Command(view, controller)
{

}

AuthorizationCommand::~AuthorizationCommand()
{

}

std::string AuthorizationCommand::enterLogin()
{
	std::cout << "Enter login:\n";
	std::string login;
	std::cin >> login;
	while (login.empty())
	{
		std::cout << "Login can't be an empty string, try again:\n";
		std::cin >> login;
	}

	return login;
}

std::string AuthorizationCommand::enterPassword()
{
	std::cout << "Enter password:\n";
	std::string password;
	std::cin >> password;
	while (password.empty())
	{
		std::cout << "Password can't be an empty string, try again:\n";
		std::cin >> password;
	}

	return password;
}

//SignUpCommand

SignUpCommand::SignUpCommand(View* view, Controller* controller) : AuthorizationCommand(view, controller)
{
	setDescription("Sign up to music salon");
}

SignUpCommand::~SignUpCommand()
{

}

void SignUpCommand::execute()
{
	std::string login = this->enterLogin();

	if (login == endCommand)
	{
		return;
	}

	while (!this->_controller->checkLoginIfAlreadyExist(login))
	{
		std::cout << "User with this login already exists, try another login or type q to quit:\n";
		login = this->enterLogin();

		if (login == endCommand)
		{
			return;
		}
	}

	std::string password = this->enterPassword();
	
	if (password == endCommand)
	{
		return;
	}

	std::cout << "Confirm your password:\n";
	std::string passwordToConfirm = this->enterPassword();

	if (passwordToConfirm == endCommand)
	{
		return;
	}

	while (password != passwordToConfirm)
	{
		std::cout << "Passwords are not equal, try to confirm again:\n";
		passwordToConfirm = this->enterPassword();

		if (passwordToConfirm == endCommand)
		{
			return;
		}
	}

	User* user = new User(0, login, password); // 0

	if (this->_controller->signUp(*user))
	{
		std::cout << "You have signed up successfully!\n";
		this->_view->setUser(user);
	}

	else
	{
		std::cout << "Sign up failed\n";
	}
}

//SignInCommand

SignInCommand::SignInCommand(View* view, Controller* controller): AuthorizationCommand(view, controller)
{
	setDescription("Sign in to to music salon");
}

SignInCommand::~SignInCommand()
{

}

void SignInCommand::execute()
{
	std::cout << "Choose a role to sign in:\n";
	std::cout << "0: customer\n";
	std::cout << "1: admin\n";

	std::string chosenUserRole;
	std::cin >> chosenUserRole;

	if (chosenUserRole == endCommand)
	{
		return;
	}

	while (chosenUserRole != "0" && chosenUserRole != "1")
	{
		std::cout << "Enter '0' or '1'\n";
		std::cin >> chosenUserRole;

		if (chosenUserRole == endCommand)
		{
			return;
		}
	}

	std::string login = this->enterLogin();

	if (login == endCommand)
	{
		return;
	}

	std::string password = this->enterPassword();

	User* user = new User(stoi(chosenUserRole), login, password);

	if (this->_controller->signIn(*user))
	{
		std::cout << "You have signed in successfully!\n";
		this->_view->setUser(user);
	}

	else
	{
		std::cout << "Incorrect login or password\n";
	}
}

//AvailableCDsInfoCommand

AvailableCDsInfoCommand::AvailableCDsInfoCommand(View* view, Controller* controller) : Command(view, controller)
{
	setDescription("Show info about all available CDs in out salon");
}

AvailableCDsInfoCommand::~AvailableCDsInfoCommand()
{

}

void AvailableCDsInfoCommand::execute()
{
	std::vector<CD> info = this->_controller->getAvailableCDsInfo();
	
	if (info.empty())
	{
		std::cout << "No data found\n";
		return;
	}

	std::cout << "Available CDs list:\n";

	for (int i = 0; i < info.size(); i++)
	{
		this->_view->printCD(info[i]);
		std::cout << "\n";
	}
}

//BestSellingCDInfoCommand

BestSellingCDInfoCommand::BestSellingCDInfoCommand(View* view, Controller* controller) : Command(view, controller)
{
	setDescription("Show info about the best selling CD");
}

BestSellingCDInfoCommand::~BestSellingCDInfoCommand()
{

}

void BestSellingCDInfoCommand::execute()
{
	CD = this->_controller->getBestSellingCDInfo();

	if (CD.empty())
	{
		std::cout << "No data found\n";
		return;
	}

	std::cout << "Information about the best selling CD:\n";
	this->_view->printCD(CD);
	std::cout << "\n";
}

//MostPopularSingerSoldCDsAmountCommand

MostPopularSingerSoldCDsAmountCommand::MostPopularSingerSoldCDsAmountCommand(View* view, Controller* controller) : Command(view, controller)
{
	setDescription("Show amount of sold CDs of the most popular singer");
}

MostPopularSingerSoldCDsAmountCommand::~MostPopularSingerSoldCDsAmountCommand()
{
	
}

void MostPopularSingerSoldCDsAmountCommand::execute()
{
	int amount = this->_controller->getMostPopularSingerSoldCDsAmount();

	if (amount == -1)
	{
		std::cout << "No fata found\n";
		return;
	}

	std::cout << "Amount of sold CDs of the most popular singer: " << amount << "\n";
}

// GetSoldCDsAmountByCDCodeAndTimePeriodCommand

GetSoldCDsAmountByCDCodeAndTimePeriodCommand::GetSoldCDsAmountByCDCodeAndTimePeriodCommand(View* view, Controller* controller) : Command(view, controller)
{
	setDescription("Show amount of sold CDs by CD code and period of time");
}

GetSoldCDsAmountByCDCodeAndTimePeriodCommand::~GetSoldCDsAmountByCDCodeAndTimePeriodCommand()
{

}

void GetSoldCDsAmountByCDCodeAndTimePeriodCommand::execute()
{
	std::string CD_code;
	std::cout << "Enter CD code:\n";
	std::getline(std::cin, CD_code);

	if (CD_code == endCommand)
	{
		return;
	}

	while (!this->_view->isCorrectCDCode(CD_code))
	{
		if (CD_code == endCommand)
		{
			return;
		}

		std::cout << "Incorrect CD code format, try again:\n";
		std::getline(std::cin, CD_code);
	}

	std::string startPeriod;
	std::cout << "Enter start period in format yyyy-mm-dd (year >= 2000):\n";
	std::getline(std::cin, startPeriod);

	if (startPeriod == endCommand)
	{
		return;
	}

	while (!this->_view->isValidDate(startPeriod))
	{
		if (startPeriod == endCommand)
		{
			return;
		}

		std::cout << "Incorrect data format, try again:\n";
		std::getline(std::cin, startPeriod);
	}

	std::string endPeriod;
	std::cout << "Enter end period in format yyyy-mm-dd:\n";
	std::getline(std::cin, endPeriod);

	if (endPeriod == endCommand)
	{
		return;
	}

	while (!this->_view->isValidDate(endPeriod))
	{
		if (endPeriod == endCommand)
		{
			return;
		}

		std::cout << "Incorrect data format, try again:\n";
		std::getline(std::cin, endPeriod);
	}

	while (this->_view->compareDates(startPeriod, endPeriod) == 1) // startPeriod > endPeriod
	{
		std::cout << "End period should  go after start period, try enter end period again:\n";
		std::getline(std::cin, endPeriod);
		if (endPeriod == endCommand)
		{
			return;
		}
	}

	int soldCDsAmount = this->_controller->getSoldCDsAmount(stoi(CD_code), startPeriod, endPeriod);

	if (soldCDsAmount == -1)
	{
		std::cout << "No data found\n";
		return;
	}

	std::cout << "Sold CDs amount by CD code: " << CD_code << " , start date: " << startPeriod;
    std::cout << " , end period: " << endPeriod << ":\n";
	std::cout << soldCDsAmount << "\n";
}
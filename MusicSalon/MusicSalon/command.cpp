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
		this->_view->_user = user;
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
		this->_view->_user = user;
	}

	else
	{
		std::cout << "Incorrect login or password\n";
	}
}

// LogOutCommand

LogOutCommand::LogOutCommand(View* view, Controller* controller): Command(view, controller)
{
	setDescription("Log out");
}

LogOutCommand::~LogOutCommand()
{

}

void LogOutCommand::execute()
{
	this->_view->_user = nullptr;
}

// QuitCommand

QuitCommand::QuitCommand(View* view, Controller* controller)
{
	setDescription("quit the program");
}

QuitCommand::~QuitCommand()
{

}

void execute()
{
	std::cout << "Goodbye!\n";
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
	CD cd = this->_controller->getBestSellingCDInfo();

	if (cd.empty())
	{
		std::cout << "No data found\n";
		return;
	}

	std::cout << "Information about the best selling CD:\n";
	this->_view->printCD(cd);
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

// BuyCDCommand

const std::string BuyCDCommand::endBuyCommand = "buy";

BuyCDCommand::BuyCDCommand(View* view, Controller* controller) : Command(view, controller)
{
	setDescription("Buy CDs");
}

BuyCDCommand::~BuyCDCommand()
{

}

bool BuyCDCommand::isCorrectCDcodeAndAmount(const std::string& input)
{
	if (input.empty())
	{
		return false;
	}

	std::istringstream iss(input);
	int num1, num2;
	char delimiter;

	if (!(iss >> num1 >> delimiter >> num2) || delimiter != ' ') {
		return false;
	}

	if (num1 <= 0 || num2 <= 0) {
		return false;
	}

	char c;
	if (iss >> c) {
		return false;
	}

	return true;
}

void BuyCDCommand::printOrders()
{
	std::cout << "Your order:\n";
	for (int i = 0; i < orders.size(); i++)
	{
		std::cout << "CD code: " << orders[i].first << " quantity: " << orders[i].second << "\n";
	}
}

void BuyCDCommand::execute()
{
	std::cout << "Choode CDs to buy:\n";
	std::cout << "For each CD enter CD code and number of CDs if format 'cd_code number'\n";
	std::cout << "To complete operation, enter 'buy'\n";

	std::string input;

	bool canMakeOrder = false;

	while (input != endCommand)
	{
		std::getline(std::cin, input);

		if (input == endBuyCommand)
		{
			if (canMakeOrder)
			{
				printOrders();

				std::cout << "If you agree to complete the operation, type 'y', if not agree, type anything but 'y':\n";
				std::string answer;
				std::getline(std::cin, answer);
				if (answer != "y")
				{
					return;
				}

				std::vector<Operation> operations(orders.size());

				for (int i = 0; i < orders.size(); i++)
				{
					Operation operation = Operation(this->_view->getCurrentDate(), operCode ? ? ? , orders[i].first, orders[i].second);
					operations[i] = operation;
				}

				if (this->_controller->buyCD(operations))
				{
					std::cout << "You successfully complete your order!\n";
				}

				else
				{
					std::cout << "Something went wrong, try again\n";
				}

				return;
			}

			else
			{
				std::cout << "There are some problems in your order, fix them and try again\n";
			}
		}

		else if(!isCorrectCDcodeAndAmount(input))
		{
			std::cout << "incorrect format, try again\n";
			canMakeOrder = false;
		}

		else
		{
			std::istringstream iss(input);
			int CD_code, quantity;
			char delimiter;
			iss >> CD_code >> delimiter >> quantity;

			if (this->_controller->canBuyCD(CD_code))
			{
				if (this->_controller->canBuyCD(CD_code, quantity))
				{
					orders.push_back(std::pair<int, int>(CD_code, quantity));
					canMakeOrder = true;
				}

				else
				{
					std::cout << "There is not anough CDs in stock, maybe try less amount\n";
					canMakeOrder = false;
				}
			}

			else
			{
				std::cout << "There isn't such disk in stock, try another option\n";
				canMakeOrder = false;
			}
		}
	}
}
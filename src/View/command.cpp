//MariaGorelik

#include "../../include/View/command.h"

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

void Command::printAuthorizedUserMenu() const
{
	if (this->_view->getUserRole() == UserRole::USER)
	{
		this->_view->printCustomerMenu();
	}
	else if (this->_view->getUserRole() == UserRole::ADMIN)
	{
		this->_view->printAdminMenu();
	}
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
		this->_view->printStartMenu();
		return;
	}

	while (this->_controller->LoginAlreadyExists(login))
	{
		std::cout << "User with this login already exists, try another login or type q to quit:\n";
		login = this->enterLogin();

		if (login == endCommand)
		{
			this->_view->printStartMenu();
			return;
		}
	}

	std::string password = this->enterPassword();
	
	if (password == endCommand)
	{
		this->_view->printStartMenu();
		return;
	}

	std::cout << "Confirm your password:\n";
	std::string passwordToConfirm = this->enterPassword();

	if (passwordToConfirm == endCommand)
	{
		this->_view->printStartMenu();
		return;
	}

	while (password != passwordToConfirm)
	{
		std::cout << "Passwords are not equal, try to confirm again:\n";
		passwordToConfirm = this->enterPassword();

		if (passwordToConfirm == endCommand)
		{
			this->_view->printStartMenu();
			return;
		}
	}

	std::string hashedPassword = this->_view->hashPassword(password);

	User* user = new User(UserRole::USER, login, hashedPassword);

	if (this->_controller->signUp(*user))
	{
		std::cout << "You have signed up successfully!\n";
		this->_view->_user = user;
		printAuthorizedUserMenu();
	}

	else
	{
		std::cout << "Sign up failed\n";
		this->_view->printStartMenu();
	}
}

//SignInCommand

SignInCommand::SignInCommand(View* view, Controller* controller): AuthorizationCommand(view, controller)
{
	setDescription("Sign in to music salon");
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
		this->_view->printStartMenu();
		return;
	}

	while (chosenUserRole != "0" && chosenUserRole != "1")
	{
		std::cout << "Enter '0' or '1'\n";
		std::cin >> chosenUserRole;

		if (chosenUserRole == endCommand)
		{
			this->_view->printStartMenu();
			return;
		}
	}

	std::string login = this->enterLogin();

	if (login == endCommand)
	{
		this->_view->printStartMenu();
		return;
	}

	std::string password = this->enterPassword();

	User* user;
	std::string hashedPassword = this->_view->hashPassword(password);

	if (chosenUserRole == "0")
	{
		user = new User(UserRole::USER, login, hashedPassword);
	}

	else
	{
		user = new User(UserRole::ADMIN, login, hashedPassword);
	}

	if (this->_controller->signIn(*user))
	{
		std::cout << "You have signed in successfully!\n";
		this->_view->_user = user;
		printAuthorizedUserMenu();
	}

	else
	{
		std::cout << "Incorrect login or password\n";
		this->_view->printStartMenu();
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
	std::cout << "You have successfully logged out\n";
	this->_view->printStartMenu();
}

// QuitCommand

QuitCommand::QuitCommand(View* view, Controller* controller)
{
	setDescription("quit the program");
}

QuitCommand::~QuitCommand()
{

}

void QuitCommand::execute()
{
	std::cout << "Goodbye!\n";
}

//AvailableCDsInfoCommand

AvailableCDsInfoCommand::AvailableCDsInfoCommand(View* view, Controller* controller) : Command(view, controller)
{
	setDescription("Show info about all available CDs in our salon");
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
	}

	else
	{
		std::cout << "Available CDs list:\n";

		for (int i = 0; i < info.size(); i++)
		{
			this->_view->printCD(info[i]);
			std::cout << "\n";
		}
	}

	printAuthorizedUserMenu();
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

	if (cd.getCDCode() == -1)
	{
		std::cout << "No data found\n";
	}

	else
	{
		std::cout << "Information about the best selling CD:\n";
		this->_view->printCD(cd);
		std::cout << "\n";
	}

	printAuthorizedUserMenu();
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
	}

	else
	{
		std::cout << "Amount of sold CDs of the most popular singer: " << amount << "\n";
	}

	printAuthorizedUserMenu();
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
		printAuthorizedUserMenu();
		return;
	}

	while (!this->_view->isCorrectCDCode(CD_code))
	{
		if (CD_code == endCommand)
		{
			printAuthorizedUserMenu();
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
		printAuthorizedUserMenu();
		return;
	}

	while (!this->_view->isValidDate(startPeriod))
	{
		if (startPeriod == endCommand)
		{
			printAuthorizedUserMenu();
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
		printAuthorizedUserMenu();
		return;
	}

	while (!this->_view->isValidDate(endPeriod))
	{
		if (endPeriod == endCommand)
		{
			printAuthorizedUserMenu();
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
			printAuthorizedUserMenu();
			return;
		}
	}

	int soldCDsAmount = this->_controller->getSoldCDsAmount(stoi(CD_code), startPeriod, endPeriod);

	if (soldCDsAmount == -1)
	{
		std::cout << "No data found\n";
		printAuthorizedUserMenu();
		return;
	}

	std::cout << "Sold CDs amount by CD code: " << CD_code << ", start date: " << startPeriod;
    std::cout << ", end period: " << endPeriod << ":\n";
	std::cout << soldCDsAmount << "\n\n";
	printAuthorizedUserMenu();
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
	std::cout << "For each CD enter CD code and number of CDs in format 'cd_code number'\n";
	std::cout << "To complete operation, enter '" << this->endBuyCommand << "'\n";

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
					orders.clear();
					printAuthorizedUserMenu();
					return;
				}

				std::vector<Operation> operations(orders.size());

				for (int i = 0; i < orders.size(); i++)
				{
					Operation operation = Operation(OperationCode::SELL, orders[i].first, this->_view->getCurrentDate(), orders[i].second);
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

				std::cout << "\n";
				printAuthorizedUserMenu();
				return;
			}

			else
			{
				std::cout << "There are some problems in your order, fix them and try again\n";
			}
		}

		else if(!this->_view->isCorrectCDcodeAndAmount(input))
		{
			std::cout << "incorrect format, try again\n";
			if (orders.empty())
			{
				canMakeOrder = false;
			}
		}

		else
		{
			std::istringstream iss(input);
			int CD_code, quantity;
			char delimiter;
			iss >> CD_code >> std::noskipws >> delimiter >> quantity;

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

// GetSoldAndLeftCDAmountSortedDescDiffCommand

GetSoldAndLeftCDAmountSortedDescDiffCommand::GetSoldAndLeftCDAmountSortedDescDiffCommand(View* view, Controller* controller): Command(view, controller)
{
	setDescription("Get information about amount of sold and left CDs sorted by descending difference");
}

void GetSoldAndLeftCDAmountSortedDescDiffCommand::execute()
{
	std::vector<std::vector<std::string>> info = this->_controller->getSoldAndLeftCDAmountSortedDescDiff();
	if (info.empty())
	{
		std::cout << "No information was recieved\n\n";
		printAuthorizedUserMenu();
		return;
	}

	std::cout << "CD code\t" << "sold amount\t" << "amount in stock\t" << "difference between amount in stock and sold\n";
	for (int i = 0; i < info.size(); i++)
	{
		for (int j = 0; j < 3; j++)
		{
			std::cout << info[i][j] << "\t";
		}
		std::cout << info[i][3] << "\n";
	}

	printAuthorizedUserMenu();
}

// GetSoldCDsNumberAndProfitByEachAuthorCommand

GetSoldCDsNumberAndProfitByEachAuthorCommand::GetSoldCDsNumberAndProfitByEachAuthorCommand(View * view, Controller * controller): Command(view, controller)
{
	this->tableWidth = 15;
	setDescription("Get information about number of sold CDs and earned money by each author");
}

void GetSoldCDsNumberAndProfitByEachAuthorCommand::execute()
{
	// Returns vector of vectors <author, sold_amount, profit>
	std::vector<std::vector<std::string>> info = this->_controller->getSoldCDsNumberAndProfitByEachAuthor();
	if (info.empty())
	{
		std::cout << "No information was recieved\n";
		printAuthorizedUserMenu();
		return;
	}

	std::cout << "author" << std::setw(tableWidth) << "sold amount" << std::setw(tableWidth) << "profit\n";
	for (int i = 0; i < info.size(); i++)
	{
		std::cout << info[i][0] << std::setw(tableWidth) << info[i][1] << std::setw(tableWidth) << info[i][2] << "\n";
	}

	printAuthorizedUserMenu();
}

// GetReceivedAndSoldCDAmountByEachCDCommand

GetReceivedAndSoldCDAmountByEachCDCommand::GetReceivedAndSoldCDAmountByEachCDCommand(View* view, Controller* controller) : Command(view, controller)
{
	this->tableWidth = 18;
	setDescription("Get information about the number of received and sold compacts for each CD number by given amount of time");
}

void GetReceivedAndSoldCDAmountByEachCDCommand::execute()
{
	std::string startPeriod;
	std::cout << "Enter start period in format yyyy-mm-dd (year >= 2000):\n";
	std::getline(std::cin, startPeriod);

	if (startPeriod == endCommand)
	{
		printAuthorizedUserMenu();
		return;
	}

	while (!this->_view->isValidDate(startPeriod))
	{
		if (startPeriod == endCommand)
		{
			printAuthorizedUserMenu();
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
		printAuthorizedUserMenu();
		return;
	}

	while (!this->_view->isValidDate(endPeriod))
	{
		if (endPeriod == endCommand)
		{
			printAuthorizedUserMenu();
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
			printAuthorizedUserMenu();
			return;
		}
	}

	std::vector<std::vector<int>> info = this->_controller->getReceivedAndSoldCDAmountByEachCD(startPeriod, endPeriod);
	if (info.empty())
	{
		std::cout << "No information was recieved\n";
		printAuthorizedUserMenu();
		return;
	}

	std::cout << "start period: " << startPeriod << ", end period: " << endPeriod << "\n";
	std::cout << std::setw(tableWidth) << "CD id" << std::setw(tableWidth) << "sold amount" << std::setw(tableWidth) << "recieved amount\n";
	for (int i = 0; i < info.size(); i++)
	{
		std::cout << std::setw(tableWidth) << info[i][0] << std::setw(tableWidth) << info[i][1] << std::setw(tableWidth) << info[i][2] << "\n";
	}

	printAuthorizedUserMenu();
}

// GetSoldCDsAmountAndProfitCommand

GetSoldCDsAmountAndProfitCommand::GetSoldCDsAmountAndProfitCommand(View* view, Controller* controller) : Command(view, controller)
{
	setDescription("Get amount of sold CDs and amount of earned money by CD number and time period");
}

void GetSoldCDsAmountAndProfitCommand::execute()
{
	std::string CD_code;
	std::cout << "Enter CD code:\n";
	std::getline(std::cin, CD_code);

	if (CD_code == endCommand)
	{
		printAuthorizedUserMenu();
		return;
	}

	while (!this->_view->isCorrectCDCode(CD_code))
	{
		if (CD_code == endCommand)
		{
			printAuthorizedUserMenu();
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
		printAuthorizedUserMenu();
		return;
	}

	while (!this->_view->isValidDate(startPeriod))
	{
		if (startPeriod == endCommand)
		{
			printAuthorizedUserMenu();
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
		printAuthorizedUserMenu();
		return;
	}

	while (!this->_view->isValidDate(endPeriod))
	{
		if (endPeriod == endCommand)
		{
			printAuthorizedUserMenu();
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
			printAuthorizedUserMenu();
			return;
		}
	}

	std::vector<double> info = this->_controller->getSoldCDsAmountAndProfit(stoi(CD_code), startPeriod, endPeriod);
	if (info.empty())
	{
		std::cout << "No information was recieved\n";
		printAuthorizedUserMenu();
		return;
	}

	std::cout << "CD code: " << CD_code << ", start period: " << startPeriod << ", end period: " << endPeriod << "\n";
	std::cout << "profit: " << info[0] << ", amount of sold CDs: " << info[1] << "\n";
	printAuthorizedUserMenu();
}

// AddCDCommand

const std::string AddCDCommand::endAddCommand = "add";

AddCDCommand::AddCDCommand(View* view, Controller* controller) : Command(view, controller)
{
	tableWidth = 15;
	setDescription("Add a particular amount of CDs of a particular CD number to the salon");
}

void AddCDCommand::execute()
{
	std::cout << "Choose CDs to add:\n";
	std::cout << "For each CD enter CD code and number of CDs in format 'cd_code number'\n";
	std::cout << "To complete operation, enter '" << this->endAddCommand << "'\n";

	std::string input;

	bool canAdd = false;

	while (input != endCommand)
	{
		std::getline(std::cin, input);

		if (input == endAddCommand)
		{
			if (canAdd)
			{
				std::cout << "CDs to add:\n";
				std::cout << std::setw(tableWidth) << "CD code" << std::setw(tableWidth) << "quantity" << "\n";
				for (int i = 0; i < addedCDsAndAmount.size(); i++)
				{
					std::cout << std::setw(tableWidth) << addedCDsAndAmount[i].first << std::setw(tableWidth) << addedCDsAndAmount[i].second << "\n";
				}

				std::cout << "If you agree to complete the operation, type 'y', if not agree, type anything but 'y':\n";
				std::string answer;
				std::getline(std::cin, answer);
				if (answer != "y")
				{
					addedCDsAndAmount.clear();
					printAuthorizedUserMenu();
					return;
				}

				std::vector<Operation> operations(addedCDsAndAmount.size());

				for (int i = 0; i < addedCDsAndAmount.size(); i++)
				{
					Operation operation = Operation(OperationCode::RECEIVE, addedCDsAndAmount[i].first, this->_view->getCurrentDate(), addedCDsAndAmount[i].second);
					operations[i] = operation;
				}

				if (this->_controller->addCD(operations))
				{
					std::cout << "You successfully add these CDs to the salon\n";
				}

				else
				{
					std::cout << "Something went wrong, try again\n";
				}

				printAuthorizedUserMenu();
				return;
			}

			else
			{
				std::cout << "There are some problems in your data, fix them and try again\n";
			}
		}

		else if (!this->_view->isCorrectCDcodeAndAmount(input))
		{
			std::cout << "incorrect format, try again\n";
			if (this->addedCDsAndAmount.empty())
			{
				canAdd = false;
			}
		}

		else
		{
			std::istringstream iss(input);
			int CD_code, quantity;
			char delimiter;
			iss >> CD_code >> std::noskipws >> delimiter >> quantity;
			this->addedCDsAndAmount.push_back(std::pair<int, int>(CD_code, quantity));
			canAdd = true;
		}
	}
}

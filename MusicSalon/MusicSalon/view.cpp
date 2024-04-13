//MariaGorelik

#include "view.h"
#include "command.h"

const std::string View::quitCommand = "quit";

View::View()
{
	this->_user = nullptr;
}

View::~View()
{
	if (this->_user)
	{
		delete this->_user;
		this->_user = nullptr;
	}

	if (this->_controller)
	{
		delete this->_controller;
		this->_controller = nullptr;
	}

	for (auto it = this->_startMenuCommands.begin(); it != this->_startMenuCommands.end(); ++it)
	{
		if (&it)
		{
			delete it->second;
		}
	}
}

Controller* View::getController()
{
	return _controller;
}

void View::addStartMenuCommands()
{
	this->_startMenuCommands["signUp"] = new SignUpCommand(this, this->getController());
	this->_startMenuCommands["signIn"] = new SignInCommand(this, this->getController());
	this->_startMenuCommands[View::quitCommand] = new QuitCommand(this, this->getController());
}

void View::addCustomerMenuCommands()
{
	this->_startMenuCommands["logOut"] = new LogOutCommand(this, this->getController());
    this->_startMenuCommands["1"] = new AvailableCDsInfoCommand(this, this->getController());
	this->_startMenuCommands["2"] = new BestSellingCDInfoCommand(this, this->getController());
	this->_startMenuCommands["3"] = new MostPopularSingerSoldCDsAmountCommand(this, this->getController());
	this->_startMenuCommands["4"] = new GetSoldCDsAmountByCDCodeAndTimePeriodCommand(this, this->getController());
	this->_startMenuCommands["buy"] = new BuyCDCommand(this, this->getController());
	this->_startMenuCommands[View::quitCommand] = new QuitCommand(this, this->getController());
}

void View::addAdminMenuCommands()
{
	this->_startMenuCommands["logOut"] = new LogOutCommand(this, this->getController());
	this->_startMenuCommands[View::quitCommand] = new QuitCommand(this, this->getController());
}


void View::addController(Controller* controller)
{
		addStartMenuCommands();
		addCustomerMenuCommands();
		addAdminMenuCommands();
}

void View::printGreeting()
{
	std::cout << "Welcome to music salon app!\n";
	std::cout << "Choose an option to start:\n";
}

void View::printStartMenu()
{
	for (auto it = this->_startMenuCommands.begin(); it != this->_startMenuCommands.end(); ++it)
	{
		std::cout << it->first << ":\t" << it->second->getDescription() << "\n";
	}

	std::cout << "use 'q' command to quit from all commands\n";
}

void View::printCustomerMenu()
{
	for (auto it = this->_customerMenuCommands.begin(); it != this->_customerMenuCommands.end(); ++it)
	{
		std::cout << it->first << ":\t" << it->second->getDescription() << "\n";
	}

	std::cout << "use 'q' command to quit from all commands\n";
}

void View::printAdminMenu()
{
	for (auto it = this->_adminMenuCommands.begin(); it != this->_adminMenuCommands.end(); ++it)
	{
		std::cout << it->first << ":\t" << it->second->getDescription() << "\n";
	}

	std::cout << "use 'q' command to quit from all commands\n";
}

void View::printComposition(const MusicalComposition& composition)
{
	std::cout << "Name: " << composition.getName() << "\n";
	
	std::vector<std::string> authors = composition.getAuthor();
	
	if (authors.empty())
	{
		std::cout << "No information about author\n";
	}
	
	else
	{
		std::cout << "Autors:\n";
		for (int i = 0; i < authors.size(); i++)
		{
			std::cout << authors[i] << " ";
		}
		std::cout << "\n";
	}

	std::vector<std::string> performers = composition.getPerformer();

	if (performers.empty())
	{
		std::cout << "No information about performer\n";
	}

	else
	{
		std::cout << "Performers:\n";
		for (int i = 0; i < performers.size(); i++)
		{
			std::cout << performers[i] << " ";
		}
		std::cout << "\n";
	}
}

void View::printCD(const CD& cd)
{
	std::cout << "Code: " << cd.getCDCode() << "\n";
	std::cout << "Manufacture year: " << cd.getManufactureYear() << "\n";
	std::cout << "Manufacturer: " << cd.getManufacturer() << "\n";

	std::vector<MusicalComposition> compositions = cd.getCompositions();
	
	if (compositions.empty())
	{
		std::cout << "No information about compositions\n";
	}

	else
	{
		std::cout << "Compositions:\n";
		for (int i = 0; i < compositions.size(); i++)
		{
			this->printComposition(compositions[i]);
		}
	}

	std::cout << "Price: " << cd.getPrice() << "\n";
	std::cout << "Amount in stock: " << cd.getAmounInStock() << "\n";
}

bool View::isCorrectCDCode(const std::string& str) {
	if (str.empty()) {
		return false;
	}
	for (char ch : str) {
		if (!std::isdigit(ch)) {
			return false;
		}
	}

	int number;
	std::istringstream iss(str);
	iss >> number;
	return (number > 0);
}

/*bool View::isCorrectCDsAmount(const std::string& amount)
{
	if (amount.empty()) {
		return false;
	}
	for (char ch : amount) {
		if (!std::isdigit(ch)) {
			return false;
		}
	}

	int number;
	std::istringstream iss(amount);
	iss >> number;
	return (number > 0);
}*/

bool View::isValidDate(const std::string& dateStr) {
	std::regex pattern("^\\d{4}-\\d{2}-\\d{2}$");

	if (!std::regex_match(dateStr, pattern)) {
		return false;
	}

	int year, month, day;
	sscanf(dateStr.c_str(), "%d-%d-%d", &year, &month, &day);

	auto now = std::chrono::system_clock::now();
	time_t nowTime = std::chrono::system_clock::to_time_t(now);
	struct tm* nowTM = std::localtime(&nowTime);
	int currentYear = nowTM->tm_year + 1900;

	if (year < 2000 || year > currentYear) {
		return false;
	}

	if (month < 1 || month > 12) {
		return false;
	}

	if (day < 1 || day > 31) {
		return false;
	}

	return true;
}

int View::compareDates(const std::string& date1, const std::string& date2) {
	int year1, month1, day1;
	sscanf(date1.c_str(), "%d-%d-%d", &year1, &month1, &day1);

	int year2, month2, day2;
	sscanf(date2.c_str(), "%d-%d-%d", &year2, &month2, &day2);

	if (year1 < year2) return -1;
	if (year1 > year2) return 1;

	if (month1 < month2) return -1;
	if (month1 > month2) return 1;

	if (day1 < day2) return -1;
	if (day1 > day2) return 1;

	return 0;
}

std::string View::getCurrentDate() 
{
	std::time_t currentTime = std::time(nullptr);
	struct std::tm* localTime = std::localtime(&currentTime);

	std::stringstream ss;
	ss << std::setfill('0') << std::setw(4) << localTime->tm_year + 1900 << ":"
		<< std::setw(2) << localTime->tm_mon + 1 << ":"
		<< std::setw(2) << localTime->tm_mday;

	return ss.str();
}

void View::start()
{
	printGreeting();
	printStartMenu();
	std::string userCommand;

	while (userCommand != View::quitCommand)
	{
		std::getline(std::cin, userCommand);
		
		if (this->_user == nullptr)
		{
			if (this->_startMenuCommands.find(userCommand) == this->_startMenuCommands.end())
			{
				std::cout << "Choose an appropriate command: \n";
			}

			else
			{
				this->_startMenuCommands[userCommand]->execute();
			}
		}

		else if (this->_user->getUserRoleId() == UserRole::USER)
		{
			if (this->_customerMenuCommands.find(userCommand) == this->_customerMenuCommands.end())
			{
				std::cout << "Choose an appropriate command: \n";
			}

			else
			{
				this->_customerMenuCommands[userCommand]->execute();
			}
		}

		else if (this->_user->getUserRoleId() == UserRole::ADMIN)
		{
			if (this->_adminMenuCommands.find(userCommand) == this->_adminMenuCommands.end())
			{
				std::cout << "Choose an appropriate command: \n";
			}

			else
			{
				this->_adminMenuCommands[userCommand]->execute();
			}
		}
	}
}
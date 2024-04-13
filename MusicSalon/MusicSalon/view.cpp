//MariaGorelik

#include "view.h"
#include "command.h"

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
}

void View::addCustomerMenuCommands()
{

}

void View::addAdminMenuCommands()
{

}


bool View::addController(std::string dbFileName)
{
	this->_dbFileName = dbFileName;
	this->_controller = new Controller();
	if (this->_controller->addModel(dbFileName))
	{
		addStartMenuCommands();

		return true;
	}
	return false;
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

	std::cout << "quit:\tquit\n";
	std::cout << "use 'q' command to quit from all commands\n";
}

void View::setUser(User* user)
{
	this->_user = user;
}

void View::printComposition(const MusicalComposition& composition)
{
	std::cout << "Name: " << composition.name << "\n";
	
	if (composition.author.empty())
	{
		std::cout << "No information about author\n";
	}
	
	else
	{
		std::cout << "Autors:\n";
		for (int i = 0; i < composition.author.size(); i++)
		{
			std::cout << composition.author[i] << " ";
		}
		std::cout << "\n";
	}

	if (composition.performer.empty())
	{
		std::cout << "No information about performer\n";
	}

	else
	{
		std::cout << "Performers:\n";
		for (int i = 0; i < composition.performer.size(); i++)
		{
			std::cout << composition.performer[i] << " ";
		}
		std::cout << "\n";
	}
}

void View::printCD(const CD& cd)
{
	std::cout << "Code: " << CD.CD_code << "\n";
	std::cout << "Manufacture year: " << CD.manufacture_year << "\n";
	std::cout << "Manufacturer: " << CD.manufacturer << "\n";

	if (CD.compositions.empty())
	{
		std::cout << "No information about compositions\n";
	}

	else
	{
		std::cout << "Compositions:\n";
		for (int i = 0; i < CD.compositions.size(); i++)
		{
			this->printComposition(CD.compositions[i]);
		}
	}

	std::cout << "Price: " << CD.price << "\n";
	std::cout << "Amount in stock: " << CD.amountInStock << "\n";
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
		return false; // Неверный формат даты
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
	do
	{
		std::cout << "Choose an appropriate command: \n";
		std::cin >> userCommand;
	} while (this->_startMenuCommands.find(userCommand) == this->_startMenuCommands.end());

	if (this->_startMenuCommands.contains(userCommand))
	{
		this->_startMenuCommands[userCommand]->execute();
	}


}
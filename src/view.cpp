//MariaGorelik

#include "./include/view.h"
#include "./include/command.h"

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
		this->controller = nullptr;
	}
	
	for (auto it = this->_startMenuCommands.begin(); it != this->_startMenuCommands.end(); ++it)
	{
		if (it)
		{
			delete it->second;
		}
	}
}

void View::addStartMenuCommands()
{
	SignUpCommand* signUpCommand(this->_controller);
	SignInCommand* signInCommand(this->_controller);
	this->_startMenuCommands.insert(std::pair<std::string, Command*>("signUp", signUpCommand));
	this->_startMenuCommands.insert(std::pair<std::string, Command*>("signIn", signInCommand));
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

void View::printStartMenu()
{
	std::cout << "Welcome to music salon app!\n";
	std::cout << "Choose an option to start:\n";

	for (auto it = this->_startMenuCommands.begin(); it != this->_startMenuCommands.end(); ++it)
	{
		std::cout << it->first << ":\t" << it->second->getDescription() << "\n";
	}
}

void start()
{
	printStartMenu();
	std::string userCommand;
	do
	{
		std::cout << "Choose an appropriate command: \n";
		std::cin >> userCommand;
	} while (!(this->_startMenuCommands.contains(userCommand)));

	if (this->_startMenuCommands.contains(userCommand))
	{
		this->_startMenuCommands[userCommand]->execute();
	}


}
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

const Controller& View::getController()
{
	return *_controller;
}

void View::addStartMenuCommands()
{
	this->_startMenuCommands["signUp"] = new SignUpCommand(this);
	this->_startMenuCommands["signIn"] = new SignInCommand(this);
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
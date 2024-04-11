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

void View::printComposition(MusicalComposition* composition)
{
	if (composition == nullptr)
	{
		std::cout << "No information about composition\n";
		return;
	}

	std::cout << "Name: " << composition->name << "\n";
	
	if (composition->author.empty())
	{
		std::cout << "No information about author\n";
	}
	
	else
	{
		std::cout << "Autors:\n";
		for (int i = 0; i < composition->author.size(); i++)
		{
			std::cout << composition->author[i] << " ";
		}
		std::cout << "\n";
	}

	if (composition->performer.empty())
	{
		std::cout << "No information about performer\n";
	}

	else
	{
		std::cout << "Performers:\n";
		for (int i = 0; i < composition->performer.size(); i++)
		{
			std::cout << composition->performer[i] << " ";
		}
		std::cout << "\n";
	}
}

void View::printCD(CD* cd)
{
	if (CD == nullptr)
	{
		std::cout << "No information about CD\n";
		return;
	}

	std::cout << "Code: " << CD->CD_code << "\n";
	std::cout << "Manufacture year: " << CD->manufacture_year << "\n";
	std::cout << "Manufacturer: " << CD->manufacturer << "\n";

	if (CD->compositions.empty())
	{
		std::cout << "No information about compositions\n";
	}

	else
	{
		std::cout << "Compositions:\n";
		for (int i = 0; i < CD->compositions.size(); i++)
		{
			this->printComposition(CD->compositions[i]);
		}
	}

	std::cout << "Price: " << CD->price << "\n";
	std::cout << "Amount in stock: " << CD->amountInStock << "\n";
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
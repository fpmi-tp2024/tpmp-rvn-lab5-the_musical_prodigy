//MariaGorelik

#include "command.h"

//Command

Command::Command(Controller* controller)
{
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

//SignUpCommand

SignUpCommand::SignUpCommand(Controller* controller)
{
	Command(controller);
	setDescription("Sign up to music salon");
}

SignUpCommand::~SignUpCommand()
{

}

std::string SignUpCommand::enterLogin()
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

void SignUpCommand::execute()
{
	std::string login = enterLogin();

	while (!this->_controller->checkLoginIfAlreadyExist(login))
	{
		std::cout << "User with this login already exists, try another login or type q to quit:\n";

	}



	std::cout << "Enter password:\n";
	std::string password;
	std::cin >> password;
	while (password.empty())
	{
		std::cout << "Password can't be an empty string, try again:\n";
		std::cin >> password;
	}

	std::cout << "Confirm your password:\n";
	std::string passwordToConfirm;
	std::cin >> passwordToConfirm;
	while (password != passwordToConfirm)
	{
		std::cout << "Passwords are not equal, try to confirm again:\n";
		std::cin >> passwordToConfirm;
	}


}

//SignInCommand

SignInCommand::SignInCommand(Controller* controller)
{
	Command(controller);
	setDescription("Sign in to to music salon");
}

SignInCommand::SignInCommand()
{

}

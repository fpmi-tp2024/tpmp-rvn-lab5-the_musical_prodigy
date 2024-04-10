//MariaGorelik

#include "command.h"

//Command

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

	if (login == "q")
	{
		return;
	}

	while (!this->_view->checkLoginIfAlreadyExist(login))
	{
		std::cout << "User with this login already exists, try another login or type q to quit:\n";
		login = this->enterLogin();

		if (login == "q")
		{
			return;
		}
	}

	std::string password = this->enterPassword();
	
	if (password == "q")
	{
		return;
	}

	std::cout << "Confirm your password:\n";
	std::string passwordToConfirm = this->enterPassword();

	if (passwordToConfirm == "q")
	{
		return;
	}

	while (password != passwordToConfirm)
	{
		std::cout << "Passwords are not equal, try to confirm again:\n";
		passwordToConfirm = this->enterPassword();

		if (passwordToConfirm == "q")
		{
			return;
		}
	}

	User* user = new User(0, login, password); // 0

	if (this->_controller->signUp(user))
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

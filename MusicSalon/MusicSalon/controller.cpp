//MariaGorelik

#include "controller.h"

Controller::Controller()
{

}

Controller::~Controller()
{
	if (this->_model)
	{
		delete this->_model;
		this->_model = nullptr;
	}
}

bool Controller::addModel(std::string dbFileName)
{
	this->_model = new Model();
	if (this->_model->addDatabase(dbFileName))
	{
		return true;
	}
	return false;
}

bool Controller::checkLoginIfAlreadyExist(std::string login)
{
	return this->_model->hasUserWithLogin(login);
}

bool Controller::signUp(const User& user)
{
	return this->_model->addNewUser(user);
}

bool Controller::signIn(const User& user)
{
	return this->_model->hasUser(user);
}

std::vector<CD> Controller::getAvailableCDsInfo()
{
	return this->_model->availableCDsInfo();
}

CD Controller::getBestSellingCDInfo()
{
	return this->_model->bestSellingCDInfo();
}

int Controller::getMostPopularSingerSoldCDsAmount()
{
	return this->_model->getMostPopularSingerSoldCDsAmount();
}

int Controller::getSoldCDsAmount(int CD_code, std::string startPeriod, std::string endPeriod)
{
	return this->_model->getSoldCDsAmount(CD_code, startPeriod, endPeriod);
}

bool Controller::canBuyCD(int CD_code)
{
	return this->_model->canBuyCD(CD_code);
}

bool Controller::canBuyCD(int CD_code, int quantity)
{
	return this->_model->canBuyCD(CD_code, quantity);
}

bool Controller::buyCD(const std::vector<Operation>& operations)
{
	return this->_model->buyCD(operations);
}

std::vector<std::vector<std::string>> Controller::getSoldAndLeftCDAmountSortedDescDiff()
{
	std::vector<std::vector<std::string>> info = this->_model->getSoldAndLeftCDSortedDescDiff();
	for (int i = 0; i < info.size(); i++)
	{
		// if some data is lost, not show it
		if (info[i].size() < 4)
		{
			info.erase(info.begin() + i);
			i--;
		}
	}
	return info;
}

std::vector<std::vector<std::string>> Controller::getSoldCDsNumberAndProfitByEachAuthor()
{
	std::vector<std::vector<std::string>> info = this->_model->getSoldCDsNumberAndProfitByEachAuthor();
	// if some data is lost, not show it
	for (int i = 0; i < info.size(); i++)
	{
		if (info[i].size() < 3)
		{
			info.erase(info.begin() + i);
			i--;
		}
	}
	return info;
}

std::vector<std::vector<int>> Controller::getReceivedAndSoldCDAmountByEachCD(std::string startPeriod, std::string endPeriod)
{
	std::vector<std::vector<int>> info = this->_model->getReceivedAndSoldCDAmountByEachCD(startPeriod, endPeriod);
	// if some data is lost, not show it
	for (int i = 0; i < info.size(); i++)
	{
		if (info[i].size() < 3)
		{
			info.erase(info.begin() + i);
			i--;
		}
	}
	return info;
}
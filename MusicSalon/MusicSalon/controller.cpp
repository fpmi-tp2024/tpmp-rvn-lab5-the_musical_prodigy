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
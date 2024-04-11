#include "../include/Operation.h"

Operation::Operation()
{
}

Operation::~Operation()
{
}

//Getters
std::string Operation::getOperationDate() const
{
    return this->operationDate;
}
int Operation::getCDCode() const
{
    return this->CDCode;
}
int Operation::getNumberOfCDs() const
{
    return this->numberOfCDs;
}

//Setters
void Operation::setOperationDate(std::string& date)
{
    this->operationDate = date;
}
void Operation::setCDCode(int code)
{
    this->CDCode = code;
}
void Operation::setNumberOfCDs(int number)
{
    this->numberOfCDs = number;
}   

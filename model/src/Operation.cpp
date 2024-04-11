#include "../include/Operation.h"

Operation::Operation()
{
}

Operation::~Operation()
{
}

//Getters
OperationCode Operation::getOperationCode() const
{
    return this->operationCode;
}
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
void Operation::setOperationCode(OperationCode code)
{
    this->operationCode = code;
}
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

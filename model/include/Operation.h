#pragma once
#include <iostream>
#include <string>

class Operation
{
private:
    std::string operationDate;
    enum OperationCode{
        SELL = 0,
        RECEIVE
    };
    int CDCode;
    int numberOfCDs;
public:
    Operation();
    ~Operation();
    std::string getOperationDate() const;
    int getCDCode() const;
    int getNumberOfCDs() const;
    void setOperationDate(std::string& date);
    void setCDCode(int code);
    void setNumberOfCDs(int number);
};



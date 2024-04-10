#pragma once
#include <iostream>
#include <string>

class Operation
{
private:
    std::string operationDate;
    enum OperationCode;
    int CD_Code;
    int numberOfCDs;
public:
    Operation(/* args */);
    ~Operation();
};



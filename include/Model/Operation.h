#pragma once
#include <iostream>
#include <string>

enum class OperationCode {
    SELL = 1,
    RECEIVE
};

class Operation
{
private:
    std::string operationDate;
    OperationCode operationCode;
    int CDCode;
    int numberOfCDs;
public:
    Operation();
    Operation(OperationCode code,
        int CDCode,
        std::string date = "2024-01-01",
        int number = 10);

    ~Operation();
    OperationCode getOperationCode() const;
    std::string getOperationDate() const;
    int getCDCode() const;
    int getNumberOfCDs() const;
    void setOperationCode(OperationCode code);
    void setOperationDate(std::string& date);
    void setCDCode(int code);
    void setNumberOfCDs(int number);
};
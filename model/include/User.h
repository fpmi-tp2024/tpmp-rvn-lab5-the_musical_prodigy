#pragma once
#include <iostream>
#include <string>

class User
{
private:
    int user_role_id;
    std::string username;
    std::string password;
public:
    User(/* args */);
    ~User();
};

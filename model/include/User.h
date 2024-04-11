#pragma once
#include <iostream>
#include <string>

class User
{
private:
    int userRoleId;
    std::string username;
    std::string password;
public:
    User();
    ~User();
    int getUserRoleId() const;
    std::string getUsername() const;
    std::string getPassword() const;
    void setUserRoleId(int newRole);
    std::string setUsername(std::string& newUsername);
    std::string setPassword(std::string& newPassword);
};

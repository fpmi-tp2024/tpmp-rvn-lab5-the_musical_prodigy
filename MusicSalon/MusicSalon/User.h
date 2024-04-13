#pragma once
#include <iostream>
#include <string>

enum class UserRole {
    ADMIN = 1,
    USER
};

class User
{
private:
    UserRole userRoleId;
    std::string username;
    std::string password;
public:
    User();
    User(UserRole id,
        std::string name,
        std::string pass);

    ~User();
    UserRole getUserRoleId() const;
    std::string getUsername() const;
    std::string getPassword() const;
    void setUserRoleId(UserRole newRole);
    void setUsername(std::string& newUsername);
    void setPassword(std::string& newPassword);
};
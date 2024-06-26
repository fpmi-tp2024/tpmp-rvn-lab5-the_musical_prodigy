#include "../../include/Model/User.h"

User::User()
{
}

User::User(UserRole id,
    std::string name,
    std::string pass)
{
    this->userRoleId = id;
    this->username = name;
    this->password = pass;
}

User::~User()
{
}

//Getters
UserRole User::getUserRoleId() const
{
    return this->userRoleId;
}
std::string User::getUsername() const
{
    return this->username;
}
std::string User::getPassword() const
{
    return this->password;
}

//Setters
void User::setUserRoleId(UserRole newRole)
{
    this->userRoleId = newRole;
}
void User::setUsername(std::string& newUsername)
{
    this->username = newUsername;
}
void User::setPassword(std::string& newPassword)
{
    this->password = newPassword;
}
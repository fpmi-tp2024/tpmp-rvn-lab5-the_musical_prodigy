#include "../include/User.h"

User::User()
{
}

User::~User()
{
}

//Getters
int User::getUserRoleId() const
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
void User::setUserRoleId(int newRole)
{
    this->userRoleId = newRole;
}
std::string User::setUsername(std::string& newUsername)
{
    this->username = newUsername;
}
std::string User::setPassword(std::string& newPassword)
{
    this->password = newPassword;
}
#pragma once
#include <iostream>
#include "../users/User.cpp"

class AdminUser : public User
{
public:
    AdminUser(string username, string password) : User(username, password) {}

    bool getIsAdmin() const override
    {
        return true;
    }
};

#pragma once
#include <iostream>
#include <string>

using namespace std;

class User
{
protected:
    string username;
    string password;

public:
    User(const string &username, const string &password)
        : username(username), password(password) {}

    virtual bool getIsAdmin() const = 0;

    virtual string getUsername() const { return username; }
    virtual string getPassword() const { return password; }

    void setUsername(const string &newUsername) { username = newUsername; }
    void setPassword(const string &newPassword) { password = newPassword; }
};

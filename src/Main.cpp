#include <iostream>
#include "AccountManager.cpp"
#include "../users/AdminUser.cpp"
#include "../users/RegularUser.cpp"
#include "../users/User.cpp"
#include "PersonalAccount.cpp"
#include "BusinessAccount.cpp"
#include "App.cpp"

using namespace std;

int main()
{
    App app;
    app.run();
    return 0;
}

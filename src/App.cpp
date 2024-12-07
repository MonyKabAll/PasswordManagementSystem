#pragma once
#include <iostream>
#include "AccountManager.cpp"
#include "../users/AdminUser.cpp"
#include "../users/RegularUser.cpp"
#include "../users/User.cpp"
#include "PersonalAccount.cpp"
#include "BusinessAccount.cpp"

using namespace std;

class App
{
private:
    AccountManager manager;

    void showMenu(User *loggedInUser)
    {
        if (loggedInUser->getIsAdmin())
        {
            cout << "\nAdmin Menu:\n";
            cout << "1. Add Account\n";
            cout << "2. View All Accounts\n";
            cout << "3. Update Password\n";
            cout << "4. Delete Account\n";
            cout << "5. Search Account\n";
            cout << "6. Sort Accounts\n";
            cout << "7. Save Accounts to File\n";
            cout << "8. Load Accounts from File\n";
            cout << "0. Exit\n";
        }
        else
        {
            cout << "\nUser Menu:\n";
            cout << "1. Add Account\n";
            cout << "2. View My Accounts\n";
            cout << "3. Search Account\n";
            cout << "4. Sort Accounts\n";
            cout << "5. Save Accounts to File\n";
            cout << "6. Load Accounts from File\n";
            cout << "0. Exit\n";
        }
        cout << "Enter your choice: ";
    }

    void addAccount()
    {
        string accountType, accountName, username, password;

        cout << "Enter account type (1 for personal/2 for business): ";
        cin >> accountType;
        cout << "Enter account name: ";
        cin.ignore();
        getline(cin, accountName);
        cout << "Enter username: ";
        cin >> username;
        cout << "Enter password: ";
        cin >> password;

        if (accountType == "1")
        {
            PersonalAccount *newAccount = new PersonalAccount(accountName, username, password);
            manager.addAccount(newAccount);
            cout << "Personal account added.\n";
        }
        else if (accountType == "2")
        {
            BusinessAccount *newAccount = new BusinessAccount(accountName, username, password);
            manager.addAccount(newAccount);
            cout << "Business account added.\n";
        }
        else
        {
            cout << "Invalid account type.\n";
        }
    }

    void updateAccountPassword()
    {
        string username, newPassword;
        cout << "Enter username to update password: ";
        cin >> username;
        cout << "Enter new password: ";
        cin >> newPassword;
        manager.updatePassword(username, newPassword);
    }

    void deleteAccount()
    {
        string username;
        cout << "Enter username to delete: ";
        cin >> username;
        manager.deletePassword(username);
    }

    void saveAccounts()
    {
        string filename;
        cout << "Enter filename to save accounts: ";
        cin >> filename;
        manager.saveAccountsToFile(filename);
    }

    void loadAccounts()
    {
        string filename;
        cout << "Enter filename to load accounts: ";
        cin >> filename;
        manager.loadAccountsFromFile(filename);
    }

    void viewMyAccounts(User *loggedInUser)
    {
        manager.viewAccounts(loggedInUser);
    }

    void searchAccount()
    {
        string username;
        cout << "Enter username to search for: ";
        cin >> username;
        manager.searchPassword(username);
    }

public:
    void run()
    {
        AdminUser *admin = new AdminUser("admin", "admin123");
        RegularUser *regular = new RegularUser("user", "user123");

        PersonalAccount *adminAccount = new PersonalAccount("Admin Account", "admin", "admin123");
        PersonalAccount *regularAccount = new PersonalAccount("Regular Account", "user", "user123");

        manager.addUser(admin);
        manager.addUser(regular);
        manager.addAccount(adminAccount);
        manager.addAccount(regularAccount);

        string username, password;
        cout << "\nAdmin username: admin\nPassword: admin123\n";
        cout << "Regular username: user\nPassword: user123\n\n";
        cout << "Enter username: ";
        cin >> username;
        cout << "Enter password: ";
        cin >> password;

        User *loggedInUser = manager.login(username, password);

        if (!loggedInUser)
        {
            cout << "Invalid credentials. Exiting program.\n";
            return;
        }

        cout << "\nWelcome " << (loggedInUser->getIsAdmin() ? "Admin" : "User") << endl;

        int choice;
        while (true)
        {
            showMenu(loggedInUser);
            cin >> choice;

            if (choice < 0 || choice > 8)
            {
                cout << "Invalid choice. Please select a valid option.\n";
                continue;
            }

            if (loggedInUser->getIsAdmin())
            {
                switch (choice)
                {
                case 1:
                    addAccount();
                    break;
                case 2:
                    manager.viewAccounts(loggedInUser);
                    break;
                case 3:
                    updateAccountPassword();
                    break;
                case 4:
                    deleteAccount();
                    break;
                case 5:
                    searchAccount();
                    break;
                case 6:
                    manager.sortAccounts();
                    break;
                case 7:
                    saveAccounts();
                    break;
                case 8:
                    loadAccounts();
                    break;
                case 0:
                    return;
                }
            }
            else
            {
                switch (choice)
                {
                case 1:
                    addAccount();
                    break;
                case 2:
                    manager.viewAccounts(loggedInUser);
                    break;
                case 3:
                    searchAccount();
                case 4:
                    manager.sortAccounts();
                    break;
                case 5:
                    saveAccounts();
                    break;
                case 6:
                    loadAccounts();
                    break;
                case 0:
                    return;
                }
            }
        }
    }
};

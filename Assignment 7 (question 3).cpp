/*. Write a class to store Account information of Bank customer by using following class diagram.
Use enum to store information of account type.
Create an array of 5 Accounts in main() and accept their details from user.
Write Menu driven program to deposit/withdraw
amount from the account.
After each transaction display updated account balance.
Throw exceptions for invalid values.
Also implement an exception class InsufficientFundsException.
In withdraw if sufficient balance is not available in account or while
deposit the entered amount is
negative then throw this exception.*/

#include <iostream>
#include <string>
using namespace std;

// Enum to store Account Type
enum AccountType {
    SAVINGS,
    CURRENT,
    FIXED_DEPOSIT
};

// Exception class for insufficient funds
class InsufficientFundsException : public runtime_error {
public:
    InsufficientFundsException(const string& message)
        : runtime_error(message) {}
};

// Class to store account information
class Account {
    int accountNumber;
    string accountHolderName;
    AccountType accountType;
    double balance;

public:
    // Constructor to initialize account details
    Account() {
        accountNumber = 0;
        accountHolderName = "";
        accountType = SAVINGS;
        balance = 0.0;
    }

    // Method to set account details
    void setAccountDetails(int accNo, string name, AccountType type, double bal) {
        accountNumber = accNo;
        accountHolderName = name;
        accountType = type;
        balance = bal;
    }

    // Display Account Details
    void displayAccountDetails() {
        cout << "Account Number: " << accountNumber << endl;
        cout << "Account Holder: " << accountHolderName << endl;
        cout << "Account Type: " << (accountType == SAVINGS ? "Savings" : accountType == CURRENT ? "Current" : "Fixed Deposit") << endl;
        cout << "Account Balance: " << balance << endl;
    }

    // Method to deposit amount
    void deposit(double amount) {
        if (amount < 0) {
            throw InsufficientFundsException("Cannot deposit negative amount!");
        }
        balance += amount;
        cout << "Amount deposited successfully. Updated Balance: " << balance << endl;
    }

    // Method to withdraw amount
    void withdraw(double amount) {
        if (amount > balance) {
            throw InsufficientFundsException("Insufficient balance to withdraw!");
        }
        balance -= amount;
        cout << "Amount withdrawn successfully. Updated Balance: " << balance << endl;
    }

    // Getter for Account Number
    int getAccountNumber() {
        return accountNumber;
    }
};

int main() {
    Account accounts[5]; // Array to store 5 accounts
    int accNo, accType;
    string name;
    double balance;

    // Accepting account details for 5 accounts
    for (int i = 0; i < 5; ++i) {
        cout << "Enter details for Account " << (i + 1) << ":\n";
        cout << "Account Number: ";
        cin >> accNo;
        cout << "Account Holder Name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Account Type (0 for Savings, 1 for Current, 2 for Fixed Deposit): ";
        cin >> accType;
        cout << "Initial Balance: ";
        cin >> balance;

        // Set account details
        accounts[i].setAccountDetails(accNo, name, static_cast<AccountType>(accType), balance);
        cout << endl;
    }

    // Menu driven program for deposit/withdraw operations
    int choice, accIndex;
    double amount;
    do {
        cout << "\n--- Menu ---\n";
        cout << "1. Deposit\n2. Withdraw\n3. Display Account\n4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1 || choice == 2 || choice == 3) {
            cout << "Enter account number: ";
            cin >> accNo;

            // Search for the account
            accIndex = -1;
            for (int i = 0; i < 5; ++i) {
                if (accounts[i].getAccountNumber() == accNo) {
                    accIndex = i;
                    break;
                }
            }

            if (accIndex == -1) {
                cout << "Account not found!\n";
                continue;
            }
        }

        try {
            switch (choice) {
                case 1: // Deposit
                    cout << "Enter amount to deposit: ";
                    cin >> amount;
                    accounts[accIndex].deposit(amount);
                    break;
                case 2: // Withdraw
                    cout << "Enter amount to withdraw: ";
                    cin >> amount;
                    accounts[accIndex].withdraw(amount);
                    break;
                case 3: // Display Account
                    accounts[accIndex].displayAccountDetails();
                    break;
                case 4: // Exit
                    cout << "Exiting...\n";
                    break;
                default:
                    cout << "Invalid choice! Please try again.\n";
            }
        } catch (const InsufficientFundsException& e) {
            cout << "Error: " << e.what() << endl;
        }
    } while (choice != 4);

    return 0;
}



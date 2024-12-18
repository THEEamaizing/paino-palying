#include <iostream>
#include <map>
#include <string>
using namespace std;

// Structure to represent a Bank Account
struct Account {
    string name;
    double balance;
};

class BankingSystem {
private:
    map<int, Account> accounts; // Store accounts using an account number as key
    int nextAccountNumber;      // Generate unique account numbers

public:
    BankingSystem() : nextAccountNumber(1) {}

    // Function to create a new account
    void createAccount() {
        string name;
        double initialDeposit;

        cout << "Enter your name: ";
        cin >> name;
        cout << "Enter initial deposit amount: ";
        cin >> initialDeposit;

        if (initialDeposit < 0) {
            cout << "Initial deposit cannot be negative!\n";
            return;
        }

        int accountNumber = nextAccountNumber++;
        accounts[accountNumber] = {name, initialDeposit};

        cout << "Account created successfully! Your account number is " << accountNumber << "\n";
    }

    // Function to check account balance
    void checkBalance() {
        int accountNumber;
        cout << "Enter account number: ";
        cin >> accountNumber;

        if (accounts.find(accountNumber) != accounts.end()) {
            cout << "Account Holder: " << accounts[accountNumber].name << "\n";
            cout << "Current Balance: $" << accounts[accountNumber].balance << "\n";
        } else {
            cout << "Account not found!\n";
        }
    }

    // Function to deposit money
    void deposit() {
        int accountNumber;
        double amount;

        cout << "Enter account number: ";
        cin >> accountNumber;
        cout << "Enter amount to deposit: ";
        cin >> amount;

        if (accounts.find(accountNumber) != accounts.end()) {
            if (amount < 0) {
                cout << "Cannot deposit a negative amount!\n";
                return;
            }

            accounts[accountNumber].balance += amount;
            cout << "$" << amount << " deposited successfully!\n";
        } else {
            cout << "Account not found!\n";
        }
    }

    // Function to withdraw money
    void withdraw() {
        int accountNumber;
        double amount;

        cout << "Enter account number: ";
        cin >> accountNumber;
        cout << "Enter amount to withdraw: ";
        cin >> amount;

        if (accounts.find(accountNumber) != accounts.end()) {
            if (amount < 0) {
                cout << "Cannot withdraw a negative amount!\n";
                return;
            }

            if (accounts[accountNumber].balance >= amount) {
                accounts[accountNumber].balance -= amount;
                cout << "$" << amount << " withdrawn successfully!\n";
            } else {
                cout << "Insufficient balance!\n";
            }
        } else {
            cout << "Account not found!\n";
        }
    }
};

int main() {
    BankingSystem bank;
    int choice;

    do {
        cout << "\n--- Banking System Menu ---\n";
        cout << "1. Create Account\n";
        cout << "2. Check Balance\n";
        cout << "3. Deposit\n";
        cout << "4. Withdraw\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            bank.createAccount();
            break;
        case 2:
            bank.checkBalance();
            break;
        case 3:
            bank.deposit();
            break;
        case 4:
            bank.withdraw();
            break;
        case 5:
            cout << "Thank you for using the Banking System!\n";
            break;
        default:
            cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}

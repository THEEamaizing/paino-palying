#include <iostream>
#include <ctime>
#include <thread>
#include <chrono>
#include <iomanip>
using namespace std;

// Function prototypes
void showMenu();
double add(double a, double b);
double subtract(double a, double b);
double multiply(double a, double b);
double divide(double a, double b);

int main() {
    int choice;
    double num1, num2;

    do {
        showMenu();
        cout << "Enter your choice (1-5): ";
        cin >> choice;

        // Check if the user wants to exit
        if (choice == 5) {
            cout << "Exiting the calculator. Goodbye!" << endl;
            break;
        }

        // Input validation for choice
        if (choice < 1 || choice > 5) {
            cout << "Invalid choice. Please try again." << endl;
            continue;
        }

        // Get numbers from the user
        cout << "Enter first number: ";
        cin >> num1;
        cout << "Enter second number: ";
        cin >> num2;

        // Perform the chosen operation
        switch (choice) {
            case 1:
                cout << "Result: " << add(num1, num2) << endl;
                break;
            case 2:
                cout << "Result: " << subtract(num1, num2) << endl;
                break;
            case 3:
                cout << "Result: " << multiply(num1, num2) << endl;
                break;
            case 4:
                if (num2 != 0) {
                    cout << "Result: " << divide(num1, num2) << endl;
                } else {
                    cout << "Error: Division by zero!" << endl;
                }
                break;
            default:
                cout << "Invalid operation." << endl;
                break;
        }

    } while (true);

    return 0;
}

// Function to display the menu
void showMenu() {
    cout << "\nSimple Digital Calculator\n";
    cout << "1. Addition (+)\n";
    cout << "2. Subtraction (-)\n";
    cout << "3. Multiplication (*)\n";
    cout << "4. Division (/)\n";
    cout << "5. Exit\n";
}

// Function definitions for arithmetic operations
double add(double a, double b) {
    return a + b;
}

double subtract(double a, double b) {
    return a - b;
}

double multiply(double a, double b) {
    return a * b;
}

double divide(double a, double b) {
    return a / b;
}
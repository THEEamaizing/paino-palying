#include <iostream>
#include <string>

using namespace std;

int main() {
    int order, no_deals;
    double total_price = 0.0;

    // Display the menu
    cout << "|*---------------------------MENU-----------------------------*|" << endl;
    cout << "(1)  Wali Chicken - $2.00" << endl;
    cout << "(2) Chicken Pilau - $1.50" << endl;
    cout << "(3) Chinese Rice - $2.50" << endl;
    cout << "(4) Chicken Burger - $1.00" << endl;
    cout << "(5)  Buza Pizza - $4.50" << endl;
    cout << "(6) coca Coke - $1.75" << endl;
    cout << "Please select the order number (1-6): ";
    cin >> order;

    // Ask for quantity
    cout << "Please enter the number of deals: ";
    cin >> no_deals;

    // Calculate total price based on the selected item
    switch(order) {
        case 1:
            total_price = 2.00 * no_deals;
            cout << "Order: Chicken Biryani." << endl;
            break;
        case 2:
            total_price = 1.50 * no_deals;
            cout << "Order: Chicken Palao." << endl;
            break;
        case 3:
            total_price = 2.50 * no_deals;
            cout << "Order: Chinese Rice." << endl;
            break;
        case 4:
            total_price = 1.00 * no_deals;
            cout << "Order: Chicken Burger." << endl;
            break;
        case 5:
            total_price = 4.50 * no_deals;
            cout << "Order: Nawabi Pizza." << endl;
            break;
        case 6:
            total_price = 1.75 * no_deals;
            cout << "Order: 2.5 Litre Coke." << endl;
            break;
        default:
            cout << "Invalid selection!" << endl;
            return 1; // Exit if invalid
    }

    // Display the total price
    cout << "Total price for your order: $" << total_price << endl;

    // Thank you message
    cout << "Thank you for your order!" << endl;

    return 0; // Indicate successful execution
}

#include <iostream>
#include <ctime>
#include <thread>
#include <chrono>
#include <iomanip> 

using namespace std;

void clearScreen() {
    // Clear the console screen using platform-specific methods
    #ifdef _WIN32
        system("cls");
    #else
        cout << "\033[2J\033[H";
    #endif
}

void displayTime() {
    time_t now = time(0);
    tm *ttime = localtime(&now);

    cout << setw(2) << setfill('0') << ttime->tm_hour << ":";
    cout << setw(2) << setfill('0') << ttime->tm_min << ":";
    cout << setw(2) << setfill('0') << ttime->tm_sec << endl;
}

int main() {
    while (true) {
        clearScreen();
        displayTime();
        this_thread::sleep_for(chrono::seconds(1));
    }

    return 0;
}
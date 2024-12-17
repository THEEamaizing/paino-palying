#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

class Vehicle {
protected:
    string make;
    string model;
    int year;
    double price;

public:
    Vehicle(string mk, string mdl, int yr, double pr) 
        : make(mk), model(mdl), year(yr), price(pr) {}

    virtual void displayInfo() = 0; // Pure virtual function
};

class Car : public Vehicle {
public:
    Car(string mk, string mdl, int yr, double pr) 
        : Vehicle(mk, mdl, yr, pr) {}

    void displayInfo() override {
        cout << "Car: " << make << " " << model << ", Year: " << year 
             << ", Price: $" << price << endl;
    }
};

class Motorcycle : public Vehicle {
public:
    Motorcycle(string mk, string mdl, int yr, double pr) 
        : Vehicle(mk, mdl, yr, pr) {}

    void displayInfo() override {
        cout << "Motorcycle: " << make << " " << model << ", Year: " << year 
             << ", Price: $" << price << endl;
    }
};

class Bus : public Vehicle {
public:
    Bus(string mk, string mdl, int yr, double pr) 
        : Vehicle(mk, mdl, yr, pr) {}

    void displayInfo() override {
        cout << "Bus: " << make << " " << model << ", Year: " << year 
             << ", Price: $" << price << endl;
    }
};

class Showroom {
private:
    vector<Vehicle*> vehicles;

public:
    void addVehicle(Vehicle* vehicle) {
        vehicles.push_back(vehicle);
    }

    void displayVehicles() {
        for (auto& vehicle : vehicles) {
            vehicle->displayInfo();
        }
    }

    ~Showroom() {
        for (auto& vehicle : vehicles) {
            delete vehicle; // Free allocated memory
        }
    }
};

int main() {
    Showroom showroom;

    // Adding vehicles to the showroom
    showroom.addVehicle(new Car("Toyota", "Camry", 2022, 24000));
    showroom.addVehicle(new Motorcycle("Yamaha", "MT-07", 2021, 8000));
    showroom.addVehicle(new Bus("Mercedes", "Sprinter", 2023, 45000));

    cout << "Welcome to the Vehicle Showroom!" << endl;
    
    // Display all vehicles
    showroom.displayVehicles();

    return 0;
}

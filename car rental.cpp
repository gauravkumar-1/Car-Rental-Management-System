#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Car {
private:
    string name;
    string model;
    string color;
    int year;
    bool isRented;

public:
    Car(string n, string m, string c, int y, bool rented)
        : name(n), model(m), color(c), year(y), isRented(rented) {}

    // Display car details
    void displayCar() {
        cout << "Name: " << name
             << ", Model: " << model
             << ", Color: " << color
             << ", Year: " << year
             << ", Rented: " << (isRented ? "Yes" : "No")
             << endl;
    }

    // Rent the car
    bool rentCar() {
        if (isRented) {
            cout << "Car is already rented.\n";
            return false;
        } else {
            isRented = true;
            cout << "Car rented successfully.\n";
            return true;
        }
    }

    // Return the car
    void returnCar() {
        if (isRented) {
            isRented = false;
            cout << "Car returned successfully.\n";
        } else {
            cout << "Car is not rented.\n";
        }
    }

    // Check if the car is rented
    bool getIsRented() {
        return isRented;
    }

    // Get car name
    string getName() {
        return name;
    }
};

// Car Rental Management System class
class CarRentalSystem {
private:
    vector<Car> cars;

public:
    // Add a new car
    void addCar(string name, string model, string color, int year, bool isRented) {
        cars.push_back(Car(name, model, color, year, isRented));
        cout << "Car added successfully!\n";
    }

    // Display all cars
    void displayCars() {
        if (cars.empty()) {
            cout << "No cars available in the system.\n";
            return;
        }

        cout << "\nAvailable Cars:\n";
        for (size_t i = 0; i < cars.size(); ++i) {
            cout << i + 1 << ". ";
            cars[i].displayCar();
        }
    }

    // Rent a car
    void rentCar(int carIndex) {
        if (carIndex < 1 || carIndex > cars.size()) {
            cout << "Invalid car selection.\n";
            return;
        }

        cars[carIndex - 1].rentCar();
    }

    // Return a car
    void returnCar(int carIndex) {
        if (carIndex < 1 || carIndex > cars.size()) {
            cout << "Invalid car selection.\n";
            return;
        }

        cars[carIndex - 1].returnCar();
    }
};

int main() {
    CarRentalSystem system;
    int choice;

    do {
        cout << "\n--- Car Rental Management System ---\n";
        cout << "1. Add a new car\n";
        cout << "2. Display all cars\n";
        cout << "3. Rent a car\n";
        cout << "4. Return a car\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            string name, model, color;
            int year;
            cout << "Enter car name: ";
            cin >> name;
            cout << "Enter car model: ";
            cin >> model;
            cout << "Enter car color: ";
            cin >> color;
            cout << "Enter car year: ";
            cin >> year;
            system.addCar(name, model, color, year, false);
            break;
        }
        case 2:
            system.displayCars();
            break;
        case 3: {
            int carIndex;
            cout << "Enter car number to rent: ";
            cin >> carIndex;
            system.rentCar(carIndex);
            break;
        }
        case 4: {
            int carIndex;
            cout << "Enter car number to return: ";
            cin >> carIndex;
            system.returnCar(carIndex);
            break;
        }
        case 5:
            cout << "Exiting the system. Thank you for choosing. Goodbye!\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}

#include <iostream>
using namespace std;

// Base Class
class Vehicle
{
protected:
    int id;
    string brand;

public:
    static int totalVehicles;

    Vehicle(int i = 0, string b = "")
    {
        id = i;
        brand = b;

        if (i != 0 || b != "")
        {
            totalVehicles++;
        }
    }

    void display()
    {
        cout << "Vehicle ID: " << id << endl;
        cout << "Brand: " << brand << endl;
    }

    int getId() const
    {
        return id;
    }
};

int Vehicle::totalVehicles = 0;

// Single Inheritance
class Car : public Vehicle
{
public:
    Car(int i = 0, string b = "") : Vehicle(i, b) {}
};

// Multilevel Inheritance
class ElectricCar : public Car
{
public:
    ElectricCar(int i, string b) : Car(i, b) {}

    void charge()
    {
        cout << "Electric Car Charging..." << endl;
    }
};

// Additional Class for Multiple Inheritance
class EntertainmentSystem
{
public:
    void playMusic()
    {
        cout << "Music Playing..." << endl;
    }
};

// Multiple Inheritance
class SuperCar : public Car, public EntertainmentSystem
{
public:
    SuperCar(int i, string b) : Car(i, b) {}
};

// Another Derived Class
class SUV : public Car
{
public:
    SUV(int i, string b) : Car(i, b) {}
};

// Vehicle Registry Class
class VehicleRegistry
{
    Vehicle vehicles[10];
    int count;

public:
    VehicleRegistry()
    {
        count = 0;
    }

    void addVehicle()
    {
        if (count >= 10)
        {
            cout << "Registry Full!" << endl;
            return;
        }

        int id;
        string brand;

        cout << "Enter Vehicle ID: ";
        cin >> id;

        cout << "Enter Vehicle Brand: ";
        cin >> brand;

        vehicles[count] = Vehicle(id, brand);
        count++;

        cout << "Vehicle Added Successfully!" << endl;
    }

    void displayVehicles()
    {
        if (count == 0)
        {
            cout << "No Vehicles Available!" << endl;
            return;
        }

        cout << "\n===== Vehicle Records =====\n";

        for (int i = 0; i < count; i++)
        {
            vehicles[i].display();
            cout << "----------------------" << endl;
        }
    }

    void searchVehicle()
    {
        int searchId;

        cout << "Enter Vehicle ID to Search: ";
        cin >> searchId;

        for (int i = 0; i < count; i++)
        {
            if (vehicles[i].getId() == searchId)
            {
                cout << "\nVehicle Found:\n";
                vehicles[i].display();
                return;
            }
        }

        cout << "Vehicle Not Found!" << endl;
    }
};

int main()
{
    VehicleRegistry vr;
    int choice;

    do
    {
        cout << "\n========== Vehicle Management System ==========\n";
        cout << "1. Add Vehicle\n";
        cout << "2. Display Vehicles\n";
        cout << "3. Search Vehicle\n";
        cout << "4. Show Total Vehicles\n";
        cout << "5. Inheritance Demo\n";
        cout << "6. Exit\n";

        cout << "\nEnter Your Choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            vr.addVehicle();
            break;

        case 2:
            vr.displayVehicles();
            break;

        case 3:
            vr.searchVehicle();
            break;

        case 4:
            cout << "Total Vehicles Added: "
                 << Vehicle::totalVehicles << endl;
            break;

        case 5:
        {
            cout << "\n===== Inheritance Demonstration =====\n";

            // Multilevel Inheritance
            ElectricCar ec(101, "Tesla");

            cout << "\nMultilevel Inheritance Example:\n";
            ec.display();
            ec.charge();

            // Multiple Inheritance
            SuperCar sc(201, "Lamborghini");

            cout << "\nMultiple Inheritance Example:\n";
            sc.display();
            sc.playMusic();

            break;
        }

        case 6:
            cout << "\nThank You for Using Vehicle Management System!" << endl;
            break;

        default:
            cout << "Invalid Choice! Please Try Again." << endl;
        }

    } while (choice != 6);

    return 0;
}
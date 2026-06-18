#include <iostream>
#include <cstring>
using namespace std;

class Train
{
private:
    int trainNumber;
    char trainName[50];
    char source[50];
    char destination[50];
    char trainTime[10];

    static int trainCount;

public:
    Train()
    {
        trainNumber = 0;
        trainName[0] = '\0';
        source[0] = '\0';
        destination[0] = '\0';
        trainTime[0] = '\0';
        trainCount++;
    }

    Train(int no, const char name[], const char src[],
          const char dest[], const char time[])
    {
        trainNumber = no;
        strcpy(trainName, name);
        strcpy(source, src);
        strcpy(destination, dest);
        strcpy(trainTime, time);
        trainCount++;
    }

    ~Train()
    {
        trainCount--;
    }

    void inputTrainDetails()
    {
        cout << "Enter Train Number: ";
        cin >> trainNumber;
        cin.ignore();

        cout << "Enter Train Name: ";
        cin.getline(trainName, 50);

        cout << "Enter Source: ";
        cin.getline(source, 50);

        cout << "Enter Destination: ";
        cin.getline(destination, 50);

        cout << "Enter Train Time: ";
        cin.getline(trainTime, 10);
    }

    void displayTrainDetails()
    {
        cout << "\nTrain Number: " << trainNumber;
        cout << "\nTrain Name: " << trainName;
        cout << "\nSource: " << source;
        cout << "\nDestination: " << destination;
        cout << "\nTrain Time: " << trainTime << endl;
    }

    int getTrainNumber()
    {
        return trainNumber;
    }

    static int getTrainCount()
    {
        return trainCount;
    }
};

int Train::trainCount = 0;

class RailwaySystem
{
private:
    Train trains[100];
    int totalTrains;

public:
    RailwaySystem()
    {
        totalTrains = 0;
    }

    void addTrain()
    {
        trains[totalTrains].inputTrainDetails();
        totalTrains++;
    }

    void displayAllTrains()
    {
        for (int i = 0; i < totalTrains; i++)
        {
            cout << "\nTrain " << i + 1 << " Details:";
            trains[i].displayTrainDetails();
        }
    }

    void searchTrainByNumber(int number)
    {
        for (int i = 0; i < totalTrains; i++)
        {
            if (trains[i].getTrainNumber() == number)
            {
                cout << "\nTrain Found!";
                trains[i].displayTrainDetails();
                return;
            }
        }

        cout << "\nTrain not found!";
    }
};

int main()
{
    RailwaySystem rs;
    int choice, number;

    do
    {
        cout << "\n\n--- Railway Reservation System Menu ---";
        cout << "\n1. Add New Train Record";
        cout << "\n2. Display All Train Records";
        cout << "\n3. Search Train by Number";
        cout << "\n4. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            rs.addTrain();
            break;

        case 2:
            rs.displayAllTrains();
            break;

        case 3:
            cout << "Enter Train Number: ";
            cin >> number;
            rs.searchTrainByNumber(number);
            break;

        case 4:
            cout << "Goodbye!";
            break;

        default:
            cout << "Invalid Choice!";
        }

    } while (choice != 4);

    return 0;
}

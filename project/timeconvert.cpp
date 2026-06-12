#include <iostream>
using namespace std;

int main()
{
    int choice;

    cout << "1. Seconds to Time\n";
    cout << "2. Time to Seconds\n";
    cout << "Enter Choice: ";
    cin >> choice;

    if(choice == 1)
    {
        int sec, h, m, s;

        cout << "Enter Seconds: ";
        cin >> sec;

        h = sec / 3600;
        m = (sec % 3600) / 60;
        s = sec % 60;

        cout << "Time = " << h << ":" << m << ":" << s;
    }
    else if(choice == 2)
    {
        int h, m, s, total;

        cout << "Enter Hours: ";
        cin >> h;

        cout << "Enter Minutes: ";
        cin >> m;

        cout << "Enter Seconds: ";
        cin >> s;

        total = h * 3600 + m * 60 + s;

        cout << "Total Seconds = " << total;
    }
    else
    {
        cout << "Invalid Choice";
    }

    return 0;
}
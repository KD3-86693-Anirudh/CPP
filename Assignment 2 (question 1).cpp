#include <iostream>
using namespace std;

struct DateStruct {
    int day;
    int month;
    int year;

    void initDate() {
        day = 1;
        month = 1;
        year = 1900;
    }

    void acceptDateFromConsole() {
        cout << "Enter day: ";
        cin >> day;
        cout << "Enter month: ";
        cin >> month;
        cout << "Enter year: ";
        cin >> year;
    }

    void printDateOnConsole() const {
        cout << "Date (Structure): " << day << "/" << month << "/" << year << endl;
    }

    bool isLeapYear() const {
        return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    }
};

class DateClass {
    int day;
    int month;
    int year;

public:
    void initDate() {
        day = 1;
        month = 1;
        year = 1900;
    }

    void acceptDateFromConsole() {
        cout << "Enter day: ";
        cin >> day;
        cout << "Enter month: ";
        cin >> month;
        cout << "Enter year: ";
        cin >> year;
    }

    void printDateOnConsole() const {
        cout << "Date (Class): " << day << "/" << month << "/" << year << endl;
    }

    bool isLeapYear() const {
        return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    }
};

int main() {
    DateStruct dateStruct;
    DateClass dateClass;
    int choice = 0;

    while (choice != 9) {
        cout << "\n--- Date Menu ---\n";
        cout << "1. Initialize Date (Structure)\n";
        cout << "2. Accept Date (Structure)\n";
        cout << "3. Print Date (Structure)\n";
        cout << "4. Check if Leap Year (Structure)\n";
        cout << "5. Initialize Date (Class)\n";
        cout << "6. Accept Date (Class)\n";
        cout << "7. Print Date (Class)\n";
        cout << "8. Check if Leap Year (Class)\n";
        cout << "9. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                dateStruct.initDate();
                cout << "Date initialized (Structure) to default (1/1/1900)\n";
                break;
            case 2:
                dateStruct.acceptDateFromConsole();
                break;
            case 3:
                dateStruct.printDateOnConsole();
                break;
            case 4:
                if (dateStruct.isLeapYear()) {
                    cout << dateStruct.year << " is a leap year.\n";
                } else {
                    cout << dateStruct.year << " is not a leap year.\n";
                }
                break;
            case 5:
                dateClass.initDate();
                cout << "Date initialized (Class) to default (1/1/1900)\n";
                break;
            case 6:
                dateClass.acceptDateFromConsole();
                break;
            case 7:
                dateClass.printDateOnConsole();
                break;
            case 8:
                if (dateClass.isLeapYear()) {
                    cout << "The year is a leap year.\n";
                } else {
                    cout << "The year is not a leap year.\n";
                }
                break;
            case 9:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    }

    return 0;
}

David Wasson
3/24/2024
CS-210 Project One

#include <iostream>
#include <iomanip>

using namespace std;

class Clock {
private:
    int hours;
    int minutes;
    int seconds;

public:
    // Constructor to initialize the clock
    Clock(int h, int m, int s) : hours(h), minutes(m), seconds(s) {}

    // User updating hours
    void addHour() {
        hours = (hours + 1) % 24;
    }

    // User updating minutes
    void addMinute() {
        minutes = (minutes + 1) % 60;
        if (minutes == 0) {
            addHour(); // Increment to hours when minutes reach 60
        }
    }

    // User upating seconds
    void addSecond() {
        seconds = (seconds + 1) % 60;
        if (seconds == 0) {
            addMinute(); // Increment to minutes when seconds reach 60
        }
    }

    // Display the clock for 12-hour format
    void display12Hour() const {
        string period = (hours < 12) ? "AM" : "PM";
        int displayHours = (hours > 12) ? hours - 12 : hours;
        if (displayHours == 0) {
            displayHours = 12;
        }
        cout << setw(2) << setfill('0') << displayHours << ":"
            << setw(2) << setfill('0') << minutes << ":"
            << setw(2) << setfill('0') << seconds << " " << period << " ";
    }

    // Display the time for 24-hour format
    void display24Hour() const {
        string period = (hours < 12) ? "AM" : "PM";
        cout << setw(2) << setfill('0') << hours << ":"
            << setw(2) << setfill('0') << minutes << ":"
            << setw(2) << setfill('0') << seconds << " " << period << " ";
    }
};

int main() {
    // Initialize two clock objects
    Clock clock12Hour(12, 0, 0); // Initialize to 12:00:00 AM
    Clock clock24Hour(12, 0, 0); // Initialize to 12:00:00 AM

    char choice;
    do {
        // Display both clocks
        cout << "12-Hour Clock: ";
        clock12Hour.display12Hour();
        cout << endl;

        cout << "24-Hour Clock: ";
        clock24Hour.display24Hour();
        cout << endl;

        // User menu for input
        cout << "Choose an option:" << endl;
        cout << "1. Add one hour" << endl;
        cout << "2. Add one minute" << endl;
        cout << "3. Add one second" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        // Update based on user choice
        switch (choice) {
        case '1':
            clock12Hour.addHour();
            clock24Hour.addHour();
            break;
        case '2':
            clock12Hour.addMinute();
            clock24Hour.addMinute();
            break;
        case '3':
            clock12Hour.addSecond();
            clock24Hour.addSecond();
            break;
        case '4':
            cout << "Exiting program..." << endl;
            break;
        default:
            cout << "Invalid choice. Please enter again." << endl;
        }
    } while (choice != '4');

    return 0;
}

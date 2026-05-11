
#ifndef BOOKING_MANAGER_H
#define BOOKING_MANAGER_H

#include "Flight.h"
#include <iostream>
#include <iomanip>

using namespace std;

// ================= HISTORY ARRAYS =================
string historyNames[100];
string historyDestinations[100];
int historySeats[100];
int bookingCount = 0;

// ================= FUNCTION PROTOTYPES =================
void displayHeader();
void displayMenu();
void showFlightsTable(const Flight flights[], int size);
void searchByBudget(const Flight flights[], int size);
void processBooking(Flight flights[], int size);
void printReceipt(string pName, Flight f, int sNum);
void showBookingHistory();

// ================= FUNCTION DEFINITIONS =================

void displayHeader() {
    cout << "==========================================================" << endl;
    cout << "|                   WELCOME TO CLOUD2GO                   |" << endl;
    cout << "|               Airline Reservation System                |" << endl;
    cout << "==========================================================" << endl;
}

void displayMenu() {
    cout << "| [1] Start Booking  [2] View History/Flights  [3] Exit  |" << endl;
    cout << "==========================================================" << endl;
}

void showFlightsTable(const Flight flights[], int size) {
    cout << "\n--- CURRENT FLIGHT SCHEDULE ---\n";
    cout << left << setw(8) << "No."
         << " | " << setw(12) << "Origin"
         << " | " << setw(15) << "Dest."
         << " | " << setw(10) << "Price" << endl;

    for (int i = 0; i < size; i++) {
        cout << left << setw(8) << flights[i].flightNumber
             << " | " << setw(12) << flights[i].origin
             << " | " << setw(15) << flights[i].destination
             << " | " << setw(10) << flights[i].price << endl;
    }
}

void searchByBudget(const Flight flights[], int size) {
    double budget;
    cout << "Enter your Budget (PHP): ";
    cin >> budget;

    bool found = false;

    for (int i = 0; i < size; i++) {
        if (flights[i].price <= budget) {
            cout << "[" << flights[i].flightNumber << "] "
                 << flights[i].destination
                 << " - PHP " << flights[i].price << endl;
            found = true;
        }
    }

    if (!found || budget <= 0) {
        cout << "\nNo available flights or invalid budget.\n";
        exit(0);
    }
}

void processBooking(Flight flights[], int size) {
    int fNum, sNum;
    string pName;

    cout << "\nEnter Flight Number: ";
    cin >> fNum;

    for (int i = 0; i < size; i++) {
        if (flights[i].flightNumber == fNum) {

            cout << "Passenger Name: ";
            cin.ignore();
            getline(cin, pName);

            cout << "Select Seat (1-5): ";

            for (int s = 1; s <= 5; s++) {
                if (flights[i].seats[s])
                    cout << "[X] ";
                else
                    cout << "[" << s << "] ";
            }

            cout << "\nChoice: ";
            cin >> sNum;

            if (sNum >= 1 && sNum <= 5 && !flights[i].seats[sNum]) {

                flights[i].seats[sNum] = true;

                historyNames[bookingCount] = pName;
                historyDestinations[bookingCount] = flights[i].destination;
                historySeats[bookingCount] = sNum;
                bookingCount++;

                printReceipt(pName, flights[i], sNum);
            }
            else {
                cout << "Invalid or Taken.\n";
            }

            return;
        }
    }

    cout << "Flight not found.\n";
    system("pause");
}

void printReceipt(string pName, Flight f, int sNum) {
    cout << "\n--- RECEIPT ---\n";
    cout << "Passenger: " << pName << endl;
    cout << "Flight   : " << f.destination << endl;
    cout << "Seat     : " << sNum << endl;
    cout << "Price    : " << f.price << endl;

    system("pause");
}

void showBookingHistory() {
    cout << "\n--- BOOKING HISTORY ---\n";

    if (bookingCount == 0) {
        cout << "No records.\n";
    }
    else {
        for (int i = 0; i < bookingCount; i++) {
            cout << historyNames[i]
                 << " | " << historyDestinations[i]
                 << " | Seat: " << historySeats[i] << endl;
        }
    }

    system("pause");
}

#endif

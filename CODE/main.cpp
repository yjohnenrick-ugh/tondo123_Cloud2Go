#include "Flight.h"
#include <iostream>
#include <string>

// Kailangan nating i-declare ang mga functions mula sa Airline_BookingManager.cpp
// para makita sila ng main.cpp
void displayHeader();
void displayMenu();
void showFlightsTable(const Flight flights[], int size);
void searchByBudget(const Flight flights[], int size);
void processBooking(Flight flights[], int size);
void showBookingHistory();

using namespace std;

int main() {
    // 1. INITIALIZATION: Dito natin ilalagay yung records (Topic 10 & 11)
    const int SIZE = 5;
    Flight flights[SIZE] = {
        {101, "Cloud2Go", "Manila", "Singapore", "SG", "May 15", "08:00", "11:00", 5000.0, 5, 0, {false}, true},
        {102, "Cloud2Go", "Manila", "Tokyo", "JP", "May 16", "10:00", "14:00", 12000.0, 5, 0, {false}, true},
        {103, "Cloud2Go", "Manila", "Seoul", "KR", "May 17", "13:00", "17:00", 8500.0, 5, 0, {false}, true},
        {104, "Cloud2Go", "Manila", "Bangkok", "TH", "May 18", "09:00", "12:00", 4500.0, 5, 0, {false}, true},
        {105, "Cloud2Go", "Manila", "Sydney", "AU", "May 19", "21:00", "07:00", 25000.0, 5, 0, {false}, true}
    };

    int choice;

    // 2. MAIN LOOP: Para bumabalik sa menu (Topic 05: Decision Control)
    while (true) {
        system("cls"); // Linisin ang screen para magmukhang professional app
        displayHeader();
        displayMenu();

        cout << "Enter Choice: ";
        cin >> choice;

        if (choice == 1) { // Start Booking
            searchByBudget(flights, SIZE);
            processBooking(flights, SIZE);
        }
        else if (choice == 2) { // View History/Flights
            system("cls");
            showFlightsTable(flights, SIZE);
            showBookingHistory();
        }
        else if (choice == 3) { // Exit
            cout << "\nThank you for using Cloud2Go! Fly safe.\n";
            break;
        }
        else {
            cout << "Invalid choice. Please try again.\n";
            system("pause");
        }
    }

    return 0;
}

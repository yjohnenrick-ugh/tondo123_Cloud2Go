#include "AirlineBookingManager.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

AirlineBookingManager::AirlineBookingManager() { loadData(); }

void AirlineBookingManager::loadData() {
    ifstream file(dbFile);
    if (!file) {
        flights.push_back(Flight(101, "Kyoto-Japan", 5000));
        flights.push_back(Flight(102, "Akihabara-Japan", 5000));
        flights.push_back(Flight(103, "Singapore", 2000));
        flights.push_back(Flight(106, "Paris-France", 45000));
        flights.push_back(Flight(107, "London-UK", 48000));
        flights.push_back(Flight(108, "Rome-Italy", 42000));
        flights.push_back(Flight(109, "Madrid-Spain", 39000));
        flights.push_back(Flight(110, "Berlin-Germany", 41000));
        flights.push_back(Flight(111, "Bangkok-Thailand", 5000));
        flights.push_back(Flight(112, "Hanoi-Vietnam", 4500));
        flights.push_back(Flight(113, "Jakarta-Indonesia", 4000));
        flights.push_back(Flight(114, "Taipei-Taiwan", 9000));
        flights.push_back(Flight(115, "Beijing-China", 15000));
        flights.push_back(Flight(116, "Washington-USA", 75000));
        flights.push_back(Flight(117, "Ottawa-Canada", 72000));
        flights.push_back(Flight(118, "Canberra-Australia", 55000));
        flights.push_back(Flight(119, "Wellington-NZ", 58000));
        flights.push_back(Flight(120, "Moscow-Russia", 35000));
        flights.push_back(Flight(121, "Brasilia-Brazil", 65000));
        flights.push_back(Flight(122, "Cairo-Egypt", 30000));
        flights.push_back(Flight(123, "New_Delhi-India", 12000));
        flights.push_back(Flight(124, "Athens-Greece", 38000));
        flights.push_back(Flight(125, "Bern-Switzerland", 85000));
        return;
    }
    int fn; string dest, sData; double p;
    while (file >> fn >> dest >> p >> sData) {
        Flight temp(fn, dest, p);
        temp.loadSeatData(sData);
        flights.push_back(temp);
    }
    file.close();
}

void AirlineBookingManager::saveData() {
    ofstream file(dbFile);
    for (int i = 0; i < flights.size(); i++) {
        file << flights[i].getFlightNumber() << " " << flights[i].getDestination() << " "
            << flights[i].getPrice() << " " << flights[i].getSeatData() << endl;
    }
    file.close();
}

void AirlineBookingManager::viewHistory() {
    cout << "\n==========================================";
    cout << "\n       TRANSACTION HISTORY / RECEIPT      ";
    cout << "\n==========================================";

    if (transactions.empty()) {
        cout << "\nNo transactions found.\n";
        return;
    }

    for (int i = 0; i < transactions.size(); i++) {
        cout << "\nPassenger: " << transactions[i].passengerName;
        cout << "\nFlight   : " << transactions[i].flightDetails;
        cout << "\nSeat #   : " << transactions[i].seatNumber;
        cout << "\nTotal    : PHP " << transactions[i].price;
        cout << "\n------------------------------------------";
    }
}

bool AirlineBookingManager::searchByBudget() {
    double budget = getValidatedDouble("Enter Budget (PHP): ");
    bool found = false;

    cout << "\n==================================================\n";
    cout << "||              AFFORDABLE FLIGHTS              ||\n";
    cout << "==================================================\n";

    for (int i = 0; i < (int)flights.size(); i++) {
        if (flights[i].getPrice() <= budget) {
            cout << left << "[" << flights[i].getFlightNumber() << "] "
                << setw(25) << flights[i].getDestination()
                << "PHP " << flights[i].getPrice() << endl;
            found = true;
        }
    }

    if (!found) {
        cout << "INVALID: No flights available for your budget. \n";
        system("pause");
        return false;
    }
    system("pause");
    return true;
}

void AirlineBookingManager::processBooking() {
    int fNum = getValidatedInt("Enter Flight Number: ");
    for (int i = 0; i < flights.size(); i++) {
        if (flights[i].getFlightNumber() == fNum) {
            string name;
            cout << "Passenger Name: "; cin.ignore(); getline(cin, name);

            cout << "Seats: ";
            for (int s = 1; s <= 5; s++) cout << (flights[i].isSeatTaken(s) ? "[X] " : "[" + to_string(s) + "] ");

            int sNum = getValidatedInt("\nSelect Seat (1-5): ");
            if (sNum >= 1 && sNum <= 5 && !flights[i].isSeatTaken(sNum)) {
                flights[i].reserveSeat(sNum);

               
                if (!history.empty() || true) {
                    BookingRecord dummy;
                    history.push_back(dummy);
                }

                
                transactions.push_back({ name, flights[i].getDestination(), flights[i].getPrice(), sNum });

                cout << "Booking Confirmed!\n";
                saveData();
            }
            else {
                cout << "Invalid or Taken.\n";
            }
            system("pause");
            return;
        }
    }
    cout << "Flight not found.\n";
    system("pause");
}

void AirlineBookingManager::showFlights() {
    cout << "\n--- ALL AVAILABLE FLIGHTS ---\n";
    for (int i = 0; i < flights.size(); i++) {
        cout << "[" << flights[i].getFlightNumber() << "] "
            << flights[i].getDestination() << "\t- PHP "
            << flights[i].getPrice() << endl;
    }
}

void AirlineBookingManager::cancelBooking() {
    string pass;
    cout << "Admin Password: "; cin >> pass;
    if (pass != "1234") { cout << "Denied.\n"; system("pause"); return; }

    int fNum = getValidatedInt("Flight Number: ");
    int sNum = getValidatedInt("Seat Number: ");
    for (int i = 0; i < flights.size(); i++) {
        if (flights[i].getFlightNumber() == fNum) {
            flights[i].freeSeat(sNum);

            
            for (int t = 0; t < transactions.size(); t++) {
                if (transactions[t].seatNumber == sNum && transactions[t].flightDetails == flights[i].getDestination()) {
                    transactions.erase(transactions.begin() + t);
                    break;
                }
            }

            
            if (!history.empty()) {
                history.pop_back();
            }

            cout << "Cancelled successfully.\n";
            saveData();
            system("pause");
            return;
        }
    }
    cout << "Flight not found.\n";
    system("pause");
}

void AirlineBookingManager::updatePassengerSeat() {
    cout << "\n--- UPDATE PASSENGER SEAT ---\n";
    cout << "Step 1: Cancel your current booking first.\n";
    cancelBooking();

    cout << "\nStep 2: Go to 'Book Flight' to choose your new seat.\n";
    system("pause");
}

void AirlineBookingManager::updatePassengerInfo() {
    string target;
    cout << "Current Passenger Name: "; cin.ignore(); getline(cin, target);

    bool found = false;
    string newName = "";

    
    for (int i = 0; i < transactions.size(); i++) {
        if (transactions[i].passengerName == target) {
            if (!found) {
                cout << "New Name: ";
                getline(cin, newName);
                found = true;
            }
            transactions[i].passengerName = newName;
        }
    }

    if (found) {
        cout << "Success!\n";
    }
    else {
        cout << "Passenger not found.\n";
    }
    system("pause");
}

int AirlineBookingManager::getValidatedInt(string prompt) {
    int val;
    while (true) {
        cout << prompt;
        if (cin >> val) return val;
        cin.clear(); cin.ignore(1000, '\n');
        cout << "Invalid. Enter a number.\n";
    }
}

double AirlineBookingManager::getValidatedDouble(string prompt) {
    double val;
    while (true) {
        cout << prompt;
        if (cin >> val) return val;
        cin.clear(); cin.ignore(1000, '\n');
        cout << "Invalid price.\n";
    }
}

// PURPOSE: Ito ang "Entity Class" (Ang Blueprint).
// Dito nakalista ang lahat ng impormasyon na dapat mayroon ang ISANG flight.
// Halimbawa: Flight 10, Destination, at Presyo.
// Isipin mo ito na parang "Biodata ng isang flight.

#ifndef FLIGHT_H
#define FLIGHT_H

#include <string>
using namespace std;

struct Flight {

    int flightNumber;      // PURPOSE: Unique ID of the flight
    string airlineName;    // PURPOSE: Name of the airline
    string origin;         // PURPOSE: Starting location of the flight
    string destination;    // PURPOSE: Destination of the flight (e.g., Singapore)
    string country;        // PURPOSE: Destination country

    string departureDate;  // PURPOSE: Date of departure
    string departureTime;  // PURPOSE: Time of departure
    string arrivalTime;    // PURPOSE: Estimated arrival time

    double price;          // PURPOSE: Ticket price
    int totalSeats;        // PURPOSE: Total number of seats
    int reservedSeats;     // PURPOSE: Number of seats already reserved

    bool seats[6];         // PURPOSE: Seat availability (true = booked, false = available)
    bool isAvailable;      // PURPOSE: Flight availability status
};

#endif

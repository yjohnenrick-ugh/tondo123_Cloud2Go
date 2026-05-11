#ifndef FLIGHT_H
#define FLIGHT_H

#include <string>
using namespace std;

struct Flight {

    int flightNumber;      
    string airlineName;  
    string origin;       
    string destination;
    string country;       

    string departureDate; 
    string departureTime;  
    string arrivalTime; 
    double price;          
    int totalSeats;       
    int reservedSeats;     

    bool seats[6];         
    bool isAvailable;      

#endif

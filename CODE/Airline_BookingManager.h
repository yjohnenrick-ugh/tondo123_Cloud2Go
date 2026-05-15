#ifndef FLIGHT_H
#define FLIGHT_H
#include <string>

class Flight {
private:
    int flightNumber;
    std::string destination;
    double price;
    bool seats[6];

public:
    Flight() {
        flightNumber = 0;
        destination = "";
        price = 0.0;
        for (int i = 0; i < 6; i++) seats[i] = false;
    }

    Flight(int fn, std::string dest, double p) {
        flightNumber = fn;
        destination = dest;
        price = p;
        for (int i = 0; i < 6; i++) seats[i] = false;
    }

    int getFlightNumber() { return flightNumber; }
    std::string getDestination() { return destination; }
    double getPrice() { return price; }
    bool isSeatTaken(int s) { return seats[s]; }

    void setPrice(double p) { price = p; }
    void reserveSeat(int s) { if (s >= 1 && s <= 5) seats[s] = true; }
    void freeSeat(int s) { if (s >= 1 && s <= 5) seats[s] = false; }

    std::string getSeatData() {
        std::string sData = "";
        for (int i = 1; i <= 5; i++) sData += (seats[i] ? "1" : "0");
        return sData;
    }
    void loadSeatData(std::string data) {
        for (int i = 0; i < 5; i++) seats[i + 1] = (data[i] == '1');
    }
};
#endif

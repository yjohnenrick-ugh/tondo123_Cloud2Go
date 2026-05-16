# Tondo123_Cloud2Go
# CLOUD2GO Airline Booking System

## Project Title and SDG Goal

The CLOUD2GO Airline Booking System is a console-based reservation system developed using the C++ programming language. The project supports Sustainable Development Goal (SDG) 9 – Industry, Innovation, and Infrastructure because it uses technology and programming to improve how airline reservations are managed.

Traditional booking methods are often done manually, which may cause errors such as incorrect passenger information, duplicate seat reservations, and difficulty managing records. Because of these problems, the group created a system that can automate the booking process and organize reservation data more efficiently.

The project also helped the developers apply programming concepts such as:
- Object-Oriented Programming (OOP)
- File Handling
- Vectors
- Structures
- Arrays
- Input Validation

These concepts were used to create a more organized and user-friendly reservation system.

---

# Project Description

The CLOUD2GO Airline Booking System allows users to:
- Search flights based on budget
- Book available seats
- Update passenger information
- Change reserved seats
- Cancel bookings
- View transaction history
- Save reservation records using text files

The program is divided into multiple files to make the code easier to manage and understand.

---

# File Structure

```bash
CODE/
├── Airline_BookingManager.cpp
├── AirlineBookingManager.h
├── Flight.h
├── main.cpp
└── database.txt
```

| File | Purpose |
|------|---------|
| `main.cpp` | Contains the main menu and user interaction |
| `Flight.h` | Stores flight details and seat management |
| `AirlineBookingManager.h` | Contains class declarations and structures |
| `Airline_BookingManager.cpp` | Contains booking functions and file handling |
| `database.txt` | Stores saved booking records |

---

# Installation and Usage Requirements

## Requirements
- C++ Compiler
- Code::Blocks or Visual Studio
- Windows Operating System

## How to Run

```bash
g++ main.cpp Airline_BookingManager.cpp -o airline
./airline
```

---

# OOP Concepts Applied

## 1. Class and Object

The project uses classes and objects to organize the airline booking system.

### Classes Used

| Class | Purpose |
|------|---------|
| `Flight` | Stores flight information and seat availability |
| `AirlineBookingManager` | Handles booking operations and transactions |

Example:

```cpp
AirlineBookingManager manager;
```

The object `manager` controls the booking system functions.

---

## 2. Encapsulation

Encapsulation is applied by hiding important data inside private class members.

Example from `Flight.h`:

```cpp
private:
    int flightNumber;
    string destination;
    double price;
    bool seats[6];
```

The data cannot be directly accessed outside the class.

Instead, getter functions are used:

```cpp
int getFlightNumber()
string getDestination()
double getPrice()
```

Seat management is also controlled through functions:

```cpp
reserveSeat(int s)
freeSeat(int s)
```

These functions make sure only valid seats are modified.

---

## 3. Abstraction

The system hides complicated processes inside functions.

Example:

```cpp
manager.processBooking();
```

When this function is called, the system automatically:
- Gets passenger information
- Displays available seats
- Checks seat availability
- Saves reservation data
- Updates transaction history

---

## 4. Modularity

The system is separated into different files.

This makes the project:
- Easier to read
- Easier to debug
- Easier to maintain

Each file has its own responsibility in the system.

---

# Data Structures Used

## 1. Vector

Vectors are used to store dynamic data.

Example:

```cpp
vector<Flight> flights;
```

Other vectors used:

```cpp
vector<BookingRecord> history;
vector<Transaction> transactions;
```

### Why Vector Was Used
- Dynamic size
- Easy insertion of data
- Easier management of records

---

## 2. Structures (Struct)

Structures are used to group related information together.

### BookingRecord Structure

```cpp
struct BookingRecord {
    string pName;
    int fID;
    int sNum;
};
```

### Transaction Structure

```cpp
struct Transaction {
    string passengerName;
    string flightDetails;
    double price;
    int seatNumber;
};
```

---

## 3. Array

Arrays are used for seat reservation management.

Example:

```cpp
bool seats[6];
```

### Seat Status

| Value | Meaning |
|------|---------|
| `true` | Reserved |
| `false` | Available |

Functions used:

```cpp
isSeatTaken(int s)
reserveSeat(int s)
freeSeat(int s)
```

---

# System Flow

## Step 1 – Program Initialization

The program starts by creating the booking manager object.

```cpp
AirlineBookingManager manager;
```

The constructor automatically calls:

```cpp
loadData();
```

---

## Step 2 – Load Flight Data

If `database.txt` does not exist, the program creates default flight records.

Example:

```cpp
flights.push_back(Flight(101, "Kyoto, Japan", 5000));
```

If the database already exists, saved seat information is loaded.

---

## Step 3 – Display Main Menu

The system displays the following menu:

```text
[1] Book Flight (Search)
[2] View Transaction History
[3] Update Passenger/Seat
[4] Cancel Booking (Delete)
[5] Exit
```

---

## Step 4 – Search Flights by Budget

Function used:

```cpp
searchByBudget();
```

The system checks flights using:

```cpp
if (flights[i].getPrice() <= budget)
```

Flights within the user's budget are displayed.

---

## Step 5 – Booking Process

Function used:

```cpp
processBooking();
```

The system:
- Validates flight number
- Gets passenger name
- Displays available seats
- Checks if the seat is already taken
- Confirms booking
- Saves records into the database

Available seats display as:

```text
[1] [2] [3] [4] [5]
```

Reserved seats display as:

```text
[X]
```

Successful reservations are stored using:

```cpp
history.push_back()
transactions.push_back()
```

The data is then saved using:

```cpp
saveData();
```

---

## Step 6 – Transaction History

Function used:

```cpp
viewHistory();
```

The system displays:
- Passenger name
- Flight destination
- Seat number
- Total payment

Example:

```text
Passenger: James
Flight   : Kyoto, Japan
Seat #   : 3
Total    : PHP 5000
```

---

## Step 7 – Cancel Booking

Function used:

```cpp
cancelBooking();
```

The system first asks for the admin password:

```cpp
if (pass != "1234")
```

If the password is correct:
- The selected seat becomes available again
- The booking is removed

---

## Step 8 – Update Passenger Information

Function used:

```cpp
updatePassengerInfo();
```

The system searches the booking history:

```cpp
if (history[i].pName == target)
```

Then updates the passenger name.

---

# Input Validation

The system uses input validation functions:

```cpp
getValidatedInt()
getValidatedDouble()
```

These functions prevent invalid inputs such as letters being entered instead of numbers.

Example:

```text
Invalid. Enter a number.
```

---

# Features

- Flight Search by Budget
- Seat Reservation
- Booking Cancellation
- Passenger Information Update
- Seat Update
- Transaction History
- File Data Storage
- Input Validation

---

# Contributor/Members:

John Enrick Yumul

Jonhval Collado

Mark Christian Valenzuela

Rouel James Caldoza

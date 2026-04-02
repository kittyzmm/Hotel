#include <iostream>
using namespace std;

class Room {
private:
    int number;
    string type;
    bool booking;
public:
    Room() { number = 0; type = ""; booking = false; }
    Room(int n, string t) { number = n; type = t; booking = false; }

    int getNumber() { return number; }
    string getType() { return type; }
    bool getBooking() { return booking; }

    void book() { booking = true; }
    void cancel() { booking = false; }
};

class Booking {
private:
    int roomNum;
    string customerName;
public:
    Booking() { roomNum = 0; customerName = ""; }
    Booking(int r, string c) { roomNum = r; customerName = c; }

    int getRoomNumber() { return roomNum; }
    string getCustomerName() { return customerName; }
};

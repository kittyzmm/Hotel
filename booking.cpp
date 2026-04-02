#include <iostream>
using namespace std;

const int MaxRooms = 10;
const int MaxBookings = 10;

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

class Hotel {
private:
    Room rooms[MaxRooms];
    Booking bookings[MaxBookings];
    int roomCount = 0;
    int bookingCount = 0;
 
public:
    void addRoom(int number, string type) {
        if (roomCount < MaxRooms) {
            rooms[roomCount] = Room(number, type);
            roomCount++;
        }
    }
 
    void showAvailableRooms() {
        cout << "\nСвободные комнаты: " << endl;
        for (int i = 0; i < roomCount; i++) {
            if (!rooms[i].getBooking()) {
                cout << "Комната: " << rooms[i].getNumber()
                    << " Тип: " << rooms[i].getType() << endl;
            }
        }
    }
 
    bool bookRoom(string name, int roomNum) {
        for (int i = 0; i < roomCount; i++) {
            if (rooms[i].getNumber() == roomNum) {
                if (!rooms[i].getBooking()) {
                    rooms[i].book();
                    bookings[bookingCount] = Booking(roomNum, name);
                    bookingCount++;
                    return true;
                }
                else {
                    return false;
                }
            }
        }
        return false;
    }
 
    bool cancelBooking(int roomNum) {
        for (int i = 0; i < bookingCount; i++) {
            if (bookings[i].getRoomNumber() == roomNum) {
                for (int j = i; j < bookingCount - 1; j++) {
                    bookings[j] = bookings[j + 1];
                }
                bookingCount--;
                for (int j = 0; j < roomCount; j++) {
                    if (rooms[j].getNumber() == roomNum) {
                        rooms[j].cancel();
                    }
                }
                return true;
            }
        }
        return false;
    }
};

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

int main() {
    setlocale(LC_ALL, "");
    Hotel hotel;
    hotel.addRoom(101, "STD");
    hotel.addRoom(102, "Superior");
    hotel.addRoom(103, "Deluxe");
    hotel.addRoom(104, "Deluxe");
    hotel.addRoom(105, "Suite");

    int choice;
    while (true) {
        cout << "\n=== Booking ===" << endl;
        cout << "1. Показать свободные комнаты" << endl;
        cout << "2. Забронировать комнату" << endl;
        cout << "3. Отменить бронирование" << endl;
        cout << "4. Выход" << endl;
        cout << "Выбор: ";
        cin >> choice;

        if (choice == 1) {
            hotel.showAvailableRooms();
        }
        else if (choice == 2) {
            string name;
            int room;
            cout << "\nУкажите своё имя: ";
            cin >> name;
            cout << "Укажите желаемый номер комнаты: ";
            cin >> room;

            if (hotel.bookRoom(name, room)) {
                cout << "Комната " << room << " успешно забронирована для " << name << endl;
            }
            else {
                cout << "Комната " << room << " занята или не существует!" << endl;
            }
        }
        else if (choice == 3) {
            int room;
            cout << "\nУкажите номер для отмены бронирования: ";
            cin >> room;
            if (hotel.cancelBooking(room)) {
                cout << "Бронирование комнаты " << room << " отменено!" << endl;
            }
            else {
                cout << "Бронирование комнаты " << room << " не найдено!" << endl;
            }
        }
        else if (choice == 4) {
            break;
        }
        else {
            cout << "Неверный ввод" << endl;
        }
    }
}

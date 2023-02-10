#include <iostream>
#include <string.h>
#include <conio.h>
#include<stdlib.h>
#define max 100
using namespace std;

// Class Customer
class Customer
{
public:
char name[100];
char address[100];
char phone[12];
char from_date[20];
char to_date[20];
float payment_advance;
int booking_id;
};

class Room
{
public:
char type;
char stype;
char ac;
int roomNumber;
int rent;
int status;

Customer cust;

Room addRoom(int);
void searchRoom(int);
void deleteRoom(int);
void displayRoom(Room);
};

// Global Declarations
Room rooms[max];
int count = 0;

Room Room::addRoom(int rno)
{
Room room;
room.roomNumber = rno;
cout << "\nType AC/Non-AC (A/N) : ";
cin >> room.ac;
cout << "\nType Comfort (S/N) : ";
cin >> room.type;
cout << "\nType Size (B/S) : ";
cin >> room.stype;
cout << "\nDaily Rent : ";
cin >> room.rent;
room.status = 0;

cout << "\n Room Added Successfully!";
getch();
return room;
}

void Room::searchRoom(int rno)
{
int i, found = 0;
for (i = 0; i < count; i++)
{
if (rooms[i].roomNumber == rno)
{
found = 1;
break;
}
}
if (found == 1)
{
cout << "Room Details\n";
if (rooms[i].status == 1)
{
cout << "\nRoom is Reserved";
}
else
{
cout << "\nRoom is available";
}
displayRoom(rooms[i]);
getch();
}
else
{
cout << "\nRoom not found";
getch();
}
}

void Room::displayRoom(Room tempRoom)
{
cout << "\nRoom Number: \t" << tempRoom.roomNumber;
cout << "\nType AC/Non-AC (A/N) " << tempRoom.ac;
cout << "\nType Comfort (S/N) " << tempRoom.type;
cout << "\nType Size (B/S) " << tempRoom.stype;
cout << "\nRent: " << tempRoom.rent;
}

// hotel management class
class HotelMgnt : public Room
{
public:
void checkIn();
void getAvailRoom();
void searchCustomer(char *);
void checkOut(int);
void guestSummaryReport();
void displayRoom(Room);
};
void HotelMgnt::guestSummaryReport()
{
int occupiedRooms = 0;
int totalRevenue = 0;
for (int i = 0; i < count; i++)
{
if (rooms[i].status == 1)
{
occupiedRooms++;
totalRevenue += rooms[i].rent;
}
}
cout << "\nOccupied Rooms: " << occupiedRooms;
cout << "\nTotal Revenue: " << totalRevenue;
getch();
}
void HotelMgnt::checkIn()
{
Room tempRoom;
int rno, found = 0;
cout << "\nEnter the Room Number : ";
cin >> rno;

for (int i = 0; i < count; i++)
{
if (rooms[i].roomNumber == rno)
{
found = 1;
if (rooms[i].status == 1)
{
cout << "\nRoom is already reserved";
getch();
return;
}
else
{
cout << "\nEnter Customer Details\n";
cout << "\nEnter Name : ";
cin >> cust.name;
cout << "\nEnter Address : ";
cin >> cust.address;
cout << "\nEnter Phone : ";
cin >> cust.phone;
cout << "\nEnter Payment Advance : ";
cin >> cust.payment_advance;
cout << "\nEnter From Date : ";
cin >> cust.from_date;
cout << "\nEnter To Date : ";
cin >> cust.to_date;

rooms[i].status = 1;
cust.booking_id = ++count;
cout << "\nRoom Booking done!!";
getch();
break;
}
}
}
if (found == 0)
{
cout << "\n Room not found";
getch();
}
}

void HotelMgnt::getAvailRoom()
{
int i, found = 0;
cout << "\nAvailable Rooms\n";
for (i = 0; i < count; i++)
{
if (rooms[i].status == 0)
{
found = 1;
cout << "\n";
displayRoom(rooms[i]);
}
}
if (found == 0)
{
cout << "\nNo Rooms Available";
}
getch();
}

void HotelMgnt::searchCustomer(char *name)
{
int i, found = 0;
for (i = 0; i < count; i++)
{
if (rooms[i].status == 1)
{
if (strcmp(rooms[i].cust.name, name) == 0)
{
found = 1;
cout << "\n Customer Details";
cout << "\nName: " << rooms[i].cust.name;
cout << "\nAddress: " << rooms[i].cust.address;
cout << "\nPhone: " << rooms[i].cust.phone;
cout << "\nPayment Advance: " << rooms[i].cust.payment_advance;
cout << "\nFrom Date: " << rooms[i].cust.from_date;
cout << "\nTo Date: " << rooms[i].cust.to_date;
break;
}
}
}
if (found == 0)
{
cout << "\nCustomer not found";
}
getch();
}

void HotelMgnt::checkOut(int rno)
{
int i, found = 0;
for (i = 0; i < count; i++)
{
if (rooms[i].roomNumber == rno)
{
found = 1;
if (rooms[i].status == 0)
{
cout << "\n Room is not booked";
getch();
return;
}
else
{
cout << "\n Customer Details";
cout << "\nName: " << rooms[i].cust.name;
cout << "\nAddress: " << rooms[i].cust.address;
cout << "\nPhone: " << rooms[i].cust.phone;
cout << "\nPayment Advance: " << rooms[i].cust.payment_advance;
cout << "\nFrom Date: " << rooms[i].cust.from_date;
cout << "\nTo Date: " << rooms[i].cust.to_date;

cout << "\nEnter Payment: ";
int payment;
cin >> payment;
int due = rooms[i].cust.payment_advance - payment;
if (due > 0)
{
cout << "\nDue Amount : " << due;
}
else
{
cout << "\nThanks for Payment!!";
}

rooms[i].status = 0;
cout << "\nChecked Out!!";
break;
}
}
}
if (found == 0)
{
cout << "\n Room not found";
getch();
}
}

void HotelMgnt::displayRoom(Room room)
{
cout << "Room Number: " << room.roomNumber;
cout << "\nRoom Type: " << room.type;
cout << "\nRoom Rent: " << room.rent;
}
int main()
{
int ch, rno;
char name[100];
HotelMgnt hm;
while (1)
{
system("cls");
cout << "\n\t\t\tHotel Management\n\n";
cout << "\n\n\t\t\t1. Add Room";
cout << "\n\n\t\t\t2. Search Room";
cout << "\n\n\t\t\t3. Check In";
cout << "\n\n\t\t\t4. Check Out";
cout << "\n\n\t\t\t5. Available Rooms";
cout << "\n\n\t\t\t6. Search Customer";
cout << "\n\n\t\t\t7. Guest Summary Report";
cout << "\n\n\t\t\t8. Exit";
cout << "\n\n\t\t\tEnter your choice : ";
cin >> ch;
switch (ch)
{
case 1:
rooms[count++] = hm.addRoom(count +  100);
break;
case 2:
cout << "\nEnter Room Number : ";
cin >> rno;
hm.searchRoom(rno);
break;
case 3:
hm.checkIn();
break;
case 4:
cout << "\nEnter Room Number : ";
cin >> rno;
hm.checkOut(rno);
break;
case 5:
hm.getAvailRoom();
break;
case 6:
cout << "\nEnter Customer Name : ";
cin >> name;
hm.searchCustomer(name);
break;
case 7:
hm.guestSummaryReport();
break;
case 8:
exit(0);
break;
}
}
return 0;
}

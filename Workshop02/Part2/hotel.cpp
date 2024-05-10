#define _CRT_SECURE_NO_WARNINGS
#include <cstring> // contains the strcpy and strcmp function
#include <iostream>
#include "hotel.h"
#include "file.h"

namespace seneca
{
	void setGuest(Guest& theGuest, const char* fName, const char* lName)
	{
		strcpy(theGuest.m_firstName, fName);
		strcpy(theGuest.m_lastName, lName);
	}

	bool loadData(const char fileName[], Hotel &theHotel)
	{
		if (theHotel.m_rooms != NULL && theHotel.m_cntRooms != 0)
		{
			deallocate(theHotel);
		}

		if (!seneca::openFile(fileName))
		{
			return false;
		}
		else
		{
			theHotel.m_cntRooms = getRecordsCount();
			theHotel.m_rooms = new Room[theHotel.m_cntRooms];
			for (int i = 0; i < theHotel.m_cntRooms; i++)
			{
				loadData(theHotel.m_rooms[i]); // overloaded function utilized to add each individual Room object to array of type Room
			}
			seneca::closeFile();
			return true;
		}
	}

	bool loadData(Room &theRoom)
	{
		bool ok = false;
		if ((theRoom.m_roomNumber = seneca::read()) != NULL && seneca::read(theRoom.m_maxCntGuests, '\n'))
		{
			ok = true; // true if the data is read successfully
		}
		return ok;
	}

	void displayRoomByType(const char label[], const Hotel& theHotel, char roomType)
	{
		std::cout << label << std::endl;
		int counter = 1;
		for (int i = 0; i < theHotel.m_cntRooms; i++)
		{
			if (theHotel.m_rooms[i].m_roomNumber[0] == roomType)
			{
				std::cout << counter << ". ";
				display(theHotel.m_rooms[i]);
				std::cout << std::endl;
				counter++;
			}
		}
	}

	void display(const Hotel& theHotel)
	{
		displayRoomByType("Standard Rooms:", theHotel, 'A');
		displayRoomByType("Family Rooms:", theHotel, 'B');
		displayRoomByType("Suites:", theHotel, 'C');
	}

	void display(const Room& theRoom)
	{
		std::cout << theRoom.m_roomNumber << " (" << theRoom.m_cntGuests << "/" << theRoom.m_maxCntGuests << ")";
		
		if (theRoom.m_cntGuests > 0)
		{
			std::cout << ": ";
			for (int i = 0; i < theRoom.m_cntGuests; i++)
			{
				std::cout << theRoom.m_guests[i].m_firstName << " " << theRoom.m_guests[i].m_lastName;
				if (i < theRoom.m_cntGuests - 1)
				{
					std::cout << ", ";
				}
			}
		}
	}

	Room* findRoom(const Hotel& theHotel, const char* roomNumber)
	{
		Room* room = nullptr;
		for (int i = 0; i < theHotel.m_cntRooms; i++)
		{
			if (strcmp(theHotel.m_rooms[i].m_roomNumber, roomNumber) == 0) // strcmp is a function in string library; will return 0 if the two char* strings match
			{
				room = &theHotel.m_rooms[i];
			}
		}
		return room;
	}

	void addGuest(Room& theRoom, const Guest& theGuest)
	{
		if (theRoom.m_cntGuests < theRoom.m_maxCntGuests)
		{
			int newSize = theRoom.m_cntGuests + 1; // updated size of the array
			Guest* tempGuest = new Guest[newSize];
			for (int i = 0; i < theRoom.m_cntGuests; i++)
			{
				tempGuest[i] = theRoom.m_guests[i];
			}
			tempGuest[theRoom.m_cntGuests] = theGuest; // no need to deallocate tempGuest array as it is a local array that will go out of scope at the end of function
			delete[] theRoom.m_guests;
			theRoom.m_guests = tempGuest;
			theRoom.m_cntGuests = newSize;
		}
	}

	void deallocate(Hotel& theHotel)
	{
		for (int i = 0; i < theHotel.m_cntRooms; i++)
		{
			//deallocate array of Guest
			delete[] theHotel.m_rooms[i].m_guests;
			theHotel.m_rooms[i].m_guests = nullptr;

			//deallocate room number data member of Room
			delete[] theHotel.m_rooms[i].m_roomNumber;
			theHotel.m_rooms[i].m_roomNumber = nullptr;
		}

		//deallocate the array of Room
		delete[] theHotel.m_rooms;
		theHotel.m_rooms = nullptr;
	}
	
}



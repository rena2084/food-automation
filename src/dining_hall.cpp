#include "../include/dining_hall.hpp"
#include <iostream>
#define EXCEPTION_LOCATION_X 0
#define EXCEPTION_LOCATION_Y 20
using namespace std;

void gotoxy(int, int);
int inputInt();
string inputString();
bool checkingDiningHall(vector<DiningHall>, unsigned int);

//---------------------------------- DiningHall Class -----------------------------------

DiningHall::DiningHall(unsigned int hallId, string name, string address, unsigned int capacity)
{
    try
    {
        setHallId(hallId);
        setName(name);
        setAddress(address);
        setCapacity(capacity);
    }
    catch(exception &e)
    {
        gotoxy(EXCEPTION_LOCATION_X,EXCEPTION_LOCATION_Y);
        cerr << e.what();
    }
}

//-------------------- setters --------------------
void DiningHall::setHallId(unsigned int hallId)
{
    //4

    if(hallId <= 9 && hallId >= 1)
    {
        _hallId = hallId;
    }
    else
    {
        throw invalid_argument("\n\nError: The entered ID is incorrect!\n\n");
    }
}
void DiningHall::setName(string name)
{
    if(name.length() >= 5 && name.length() <= 40)
    {
        int j = 0;
        for(int i = 0; i < name.length(); ++i)
        {
            if(!(name[i] >= 65 && name[i] <= 90 || name[i] >= 97 && name[i] <= 122 || name[i] == 32 || name[i] == 40 || name[i] == 41 || name[i] == 44 || name[i] == 45 || name[i] == 46))
            {
                j++;
            }
        }
        if(j == 0)
        {
            _name = name;
        }
        else
        {
            throw invalid_argument("\n\nError: The dining hall name can contain numbers, uppercase or lowercase letters, or allowed characters (. - ( ) , space)\n\n");
        }
    }
    else
    {
        throw length_error("\n\nError: length of the Dining hall name is not allowed!\n\n");
    }
}
void DiningHall::setAddress(string address)
{
    if(address.length() >= 3 && address.length() <= 60)
    {
        int j = 0;
        for(int i = 0; i < address.length(); ++i)
        {
            if(!(address[i] >= 65 && address[i] <= 90 || address[i] >= 97 && address[i] <= 122 || address[i] >= 48 && address[i] <= 57 || address[i] == 32 || address[i] == 40 || address[i] == 41 || address[i] == 44 || address[i] == 45 || address[i] == 46))
            {
                j++;
            }
        }
        if(j == 0)
        {
            _address = address;
        }
        else
        {
            throw invalid_argument("\n\nError: The dining hall address can contain numbers, uppercase or lowercase letters, or allowed characters (. - ( ) , space)\n\n");
        }
    }
    else
    {
        throw length_error("\n\nError: Dining hall address length is not allowed!\n\n");
    }
}
void DiningHall::setCapacity(unsigned int capacity)
{
    _capacity = capacity;
}

//-------------------- getters --------------------
unsigned int DiningHall::getHallId()const
{
    return _hallId;
}
string DiningHall::getName()const
{
    return _name;
}
string DiningHall::getAddress()const
{
    return _address;
}
unsigned int DiningHall::getCapacity()const
{
    return _capacity;
}

//-------------------------- print ----------------------------

void DiningHall::print()const
{
    cout << "Hall ID: " << getHallId() << endl;
    cout << "Name: " << getName() << endl;
    cout << "Address: " << getAddress() << endl;
    cout << "Capacity: " << getCapacity() << endl;
}

//---------------------- newDiningHall ------------------------

DiningHall newDiningHall()
{
    DiningHall tempDH;
    int counter = 1;
    while(true)
    {
        try
        {
            switch (counter) {
                case 1:
                    cout << "Hall ID: ";
                    tempDH.setHallId(inputInt());
                    counter++;
                case 2:
                    cout << "Name: ";
                    tempDH.setName(inputString());
                    counter++;
                case 3:
                    cout << "Address: ";
                    tempDH.setAddress(inputString());
                    counter++;
                case 4:
                    cout << "Capacity: ";
                    tempDH.setCapacity(inputInt());
                    counter++;
            }
            if(counter == 5)
            {
                return tempDH;
            }
        }
        catch(exception &e)
        {
            gotoxy(EXCEPTION_LOCATION_X,EXCEPTION_LOCATION_Y);
            cerr << e.what();
        }
    }
}

#include "../include/dining_hall.hpp"
#include <iostream>
using namespace std;

int inputInt();
string inputString();
bool checkingDiningHall(vector<DiningHall>, unsigned int);

//---------------------------------- DiningHall Class -----------------------------------

DiningHall::DiningHall(unsigned int hallId, vector<DiningHall> DHvector, string name, string address, unsigned int capacity)
{
    try
    {
        setHallId(hallId, DHvector);
        setName(name);
        setAddress(address);
        setCapacity(capacity);
    }
    catch(exception &e)
    {
        cerr << e.what();
    }
}

//-------------------- setters --------------------
void DiningHall::setHallId(unsigned int hallId, vector<DiningHall> DHvector)
{
    //120004
    //first digit -> University ID
    //second digit -> Dining hall gender
    //last digit -> Dining hall ID

    string temp = to_string(hallId);
    if(temp.length() == 6)
    {
        if(temp[1] == '1' || temp[1] == '2')
        {
            if(temp[2] == '0' && temp[3] == '0' && temp[4] == '0')
            {
                if(!(checkingDiningHall(DHvector, hallId)))
                {
                    _hallId = hallId;
                }
                else
                {
                    throw runtime_error("\n\nError: The entered ID is duplicate!\n\n");
                }
            }
            else
            {
                throw invalid_argument("\n\nError: The entered ID is incorrect!\n\n");
            }
        }
        else
        {
            throw invalid_argument("\n\nError: The entered ID is incorrect!\n\n");
        }
    }
    else
    {
        throw domain_error("\n\nError: The number of digits in the ID is incorrect!\n\n");
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

//---------------------- newDiningHall ------------------------

DiningHall newDiningHall(vector<DiningHall> DHvector)
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
                    tempDH.setHallId(inputInt(), DHvector);
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
            cerr << e.what();
        }
    }
}

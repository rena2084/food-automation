#include "../include/dining_hall.hpp"
using namespace std;


//---------------------------------- DiningHall Class -----------------------------------

DiningHall::DiningHall(unsigned int hall_id, string name, string address, int capacity)
{
    setHallId(hall_id);
    setName(name);
    setAddress(address);
    setCapacity(capacity);
}

//----- setters -----
void DiningHall::setHallId(unsigned int hall_id)
{

}
void DiningHall::setName(string name)
{

}
void DiningHall::setAddress(string address)
{

}
void DiningHall::setCapacity(int capacity)
{

}

//----- getters -----
int DiningHall::getHallId()const
{
    return _hall_id;
}
string DiningHall::getName()const
{
    return _name;
}
string DiningHall::getAddress()const
{
    return _address;
}
int DiningHall::getCapacity()const
{
    return _capacity;
}

#include "../include/dining_hall.hpp"
using namespace std;


//---------------------------------- DiningHall Class -----------------------------------

DiningHall::DiningHall(unsigned int hallId, string name, string address, int capacity)
{
    setHallId(hallId);
    setName(name);
    setAddress(address);
    setCapacity(capacity);
}

//-------------------- setters --------------------
void DiningHall::setHallId(unsigned int hallId)
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

//-------------------- getters --------------------
int DiningHall::getHallId()const
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
int DiningHall::getCapacity()const
{
    return _capacity;
}

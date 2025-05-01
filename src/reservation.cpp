#include "../include/reservation.hpp"
#include <iostream>
using namespace std;

int inputInt();
ReservationStatus inputReservationStatus();

//---------------------------------- Reservation Class ----------------------------------

Reservation::Reservation(unsigned int reservationId, ReservationStatus status, time_t createdAt)
{
    try
    {
        setReservationId(reservationId);
        setStudent();
        setDiningHall();
        setMeal();
        setStatus(status);
        setCreatedAt(createdAt);
    }
    catch(exception &e)
    {
        cerr << e.what();
    }
}

//-------------------- setters --------------------
void Reservation::setReservationId(unsigned int reservationId)
{
    //100021
    //first digit -> Dining hall ID
    //last two digit -> Food ID
    string temp = to_string(reservationId);
    if(temp.length() == 6)
    {
        if(temp[1] == '0' && temp[2] == '0' && temp[3] == '0')
        {
            _reservationId = reservationId;
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
void Reservation::setStudent()
{

}
void Reservation::setDiningHall()
{

}
void Reservation::setMeal()
{

}
void Reservation::setStatus(ReservationStatus status)
{
    _status = status;
}
void Reservation::setCreatedAt(time_t createdAt)
{
    _createdAt = createdAt;
}

//-------------------- getters --------------------
int Reservation::getReservationId()const
{
    return _reservationId;
}
Student Reservation::getStudent()const
{
    return *_student;
}
DiningHall Reservation::getDHall()const
{
    return _diningHall;
}
Meal Reservation::getMeal()const
{
    return _meal;
}
ReservationStatus Reservation::getStatus()const
{
    return _status;
}
time_t Reservation::getCreatedAt()const
{
    return _createdAt;
}

//---------------------- newReservation -----------------------

Reservation newReservation()
{
    Reservation tempR;
    int counter = 1;
    while(true)
    {
        try
        {
            switch (counter) {
                case 1:
                    cout << "Reservation ID: ";
                    tempR.setReservationId(inputInt());
                    counter++;
                case 2:
                    cout << "Reservation status: ";
                    tempR.setStatus(inputReservationStatus());
                    counter++;
                case 3:
                    cout << "Created at: ";
                    tempR.setReservationId(inputInt());
                    counter++;
            }
            if(counter == 4)
            {
                return tempR;
            }
        }
        catch(exception &e)
        {
            cerr << e.what();
        }
    }
}

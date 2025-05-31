#include "../include/reservation.hpp"
#include "../include/dining_hall.hpp"
#include "../include/meal.hpp"
#include <iostream>
#include <iomanip>
#include <sstream>
#include <vector>
#define EXCEPTION_LOCATION_X 0
#define EXCEPTION_LOCATION_Y 20
using namespace std;

void gotoxy(int, int);
int inputInt();
string time_tToString(const time_t &);
string toString(ReservationStatus);
ReservationStatus inputReservationStatus();
DiningHall checkingAndGetDiningHall(vector<DiningHall>);
Meal checkingAndGetMeal(vector<Meal>);

//---------------------------------- Reservation Class ----------------------------------

Reservation::Reservation(DiningHall diningHall, Meal meal, unsigned int reservationId, ReservationStatus status, time_t createdAt)
{
    try
    {
        setReservationId(reservationId);
        setDiningHall(diningHall);
        setMeal(meal);
        setStatus(status);
        _createdAt = time(0);
    }
    catch(exception &e)
    {
        gotoxy(EXCEPTION_LOCATION_X,EXCEPTION_LOCATION_Y);
        cerr << e.what();
    }
}

//-------------------- setters --------------------
void Reservation::setReservationId(unsigned int reservationId)
{
    //112
    //first two digit -> Dining hall ID
    //last digit -> Meal ID
    //string temp = to_string(reservationId);
    if(reservationId <= 999 && reservationId >= 111)
    {
        _reservationId = reservationId;
    }
    else
    {
        throw invalid_argument("\n\nError: The entered ID is incorrect!\n\n");
    }
}
void Reservation::setDiningHall(DiningHall diningHall)
{
    *_diningHall = diningHall;
}
void Reservation::setMeal(Meal meal)
{
    *_meal = meal;
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
DiningHall Reservation::getDiningHall()const
{
    return *_diningHall;
}
Meal Reservation::getMeal()const
{
    return *_meal;
}
ReservationStatus Reservation::getStatus()const
{
    return _status;
}
time_t &Reservation::getCreatedAt()
{
    return _createdAt;
}

string Reservation::getCreatedAtFormatted()const
{
    return time_tToString(_createdAt);
}

//---------------------- time_tToString -----------------------

string Reservation::time_tToString(const time_t &time)const
{
    tm *temp = localtime(&time);
    stringstream ss;
    ss << put_time(temp, "%d/%m/%Y %I:%M %p");
    return ss.str();
}

//--------------------------- print ---------------------------

void Reservation::print()const
{
    cout << "Reservation ID: " << getReservationId() << endl;
    cout << "Status: " << toString(getStatus()) << endl;
    cout << "Created at: " << getCreatedAtFormatted() << endl;
}

//---------------------- newReservation -----------------------

//Reservation newReservation()
//{
//    DiningHall diningHall;
//    Meal meal;
//    Reservation tempR(diningHall, meal);
//    int counter = 1;
//    while(true)
//    {
//        try
//        {
//            switch (counter) {
//                case 1:
//                    cout << "Reservation ID: ";
//                    tempR.setReservationId(inputInt());
//                    counter++;
//                case 2:
//                    cout << "Reservation status: ";
//                    tempR.setStatus(inputReservationStatus());
//                    counter++;
//                case 3:
//                    cout << "Dining hall ID: ";
//                    tempR.setDiningHall(checkingAndGetDiningHall(DHvector));
//                    counter++;
//                case 4:
//                    cout << "Meal ID: ";
//                    tempR.setMeal(checkingAndGetMeal(Mvector));
//                    counter++;
//            }
//            if(counter == 5)
//            {
//                return tempR;
//            }
//        }
//        catch(exception &e)
//        {
//            gotoxy(EXCEPTION_LOCATION_X,EXCEPTION_LOCATION_Y);
//            cerr << e.what();
//        }
//    }
//}

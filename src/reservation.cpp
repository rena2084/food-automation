#include "../include/reservation.hpp"
using namespace std;


//---------------------------------- Reservation Class ----------------------------------

Reservation::Reservation(unsigned int reservationId, ReservationStatus status, time_t createdAt)
{
    setReservationId(reservationId);
    setStudent();
    setDiningHall();
    setMeal();
    setStatus(status);
    setCreatedAt(createdAt);
}

//-------------------- setters --------------------
void Reservation::setReservationId(unsigned int reservationId)
{

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

}
void Reservation::setCreatedAt(time_t createdAt)
{

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

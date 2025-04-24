#include "../include/reservation.hpp"
using namespace std;


//---------------------------------- Reservation Class ----------------------------------

Reservation::Reservation(unsigned int reservation_id, ReservationStatus status, time_t created_at)
{
    setReservationId(reservation_id);
    setStudent();
    setDiningHall();
    setMeal();
    setStatus(status);
    setCreatedAt(created_at);
}

//----- setters -----
void Reservation::setReservationId(unsigned int reservation_id)
{

}
void Reservation::setStudent(Student student)
{

}
void Reservation::setDHall(DiningHall dining_hall)
{

}
void Reservation::setMeal(Meal meal)
{

}
void Reservation::setStatus(ReservationStatus status)
{

}
void Reservation::setCreatedAt(time_t created_at)
{

}

//----- getters -----
int Reservation::getReservationId()const
{
    return _reservation_id;
}
Student Reservation::getStudent()const
{
    return _student;
}
DiningHall Reservation::getDHall()const
{
    return *_dining_hall;
}
Meal Reservation::getMeal()const
{
    return *_meal;
}
ReservationStatus Reservation::getStatus()const
{
    return _status;
}
time_t Reservation::getCreatedAt()const
{
    return _created_at;
}

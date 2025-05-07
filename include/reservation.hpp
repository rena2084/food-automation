#ifndef RESERVATION_HPP
#define RESERVATION_HPP
#include "meal.hpp"
#include "dining_hall.hpp"
#include "student.hpp"
#include "reservation_status.hpp"
#include <string>
#include <time.h>

using namespace std;
class Student;

//---------- Reservation Class ----------
class Reservation{
private:
    unsigned int _reservationId;
    DiningHall _diningHall;
    Meal _meal;
    ReservationStatus _status;
    time_t _createdAt;
public:
    Reservation(unsigned int = 100021, ReservationStatus = ReservationStatus::SELECTED, time_t = time(nullptr));
    void print()const;
    string time_tToString(const time_t &)const;

    //----- setters -----
    void setReservationId(unsigned int);
    void setDiningHall(DiningHall);
    void setMeal(Meal);
    void setStatus(ReservationStatus);
    void setCreatedAt(time_t);

    //----- getters -----
    int getReservationId()const;
    DiningHall getDiningHall()const;
    Meal getMeal()const;
    ReservationStatus getStatus()const;
    time_t &getCreatedAt();
    string getCreatedAtFormatted()const;
};


#endif // RESERVATION_HPP

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
    Student* _student;
    DiningHall _diningHall;
    Meal _meal;
    ReservationStatus _status;
    time_t _createdAt;
public:
    Reservation(unsigned int = 100021, ReservationStatus = ReservationStatus::SELECTED, time_t = time(nullptr));
    void print()const;
    bool cancel();

    //----- setters -----
    void setReservationId(unsigned int);
    void setStudent();
    void setDiningHall();
    void setMeal();
    void setStatus(ReservationStatus);
    void setCreatedAt(time_t);

    //----- getters -----
    int getReservationId()const;
    Student getStudent()const;
    DiningHall getDHall()const;
    Meal getMeal()const;
    ReservationStatus getStatus()const;
    time_t getCreatedAt()const;
};


#endif // RESERVATION_HPP

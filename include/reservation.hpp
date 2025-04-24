#ifndef RESERVATION_H
#define RESERVATION_H
#include "meal.hpp"
#include "dining_hall.hpp"
#include "student.hpp"
#include "reservation_status.hpp"
using namespace std;
class Student;

//---------- Reservation Class ----------
class Reservation{
private:
    unsigned int _reservation_id;
    Student* _student;
    DiningHall _dining_hall;
    Meal _meal;
    ReservationStatus _status;
    time_t _created_at;
public:
    Reservation(unsigned int = 0, ReservationStatus = ReservationStatus::SELECTED, time_t = time(nullptr));
    void print()const;
    bool cancel();

    //----- setters -----
    void setReservationId(unsigned int);
    void setStudent(Student);
    void setDiningHall(DiningHall);
    void setMeal(Meal);
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

#endif // RESERVATION_H

#ifndef STUDENT_HPP
#define STUDENT_HPP
#include "meal.hpp"
#include "reservation.hpp"
#include <vector>
#include <string>
using namespace std;
class Reservation;

//------------ Student Class ------------
class Student{
private:
    unsigned int _userId;
    string _studentId;
    string _name;
    string _email;
    float _balance;
    bool _isActive;
    vector<Reservation> _reservations;
public:
    Student(unsigned int = 0, string = "0000000000", string = "Unknown", string = "Unknown@gmail.com", float = 0.0f, bool = true, vector<Reservation> reservations = {});
    void print()const;
    void reserveMeal(Meal);
    bool cancelReservation(Reservation);

    //----- setters -----
    void setUserId(unsigned int);
    void setStudentId(string);
    void setName(string);
    void setEmail(string);
    void setBalance(float);
    void setIsActive(bool);
    void setReservations(vector<Reservation>);

    //----- getters -----
    int getUserId()const;
    string getStudentId()const;
    string getName()const;
    string getEmail()const;
    float getBalance()const;
    bool getIsActive()const;
    vector<Reservation> getReservations()const;
};

#endif // STUDENT_HPP

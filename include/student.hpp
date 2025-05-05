#ifndef STUDENT_HPP
#define STUDENT_HPP
#include "user.hpp"
#include "meal.hpp"
#include "reservation.hpp"
#include <vector>
#include <string>
using namespace std;
class Reservation;

//------------ Student Class ------------
class Student : public User{
private:
    string _studentId;
    string _email;
    string _phone;
    float _balance;
    bool _isActive;
    vector<Reservation> _reservations;
public:
    Student(string = "0000000000", string = "Unknown@gmail.com", string = "00000000000", float = 0.0f, bool = true, vector<Reservation> reservations = {});
    void print()const;
    string getType();
    void reserveMeal(Meal);
    bool cancelReservation(Reservation);

    //----- setters -----
    void setStudentId(string);
    void setEmail(string);
    void setPhone(string);
    void setBalance(float);
    void setIsActive(bool);
    void setReservations(vector<Reservation>);

    //----- getters -----
    //
    string getStudentId()const;
    string getEmail()const;
    string getPhone()const;
    float getBalance()const;
    bool getIsActive()const;
    vector<Reservation> getReservations()const;
};

#endif // STUDENT_HPP

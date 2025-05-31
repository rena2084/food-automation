#ifndef STUDENT_HPP
#define STUDENT_HPP
#include "user.hpp"
#include "meal.hpp"
#include "reservation.hpp"
#include <vector>
#include <string>
#define EXCEPTION_LOCATION_X 0
#define EXCEPTION_LOCATION_Y 20
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
    vector<Reservation> _reserves;
public:
    Student(unsigned int = 00000000, string = "Unknown", string  = "Unknown", string  = "12345678" ,string = "0000000000", string = "Unknown@gmail.com", string = "00000000000", float = 0.0f, bool = true, vector<Reservation> reservations = {});
    void print()const;
    string getType();
    void reserveMeal(Reservation);
    bool cancelReservation(Reservation);
    void activate();
    void deactivate();


    //----- setters -----
    void setStudentId(string);
    void setEmail(string);
    void setPhone(string);
    void setBalance(float);
    void setIsActive(bool);
    void setReserves(vector<Reservation>);

    //----- getters -----
    //
    string getStudentId()const;
    string getEmail()const;
    string getPhone()const;
    float getBalance()const;
    bool getIsActive()const;
    vector<Reservation> getReserves()const;
};

#endif // STUDENT_HPP

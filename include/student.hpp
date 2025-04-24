#ifndef STUDENT_H
#define STUDENT_H
#include "meal.hpp"
#include "reservation.hpp"
using namespace std;

//------------ Student Class ------------
class Student{
private:
    unsigned int _user_id;
    string _student_id;
    string _name;
    string _email;
    float _balance;
    bool _is_active;
    vector<Reservation> _reservations;
public:
    Student(unsigned int = 0, string = "0000000000", string = "Unknown", string = "Unknown@gmail.com", float = 0.0f, bool = true);
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
    vector<Reservation> setReservations()const;
};

#endif // STUDENT_H

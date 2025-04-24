#include "../include/student.hpp"
using namespace std;

//------------------------------------ Student Class ------------------------------------

Student::Student(unsigned int user_id, string student_id, string name, string email, float balance, bool is_active)
{
    try
    {
        setUserId(user_id);
        setStudentId(student_id);
        setName(name);
        setEmail(email);
        setBalance(balance);
        setIsActive(is_active);
    }
    catch(invalid_argument)
    {
        cerr << "This is not a integer number!";
    }

}

//----- setters -----
void Student::setUserId(unsigned int user_id)
{

        throw invalid_argument("invalid input fo user_id");

}
void Student::setStudentId(string student_id)
{

}
void Student::setName(string name)
{

}
void Student::setEmail(string email)
{

}
void Student::setBalance(float balance)
{

}
void Student::setIsActive(bool is_active)
{

}
void Student::setReservations(vector<Reservation> reservations)
{

}
//----- getters -----
int Student::getUserId()const
{
    return _user_id;
}
string Student::getStudentId()const
{
    return _student_id;
}
string Student::getName()const
{
    return _name;
}
string Student::getEmail()const
{
    return _email;
}
float Student::getBalance()const
{
    return _balance;
}
bool Student::getIsActive()const
{
    return _is_active;
}
bool Student::getReservations()const
{
    return _reservations;
}

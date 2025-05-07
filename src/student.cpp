#include "../include/student.hpp"
#include <iostream>
#include <string.h>
using namespace std;

User newUser();
float inputFloat();
string inputString();
bool inputBool();

//------------------------------------ Student Class ------------------------------------
Student::Student(string studentId, string email, string phone, float balance, bool isActive, vector<Reservation> reservations)
{
    try
    {
        setStudentId(studentId);
        setEmail(email);
        setPhone(phone);
        setBalance(balance);
        setIsActive(isActive);
        setReserves(reservations);
    }
    catch(exception &e)
    {
        cerr << e.what();
    }
}

//-------------------- setters --------------------
void Student::setStudentId(string studentId)
{
    if(studentId.length() == 10)
    {
        int j = 0;
        for(int i = 0; i < studentId.length(); ++i)
        {
            if(!(studentId[i] >= 65 && studentId[i] <= 90 || studentId[i] >= 97 && studentId[i] <= 122 || studentId[i] >= 48 && studentId[i] <= 57))
            {
                j++;
            }
        }
        if(j == 0)
        {
            _studentId = studentId;
        }
        else
        {
            throw invalid_argument("\n\nError: Student ID must consist of only numbers or letters!\n\n");
        }
    }
    else
    {
        throw length_error("\n\nError: The number of digits entered is incorrect!\n\n");
    }
}
void Student::setEmail(string email)
{
    if(email.length() >= 10 && email.length() <= 30)
    {
        // rhsr2025@gmail.com
        if(email[email.length() - 10] == 64 && email[email.length() - 9] == 'g' &&
           email[email.length() - 8] == 'm' && email[email.length() - 7] == 'a' &&
           email[email.length() - 6] == 'i' && email[email.length() - 5] == 'l' &&
           email[email.length() - 4] == 46 && email[email.length() - 3] == 'c' &&
           email[email.length() - 2] == 'o' && email[email.length() - 1] == 'm')
        {
            int j = 0;
            for(int i = 0; i < email.length(); ++i)
            {
                if(!(email[i] >= 65 && email[i] <= 90 || email[i] >= 97 && email[i] <= 122 || email[i] >= 48 && email[i] <= 57 || email[i] == 46 || email[i] == 64))
                {
                    j++;
                }
            }
            if(j == 0)
            {
                _email = email;
            }
            else
            {
                throw invalid_argument("\n\nError: Gmail can contain numbers, uppercase or lowercase letters, or allowed characters (@ .)\n\n");
            }
        }
        else
        {
            throw invalid_argument("\n\nError: Gmail must end with '@gmail.com'\n\n");
        }
    }
    else
    {
        throw length_error("\n\nError: Gmail length is not allowed!\n\n");
    }
}
void Student::setPhone(string phone)
{
    if(phone.length() == 11)
    {
        int j;
        for(int i = 0; i < phone.length(); ++i)
        {
            if(!(phone[i] >= 48 && phone[i] <= 57))
            {
                j++;
            }
        }
        if(j == 0)
        {
            if(phone[0] == '0' && phone[1] == '9')
            {
                _phone = phone;
            }
        }
        else
        {
            throw invalid_argument("\n\nError: The phone number is invalid!\n\n");
        }

    }
    else
    {
        throw length_error("\n\nError: The phone number length is invalid!\n\n");
    }

}
void Student::setBalance(float balance)
{
    _balance = balance;
}
void Student::setIsActive(bool isActive)
{
    _isActive = isActive;
}
void Student::setReserves(vector<Reservation> reserves)
{
    _reserves = reserves;
}
//-------------------- getters --------------------
string Student::getStudentId()const
{
    return _studentId;
}
string Student::getEmail()const
{
    return _email;
}
string Student::getPhone()const
{
    return _phone;
}
float Student::getBalance()const
{
    return _balance;
}
bool Student::getIsActive()const
{
    return _isActive;
}
vector<Reservation> Student::getReserves()const
{
    return _reserves;
}

//--------------------------- print ---------------------------

void Student::print()const
{
    cout << "Student ID: " << getStudentId() << endl;
    cout << "Email: " << getEmail() << endl;
    cout << "Phone number: " << getPhone() << endl;
    cout << "Balance: " << getBalance() << endl;
    cout << "Is active: " << getIsActive() << endl;
}

//-------------------------- getType --------------------------

string Student::getType()
{
    return "student";
}

//------------------------ reserveMeal ------------------------

void Student::reserveMeal(Meal)
{

}

//--------------------- cancelReservation ---------------------

bool Student::cancelReservation(Reservation)
{

}

//------------------------- activate --------------------------

void Student::activate()
{

}

//------------------------ deactivate -------------------------

void Student::deactivate()
{

}

//------------------------ newStusent -------------------------

Student newStusent()
{
    Student tempS;
    int counter = 1;
    while(true)
    {
        try
        {
            switch (counter) {
                case 1:
                    cout << "Student ID: ";
                    tempS.setStudentId(inputString());
                    counter++;
                case 2:
                    cout << "Email address: ";
                    tempS.setEmail(inputString());
                    counter++;
                case 3:
                    cout << "Phone number: ";
                    tempS.setPhone(inputString());
                    counter++;
                case 4:
                    cout << "Balance: ";
                    tempS.setBalance(inputFloat());
                    counter++;
                case 5:
                    cout << "Is active: (true/false) or (0/1) : ";
                    tempS.setIsActive(inputBool());
                    counter++;
            }
            if(counter == 6)
            {
                return tempS;
            }
        }
        catch(exception &e)
        {
            cerr << e.what();
        }
    }
}

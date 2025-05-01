#include "../include/student.hpp"
#include <iostream>
#include <string.h>
using namespace std;

int inputInt();
float inputFloat();
string inputString();
bool inputBool();

//------------------------------------ Student Class ------------------------------------

Student::Student(unsigned int userId, string studentId, string name, string email, float balance, bool isActive, vector<Reservation> reservations)
{
    try
    {
        setUserId(userId);
        setStudentId(studentId);
        setName(name);
        setEmail(email);
        setBalance(balance);
        setIsActive(isActive);
        setReservations(reservations);
    }
    catch(exception &e)
    {
        cerr << e.what();
    }
}

//-------------------- setters --------------------
void Student::setUserId(unsigned int userId)
{
    _userId = userId;
}
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
void Student::setName(string name)
{
    if(name.length() >= 3 && name.length() <= 30)
    {
        int j = 0;
        for(int i = 0; i < name.length(); ++i)
        {
            if(!(name[i] >= 65 && name[i] <= 90 || name[i] >= 97 && name[i] <= 122 || name[i] == 32))
            {
                j++;
            }
        }
        if(j == 0)
        {
            _name = name;
        }
        else
        {
            throw invalid_argument("\n\nError: The student's name must consist only of letters or space characters!\n\n");
        }
    }
    else
    {
        throw length_error("\n\nError: Name length is not allowed!\n\n");
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
void Student::setBalance(float balance)
{
    _balance = balance;
}
void Student::setIsActive(bool isActive)
{
    _isActive = isActive;
}
void Student::setReservations(vector<Reservation> reservations)
{
    _reservations = reservations;
}
//-------------------- getters --------------------
int Student::getUserId()const
{
    return _userId;
}
string Student::getStudentId()const
{
    return _studentId;
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
    return _isActive;
}
vector<Reservation> Student::getReservations()const
{
    return _reservations;
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
                    cout << "User ID: ";
                    tempS.setUserId(inputInt());
                    counter++;
                case 2:
                    cout << "Student ID: ";
                    tempS.setStudentId(inputString());
                    counter++;
                case 3:
                    cout << "Name: ";
                    tempS.setName(inputString());
                    counter++;
                case 4:
                    cout << "Email address: ";
                    tempS.setEmail(inputString());
                    counter++;
                case 5:
                    cout << "Balance: ";
                    tempS.setBalance(inputFloat());
                    counter++;
                case 6:
                    cout << "Is active: (true/false) or (0/1) : ";
                    tempS.setIsActive(inputBool());
                    counter++;
            }
            if(counter == 7)
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

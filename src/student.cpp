#include "../include/student.hpp"
#include <iostream>
#include <string.h>
using namespace std;

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
    catch(invalid_argument)
    {
        cerr << "\nThe input is invalid!\nPlease try again...\n\n";
    }
    catch(domain_error)
    {
        cerr << "\nThe number of digits entered is not correct!\nPlease try again...\n\n";
    }
    catch(length_error)
    {
        cerr << "\nThe string size is not appropriate!\nPlease try again...\n\n";
    }
    catch(...)
    {
        cerr << "\nThere was a problem while checking the input!\nPlease try again...\n\n";
    }
}

//-------------------- setters --------------------
void Student::setUserId(unsigned int userId)
{
    string temp = to_string(userId);
    if(temp.length() <= 8)
    {
        _userId = userId;
    }
    else
    {
        throw domain_error("");
    }
}
void Student::setStudentId(string studentId)
{
    if(studentId.length() == 10)
    {
        _studentId = studentId;
    }
    else
    {
        throw length_error("");
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
            throw invalid_argument("");
        }
    }
    else
    {
        throw length_error("");
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
                throw invalid_argument("");
            }
        }
        else
        {
            throw invalid_argument("");
        }
    }
    else
    {
        throw length_error("");
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

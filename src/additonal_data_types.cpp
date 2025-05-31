#include "../include/meal_type.hpp"
#include "../include/reservation_status.hpp"
#include "../include/dining_hall.hpp"
#include "../include/meal.hpp"
#include <iostream>
#include <string.h>
#include <windows.h>
#include <conio.h>
#include <vector>
#include <time.h>
#include <sstream>

using namespace std;

void gotoxy(int, int);
bool checkingMeal(vector<Meal>, unsigned int);

//---------------------- UTL ----------------------

string UTL(string temp)
{
    for(int i = 0; i < temp.length(); ++i)
    {
        if(temp[i] >= 65 && temp[i] <= 90)
        {
            temp[i] += 32;
        }
    }
    return temp;
}

//------------------------- inputInt --------------------------

int inputInt()
{
    string temp;
    getline(cin, temp);
    int j = 0;
    if(!(temp.empty()))
    {
        if(temp.length() <= 8)
        {
            for(int i = 0; i < temp.length(); ++i)
            {
                if(!(temp[i] >= 48 && temp[i] <= 57))
                {
                    j++;
                }
            }
            if(j == 0)
            {
                //cout << endl << temp << endl;
                return stoi(temp);
            }
            else
            {
                throw invalid_argument("\n\nError: The field must contain only numbers\n\n");
            }
        }
        else
        {
            throw domain_error("\n\nError: The number of digits exceeds the allowed limit!\n\n");
        }
    }
    else
    {
        throw invalid_argument("\n\nError: Field cannot be empty. Please provide a valid input.\n\n");
    }
}

//------------------------ inputFloat -------------------------

float inputFloat()
{
    string temp;
    getline(cin, temp);
    int j = 0, k = 0;
    if(!(temp.empty()))
    {
        for(int i = 0; i < temp.length(); ++i)
        {
            if(!(temp[i] >= 48 && temp[i] <= 57 || temp[i] == 46))
            {
                j++;
            }
            if(temp[i] == 46)
            {
                k++;
            }
        }
        if(j == 0)
        {
            if(k == 0 || k == 1)
            {
                //cout << endl << stof(temp) << endl;
                return stof(temp);
            }
            else
            {
                throw invalid_argument("\n\nError: The numer entered is invalid!\n\n");
            }
        }
        else
        {
            throw invalid_argument("\n\nError: The field must contain only numbers\n\n");
        }
    }
    else
    {
        throw invalid_argument("\n\nError: Field cannot be empty. Please provide a valid input.\n\n");
    }
}

//----------------------- inputString -------------------------

string inputString()
{
    string temp;
    getline(cin, temp);
    if(!(temp.empty()))
    {
        //cout << endl << temp << endl;
        return temp;
    }
    else
    {
        throw invalid_argument("\n\nError: Field cannot be empty. Please provide a valid input.\n\n");
    }
}

//------------------------ inputBool -------------------------

bool inputBool()
{
    string temp;
    getline(cin, temp);
    int j = 0;
    if(!(temp.empty()))
    {
        UTL(temp);
        if(temp == "true" || temp == "1")
        {
            return true;
        }
        else if(temp == "false" || temp == "0")
        {
            return false;
        }
        else
        {
            throw invalid_argument("\n\nError: The entered value is invalid!\n\n");
        }
    }
    else
    {
        throw invalid_argument("\n\nError: Field cannot be empty. Please provide a valid input.\n\n");
    }
}

//---------------------- inputMealType -----------------------

MealType inputMealType()
{
    string temp;
    getline(cin, temp);
    UTL(temp);
    if(temp == "breakfast")
    {
        return MealType::BREAKFAST;
    }
    else if(temp == "lunch")
    {
        return MealType::BREAKFAST;
    }
    else if(temp == "dinner")
    {
        return MealType::BREAKFAST;
    }
    else
    {
        throw invalid_argument("\n\nError: Invalid meal type!\n\n");
    }
}

//------------------ inputReservationStatus ------------------

ReservationStatus inputReservationStatus()
{
    string temp;
    getline(cin, temp);
    UTL(temp);
    if(temp == "cancelled")
    {
        return ReservationStatus::CANCELLED;
    }
    else if(temp == "faileed")
    {
        return ReservationStatus::FAILEED;
    }
    else if(temp == "selected")
    {
        return ReservationStatus::SELECTED;
    }
    else if(temp == "success")
    {
        return ReservationStatus::SUCCESS;
    }
    else
    {
        throw invalid_argument("\n\nError: The entered reservation status is invalid!\n\n");
    }
}

//-------------------- inputStringVector ---------------------

vector<string> inputStringVector()
{
    vector<string> tempVector;
    string temp;
    while(true)
    {
        try
        {
            temp = inputString();
            temp = UTL(temp);
            if(temp == "end")
            {
                break;
            }
            if(temp.length() >= 3 && temp.length() <= 20)
            {
                int j = 0;
                for(int i = 0; i < temp.length(); ++i)
                {
                    if(!(temp[i] >= 65 && temp[i] <= 90 || temp[i] >= 97 && temp[i] <= 122 || temp[i] == 32 || temp[i] == 44))
                    {
                        j++;
                    }
                }
                if(j == 0)
                {
                    if(temp[0] >= 97 && temp[0] <= 122)
                    {
                        temp[0] -= 32;
                    }
                    tempVector.push_back(temp);
                }
                else
                {
                    throw invalid_argument("\n\nError: The meal name can contain uppercase or lowercase letters, or allowed characters (, space)\n\n");
                }
            }
            else
            {
                throw length_error("\n\nError: Meal name length is not allowed!\n\n");
            }
        }
        catch(exception &e)
        {
            cerr << e.what();
        }
        cout << "Next side dish: ";
    }
    return tempVector;
}

//-------------------------- inputPass --------------------------

string inputPass()
{
    string temp;
    char ch;
    while((ch = _getch()) != '\r')
    {
        if(ch == '\b')
        {
            if(!temp.empty())
            {
                temp.pop_back();
                cout<<"\b \b";
            }
        }
        else
        {
            temp += ch;
            cout << "*";
        }

    }
    if(!(temp.empty()))
    {
        if(temp.length() >= 8 && temp.length() <= 16)
        {
            int j = 0;
            for(int i = 0; i < temp.length(); ++i)
            {
                if(!(temp[i] >= 48 && temp[i] <= 57 || temp[i] >= 64 && temp[i] <= 90 || temp[i] >= 97 && temp[i] <= 122 || temp[i] == 95 || temp[i] >= 44 && temp[i] <= 46))
                {
                    //cout <<  temp[i];
                    j++;
                }
            }
            if(j == 0)
            {
                return temp;
            }
            else
            {
                throw invalid_argument("\n\nError: Password can contain numbers, uppercase or lowercase letters, or allowed characters (@ _ - , .)\n\n");
            }
        }
        else
        {
            throw length_error("\n\nError: The password length most between 8 and 16 charackters!\n\n");
        }
    }
    else
    {
        throw invalid_argument("\n\nError: Field cannot be empty. Please provide a valid input.\n\n");
    }
}

//--------------------- checkingDiningHall ----------------------

bool checkingDiningHall(vector<DiningHall> DHvector, unsigned int temp)
{
    for(int i = 0; i < DHvector.size(); ++i)
    {
        if(temp == DHvector[i].getHallId())
        {
            return true;
        }
    }
    return false;
}

//------------------ checkingAndGetDiningHall -------------------

DiningHall checkingAndGetDiningHall(vector<DiningHall> DHvector)
{
    string temp;
    getline(cin, temp);
    if(temp.length() == 6)
    {
        if(temp[1] == '1' || temp[1] == '2')
        {
            if(temp[2] == '0' && temp[3] == '0' && temp[4] == '0')
            {
                for(int i = 0; i < DHvector.size(); ++i)
                {
                    if(stoi(temp) == DHvector[i].getHallId())
                    {
                        return DHvector[i];
                    }
                }
                throw runtime_error("\n\nError: There is no dining hall with this ID!\n\n");
            }
            else
            {
                throw invalid_argument("\n\nError: The entered ID is incorrect!\n\n");
            }
        }
        else
        {
            throw invalid_argument("\n\nError: The entered ID is incorrect!\n\n");
        }
    }
    else
    {
        throw domain_error("\n\nError: The number of digits in the ID is incorrect!\n\n");
    }


}

//------------------------ checkingMeal -------------------------

bool checkingMeal(vector<Meal> Mvector, unsigned int temp)
{
    for(int i = 0; i < Mvector.size(); ++i)
    {
        if(temp == Mvector[i].getMealID())
        {
            return true;
        }
    }
    return false;
}

//--------------------- checkingAndGetMeal ----------------------

Meal checkingAndGetMeal(vector<Meal> Mvector)
{
    string temp;
    getline(cin, temp);
    if(temp.length() == 6)
    {
        if(temp[0] == '1' || temp[0] == '2' || temp[0] == '3')
        {
            if(temp[1] == '0' && temp[2] == '0' && temp[3] == '0')
            {
                for(int i = 0; i < Mvector.size(); ++i)
                {
                    if(stoi(temp) == Mvector[i].getMealID())
                    {
                        return Mvector[i];
                    }
                }
                throw runtime_error("\n\nError: There is no meal with this ID!\n\n");
            }
            else
            {
                throw invalid_argument("\n\nError: The entered ID is incorrect!\n\n");
            }
        }
        else
        {
            throw invalid_argument("\n\nError: The entered ID is incorrect!\n\n");
        }
    }
    else
    {
        throw domain_error("\n\nError: The number of digits in the ID is incorrect!\n\n");
    }
}

//-------------------------- toString ---------------------------

string toString(MealType mealType)
{
    switch (mealType){
        case MealType::BREAKFAST:
            return "Breakfast";
        case MealType::LUNCH:
            return "Lunch";
        case MealType::DINNER:
            return "Dinner";
        default:
            throw invalid_argument("\n\nError: The input is invalid!\n\n");
    }
}

string toString(ReserveDay reserveDay)
{
    switch (reserveDay){
        case ReserveDay::SATURDAY:
            return "Saturday";
        case ReserveDay::SUNDAY:
            return "Sunday";
        case ReserveDay::MONDAY:
            return "Monday";
        case ReserveDay::TUESDAY:
            return "Tuesday";
        case ReserveDay::WEDNESDAY:
            return "Wednesday";
        case ReserveDay::THURSDAY:
            return "Thursday";
        case ReserveDay::FRIDAY:
            return "Friday";
        default:
            throw invalid_argument("\n\nError: The input is invalid!\n\n");
    }
}

string toString(ReservationStatus status)
{
    switch (status){
        case ReservationStatus::CANCELLED:
            return "Cancelled";
        case ReservationStatus::FAILEED:
            return "Faileed";
        case ReservationStatus::SELECTED:
            return "Selected";
        case ReservationStatus::SUCCESS:
            return "Success";
        default:
            throw invalid_argument("\n\nError: The input is invalid!\n\n");
    }
}

//--------------------------------------------------------------------------

MealType stringToMealType(string str)
{
    if(str == "Breakfast")
    {
        return MealType::BREAKFAST;
    }
    else if(str == "Lunch")
    {
            return MealType::LUNCH;
    }
    else if(str == "Dinner")
    {
            return MealType::DINNER;
    }
    else
    {
            throw invalid_argument("\n\nError: The input is invalid!\n\n");
    }
}

ReserveDay stringToReserveDay(string str)
{
    if(str == "Saturday")
    {
        return ReserveDay::SATURDAY;
    }
    else if(str == "Sunday")
    {
        return ReserveDay::SUNDAY;
    }
    else if(str == "Monday")
    {
        return ReserveDay::MONDAY;
    }
    else if(str == "Tuesday")
    {
        return ReserveDay::TUESDAY;
    }
    else if(str == "Wednesday")
    {
        return ReserveDay::WEDNESDAY;
    }
    else if(str == "Thursday")
    {
        return ReserveDay::THURSDAY;
    }
    else if(str == "Friday")
    {
        return ReserveDay::FRIDAY;
    }
    else
    {
        throw invalid_argument("\n\nError: The input is invalid!\n\n");
    }
}


ReservationStatus stringToReservationStatus(string str)
{
    if(str == "Cancelled")
    {
        return ReservationStatus::CANCELLED;
    }
    else if(str == "Faileed")
    {
        return ReservationStatus::FAILEED;
    }
    else if(str == "Selected")
    {
        return ReservationStatus::SELECTED;
    }
    else if(str == "Success")
    {
        return ReservationStatus::SUCCESS;
    }
    else
    {
            throw invalid_argument("\n\nError: The input is invalid!\n\n");
    }
}

time_t stringToTime(const string& dateStr)
{
    struct tm timeStruct = {};
    istringstream ss(dateStr);

    ss >> timeStruct.tm_year >> timeStruct.tm_mon >> timeStruct.tm_mday
       >> timeStruct.tm_hour >> timeStruct.tm_min >> timeStruct.tm_sec;

    timeStruct.tm_year -= 1900;
    timeStruct.tm_mon -= 1;

    return mktime(&timeStruct);
}


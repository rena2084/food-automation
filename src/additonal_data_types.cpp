#include "../include/meal_type.hpp"
#include "../include/reservation_status.hpp"
#include <iostream>
#include <vector>

using namespace std;

//--------------------- inputUnsignedInt ----------------------

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
        for(int i = 0; i < temp.length(); ++i)
        {
            if(temp[i] >= 65 && temp[i] <= 90)
            {
                temp[i] += 32;
            }
        }
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
    for(int i = 0; i < temp.length(); ++i)
    {
        if(temp[i] >= 65 && temp[i] <= 90)
        {
            temp[i] += 32;
        }
    }
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
    for(int i = 0; i < temp.length(); ++i)
    {
        if(temp[i] >= 65 && temp[i] <= 90)
        {
            temp[i] += 32;
        }
    }
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
            for(int i = 0; i < temp.length(); ++i)
            {
                if(temp[i] >= 65 && temp[i] <= 90)
                {
                    temp[i] += 32;
                }
            }
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

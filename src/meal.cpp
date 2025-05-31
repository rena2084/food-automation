#include "../include/meal.hpp"
#include <iostream>
#include <string.h>
#define EXCEPTION_LOCATION_X 0
#define EXCEPTION_LOCATION_Y 20
using namespace std;

void gotoxy(int, int);
int inputInt();
float inputFloat();
string inputString();
string toString(MealType);
string toString(ReserveDay);
MealType inputMealType();
vector<string> inputStringVector();
bool checkingMeal(vector<Meal>, unsigned int);

//------------------------------------- Meal Class --------------------------------------

Meal::Meal(unsigned int mealID, string name, float price, bool isActive, MealType mealType, ReserveDay reserveDay, vector<string> sideItem)
{
    try
    {
        setMealID(mealID);
        setName(name);
        setPrice(price);
        setIsActive(isActive);
        setMealType(mealType);
        setReserveDay(reserveDay);
        setSideItem(sideItem);
    }
    catch(exception &e)
    {
        gotoxy(EXCEPTION_LOCATION_X,EXCEPTION_LOCATION_Y);
        cerr << e.what();
    }
}

//-------------------- setters --------------------
void Meal::setMealID(unsigned int mealID)
{
    //21
    //string temp = to_string(mealID);
    if(mealID <= 99 && mealID >= 11)
    {
        _mealID = mealID;
    }
    else
    {
        throw invalid_argument("\n\nError: The entered ID is incorrect!\n\n");
    }
}
void Meal::setName(string name)
{
    if(name.length() >= 3 && name.length() <= 20)
    {
        int j = 0;
        for(int i = 0; i < name.length(); ++i)
        {
            if(!(name[i] >= 65 && name[i] <= 90 || name[i] >= 97 && name[i] <= 122 || name[i] == 32 || name[i] == 44))
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
            throw invalid_argument("\n\nError: The meal name can contain uppercase or lowercase letters, or allowed characters (, space)\n\n");
        }
    }
    else
    {
        throw length_error("\n\nError: Meal name length is not allowed!\n\n");
    }
}
void Meal::setPrice(float price)
{
    _price = price;
}
void Meal::setIsActive(bool isActive)
{
    _isActive = isActive;
}
void Meal::setMealType(MealType mealType)
{
    _mealType = mealType;
}
void Meal::setReserveDay(ReserveDay reserveDay)
{
    _reserveDay = reserveDay;
}
void Meal::setSideItem(vector<string> sideItem)
{
    _sideItem = sideItem;
}

//-------------------- getters --------------------
int Meal::getMealID()const
{
    return _mealID;
}
string Meal::getName()const
{
    return _name;
}
float Meal::getPrice()const
{
    return _price;
}
bool Meal::getIsActive()const
{
    return _isActive;
}
MealType Meal::getMealType()const
{
    return _mealType;
}
ReserveDay Meal::getReserveDay()const
{
    return _reserveDay;
}
vector<string> Meal::getSideItem()const
{
    return _sideItem;
}

//------------------------- activate --------------------------

void Meal::activate()
{
    _isActive = true;
}

//------------------------ deactivate -------------------------

void Meal::deactivate()
{
    _isActive = false;
}

//--------------------------- print ---------------------------

void Meal::print()const
{
    cout << "Meal ID: " << getMealID() << endl;
    cout << "Name: " << getName() << endl;
    cout << "Price: " << getPrice() << endl;
    cout << "Is active: " << getIsActive() << endl;
    cout << "Meal type: " << toString(getMealType()) << endl;
    cout << "Reserve Day: " << toString(getReserveDay()) << endl;
    cout << "Side Item:";
    //for(int i = 0; i < getSideItem().length() ++i)
    //{
    //    cout << " " << getSideItem()[i];
    //}
    //cout << endl;
}

//------------------------ updatePrice ------------------------

void Meal::updatePrice(float price)
{
    _price = price;
}

//------------------------ addSideItem ------------------------

void Meal::addSideItem(string sideItem)
{
    _sideItem.push_back(sideItem);
}

//------------------------- newMeal ---------------------------

Meal newMeal()
{
    Meal tempM;
    int counter = 1;
    while(true)
    {
        try
        {
            switch (counter) {
                case 1:
                    cout << "Meal ID: ";
                    tempM.setMealID(inputInt());
                    counter++;
                case 2:
                    cout << "Name: ";
                    tempM.setName(inputString());
                    counter++;
                case 3:
                    cout << "Price: ";
                    tempM.setPrice(inputFloat());
                    counter++;
                case 4:
                    cout << "Meal type: ";
                    tempM.setMealType(inputMealType());
                    counter++;
                case 5:
                    cout << "(Note: To end the input, enter the word 'end')\nSide item: ";
                    tempM.setSideItem(inputStringVector());
                    counter++;
            }
            if(counter == 6)
            {
                return tempM;
            }
        }
        catch(exception &e)
        {
            gotoxy(EXCEPTION_LOCATION_X,EXCEPTION_LOCATION_Y);
            cerr << e.what();
        }
    }
}

#include "../include/meal.hpp"
#include <iostream>
#include <string.h>
using namespace std;

int inputInt();
float inputFloat();
string inputString();
MealType inputMealType();
vector<string> inputStringVector();

//------------------------------------- Meal Class --------------------------------------

Meal::Meal(unsigned int mealId, string name, float price, MealType mealType, vector<string> sideItem)
{
    try
    {
        setMealId(mealId);
        setName(name);
        setPrice(price);
        setMealType(mealType);
        setSideItem(sideItem);
    }
    catch(exception &e)
    {
        cerr << e.what();
    }
}

//-------------------- setters --------------------
void Meal::setMealId(unsigned int mealId)
{
    //100021
    //first digit -> Food price range(1 or 2 or 3)
    //last two digits -> Food ID

    string temp = to_string(mealId);
    if(temp.length() == 6)
    {
        if(temp[0] == '1' || temp[0] == '2' || temp[0] == '3')
        {
            if(temp[1] == '0' && temp[2] == '0' && temp[3] == '0')
            {
                _mealId = mealId;
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
void Meal::setMealType(MealType mealType)
{
    _mealType = mealType;
}
void Meal::setSideItem(vector<string> sideItem)
{
    _sideItem = sideItem;
}

//-------------------- getters --------------------
int Meal::getMealId()const
{
    return _mealId;
}
string Meal::getName()const
{
    return _name;
}
float Meal::getPrice()const
{
    return _price;
}
MealType Meal::getMealType()const
{
    return _mealType;
}
vector<string> Meal::getSideItem()const
{
    return _sideItem;
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
                    tempM.setMealId(inputInt());
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
            cerr << e.what();
        }
    }
}

#include "../include/meal.hpp"
using namespace std;

//------------------------------------- Meal Class --------------------------------------

Meal::Meal(unsigned int mealId, string name, float price, MealType mealType, vector<string> sideItem)
{
    setMealId(mealId);
    setName(name);
    setPrice(price);
    setMealType(mealType);
    setSideItem(sideItem);
}

//-------------------- setters --------------------
void Meal::setMealId(unsigned int mealId)
{

}
void Meal::setName(string name)
{

}
void Meal::setPrice(float price)
{

}
void Meal::setMealType(MealType mealType)
{

}
void Meal::setSideItem(vector<string> sideItem)
{

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



#include "../include/meal.hpp"
using namespace std;


//------------------------------------- Meal Class --------------------------------------

Meal::Meal(unsigned int meal_id, string name, float price, MealType meal_type, vector<string> side_item)
{
    setMealId(meal_id);
    setName(name);
    setPrice(price);
    setMealType(meal_type);
    setSideItem(side_item);
}

//----- setters -----
void Meal::setMealId(unsigned int meal_id)
{

}
void Meal::setName(string name)
{

}
void Meal::setPrice(float price)
{

}
void Meal::setMealType(MealType meal_type)
{

}
void Meal::setSideItem(vector<string> side_item)
{

}

//----- getters -----
int Meal::getMealId()const
{
    return _meal_id;
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
    return _meal_type;
}
vector<string> Meal::getSideItem()const
{
    return _side_item;
}

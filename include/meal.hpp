#ifndef MEAL_HPP
#define MEAL_HPP
#include "meal_type.hpp"
#include <vector>
#include <string>
using namespace std;

//------------- Meal Class --------------
class Meal{
private:
    unsigned int _mealId;
    string _name;
    float _price;
    MealType _mealType;
    vector<string> _sideItem;
public:
    Meal(unsigned int = 100001, vector<Meal> = {}, string = "Unknown", float = 15000.0f, MealType = MealType::LUNCH, vector<string> = {"not selected"});
    void print()const;
    void updatePrice(float);
    void addSideItem(string);

    //----- setters -----
    void setMealId(unsigned int, vector<Meal>);
    void setName(string);
    void setPrice(float);
    void setMealType(MealType);
    void setSideItem(vector<string>);

    //----- getters -----
    int getMealId()const;
    string getName()const;
    float getPrice()const;
    MealType getMealType()const;
    vector<string> getSideItem()const;
};

#endif // MEAL_HPP

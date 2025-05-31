#ifndef MEAL_HPP
#define MEAL_HPP
#include "meal_type.hpp"
#include "reserve_day.hpp"
#include <vector>
#include <string>
using namespace std;

//------------- Meal Class --------------SATURDAY
class Meal{
private:
    unsigned int _mealID;
    string _name;
    float _price;
    bool _isActive;
    MealType _mealType;
    ReserveDay _reserveDay;
    vector<string> _sideItem;
public:
    Meal(unsigned int = 11, string = "Unknown", float = 15000.0f, bool = true, MealType = MealType::LUNCH, ReserveDay = ReserveDay::SATURDAY, vector<string> = {"not selected"});
    void activate();
    void deactivate();
    void print()const;
    void updatePrice(float);
    void addSideItem(string);

    //----- setters -----
    void setMealID(unsigned int);
    void setName(string);
    void setPrice(float);
    void setIsActive(bool);
    void setMealType(MealType);
    void setReserveDay(ReserveDay);
    void setSideItem(vector<string>);

    //----- getters -----
    int getMealID()const;
    string getName()const;
    float getPrice()const;
    bool getIsActive()const;
    MealType getMealType()const;
    ReserveDay getReserveDay()const;
    vector<string> getSideItem()const;
};

#endif // MEAL_HPP

#ifndef MEAL_H
#define MEAL_H
#include "meal_type.hpp"
using namespace std;

//------------- Meal Class --------------
class Meal{
private:
    unsigned int _meal_id;
    string _name;
    float _price;
    MealType _meal_type;
    vector<string> _side_item;
public:
    Meal(unsigned int = 0, string = "Unknown", float = 15000.0f, MealType = MealType::LUNCH, vector<string> = {"not selected"});
    void print()const;
    void updatePrice(float);
    void addSideItem(string);

    //----- setters -----
    void setMealId(unsigned int);
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

#endif // MEAL_H

#ifndef STORAGE_HPP
#define STORAGE_HPP
#include "meal.hpp"
#include "dining_hall.hpp"


class Storage{
private:
    int _mealDCounter;
    int _diningHallDCounter;
    Storage();
    Storage(const Storage&) = delete;
    Storage operator=(const Storage&) = delete;

public:
    vector<Meal> allMeals;
    vector<DiningHall> allDiningHalls;
    static Storage& instance();

};



#endif // STORAGE_HPP

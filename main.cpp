#include <iostream>
#include <vector>
#include <string.h>
#include <time.h>
#include <conio.h>
#include <windows.h>

#include "./include/meal.hpp"
#include "./include/dining_hall.hpp"
#include "./include/reservation.hpp"
#include "./include/student.hpp"
#include "./include/reservation_status.hpp"
#include "./include/meal_type.hpp"

using namespace std;


//------------------------------------------------------------ Main ------------------------------------------------------------


void gotoxy(int, int);
Student newStusent();
DiningHall newDiningHall();
Meal newMeal();


int main()
{
    //Student a;
    //a = newStusent();
    //cout << "\n\n" << a.getBalance();

    //DiningHall b;
    //b = newDiningHall();
    //cout << "\n\n" << b.getAddress();

    Meal c;
    c = newMeal();
    //cout << "\n\n" << c.getMealId();
    return 0;
}


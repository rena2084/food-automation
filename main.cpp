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
DiningHall newDiningHall(vector<DiningHall>);
Meal newMeal(vector<Meal>);
Reservation newReservation(vector<DiningHall>, vector<Meal>);


int main()
{/*
    //Student a;
    //a = newStusent();
    //cout << "\n\n" << a.getBalance();
    array<int, 5> a = {1,2,3,4,5};
    array<int, 5> b = {1,2,3,4,5};

    bool c = a==b;
    cout << c;
*/

    //char a = 'r', b = 's';
    //SetConsoleOutputCP(CP_UTF8);
    //cout << "\U0001F60E";
    //cout << "\U0001F370";




    /*
class string
{
    char Array;
    int Size;
public:
    string operator+(string);
};
string string::operator+(string ob)
{
    char temp[this.Size + ob.Size];
    temp = ob.Array;
}
    string a = "dfgh";

    */



    vector<DiningHall> DHvector;
    //while(true)
    //{
        DiningHall b;
        b = newDiningHall(DHvector);
        DHvector.push_back(b);
    //}
    //cout << "\n\n" << b.getAddress();



    vector<Meal> Mvector;
    //while(true)
    //{
        Meal c;
        c = newMeal(Mvector);
        Mvector.push_back(c);
    //}
    //cout << "\n\n" << c.getMealId();




    Reservation d;
    d = newReservation(DHvector, Mvector);
    //cout << "\n\n" << d.getReservationId();



    return 0;
}


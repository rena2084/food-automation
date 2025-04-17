#include <iosteam>
#include <vector>
#include <string.h>
#include <windows.h>

using namespace sdt;


class Student(){

};

class Reservation(){

};

class Meal(){

};

class DiningHall(){

};

int main()
{

    return 0;

}

//-------------------------- Gotoxy --------------------------

void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

//------------------------ TextColor -------------------------

void textColor(int x){
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h, x);
}

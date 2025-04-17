#include <iosteam>
#include <vector>
#include <string.h>
#include <windows.h>

using namespace sdt;


class Student{
private:
    int _user_id;
    string _student_id;
    string _name;
    string _email;
    float _balance;
    bool _is_active;
public:
    Student();
    void print()const;
    void reserve_meal(Meal);
    bool cancel_reservation(Reservation);

    //----- setters -----
    void set_user_id();
    void set_student_id();
    void set_name();
    void set_email();
    void set_balance();
    void set_is_active();

    //----- getters -----
    int get_user_id();
    string get_student_id();
    string get_name();
    string get_email();
    float get_balance();
    bool get_is_active();
};

class Reservation{

};

class Meal{

};

class DiningHall{

};




void gotoxy(int, int);
void text_color(int);
void cursor(bool);




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

void text_color(int x){
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h, x);
}

//---------------------- cursor_status -----------------------

void cursor_status(bool status){
    HANDLE hStdOut = NULL;
    CONSOLE_CURSOR_INFO curInfo;
    hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    GetConsoleCursorInfo(hStdOut, &curInfo);
    curInfo.bVisible = status;
    SetConsoleCursorInfo(hStdOut, &curInfo);
}

#include <iostream>
#include <vector>
#include <string.h>
#include <windows.h>

using namespace std;


class Student;
class Reservation;
class Meal;
class DiningHall;


//------------- Enum Class --------------
class Enum{

};

//------------ Student Class ------------
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
    void reserveMeal(Meal);
    bool cancelReservation(Reservation);

    //----- setters -----
    void setUserId(int);
    void setStudentId(string);
    void setName(string);
    void setEmail(string);
    void setBalance(float);
    void setIsActive(bool);

    //----- getters -----
    int getUserId()const;
    string getStudentId()const;
    string getName()const;
    string getEmail()const;
    float getBalance()const;
    bool getIsActive()const;
};

//---------- Reservation Class ----------
class Reservation{
private:
    int _reservation_id;
    Student _student;
    DiningHall* _dining_hall;
    Meal* _meal;
    Enum _status;
    time_t _created_at;
public:
    Reservation();
    void print()const;
    bool cancel();

    //----- setters -----
    void setReservationId(int);
    void setStudent(Student);
    void setDHall(DiningHall);
    void setMeal(Meal);
    void setStatus(Enum);
    void setCreatedAt(time_t);

    //----- getters -----
    int getReservationId()const;
    Student getStudent()const;
    DiningHall getDHall()const;
    Meal getMeal()const;
    Enum getStatus()const;
    time_t getCreatedAt()const;
};

//------------- Meal Class --------------
class Meal{
private:
    int _meal_id;
    string _name;
    float _price;
    Enum _meal_type;
    vector<Meal> _side_item;
public:
    Meal();
    void print()const;
    void updatePrice(float);
    void addSideItem(string);

    //----- setters -----
    void setMealId(int);
    void setName(string);
    void setPrice(float);
    void setMealType(Enum);
    void setSideItem(vector<Meal>);

    //----- getters -----
    int getMealId()const;
    string getName()const;
    float getPrice()const;
    Enum getMealType()const;
    vector<Meal> getSideItem()const;
};

//---------- DiningHall Class -----------
class DiningHall{
private:
    int _hall_id;
    string _name;
    string _address;
    int _capacity;
public:
    DiningHall();
    void print()const;

    //----- setters -----
    void setHallId(int);
    void setName(string);
    void setAddress(string);
    void setCapacity(int);

    //----- getters -----
    int getHallId()const;
    string getName()const;
    string getAddress()const;
    int getCapacity()const;
};




void gotoxy(int, int);
void textColor(int);
void cursor(bool);


//------------------------------------------------------------ Main ------------------------------------------------------------

int main()
{

    return 0;

}

//-------------------------- gotoxy --------------------------

void gotoxy(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

//------------------------ textColor -------------------------

void textColor(int x)
{
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h, x);
}

//----------------------- cursorStatus -----------------------

void cursor_status(bool status)
{
    HANDLE hStdOut = NULL;
    CONSOLE_CURSOR_INFO curInfo;
    hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    GetConsoleCursorInfo(hStdOut, &curInfo);
    curInfo.bVisible = status;
    SetConsoleCursorInfo(hStdOut, &curInfo);
}

//------------------------------------ Student Class ------------------------------------

Student::Student()
{
    _user_id = 0;
    _student_id = "0000000000";
    _name = "Unknown";
    _email = _student_id + ".gmail.com";
    _balance = 0.00;
    _is_active = true;
}

//----- setters -----
void Student::setUserId(int);
void Student::setStudentId(string);
void Student::setName(string);
void Student::setEmail(string);
void Student::setBalance(float);
void Student::setIsActive(bool);

//----- getters -----
int Student::getUserId()const
{
    return _user_id;
}
string Student::getStudentId()const
{
    return _student_id;
}
string Student::getName()const
{
    return _name;
}
string Student::getEmail()const
{
    return _email;
}
float Student::getBalance()const
{
    return _balance;
}
bool Student::getIsActive()const
{
    return _is_active;
}

//---------------------------------- Reservation Class ----------------------------------

Reservation::Reservation()
{
    _reservation_id = 0;
    _dining_hall = new DiningHall();
    _meal = new Meal();
    _status;
    _created_at;
}

//----- setters -----
void Reservation::setReservationId(int);
void Reservation::setStudent(Student);
void Reservation::setDHall(DiningHall);
void Reservation::setMeal(Meal);
void Reservation::setStatus(Enum);
void Reservation::setCreatedAt(time_t);

//----- getters -----
int Reservation::getReservationId()const
{
    return _reservation_id;
}
Student Reservation::getStudent()const
{
    return _student;
}
DiningHall Reservation::getDHall()const
{
    return _dining_hall;
}
Meal Reservation::getMeal()const
{
    return _meal;
}
Enum Reservation::getStatus()const
{
    return _status;
}
time_t Reservation::getCreatedAt()const
{
    return _created_at;
}

//------------------------------------- Meal Class --------------------------------------

Meal::Meal()
{
    _meal_id = 0;
    _name = "Unknown";
    _price = 15000.00;
    _meal_type;
    _side_item;
}

//----- setters -----
void Enum Meal::setMealId(int);
void Enum Meal::setName(string);
void Enum Meal::setPrice(float);
void Enum Meal::setMealType(Enum);
void Enum Meal::setSideItem(vector<Meal>);

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
Enum Meal::getMealType()const
{
    return _meal_type;
}
vector<Meal> Meal::getSideItem()const
{
    return _side_item;
}

//---------------------------------- DiningHall Class -----------------------------------

DiningHall::DiningHall()
{
    int _hall_id = 0;
    string _name = "University";
    string _address = "---";
    int _capacity = 200;
}

//----- setters -----
void DiningHall::setHallId(int);
void DiningHall::setName(string);
void DiningHall::setAddress(string);
void DiningHall::setCapacity(int);

//----- getters -----
int DiningHall::getHallId()const
{
    return _hall_id;
}
string DiningHall::getName()const
{
    return _name;
}
string DiningHall::getAddress()const
{
    return _address;
}
int DiningHall::getCapacity()const
{
    return _capacity;
}

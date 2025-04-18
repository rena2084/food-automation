#include <iostream>
#include <vector>
#include <string.h>
#include <time.h>
#include <windows.h>

using namespace std;


class Student;
class Reservation;
class Meal;
class DiningHall;

void gotoxy(int, int);
void textColor(int);
void cursor(bool);


//------ ReservationStatus Class --------
enum class ReservationStatus{
    SUCCESS,
    CANCELLED,
    SELECTED,
    FAILEED,
};

//----------- MealType Class ------------
enum class MealType{
    BREAKFAST,
    LUNCH,
    DINNER,
};

//------------ Student Class ------------
class Student{
private:
    unsigned int _user_id;
    string _student_id;
    string _name;
    string _email;
    float _balance;
    bool _is_active;
public:
    Student(unsigned int = 0, string = "0000000000", string = "Unknown", string = "Unknown@gmail.com", float = 0.00, bool = true);
    void print()const;
    void reserveMeal(Meal);
    bool cancelReservation(Reservation);

    //----- setters -----
    void setUserId(unsigned int);
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
    unsigned int _reservation_id;
    Student _student;
    DiningHall* _dining_hall;
    Meal* _meal;
    ReservationStatus _status;
    time_t _created_at;
public:
    Reservation(unsigned int = 0, ReservationStatus = SELECTED, time_t = time(nullptr));
    void print()const;
    bool cancel();

    //----- setters -----
    void setReservationId(unsigned int);
    void setStudent(Student);
    void setDHall(DiningHall);
    void setMeal(Meal);
    void setStatus(ReservationStatus);
    void setCreatedAt(time_t);

    //----- getters -----
    int getReservationId()const;
    Student getStudent()const;
    DiningHall getDHall()const;
    Meal getMeal()const;
    ReservationStatus getStatus()const;
    time_t getCreatedAt()const;
};

//------------- Meal Class --------------
class Meal{
private:
    unsigned int _meal_id;
    string _name;
    float _price;
    MealType _meal_type;
    vector<string> _side_item;
public:
    Meal(unsigned int = 0, string = "Unknown", float = 15000.0f, MealType = LUNCH, vector<string> = {"not selected"});
    void print()const;
    void updatePrice(float);
    void addSideItem(string);

    //----- setters -----
    void setMealId(unsigned int);
    void setName(string);
    void setPrice(float);
    void setMealType(MealType);
    void setSideItem(vector<Meal>);

    //----- getters -----
    int getMealId()const;
    string getName()const;
    float getPrice()const;
    MealType getMealType()const;
    vector<Meal> getSideItem()const;
};

//---------- DiningHall Class -----------
class DiningHall{
private:
    unsigned int _hall_id;
    string _name;
    string _address;
    int _capacity;
public:
    DiningHall(unsigned int = 0, string = "University", string = "...", int = 200);
    void print()const;

    //----- setters -----
    void setHallId(unsigned int);
    void setName(string);
    void setAddress(string);
    void setCapacity(int);

    //----- getters -----
    int getHallId()const;
    string getName()const;
    string getAddress()const;
    int getCapacity()const;
};







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

Student::Student(unsigned int user_id, string student_id, string name, string email, float balance, bool is_active)
{
    setUserId(user_id);
    setStudentId(student_id);
    setName(name);
    setEmail(email);
    setBalance(balance);
    setIsActive(is_active);
}

//----- setters -----
void Student::setUserId(unsigned int user_id)
{

}
void Student::setStudentId(string student_id)
{

}
void Student::setName(string name)
{

}
void Student::setEmail(string email)
{

}
void Student::setBalance(float balance)
{

}
void Student::setIsActive(bool is_active)
{

}

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

Reservation::Reservation(unsigned int reservation_id, ReservationStatus status, time_t created_at)
{
    setReservationId(reservation_id);
    _dining_hall = new DiningHall();
    _meal = new Meal();
    setStatus(status);
    setCreatedAt(created_at);
}

//----- setters -----
void Reservation::setReservationId(unsigned int reservation_id)
{

}
void Reservation::setStudent(Student student)
{

}
void Reservation::setDHall(DiningHall dining_hall)
{

}
void Reservation::setMeal(Meal meal)
{

}
void Reservation::setStatus(ReservationStatus status)
{

}
void Reservation::setCreatedAt(time_t created_at)
{

}

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
    return *_dining_hall;
}
Meal Reservation::getMeal()const
{
    return *_meal;
}
ReservationStatus Reservation::getStatus()const
{
    return _status;
}
time_t Reservation::getCreatedAt()const
{
    return _created_at;
}

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
void Meal::setSideItem(vector<Meal> side_item)
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
vector<Meal> Meal::getSideItem()const
{
    return _side_item;
}

//---------------------------------- DiningHall Class -----------------------------------

DiningHall::DiningHall(unsigned int hall_id, string name, string address, int capacity)
{
    setHallId(hall_id);
    setName(name);
    setAddress(address);
    setCapacity(capacity);
}

//----- setters -----
void DiningHall::setHallId(unsigned int hall_id)
{

}
void DiningHall::setName(string name)
{

}
void DiningHall::setAddress(string address)
{

}
void DiningHall::setCapacity(int capacity)
{

}

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

#include <iosteam>
#include <vector>
#include <string.h>
#include <windows.h>

using namespace sdt;


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
    void setUserId();
    void setStudentId();
    void setName();
    void setEmail();
    void setBalance();
    void setIsActive();

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
    DiningHall _dHall;
    Meal _meal;
    Enum _status;
    time_t _created_at;
public:
    Reservation();
    void print()const;
    bool cancel();

    //----- setters -----
    void setReservationId();
    void setStudent();
    void setDHall();
    void setMeal();
    void setStatus();
    void setCreatedAt();

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
    void setMealId();
    void setName();
    void setPrice();
    void setMealType();
    void setSideItem();

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
    int capacity;
public:
    DiningHall();
    void print()const;

    //----- setters -----
    void setHallId();
    void setName();
    void setAddress();
    void setCapacity();

    //----- getters -----
    int getHallId()const;
    string getName()const;
    string getAddress()const;
    int getCapacity()const;
};




void gotoxy(int, int);
void text_color(int);
void cursor(bool);


//------------------------------------------------------------ Main ------------------------------------------------------------

int main()
{

    return 0;

}

//-------------------------- gotoxy --------------------------

void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

//------------------------ text_color ------------------------

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

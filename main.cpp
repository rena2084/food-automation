#include <iostream>
#include <fstream>
#include <vector>
#include <limits>
#include <cstdlib>
#include <math.h>
#include <string.h>
#include <time.h>
#include <conio.h>
#include <windows.h>
#include <sstream>

#include "./include/meal.hpp"
#include "./include/dining_hall.hpp"
#include "./include/reservation.hpp"
#include "./include/student.hpp"
#include "./include/reservation_status.hpp"
#include "./include/meal_type.hpp"
#include "./include/admin.hpp"


#define EXCEPTION_LOCATION_X 0
#define EXCEPTION_LOCATION_Y 20


using namespace std;


//------------------------------------------------------------ Main ------------------------------------------------------------

void gotoxy(int, int);
void loginOperation(vector<User>);
Student newStusent();
DiningHall newDiningHall();
Meal newMeal();
Reservation newReservation();
User newUser();
void showLoginPage();
void loginOperation(vector<User>);
MealType stringToMealType(string);
ReserveDay stringToReserveDay(string);
ReservationStatus stringToReservationStatus(string);
time_t stringToTime(const string&);
string toString(MealType);
string toString(ReservationStatus);
string toString(ReserveDay);
//string time_tToString(time_t);


string trashBin;


int main()
{
    struct{
        unsigned int userID;
        string name;
        string lastName;
        string hashedPassword;
        string studentId;
        string email;
        string phone;
        float balance;
        bool isActive;
        vector<Reservation> reserves;
    }tempStudent;



    struct{
        unsigned int reservationId;
        DiningHall diningHall;
        Meal meal;
        ReservationStatus status;
        time_t createdAt;
    }tempReserve;



    struct{
        unsigned int hallId;
        string name;
        string address;
        int capacity;
    }tempDiningHall;


    struct{
        unsigned int mealID;
        string name;
        float price;
        bool isActive;
        MealType mealType;
        ReserveDay reserveDay;
        vector<string> sideItem;
    }tempMeal;
//
//    struct {
//        unsigned int _userID;
//        string name;
//        string lastName;
//        string hashedPassword;
//    }tempAdmin;

    vector<Student> students;
    vector<Admin> Admins;
    vector<User> users;

//    ofstream sout;
//    sout.open("./data/student_data.txt" , ios::out | ios::app);
//    if(!sout)
//    {
//        gotoxy(EXCEPTION_LOCATION_X, EXCEPTION_LOCATION_Y);
//        cerr <<"Data not received!";
//        system("pause");
//        exit(0);
//    }
//
//
//    sout.close();



    ifstream student_in;
    student_in.open("./data/students_data.txt" , ios::in);
    if(!student_in)
    {
        gotoxy(EXCEPTION_LOCATION_X, EXCEPTION_LOCATION_Y);
        cerr <<"Data not received!";
        system("pause");
        exit(0);
    }
    while(!(student_in.eof()))
    {
        cout << student_in.tellg() << endl;
        student_in >> tempStudent.userID >> tempStudent.name >> tempStudent.lastName >> tempStudent.hashedPassword >> tempStudent.studentId >> tempStudent.email >> tempStudent.phone >> tempStudent.balance >> tempStudent.isActive;
        cout << tempStudent.isActive << endl;
        string checkStudentID;
        //vector<Reservation> studentReserves;
        ifstream reserves_in;
        reserves_in.open("./data/reserves_data.txt" , ios::in);
        if(!reserves_in)
        {
            gotoxy(EXCEPTION_LOCATION_X, EXCEPTION_LOCATION_Y);
            cerr <<"Data not received!";
            system("pause");
            exit(0);
        }
        while(reserves_in >> checkStudentID)
        {

            cout << checkStudentID << " , " << tempStudent.studentId << endl;
            if(tempStudent.studentId == checkStudentID)
            {
                string status;
                string createdAt;

                reserves_in >> tempReserve.reservationId >> status >> createdAt;
                cout << createdAt<<endl;
                for(int i = 0; i < createdAt.length(); i++)
                {
                    if(createdAt[i] == '&')
                    {
                        createdAt[i] = ' ';
                    }
                }
//                cout << "hi2";
                tempReserve.status = stringToReservationStatus(status);
                tempReserve.createdAt = stringToTime(createdAt);
                int checkReserveID;
                ifstream diningHall_in;
                diningHall_in.open("./data/dining_halls_data.txt" , ios::in);

                if(!diningHall_in)
                {
                    gotoxy(EXCEPTION_LOCATION_X, EXCEPTION_LOCATION_Y);
                    cerr <<"Data not received!";
                    system("pause");
                    exit(0);
                }

                while(diningHall_in >> checkReserveID)
                {
//                    cout << floor(tempReserve.reservationId/100);
                    if(floor(tempReserve.reservationId/100) == checkReserveID)
                    {
                        diningHall_in >> tempDiningHall.name >> tempDiningHall.address >> tempDiningHall.capacity;
                        tempDiningHall.hallId = checkReserveID;
                        DiningHall diningHall(tempDiningHall.hallId, tempDiningHall.name, tempDiningHall.address, tempDiningHall.capacity);
                        tempReserve.diningHall = diningHall;
                        break;
                    }
                    else
                    {
                        getline(diningHall_in, trashBin);
                        //diningHall_in.ignore();
                    }
                }
                diningHall_in.close();



                int checkMealID;
                ifstream meal_in;
                meal_in.open("./data/meals_data.txt" , ios::in);
                if(!meal_in)
                {
                    gotoxy(EXCEPTION_LOCATION_X, EXCEPTION_LOCATION_Y);
                    cerr <<"Data not received!";
                    system("pause");
                    exit(0);
                }
                while(meal_in >> checkMealID)
                {
//                    cout << checkMealID << " , " << tempReserve.reservationId%100 << endl;
                    if(checkMealID == tempReserve.reservationId%100)
                    {
                        string mealType, reserveDay;
                        tempMeal.mealID = checkMealID;

                        meal_in >> tempMeal.name >> tempMeal.price >> tempMeal.isActive >> mealType >> reserveDay;
                        tempMeal.mealType = stringToMealType(mealType);
                        tempMeal.reserveDay = stringToReserveDay(reserveDay);

                        int checkSideItemlID;
                        ifstream sideItem_in;
                        sideItem_in.open("./data/side_item_data.txt" , ios::in);
                        if(!sideItem_in)
                        {
                            gotoxy(EXCEPTION_LOCATION_X, EXCEPTION_LOCATION_Y);
                            cerr <<"Data not received!";
                            system("pause");
                            exit(0);
                        }
                        while(sideItem_in >> checkSideItemlID)
                        {
                            if(tempMeal.mealID == checkSideItemlID)
                            {
                                //cout << tempMeal.mealID << endl;
                                string tempSideItem;
                                getline(sideItem_in, tempSideItem);
                                sideItem_in.ignore();
                                stringstream ss(tempSideItem);
                                string item;
                                while(ss >> item)
                                {
                                    tempMeal.sideItem.push_back(item);
                                }

//                                for(int j = 0; j < tempMeal.sideItem.size(); j++)
//                                {
//                                    cout << tempMeal.sideItem[j] << endl;
//                                }
                            }
                        }
//                        cout << endl << endl << tempMeal.mealID << tempMeal.name << endl << endl;
                        sideItem_in.close();
                        Meal meal(tempMeal.mealID, tempMeal.name, tempMeal.price, tempMeal.isActive, tempMeal.mealType, tempMeal.reserveDay, tempMeal.sideItem);
                        tempReserve.meal = meal;
                        break;
                    }
                    else
                    {
                        getline(meal_in, trashBin);
                        //meal_in.ignore();
                    }
                }
                meal_in.close();
//                cout << tempReserve.reservationId << endl;
//                cout << tempStudent.studentId << endl;
//                cout << tempReserve.createdAt << endl;
//                cout << toString(tempReserve.status) << endl;
//                cout << Reservation::time_tToString(tempReserve.createdAt) << endl;
                Reservation Reserve(tempReserve.diningHall , tempReserve.meal , tempReserve.reservationId , tempReserve.status , tempReserve.createdAt);
                tempStudent.reserves.push_back(Reserve);
//                for(int i = 0; i < tempStudent.reserves.size(); i++)
//                {
//                    cout << tempStudent.reserves[i].getCreatedAtFormatted() << endl;
//                }
            }
            else
            {

                getline(reserves_in, trashBin);
                reserves_in.ignore();
                //reserves_in.ignore(numeric_limits<streamsize>::max(), '\n');

            }
            //for(int i = 0; i < tempStudent.reserves.size(); i++)
            //{
            //    cout << tempStudent.reserves[i].getReservationId() << endl;
            //}
            //cout << "Hi1" << endl;
        }

        reserves_in.close();
        Student student(tempStudent.userID,
                        tempStudent.name,
                        tempStudent.lastName,
                        tempStudent.hashedPassword,
                        tempStudent.studentId,
                        tempStudent.email,
                        tempStudent.phone,
                        tempStudent.balance,
                        tempStudent.isActive,
                        tempStudent.reserves);
        cout << "hi";
        for(int i = 0; i < student.getReserves().size(); i++)
        {
            cout << student.getReserves()[i].getReservationId() << endl;
        }
        cout << "bye";
        students.push_back(student);
//        getline(student_in, trashBin);

    }
        //cout << "Hi2" << endl;
    student_in.close();

//    showLoginPage();
//    loginOperation(users);






























//    vector<User> users;
//    User e;
//    //e = newUser();
//    users.push_back(e);
//    SetConsoleOutputCP(CP_UTF8);
//    loginOperation(users);




    /*
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



    //vector<DiningHall> DHvector;
    //while(true)
    //{
      //  DiningHall b;
      //  b = newDiningHall(DHvector);
      //  DHvector.push_back(b);
    //}
    //cout << "\n\n" << b.getAddress();



    //vector<Meal> Mvector;
    //while(true)
    //{
       // Meal c;
       // c = newMeal(Mvector);
        //Mvector.push_back(c);
    //}
    //cout << "\n\n" << c.getMealId();




    //Reservation d;
    //d = newReservation(DHvector, Mvector);
   // cout << "\n\n" << d.getCreatedAtFormatted();




    return 0;
}


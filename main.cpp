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

#include "./src/system.cpp"
//#include "./src/additonal_data_types.cpp"

using namespace std;



//------------------------------------------------------------ Main ------------------------------------------------------------

int inputInt();
float inputFloat();
string inputString();
string inputName();
bool inputBool();
void gotoxy(int, int);
Student newStusent();


int main()
{
    Student a;
    a = newStusent();
    cout << "\n\n" << a.getBalance();
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

void cursorStatus(bool status)
{
    HANDLE hStdOut = NULL;
    CONSOLE_CURSOR_INFO curInfo;
    hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    GetConsoleCursorInfo(hStdOut, &curInfo);
    curInfo.bVisible = status;
    SetConsoleCursorInfo(hStdOut, &curInfo);
}

//------------------------- inputInt --------------------------

int inputInt()
{
    string temp;
    getline(cin, temp);
    int j = 0;
    if(!(temp.empty()))
    {

        for(int i = 0; i < temp.length(); ++i)
        {
            if(!(temp[i] >= 48 && temp[i] <= 57))
            {
                j++;
            }
        }
        if(j == 0)
        {
            //cout << endl << temp << endl;
            return stoi(temp);
        }
        else
        {
            throw invalid_argument("");
        }
    }
    else
    {
        throw invalid_argument("");
    }
}

//------------------------ inputFloat -------------------------

float inputFloat()
{
    string temp;
    getline(cin, temp);
    int j = 0, k = 0;
    if(!(temp.empty()))
    {
        for(int i = 0; i < temp.length(); ++i)
        {
            if(!(temp[i] >= 48 && temp[i] <= 57 || temp[i] == 46))
            {
                j++;
            }
            if(temp[i] == 46)
            {
                k++;
            }
        }
        if(j == 0 && k == 0 || k == 1)
        {
            //cout << endl << stof(temp) << endl;
            return stof(temp);
        }
        else
        {
            throw invalid_argument("");
        }
    }
    else
    {
        throw invalid_argument("");
    }
}

//----------------------- inputString -------------------------

string inputString()
{
    string temp;
    getline(cin, temp);
    if(!(temp.empty()))
    {
        //cout << endl << temp << endl;
        return temp;
    }
    else
    {
        throw invalid_argument("");
    }
}

//------------------------ inputName -------------------------

string inputName()
{
    string temp;
    getline(cin, temp);
    int j = 0;
    if(!(temp.empty()))
    {
        for(int i = 0; i < temp.length(); ++i)
        {
            if(!(temp[i] >= 65 && temp[i] <= 90 || temp[i] >= 97 && temp[i] <= 122 || temp[i] == 32))
            {
                j++;
            }
        }
        if(j == 0)
        {
            //cout << endl << temp << endl;
            return temp;
        }
        else
        {
            throw invalid_argument("");
        }
    }
    else
    {
        throw invalid_argument("");
    }
}

//------------------------ inputBool -------------------------

bool inputBool()
{
    string temp;
    getline(cin, temp);
    int j = 0;
    if(!(temp.empty()))
    {
        for(int i = 0; i < temp.length(); ++i)
        {
            if(temp[i] >= 65 && temp[i] <= 90)
            {
                temp[i] += 32;
            }
        }
        if(temp == "true" || temp == "1")
        {
            return true;
        }
        else if(temp == "false" || temp == "0")
        {
            return false;
        }
        else
        {
            throw invalid_argument("");
        }
    }
    else
    {
        throw invalid_argument("");
    }
}

//------------------------ newStusent -------------------------

Student newStusent()
{
    Student tempStudent;
    int counter = 1;
    while(true)
    {
        try
        {
            switch (counter) {
                case 1:
                    cout << "user ID: ";
                    tempStudent.setUserId(inputInt());
                    counter++;
                case 2:
                    cout << "student ID: ";
                    tempStudent.setStudentId(inputString());
                    counter++;
                case 3:
                    cout << "Name: ";
                    tempStudent.setName(inputName());
                    counter++;
                case 4:
                    cout << "Email address: ";
                    tempStudent.setEmail(inputString());
                    counter++;
                case 5:
                    cout << "balance: ";
                    tempStudent.setBalance(inputFloat());
                    counter++;
                case 6:
                    cout << "Is active: (true/false) or (0/1) : ";
                    tempStudent.setIsActive(inputBool());
                    counter++;
            }
            if(counter == 7)
            {
                return tempStudent;
            }
        }
        catch(invalid_argument)
        {
            cerr << "\nThe input is invalid!\nPlease try again...\n\n";
        }
        catch(domain_error)
        {
            cerr << "\nThe number of digits entered is not correct!\nPlease try again...\n\n";
        }
        catch(length_error)
        {
            cerr << "\nThe string size is not appropriate!\nPlease try again...\n\n";
        }
        catch(...)
        {
            cerr << "\nThere was a problem while checking the input!\nPlease try again...\n\n";
        }
    }
}

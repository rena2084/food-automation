#include "../include/user.hpp"
#include <iostream>
#include <vector>
#include <windows.h>

#define EXCEPTION_LOCATION_X 0
#define EXCEPTION_LOCATION_Y 20


using namespace std;

void textColor(int);
void gotoxy(int, int);
int inputInt();
string inputPass();

//---------------------- showLoginPage -----------------------

void showLoginPage()
{
    SetConsoleOutputCP(CP_UTF8);
    textColor(7);
    cout <<"╔═══════════════════════════════════════════════════╗"<< endl;
    cout <<"║                                                   ║"<< endl;
    cout <<"║                                                   ║"<< endl;
    cout <<"║                ";
    textColor(8);
    cout <<"█   █▀█ █▀▀ █ █▄ █";
    textColor(7);
    cout <<"                 ║"<< endl;
    cout <<"║                ";
    textColor(8);
    cout <<"█▄▄ █▄█ █▄█ █ █ ▀█";
    textColor(7);
    cout <<"                 ║"<< endl;
    cout <<"║                                                   ║"<< endl;
    cout <<"║                                                   ║"<< endl;
    cout <<"║───────────────────────────────────────────────────║"<< endl;
    cout <<"║                                                   ║"<< endl;
    cout <<"║  ";
    textColor(15);
    cout <<"\U0001F464User ID:";
    textColor(7);
    cout <<"                                       ║"<< endl;
    cout <<"║                                                   ║"<< endl;
    cout <<"║  ";
    textColor(15);
    cout <<"\U0001F512Password:";
    textColor(7);
    cout <<"                                      ║"<< endl;
    cout <<"║                                                   ║"<< endl;
    cout <<"║  ";
    textColor(8);
    cout <<"Forgot Password?";
    textColor(7);
    cout <<"                                 ║"<< endl;
    cout <<"╚═══════════════════════════════════════════════════╝"<< endl;

    //gotoxy(2,9);
    //cout<<"►";
    //gotoxy(15,11);
}

//---------------------- loginOperation ----------------------

void loginOperation(vector<User> users)
{
    int tempID;
    string tempPass;
    system("cls");
    while(true)
    {
        try
        {
            gotoxy(0,0);
            showLoginPage();
            gotoxy(14,9);
            tempID = inputInt();
            gotoxy(15,11);
            tempPass = inputPass();

            for(int i = 0; i < users.size(); ++i)
            {
                if(users[i].getUserID() == tempID && users[i].getHashedPassword() == tempPass)
                {
                    if(users[i].getType() == "admin")
                    {

                    }
                    else if(users[i].getType() == "student")
                    {

                    }
                    else
                    {
                        throw invalid_argument("\n\nError: Your user type is unknown!\n\n");
                    }
                }
                else
                {
                throw invalid_argument("\n\nError: The ID or Password is incorrect!\n\n");
                }
            }
            break;
        }
        catch(exception &e)
        {
            gotoxy(EXCEPTION_LOCATION_X,EXCEPTION_LOCATION_Y);
            cerr << e.what();

        }
    }

}

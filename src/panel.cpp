#include "../include/panel.hpp"
#include "../include/reservation.hpp"
#include <cstdlib>
#include <windows.h>


void gotoxy(int, int);



//------------------------------------- Panel Class -------------------------------------

//-------------------------- action ---------------------------

void Panel::action(char answer)
{
    switch (answer){
    case 'B':
        system("cls");
        break;
    case 'I':
        system("cls");
        showStudentInfo();
        break;
    case 'M':
        showFoodMenu();
        break;
    case 'A':
        break;
        addReservation();
    case 'R':
        viewReservations();
        break;
    case 'T':
        viewRecentTransactions();
        break;
    }
}

//------------------------- showMenu --------------------------

void Panel::showMenu()
{
    gotoxy(0,0);
    cout <<"╔═══════════════════════════════════════════════════╗"<< endl;
    cout <<"║ Name:                         Balance:            ║"<< endl;
    cout <<"╠═══════════════════════════════════════════════════╣"<< endl;
    cout <<"║ ┌──────────────────────────┐ ┌──────────────────┐ ║"<< endl;
    cout <<"║ │  ▲ Increase balance(B)   │ │    \U000025C6 Info(I)     │ ║"<< endl;
    cout <<"║ └──────────────────────────┘ └──────────────────┘ ║"<< endl;
    cout <<"║ ┌──────────────────────────┐ ┌──────────────────┐ ║"<< endl;
    cout <<"║ │ \U0001F374Table of weeks meal(M) │ │ Add reservation  │ ║"<< endl;
    cout <<"║ └──────────────────────────┘ │       (A)        │ ║"<< endl;
    cout <<"║ ┌──────────────────────────┐ └──────────────────┘ ║"<< endl;
    cout <<"║ │   View reservations(R)   │                      ║"<< endl;
    cout <<"║ └──────────────────────────┘                      ║"<< endl;
    cout <<"║ ┌────────────────────────────┐                    ║"<< endl;
    cout <<"║ │ View Recnt Transactions(T) │                    ║"<< endl;
    cout <<"║ └────────────────────────────┘                    ║"<< endl;
    cout <<"╚═══════════════════════════════════════════════════╝"<< endl;
}

//----------------------- showFoodMenu ------------------------

void Panel::showFoodMenu()
{

}

//---------------------- showStudentInfo ----------------------

void Panel::showStudentInfo()
{

}

//----------------------- checkBalance ------------------------

void Panel::checkBalance()
{

}

//--------------------- viewReservations ----------------------

void Panel::viewReservations()
{

}

//---------------------- addReservation -----------------------

void Panel::addReservation()
{

}

//--------------------- addToShoppingCart ---------------------

void Panel::addToShoppingCart()
{

}

//------------------ confirmShoppingCartItem ------------------

void Panel::confirmShoppingCartItem()
{

}

//---------------------- increaseBalance ----------------------

void Panel::increaseBalance()
{

}

//------------------ viewRecentTransactions -------------------

void Panel::viewRecentTransactions()
{

}

//--------------------- cancelReservation ---------------------

void Panel::cancelReservation(int)
{

}

//--------------------------- exit ----------------------------

void Panel::exit()
{
    std::exit(0);
}

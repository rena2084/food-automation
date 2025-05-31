#ifndef PANEL_HPP
#define PANEL_HPP
#include "reservation.hpp"


//------------- Panel Class -------------
class Panel{
public:
    void action(char);
    void showMenu();
    void showFoodMenu();
    void showStudentInfo();
    void checkBalance();
    void viewReservations();
    void addReservation();
    void addToShoppingCart();
    void confirmShoppingCartItem();
    void increaseBalance();
    void viewRecentTransactions();
    void cancelReservation(int);
    void exit();
};

#endif // PANEL_HPP

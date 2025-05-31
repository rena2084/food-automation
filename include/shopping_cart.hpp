#ifndef SHOPPING_CART_HPP
#define SHOPPING_CART_HPP

#include <vector>
#include "Reservation.hpp"
#include "Transaction.hpp"

class ShoppingCart{
private:
    vector<Reservation> _reservations;
public:
    Transaction confrim();
    void addReservation(Reservation reservation);
    void removeReservation(int ID);
    void viewShoppingCartItems();
    void clear();
    vector<Reservation> getReservation()const;
};


#endif // SHOPPING_CART_HPP

#ifndef ADMIN_HPP
#define ADMIN_HPP
#include "user.hpp"

class Admin : public User{
public:
    void print()const;
    string getType();
};

#endif // ADMIN_HPP

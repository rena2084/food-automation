#ifndef USER_HPP
#define USER_HPP
#include <iostream>
#include <string.h>
using namespace std;

class User{
private:
    unsigned int _userID;
    string _name;
    string _lastName;
    string _hashedPassword;

public:
    User(unsigned int = 00000000, string = "Unknown", string  = "Unknown", string  = "12345678");
    virtual void print()const;
    virtual string getType();

    //----- setters -----
    void setUserID(unsigned int);
    void setName(string);
    void setLastName(string);
    void setHashedPassword(string);


    //----- getters -----
    int getUserID()const;
    string getName()const;
    string getLastName()const;
    string getHashedPassword()const;



};


#endif // USER_HPP

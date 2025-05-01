#ifndef DINING_HALL_H
#define DINING_HALL_H
#include <string>
using namespace std;


//---------- DiningHall Class -----------
class DiningHall{
private:
    unsigned int _hallId;
    string _name;
    string _address;
    int _capacity;
public:
    DiningHall(unsigned int = 120004, string = "University", string = "...", unsigned int = 200);
    void print()const;

    //----- setters -----
    void setHallId(unsigned int);
    void setName(string);
    void setAddress(string);
    void setCapacity(unsigned int);

    //----- getters -----
    unsigned int getHallId()const;
    string getName()const;
    string getAddress()const;
    unsigned int getCapacity()const;
};


#endif // DINING_HALL_H

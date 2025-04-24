#ifndef DINING_HALL_H
#define DINING_HALL_H
using namespace std;


//---------- DiningHall Class -----------
class DiningHall{
private:
    unsigned int _hall_id;
    string _name;
    string _address;
    int _capacity;
public:
    DiningHall(unsigned int = 0, string = "University", string = "...", int = 200);
    void print()const;

    //----- setters -----
    void setHallId(unsigned int);
    void setName(string);
    void setAddress(string);
    void setCapacity(int);

    //----- getters -----
    int getHallId()const;
    string getName()const;
    string getAddress()const;
    int getCapacity()const;
};


#endif // DINING_HALL_H

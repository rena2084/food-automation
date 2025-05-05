#include "../include/user.hpp"

int inputInt();
string inputString();
string inputPass();

//------------------------------------- User Class --------------------------------------


//-------------------- setters --------------------
void User::setUserID(unsigned int userID)
{
    _userID = userID;
}
void User::setName(string name)
{
    if(name.length() >= 3 && name.length() <= 20)
    {
        int j = 0;
        for(int i = 0; i < name.length(); ++i)
        {
            if(!(name[i] >= 65 && name[i] <= 90 || name[i] >= 97 && name[i] <= 122 || name[i] == 32))
            {
                j++;
            }
        }
        if(j == 0)
        {
            _name = name;
        }
        else
        {
            throw invalid_argument("\n\nError: The User's name must consist only of letters or space characters!\n\n");
        }
    }
    else
    {
        throw length_error("\n\nError: Name length is not allowed!\n\n");
    }
}
void User::setLastName(string lastName)
{
    if(lastName.length() >= 3 && lastName.length() <= 20)
    {
        int j = 0;
        for(int i = 0; i < lastName.length(); ++i)
        {
            if(!(lastName[i] >= 65 && lastName[i] <= 90 || lastName[i] >= 97 && lastName[i] <= 122 || lastName[i] == 32))
            {
                j++;
            }
        }
        if(j == 0)
        {
            _lastName = lastName;
        }
        else
        {
            throw invalid_argument("\n\nError: The User's last name must consist only of letters or space characters!\n\n");
        }
    }
    else
    {
        throw length_error("\n\nError: Last name length is not allowed!\n\n");
    }
}
void User::setHashedPassword(string hashedPassword)
{
    _hashedPassword = hashedPassword;
}

//-------------------- getters --------------------
int User::getUserID()const
{
    return _userID;
}
string User::getName()const
{
    return _name;
}
string User::getLastName()const
{
    return _lastName;
}
string User::getHashedPassword()const
{
    return _hashedPassword;
}

//--------------------------- print ---------------------------

void User::print()const
{
    cout << "User ID: " << getUserID() << endl;
    cout << "Name: " << getName() << endl;
    cout << "Last name: " << getLastName() << endl;
    cout << "Password: " << getHashedPassword() << endl;
}

//-------------------------- getType --------------------------

string User::getType()
{
    return "unknown";
}

//-------------------------- newUser --------------------------

User newUser()
{
    User tempU;
    int counter = 1;
    while(true)
    {
        try
        {
            switch (counter) {
                case 1:
                    cout << "User ID: ";
                    tempU.setUserID(inputInt());
                    counter++;
                case 2:
                    cout << "Name: ";
                    tempU.setName(inputString());
                    counter++;
                case 3:
                    cout << "Last name: ";
                    tempU.setLastName(inputString());
                    counter++;
                case 4:
                    cout << "Password: ";
                    tempU.setHashedPassword(inputPass());
                    counter++;
            }
            if(counter == 5)
            {
                cout << tempU.getHashedPassword();
                return tempU;
            }
        }
        catch(exception &e)
        {
            cerr << e.what();
        }
    }
}

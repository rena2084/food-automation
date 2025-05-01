#include <iostream>

using namespace std;

//--------------------- inputUnsignedInt ----------------------

int inputUnsignedInt()
{
    string temp;
    getline(cin, temp);
    int j = 0;
    if(!(temp.empty()))
    {
        if(temp.length() <= 8)
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
                throw invalid_argument("\n\nError: The field must contain only numbers\n\n");
            }
        }
        else
        {
            throw domain_error("\n\nError: The number of digits exceeds the allowed limit!\n\n");
        }
    }
    else
    {
        throw invalid_argument("\n\nError: Field cannot be empty. Please provide a valid input.\n\n");
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
        if(j == 0)
        {
            if(k == 0 || k == 1)
            {
                //cout << endl << stof(temp) << endl;
                return stof(temp);
            }
            else
            {
                throw invalid_argument("\n\nError: The numer entered is invalid!\n\n");
            }
        }
        else
        {
            throw invalid_argument("\n\nError: The field must contain only numbers\n\n");
        }
    }
    else
    {
        throw invalid_argument("\n\nError: Field cannot be empty. Please provide a valid input.\n\n");
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
        throw invalid_argument("\n\nError: Field cannot be empty. Please provide a valid input.\n\n");
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
            throw invalid_argument("\n\nError: The entered value is invalid!\n\n");
        }
    }
    else
    {
        throw invalid_argument("\n\nError: Field cannot be empty. Please provide a valid input.\n\n");
    }
}

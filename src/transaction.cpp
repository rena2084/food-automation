#include "../include/transaction.hpp"


void gotoxy(int, int);

//---------------------------------- Transaction Class ----------------------------------

Transaction::Transaction(int transationID, string trakingCode, float amount, TransactionType type, TransactionStatus status, time_t createdAt)
{
    try
    {
        setTransationID(transationID);
        setTrakingCode(trakingCode);
        setAmount(amount);
        setType(type);
        setStatus(status);
        setCreatedAt(createdAt);
    }
    catch(exception &e)
    {
        gotoxy(EXCEPTION_LOCATION_X,EXCEPTION_LOCATION_Y);
        cerr << e.what();
    }

}

//-------------------- setters --------------------
void Transaction::setTransationID(int transationID)
{
    _transationID = transationID;
}
void Transaction::setTrakingCode(string trakingCode)
{
    _trakingCode = trakingCode;
}
void Transaction::setAmount(float amount)
{
    _amount = amount;
}
void Transaction::setType(TransactionType type)
{
    _type = type;
}
void Transaction::setStatus(TransactionStatus status)
{
    _status = status;
}
void Transaction::setCreatedAt(time_t createdAt)
{
    _createdAt = createdAt;
}

//-------------------- getters --------------------
int Transaction::getTransationID()
{
    return _transationID;
}
string Transaction::getTrakingCode()
{
    return _trakingCode;
}
float Transaction::getAmount()
{
    return _amount;
}
TransactionType Transaction::getType()
{
    return _type;
}
TransactionStatus Transaction::getStatus()
{
    return _status;
}
time_t Transaction::getCreatedAt()
{
    return _createdAt;
}

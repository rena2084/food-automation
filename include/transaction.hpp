#ifndef TRANSACTION_HPP
#define TRANSACTION_HPP

#include <iostream>
#include <time.h>
#include "transaction_type.hpp"
#include "transaction_status.hpp"


#define EXCEPTION_LOCATION_X 0
#define EXCEPTION_LOCATION_Y 20

using namespace std;


class Transaction{
private:
    int _transationID;
    string _trakingCode;
    float _amount;
    TransactionType _type;
    TransactionStatus _status;
    time_t _createdAt;
public:
    Transaction(int = 0, string = "100001", float = 15000, TransactionType = TransactionType::PAYMENT, TransactionStatus = TransactionStatus::PENDING, time_t = time(nullptr));

    //----- setters -----
    void setTransationID(int);
    void setTrakingCode(string);
    void setAmount(float);
    void setType(TransactionType);
    void setStatus(TransactionStatus);
    void setCreatedAt(time_t);


    //----- getters -----
    int getTransationID();
    string getTrakingCode();
    float getAmount();
    TransactionType getType();
    TransactionStatus getStatus();
    time_t getCreatedAt();


};


#endif // TRANSACTION_HPP

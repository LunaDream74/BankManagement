#include <iostream>
#include "Loan.h"
using namespace std;

int Loan::countId = 0;

Loan::Loan(){
    id = countId;
    countId++;
    type = "Undefined";
    accountId = 0;
    customerId = 0;
    money = 0;
}

Loan::Loan(string newType, int AccountId, int CustomerId, int moneyLoaning){
    id = countId;
    countId;
    type = newType;
    accountId = AccountId;
    customerId = CustomerId;
    money = moneyLoaning;
}
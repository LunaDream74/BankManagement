#include <iostream>
#include "Loan.h"
using namespace std;

int Loan::countId = 1;

Loan::Loan(){
    id = countId++;
    type = "Undefined";
    accountId = 0;
    customerId = 0;
    money = 0;
}

Loan::Loan(string newType, int AccountId, int CustomerId, int moneyLoaning){
    id = countId++;
    type = newType;
    accountId = AccountId;
    customerId = CustomerId;
    money = moneyLoaning;
}

int Loan::getLoanId(){
    return id;
}

int Loan::getMoney(){
    return money;
}

int Loan::getAccountId(){
    return accountId;
}

string Loan::getLoanType(){
    return type;
}

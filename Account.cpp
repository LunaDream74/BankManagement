#include <iostream>
#include "Account.h"
using namespace std;

int Account::countId = 1;

Account::Account(){
    id = countId++;
    customerId = 0;
    money = 0;
}

Account::~Account(){}

Account::Account(int newCustomerId, int moneyAdded){
    id = countId++;
    customerId = newCustomerId;
    money = moneyAdded;
}

int Account::getAccountId(){
    return id;
}

int Account::getMoney(){
    return money;
}

void Account::retrieveMoney(int moneyRetrieve){
    money -= moneyRetrieve;
}

void Account::addMoney(int moneyAdd){
    money += moneyAdd;
}
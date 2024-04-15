#include "CreditCard.h"
#include <iostream>

CreditCard::CreditCard(){
    Loan("", accountId, customerId, money);
}

CreditCard::CreditCard(int nAccountId, int nCustomerId, int moneyLoan){
    Loan("", nAccountId, nCustomerId, moneyLoan);
}

CreditCard::~CreditCard(){}
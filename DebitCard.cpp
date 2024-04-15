#include "DebitCard.h"
#include <iostream>

DebitCard::DebitCard(){
    Account(customerId, money);
}

DebitCard::DebitCard(int nCustomerId, int moneyAdd){
    Account(nCustomerId, moneyAdd);
}

DebitCard::~DebitCard(){}
#ifndef CREDITCARD_H
#define CREDITCARD_H
#include "Loan.h"

class CreditCard : public Loan {
    public:
        CreditCard();
        CreditCard(int, int, int);
        virtual ~CreditCard();
};

#endif
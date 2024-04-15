#ifndef DEBITCARD_H
#define DEBITCARD_H
#include "Account.h"

class DebitCard : public Account {
    public:
        DebitCard();
        DebitCard(int, int);
        virtual ~DebitCard();
};

#endif
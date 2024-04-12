#ifndef LOAN_H
#define LOAN_H
#include <iostream>
#include <string>
using namespace std;
class Loan {
    protected:
        int id, accountId, customerId, money;
        string type;
    public:
        static int countId;

        Loan();

        Loan(string, int, int, int);
        int getLoanId();
        int getMoney();
        int getAccountId();
        string getLoanType();
};

#endif
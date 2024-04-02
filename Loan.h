#ifndef LOAN_H
#define LOAN_H
#include <iostream>
#include <string>
using namespace std;
class Loan {
    public:
        static int countId;
        int id, accountId, customerId, money;
        string type;

        Loan();

        Loan(string, int, int, int);
};

#endif
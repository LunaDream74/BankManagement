#ifndef CUSTOMER_H
#define CUSTOMER_H
#include "Account.h"
#include "Loan.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Customer{
    public:
        static int countId;
        int id, phoneNo;
        string name, address;
        vector<Account> accounts;
        vector<Loan> loans;

        Customer();

        Customer(string, string, int);

        void generalInquiry();

        void depositMoney(int money, int accountId);

        int withdrawMoney(int money, int accountId);

        void openAccount(int customerId, int money);

        bool closeAccount(int accountId);

        bool applyForLoan(string type, int accountId);
};

#endif
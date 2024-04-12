#ifndef BANK_H
#define BANK_H
#include "Teller.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Bank {
    private:
        static int countbankId;
        int bankId;
        string name, location;
    public:
        vector<Teller> tellers;
        Bank();

        Bank(string, string);

        void bankStart();
        void bankGUI();

        void addTeller(Teller teller);

        void newCustomer();
        void addCustomer();

        int findTeller(int tellerId);

        int inputCustomerId();
        int inputTellerId();

        void validMoney(int money);
        void validTeller(int tellerId);
        void validCustomer(int customerId, int tellerIndex);
        void validAccount(int accountId, int tellerIndex, int customerIndex);
};

#endif
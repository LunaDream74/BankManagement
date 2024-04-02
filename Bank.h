#ifndef BANK_H
#define BANK_H
#include "Teller.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Bank {
    public:
        static int countbankId;
        int bankId;
        string name, location;
        vector<Teller> tellers;

        Bank();

        Bank(string, string);

        void bankStart();

        void bankGUI();

        void addTeller(Teller teller);

        void newCustomer();

        void addCustomer();

        int findTeller(int tellerId);
};

#endif
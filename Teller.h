#ifndef TELLER_H
#define TELLER_H
#include "Customer.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Teller {
    private:
        int id;
        string name;
    public:
        vector<Customer> customers;
        static int countId;

        Teller();

        Teller(string);

        void collectMoney(int customerId , int accountId, int money);
        bool openAccount(int customerId, int money);
        int closeAccount(int customerId, int accountId);
        bool loanRequest(int customerId,int accountId, int loanMoney, string type);
        void provideInfo(int customerId);

        int findAccount(int customerId, int accountId);
        int findCustomer(int customerId);

        void addCustomerToTeller(Customer customer);

        int getTellerId();
        string getTellerName();

};

#endif
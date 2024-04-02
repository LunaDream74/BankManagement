#ifndef ACCOUNT_H
#define ACCOUNT_H


class Account {
    public:
        static int countId;
        int id, customerId, money;
        //constructor
        Account();
        
        Account(int, int);
};

#endif
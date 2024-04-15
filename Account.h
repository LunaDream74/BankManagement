#ifndef ACCOUNT_H
#define ACCOUNT_H


class Account {
    protected:
        int id, customerId, money;
    public:
        static int countId;
        //constructor
        Account();
        //destructor
        ~Account();
        
        Account(int, int);

        int getAccountId();
        int getMoney();
        
        void retrieveMoney(int money);
        void addMoney(int money);
};

#endif
#include <iostream>
#include "Customer.h"
#include "Account.h"
using namespace std;

int Customer::countId = 0;

Customer::Customer(){
    id = countId++;
    name = "No name";
    address = "Don't know";
    phoneNo = 0;
}

Customer::Customer(string newName, string newAddress, int newPhoneNo){
    id = countId++;
    name = newName;
    address =  newAddress;
    phoneNo = newPhoneNo;
}

void Customer::generalInquiry(){
    cout << "Customer's name: " << name << endl;
    cout << "Customer's address: " << address << endl;
    cout << "Customer's phone number: " << phoneNo << endl;
    for (auto &a1 : accounts){
        cout << "Customer's account id: " << a1.getAccountId() << endl;
        cout << "Balance: " << a1.getMoney() << endl;
        for (auto &l1 : loans){
            if (l1.getAccountId() == a1.getAccountId()){
                cout << "Customer's loan id: " << l1.getLoanId() << endl;
                cout << "Loan type: " << l1.getLoanType() << endl;
                cout << "Debt: " << l1.getMoney() << endl;
            }
        }
    }    
}

void Customer::depositMoney(int moneyDeposited, int accountId){
    cout << "Successfully deposited " << moneyDeposited << "VND to this account\n";
}

int Customer::withdrawMoney(int moneyWithdrawing, int accountId){
    //check if money withdrawing is under balance in account
    if (moneyWithdrawing <= accounts[accountId - 1].getMoney()){
        cout << "Withdrawing " << moneyWithdrawing << "VND\n";
        accounts[accountId - 1].retrieveMoney(moneyWithdrawing);
    }
    //not enough
    else {
        cout << "Not enough money in account to withdraw.\n";
    }
    return 0;
}

void Customer::openAccount(int customerId, int moneyAdded){
    cout << "Successfully opened an account!!\n";
}

bool Customer::closeAccount(int accountId){
    //ask customer if they want to close account
    cout << "Are you sure you want to close this account?" << endl;
    cout << "1. Yes\n2. No\n";
    int choice;
    cin >> choice;
    if (choice == 1) {
        //check if there's still money in account
        if (accounts[accountId - 1].getMoney()){
            cout << "There's still money in this account.\n";
            withdrawMoney(accounts[accountId - 1].getMoney(), accountId);
        }
        return true;
    }
    else{
        cout << "Account will not be close.";
        return false;
    }
    
}

bool Customer::applyForLoan(string type, int accountId){
    //check if correct loan type (ie "Trust" and "Mortgage")
    if (type == "trust" || type == "mortgage" || type == "Trust" || type == "Mortgage")
        return true;
    else
        return false;
}

int Customer::getId(){
    return id;
}

string Customer::getName(){
    return name;
}

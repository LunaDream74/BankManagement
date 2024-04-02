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
        cout << "Customer's account id: " << a1.id << endl;
        cout << "Balance: " << a1.money << endl;
    }
    for (auto &l1 : loans){
        cout << "Customer's loan id: " << l1.id << endl;
        cout << "Debt: " << l1.money << endl;
    }
}

void Customer::depositMoney(int moneyDeposited, int accountId){
    cout << "Successfully deposited " << moneyDeposited << "VND to this account\n";
}

int Customer::withdrawMoney(int moneyWithdrawing, int accountId){
    //check if money withdrawing is under balance in account
    if (moneyWithdrawing <= accounts[accountId - 1].money){
        cout << "Withdrawing " << moneyWithdrawing << "VND\n";
        accounts[accountId - 1].money -= moneyWithdrawing;
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
    cout << "1. Yes\n 2. No\n";
    int choice;
    cin >> choice;
    if (choice == 1) {
        //check if there's still money in account
        if (accounts[accountId - 1].money){
            cout << "There's still money in this account.\n";
            withdrawMoney(accounts[accountId - 1].money, accountId);
        }
        return true;
    }
    else
        return false;
}

bool Customer::applyForLoan(string type, int accountId){
    //check if correct loan type (ie "Trust" and "Mortgage")
    if (type == "trust" || type == "mortgage" || type == "Trust" || type == "Mortgage")
        return true;
    else
        return false;
}
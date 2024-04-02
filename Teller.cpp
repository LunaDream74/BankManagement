#include <iostream>
#include "Teller.h"
#include "Customer.h"
#include "Account.h"

using namespace std;

int Teller::countId = 0;

Teller::Teller(){
    id = countId++;
    name = "No name";
}

Teller::Teller(string newName){
    id = countId++;
    name = newName;
}

void Teller::addCustomerToTeller(Customer customer){
    //add customer to customer list
    customers.push_back(customer);
    cout << "Successfully added customer: " << customer.name << " under teller: " << name << endl;
}

void Teller::collectMoney(int customerId , int accountId, int moneyCollected){
    int customerPosition = findCustomer(customerId);
    int accountPosition = findAccount(customerId,accountId);
    Customer *currentCustomer = &customers[customerPosition];
    //add money collected to customer's account
    (*currentCustomer).accounts[accountPosition].money += moneyCollected;
}

bool Teller::openAccount(int customerId, int moneyAdded){
    int customerPosition = findCustomer(customerId);
    Customer *currentCustomer = &customers[customerPosition];
    //create new account and add to list
    (*currentCustomer).accounts.push_back(Account(customerId, moneyAdded));
    cout << "Successfully added an account under customer: " << (*currentCustomer).name << endl;
    cout << "Your new account's ID: " << (*currentCustomer).accounts.size()<< endl;
    return true;
}

int Teller::closeAccount(int customerId, int accountId){
    int customerPosition = findCustomer(customerId);
    int accountPosition = findAccount(customerId, accountId);
    customers[customerPosition].accounts.erase(customers[customerPosition].accounts.begin() + accountPosition);
    return 0;
}

bool Teller::loanRequest(int customerId, int accountId, int moneyLoaning, string type){
    int customerPosition = findCustomer(customerId);
    int accountPosition = findAccount(customerId,accountId);
    //check if customer wanted to loan
    Customer *currentCustomer = &customers[customerPosition];
    if((*currentCustomer).applyForLoan(type,accountId)){
        //create loan
        Loan tempLoan = Loan(type, accountId, customerId, moneyLoaning);
        //add loan to list
        (*currentCustomer).loans.push_back(tempLoan);
        cout << "You've successfully opened a loan.\n";
        return true;
    }
    else
        //wrong type
        cout << "Please type 'Trust' or 'Mortgage'.\n";
        return false;
}

//get info from customer
void Teller::provideInfo(int customerId){
    int customerPosition = findCustomer(customerId);
    //get information from customer
    Customer *current = &customers[customerPosition];
    (*current).generalInquiry();
}

//find index of account
int Teller::findAccount(int customerId, int accountId){
    int accountPosition = 0;
    int customerPosition = findCustomer(customerId);
    int n = customers[customerPosition].accounts.size();
    while (accountPosition < n){
        if (customers[customerPosition].accounts[accountPosition].id == accountId)
            return accountPosition;
        accountPosition++;
    }
    return accountPosition - 1;
}

//find index of customer
int Teller::findCustomer(int customerId){
    int customerPosition = 0;
    int n = customers.size();
    while (customerPosition < n){
        if (customers[customerPosition].id == customerId)
            return customerPosition;
        customerPosition++;
    }
    return customerPosition - 1;
}
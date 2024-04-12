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
    cout << "Successfully added customer: " << customer.getName() << " under teller: " << name << endl;
}

void Teller::collectMoney(int customerId , int accountId, int moneyCollected){
    //get indexes
    int customerIndex = findCustomer(customerId);
    int accountIndex = findAccount(customerId,accountId);

    Customer *currentCustomer = &customers[customerIndex];

    //add money collected to customer's account
    (*currentCustomer).accounts[accountIndex].addMoney(moneyCollected);
}

bool Teller::openAccount(int customerId, int moneyAdded){
    //get customer index
    int customerIndex = findCustomer(customerId);

    Customer *currentCustomer = &customers[customerIndex];

    //create new account and add to list
    (*currentCustomer).accounts.push_back(Account(customerId, moneyAdded));

    cout << "Successfully added an account under customer: " << (*currentCustomer).getName() << endl;
    cout << "Your new account's ID: " << (*currentCustomer).accounts.size()<< endl;
    return true;
}

int Teller::closeAccount(int customerId, int accountId){
    //get indexes
    int customerIndex = findCustomer(customerId);
    int accountIndex = findAccount(customerId, accountId);

    //delete account
    customers[customerIndex].accounts.erase(customers[customerIndex].accounts.begin() + accountIndex);
    return 0;
}

bool Teller::loanRequest(int customerId, int accountId, int moneyLoaning, string type){
    //get indexes
    int customerIndex = findCustomer(customerId);
    int accountIndex = findAccount(customerId,accountId);
    
    Customer *currentCustomer = &customers[customerIndex];

    //check if customer wanted to loan
    if((*currentCustomer).applyForLoan(type,accountId)){
        //create loan
        Loan tempLoan = Loan(type, accountId, customerId, moneyLoaning);

        //add loan to list
        (*currentCustomer).loans.push_back(tempLoan);

        cout << "You've successfully opened a loan.\n";
        return true;
    }
    else{
        //wrong type
        cout << "Please type 'Trust' or 'Mortgage'.\n";
        return false;
    }
}

void Teller::provideInfo(int customerId){
    //get customer index
    int customerIndex = findCustomer(customerId);

    //get information from customer
    Customer *current = &customers[customerIndex];
    (*current).generalInquiry();
}

//find index of account
int Teller::findAccount(int customerId, int accountId){
    int accountIndex = 0;

    //get customer index
    int customerIndex = findCustomer(customerId);

    //get size of account list
    int n = customers[customerIndex].accounts.size();

    while (accountIndex < n){
        if (customers[customerIndex].accounts[accountIndex].getAccountId() == accountId)
            return accountIndex;
        accountIndex++;
    }
    return accountIndex - 1;
}

//find index of customer
int Teller::findCustomer(int customerId){
    int customerIndex = 0;

    //get size of customer list
    int n = customers.size();

    while (customerIndex < n){
        if (customers[customerIndex].getId() == customerId)
            return customerIndex;
        customerIndex++;
    }
    return customerIndex - 1;
}

int Teller::getTellerId(){
    return id;
}

string Teller::getTellerName(){
    return name;
}

// vector<Customer> Teller::getCustomer(){
//     return customers;
// }
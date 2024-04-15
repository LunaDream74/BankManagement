#include <iostream>
#include "Bank.h"
#include "Teller.h"
using namespace std;

int Bank::countbankId = 0;

Bank::Bank(){
    bankId = countbankId;
    countbankId++;
    name = "Bank name";
    location = "Earth";
}

Bank::~Bank(){}

Bank::Bank(string newName, string newLocation){
    bankId = countbankId;
    countbankId++;
    name = newName;
    location = newLocation;
}

void Bank::addTeller(Teller teller){
    //add teller to teller list
    tellers.push_back(teller);
    cout << "Added teller: " << teller.getTellerName() << " to " << name << endl;
}

int Bank::findTeller(int tellerId){
    int tellerIndex = 0;
    int n = tellers.size();
    while (tellerIndex < n){
        if (tellers[tellerIndex].getTellerId() == tellerId)
            return tellerIndex;
        tellerIndex++;
    }
    return tellerIndex - 1;
}

//GUI screen for bank
void Bank::bankGUI(){
    cout << "---------------------------------\n";
    cout << "1. General inquiry\n";
    cout << "2. Deposit money\n";
    cout << "3. Withdraw money\n";
    cout << "4. Open new account\n";
    cout << "5. Close account\n";
    cout << "6. Apply for loan\n";
    cout << "0. Exit\n";
    cout << "---------------------------------\n";

    int choice, customerId, tellerId, accountId;
    int tellerIndex, customerIndex;

    //get option and execute
    cin >> choice;
    switch (choice) {
        //exit
        case 0: {
            cout << "Thank you for using " << name << endl;
            cout << "Have a great day\n";
            break;
        }
        //give information to customer
        case 1: {
            tellerId = inputTellerId();
            validTeller(tellerId);
            tellerIndex = Bank::findTeller(tellerId);

            customerId = inputCustomerId();
            validCustomer(customerId,tellerIndex);

            system("cls");
            tellers[tellerIndex].provideInfo(customerId);
            bankGUI();
            break;
        }
        //deposit money
        case 2: {
            cout << "Please enter amount of money you want to deposit: ";
            int moneyDepositing;
            cin >> moneyDepositing;
            validMoney(moneyDepositing);

            
            tellerId = inputTellerId();
            validTeller(tellerId);
            tellerIndex = Bank::findTeller(tellerId);

            customerId = inputCustomerId();
            validCustomer(customerId,tellerIndex);
            customerIndex = tellers[tellerIndex].findCustomer(customerId);

            cout << "Please enter your account ID you would like to deposit to: \n";
            cin >> accountId;
            validAccount(accountId,tellerIndex,customerIndex);

            system("cls");

            tellers[tellerIndex].customers[customerIndex].depositMoney(moneyDepositing,accountId);
            tellers[tellerIndex].collectMoney(customerId, accountId, moneyDepositing);
            bankGUI();
            break;
        }
        //withdraw money
        case 3: {
            cout << "Please enter amount of money you want to withdraw: ";
            int moneyWithdrawing;
            cin >> moneyWithdrawing;
            validMoney(moneyWithdrawing);

            
            tellerId = inputTellerId();
            validTeller(tellerId);
            tellerIndex = Bank::findTeller(tellerId);

            customerId = inputCustomerId();
            validCustomer(customerId,tellerIndex);
            customerIndex = tellers[tellerIndex].findCustomer(customerId);

            cout << "Please enter your account ID you would like to withdraw from: ";
            cin >> accountId;
            validAccount(accountId,tellerIndex,customerIndex);

            system("cls");

            tellers[tellerIndex].customers[customerIndex].withdrawMoney(moneyWithdrawing, accountId);
            bankGUI();
            break;
        }
        //open new account
        case 4: {
            cout << "Please enter amount of money to open an account: ";
            int moneyAdd;
            cin >> moneyAdd;
            validMoney(moneyAdd);
            
            tellerId = inputTellerId();
            validTeller(tellerId);
            tellerIndex = Bank::findTeller(tellerId);
            
            customerId = inputCustomerId();
            validCustomer(customerId,tellerIndex);
            customerIndex = tellers[tellerIndex].findCustomer(customerId);

            system("cls");

            tellers[tellerIndex].customers[customerIndex].openAccount(customerId, moneyAdd);
            tellers[tellerIndex].openAccount(customerId, moneyAdd);
            bankGUI();
            break;
        }
        //closing account
        case 5: {
            tellerId = inputTellerId();
            validTeller(tellerId);
            tellerIndex = Bank::findTeller(tellerId);

            customerId = inputCustomerId();
            validCustomer(customerId,tellerIndex);
            customerIndex = tellers[tellerIndex].findCustomer(customerId);

            cout << "Please enter your account ID you would like to close: ";
            cin >> accountId;
            validAccount(accountId,tellerIndex,customerIndex);

            system("cls");

            tellers[tellerIndex].customers[customerIndex].closeAccount(accountId);
            tellers[tellerIndex].closeAccount(customerId, accountId);
            bankGUI();
            break;
        }
        //apply for loan
        case 6: {
            tellerId = inputTellerId();
            validTeller(tellerId);
            tellerIndex = Bank::findTeller(tellerId);

            
            customerId = inputCustomerId();
            validCustomer(customerId,tellerIndex);
            customerIndex = tellers[tellerIndex].findCustomer(customerId);

            cout << "Please enter your account ID you would like to get a loan: ";
            cin >> accountId;
            validAccount(accountId,tellerIndex,customerIndex);

            cout << "Please enter what type of loan you would like.  (Trust or Mortgage) ";
            string loanType, temp;
            getline(cin, temp);
            getline(cin, loanType);
            
            cout << "Please enter amount of money you want to loan: ";
            int moneyLoaning;
            cin >> moneyLoaning;
            validMoney(moneyLoaning);

            system("cls");

            tellers[tellerIndex].customers[customerIndex].applyForLoan(loanType, accountId);
            tellers[tellerIndex].loanRequest(customerId, accountId, moneyLoaning, loanType);
            bankGUI();
            break;
        }
        default:
            cout << "Please choose again.\n";
            bankGUI();
    }
}

int Bank::inputCustomerId(){
    int customerId;
    cout << "Please enter your customer ID: ";
    cin >> customerId;
    return customerId;
}

int Bank::inputTellerId(){
    int tellerId;
    cout << "Please enter your assigned teller's ID: ";
    cin >> tellerId;
    return tellerId;
}

//check for negative money input
void Bank::validMoney(int money){
    if (money <= 0){
        cout << "You must enter in amount of money that is larger than 0!!!\n";
        Bank::bankGUI();
    }
}

//check if teller's id is valid
void Bank::validTeller(int tellerId){
    if (tellerId > tellers.size() || tellerId <= 0){
        cout << "Invalid teller id!!!\n";
        Bank::bankGUI();
    }
}

//check if customer's id is valid
void Bank::validCustomer(int customerId, int tellerIndex){
    if (customerId > tellers[tellerIndex].customers.size() || customerId <= 0){
        cout<<"Invalid customer id!!!"<<'\n';
        Bank::bankGUI();
    }
}

//check if account's id is valid
void Bank::validAccount(int accountId, int tellerIndex, int customerIndex){
    if (accountId > tellers[tellerIndex].customers[customerIndex].accounts.size() || accountId <= 0){
        cout<<"Invalid account id!!!"<<'\n';
        Bank::bankGUI();
    }
}

//start
void Bank::bankStart(){
    cout << "------------------------------\n";
    cout << "WELCOME TO " << name << endl;
    Bank::newCustomer();
}

//add new customer
void Bank::addCustomer(){
    string name,address;
    int phoneNumber, tellerId, tellerIndex;

    cout << "Please enter your name: ";
    getline(cin,name);
    cout << "Please enter your address: ";
    getline(cin,address);
    cout << "Please enter your phone number: ";
    cin >> phoneNumber;

    addTeller:
        cout << "Please enter a teller's ID you want to be assigned to (Starts from 1): ";
        cin >> tellerId;
    
    if (tellerId > tellers.size()){
        cout << "Teller doesn't exist. Try again\n";
        //doesn't exit so go back to "addTeller"
        goto addTeller;
    }

    tellerIndex = Bank::findTeller(tellerId);

    tellers[tellerIndex].customers.push_back(Customer(name,address,phoneNumber));
    tellers[tellerIndex].addCustomerToTeller(Customer(name,address,phoneNumber));

    cout << "Successfully registered! Your customer id is "<< tellers[tellerIndex].customers.size() - 1<< endl;
}

void Bank::newCustomer(){
    cout<<"Are you a new customer? (Yes: 1 | No: 0 | Exit: -1): ";

    int choice; string temp;

    cin >> choice; getline(cin,temp);

    switch (choice)
    {
        case 0:
        //continue as normal
            Bank::bankGUI();   
            Bank::newCustomer(); 
            break;
        
        case 1:
        //add customer
            Bank::addCustomer();
            Bank::bankGUI();
            Bank::newCustomer();
            break;

        case -1:
        //exit
            cout<<"Thank you and see you!"<<'\n';
            break;

        //for when you're dumb
        default:
            cout<<"Invalid option!!! Please select again!"<<'\n';
            Bank::newCustomer();
            break;
    }
}


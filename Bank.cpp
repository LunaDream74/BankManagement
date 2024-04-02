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

Bank::Bank(string newName, string newLocation){
    bankId = countbankId;
    countbankId++;
    name = newName;
    location = newLocation;
}

void Bank::addTeller(Teller teller){
    //add teller to teller list
    tellers.push_back(teller);
    cout << "Added teller: " << teller.name << " to " << name << endl;
}

int Bank::findTeller(int tellerId){
    int tellerPosition = 0;
    int n = tellers.size();
    while (tellerPosition < n){
        if (tellers[tellerPosition].id == tellerId)
            return tellerPosition;
        tellerPosition++;
    }
    return tellerPosition - 1;
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

    //get option and execute
    int choice, customerId, tellerId, accountId;
    int tellerPosition, customerPosition;
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
            cout << "Please enter your customer ID: ";
            cin >> customerId;

            cout << "Please enter your assigned teller's ID: ";
            cin >> tellerId;

            tellerPosition = Bank::findTeller(tellerId);

            if (tellerId > tellers.size()){
                cout << "Invalid teller id!!!\n";
                Bank::bankGUI();
            }

            if (customerId > tellers[tellerPosition].customers.size())
            {
                cout<<"Invalid customer id!!!"<<'\n';
                Bank::bankGUI();
                break;
            }
            system("cls");
            tellers[tellerPosition].provideInfo(customerId);
            bankGUI();
            break;
        }
        //deposit money
        case 2: {
            cout << "Please enter amount of money you want to deposit: ";
            int moneyDepositing;
            cin >> moneyDepositing;

            cout << "Please enter your customer ID: ";
            cin >> customerId;
            
            cout << "Please enter your assigned teller's ID: ";
            cin >> tellerId;

            if (tellerId > tellers.size()){
                cout << "Invalid teller id!!!\n";
                Bank::bankGUI();
            }

            tellerPosition = Bank::findTeller(tellerId);
            customerPosition = tellers[tellerPosition].findCustomer(customerId);

            if (customerId > tellers[tellerPosition].customers.size())
            {
                cout<<"Invalid customer id!!!"<<'\n';
                Bank::bankGUI();
                break;
            }
            cout << "Please enter your account ID you would like to deposit to: \n";
            cin >> accountId;

            system("cls");

            tellers[tellerPosition].customers[customerPosition].depositMoney(moneyDepositing,accountId);
            tellers[tellerPosition].collectMoney(customerId, accountId, moneyDepositing);
            bankGUI();
            break;
        }
        //withdraw money
        case 3: {
            cout << "Please enter amount of money you want to withdraw: ";
            int moneyWithdrawing;
            cin >> moneyWithdrawing;

            cout << "Please enter your customer ID: ";
            cin >> customerId;

            cout << "Please enter your assigned teller's ID: ";
            cin >> tellerId;

            if (tellerId > tellers.size()){
                cout << "Invalid teller id!!!\n";
                Bank::bankGUI();
            }

            tellerPosition = Bank::findTeller(tellerId);
            customerPosition = tellers[tellerPosition].findCustomer(customerId);

            if (customerId > tellers[tellerPosition].customers.size())
            {
                cout<<"Invalid customer id!!!"<<'\n';
                Bank::bankGUI();
                break;
            }

            cout << "Please enter your account ID you would like to withdraw from: ";
            cin >> accountId;

            system("cls");

            tellers[tellerPosition].customers[customerPosition].withdrawMoney(moneyWithdrawing, accountId);
            bankGUI();
            break;
        }
        //open new account
        case 4: {
            cout << "Please enter amount of money to open an account: ";
            int moneyAdd;
            cin >> moneyAdd;

            cout << "Please enter your customer ID: ";
            cin >> customerId;

            cout << "Please enter your assigned teller's ID: ";
            cin >> tellerId;

            if (tellerId > tellers.size()){
                cout << "Invalid teller id!!!\n";
                Bank::bankGUI();
            }
            
            tellerPosition = Bank::findTeller(tellerId);
            customerPosition = tellers[tellerPosition].findCustomer(customerId);

            if (customerId > tellers[tellerPosition].customers.size())
            {
                cout<<"Invalid customer id!!!"<<'\n';
                Bank::bankGUI();
                break;
            }

            system("cls");

            tellers[tellerPosition].customers[customerPosition].openAccount(customerId, moneyAdd);
            tellers[tellerPosition].openAccount(customerId, moneyAdd);
            bankGUI();
            break;
        }
        //closing account
        case 5: {
            cout << "Please enter your customer ID: ";
            cin >> customerId;

            cout << "Please enter your assigned teller's ID: ";
            cin >> tellerId;

            if (tellerId > tellers.size()){
                cout << "Invalid teller id!!!\n";
                Bank::bankGUI();
            }

            tellerPosition = Bank::findTeller(tellerId);
            customerPosition = tellers[tellerPosition].findCustomer(customerId);

            if (customerId > tellers[tellerPosition].customers.size())
            {
                cout<<"Invalid customer id!!!"<<'\n';
                Bank::bankGUI();
                break;
            }

            cout << "Please enter your account ID you would like to close: ";
            cin >> accountId;

            system("cls");

            tellers[tellerPosition].customers[customerPosition].closeAccount(accountId);
            tellers[tellerPosition].closeAccount(customerId, accountId);
            bankGUI();
            break;
        }
        //apply for loan
        case 6:{
            cout << "Please enter your customer ID: ";
            cin >> customerId;

            cout << "Please enter your assigned teller's ID: ";
            cin >> tellerId;

            if (tellerId > tellers.size()){
                cout << "Invalid teller id!!!\n";
                Bank::bankGUI();
            }

            tellerPosition = Bank::findTeller(tellerId);
            customerPosition = tellers[tellerPosition].findCustomer(customerId);

            if (customerId > tellers[tellerPosition].customers.size())
            {
                cout<<"Invalid customer id!!!"<<'\n';
                Bank::bankGUI();
                break;
            }

            cout << "Please enter your account ID you would like to get a loan: ";
            cin >> accountId;

            cout << "Please enter what type of loan you would like.  (Trust or Mortgage) ";
            string loanType;
            getline(cin,loanType);
            cout << "Please enter amount of money you want to loan:";
            int moneyLoaning;
            cin >> moneyLoaning;

            system("cls");

            tellers[tellerPosition].customers[customerPosition].applyForLoan(loanType, accountId);
            tellers[tellerPosition].loanRequest(customerId, accountId, moneyLoaning, loanType);
            bankGUI();
            break;
        }
        default:
            cout << "Please choose again.\n";
            bankGUI();
    }
}

//start
void Bank::bankStart(){
    cout << "------------------------------\n";
    cout << "WELCOME TO " << name << endl;
    Bank::newCustomer();
}

void Bank::addCustomer(){
    string name,address;
    int phoneNumber, tellerId, tellerPosition;

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
        goto addTeller;
    }

    tellerPosition = Bank::findTeller(tellerId);

    tellers[tellerPosition].customers.push_back(Customer(name,address,phoneNumber));
    tellers[tellerPosition].addCustomerToTeller(Customer(name,address,phoneNumber));

    cout << "Successfully registered! Your customer id is "<< tellers[tellerPosition].customers.size() - 1 << endl;
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
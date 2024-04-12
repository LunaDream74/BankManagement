#include <iostream>
#include "Customer.h"
#include "Bank.h"
#include "Loan.h"
#include "Teller.h"
#include "Account.h"
using namespace std;

int main(){
    //initialize list of banks
    Bank bankList[] = {Bank("Bank of America","USA")};

    //initialize list of tellers
    Teller tellerList[] = {Teller("Andrew")};

    //loading phase
    cout << "===========LOADING============\n";
    bankList[0].addTeller(tellerList[0]);

    //run bank
    bankList[0].bankStart();
    return 0;
}

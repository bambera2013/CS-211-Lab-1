// Stephania Rey
// Lab 1 Assignment

#include <iostream>
#include <fstream>
#include <string>
#include "stdlib.h"   // For use with atof function
#include <iomanip>    //For use of formating 2 decimal places

using namespace std;  // for cout

string accNum, accType;
double startBal, deposit, withdraw, endBal;
string startBal_s, deposit_s, withdraw_s, endBal_s;                     // string variable for each line item
const double PREM_INT = 1.05, CHOICE_INT = 1.03, BASIC_INT = 1.01;      // constants for interest rates

int main(){
    ofstream output;                        // Declares output file
    output.open("accountOut.txt");          // name output file "output" and open
    output << "Account   Type \t      StartBalance \t Deposit \t Withdrawal   EndBalance\n";
    output << "--------------------------------------------------------------------------------\n";

    ifstream infile("accounts.txt");                                     // reads file as an input
    while (infile >> accNum >> accType >> startBal_s >> deposit_s >> withdraw_s){ // assigns each element of each line to string variables
        startBal = atof(startBal_s.c_str());                             // converts string variables to double for end balance calculation
        deposit = atof(deposit_s.c_str());
        withdraw = atof(withdraw_s.c_str());

        if (accType == "Premium")                                       // calculates using interest rates depending on account type
            endBal = (startBal + deposit - withdraw)* PREM_INT;

        else if (accType == "Choice")
            endBal = (startBal + deposit - withdraw)* CHOICE_INT;

        else
            endBal = (startBal + deposit - withdraw)* BASIC_INT;

        output << accNum << "   " << accType << "  \t" << startBal_s << " \t " << deposit_s << "\t "  << withdraw_s  << "\t" << fixed << setprecision(2) << endBal << endl;
}
infile.close();
output.close();
return 0;
}

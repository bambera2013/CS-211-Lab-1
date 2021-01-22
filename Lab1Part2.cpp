// Stephania Rey
// Lab 1 Part 2 Assignment

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <iomanip>    //For use of formating 2 decimal places

using namespace std;  // for cout

double getEndBalance(double startBal, double deposit, double withdraw, double interestRate);  // Function prototype

const double PREM_INT = 1.05, CHOICE_INT = 1.03, BASIC_INT = 1.01;      // constants for interest rates

int main(){
string accNum, accType;
double startBal, deposit, withdraw, endBal;
string startBal_s, deposit_s, withdraw_s, endBal_s;                     // string variable for each line item

    ofstream output;                        // Declares output file
    output.open("accountOut.txt");          // name output file "output" and open
    output << "Account   Type \t      StartBalance \t Deposit \t Withdrawal   EndBalance\n";
    output << "--------------------------------------------------------------------------------\n";
    cout << "Account   Type \t      StartBalance \t Deposit \t Withdrawal   EndBalance\n";
    cout << "--------------------------------------------------------------------------------\n";

    ifstream infile("accounts.txt");                                     // reads file as an input
    while (infile >> accNum >> accType >> startBal_s >> deposit_s >> withdraw_s){ // assigns each element of each line to string variables
        stringstream ss; stringstream tt; stringstream uu;
        ss << startBal_s; ss >> startBal;
        tt << deposit_s; tt >> deposit;
        uu << withdraw_s; uu >> withdraw;

        if (accType == "Premium")                                       // calculates using interest rates depending on account type
          endBal = getEndBalance(startBal, deposit, withdraw, PREM_INT);

        else if (accType == "Choice")
          endBal = getEndBalance (startBal, deposit, withdraw, CHOICE_INT);

        else
          endBal = getEndBalance (startBal, deposit, withdraw,  BASIC_INT);

        output << accNum << setw(12) << accType << setw(16) << startBal_s << setw(15) << deposit_s << setw(16)  << withdraw_s  << setw(13) << fixed << setprecision(2) << endBal << endl;
        cout << accNum << setw(12) << accType << setw(16) << startBal_s << setw(15) << deposit_s << setw(16)  << withdraw_s  << setw(13) << fixed << setprecision(2) << endBal << endl;
}
infile.close();
output.close();
return 0;
}

double getEndBalance(double startBal, double deposit, double withdraw, double interestRate)
{
  double endBal = (startBal + deposit - withdraw)*interestRate;
  return endBal;
}

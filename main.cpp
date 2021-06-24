/*
* main.cpp
*
* Created on: 6/2/2021
* Author: David Silva
*/

#include <iostream>
#include <limits>
#include "savings.h"
using namespace std;

int main() {

    while (true) {
        //output to show what the user data input will look like
        cout << "*************************************" << endl;
        cout << "*************Data Input**************" << endl;
        cout << "Initial Investment Amount: " << endl;
        cout << "Monthly Deposit: " << endl;
        cout << "Annual Interest: " << endl;
        cout << "Number of years: " << endl;
        system("PAUSE");
        cout << endl;
        //get input from the user
        cout << "*************************************" << endl;
        cout << "*************Data Input**************" << endl;
        cout << "Initial Investment Amount: $";

        double investment, monthlyDeposit, interestRate;
        int years;

        cin >> investment;

        cout << "Monthly Deposit: $";
        cin >> monthlyDeposit;

        cout << "Annual Interest: %";
        cin >> interestRate;

        cout << "Number of years: ";
        cin >> years;

        system("PAUSE");

        //create an object of mysavings using the user inputted data
        Savings mySavings = Savings(investment, monthlyDeposit, interestRate, years);

        cout << endl;

        //call reportNoMonthlyDeposits method
        mySavings.reportNoMonthlyDeposits();
        cout << endl;

        //call reportWithMonthlyDeposits method if user inputted a value greater than 0 for their monthly deposit
        if (monthlyDeposit > 0) {
            mySavings.reportWithMonthlyDeposits();
        }

        //ask the user if they want to perform another calculation 
        cout << endl << "Do you wish to perform another calculation? (y/n): ";
        string choice;
        cin >> choice;

        //if user does not type "y" to perform another calculation, end program
        if (choice != "y") {
            break;
        }
        cout << endl;
    }
    return 0;
}
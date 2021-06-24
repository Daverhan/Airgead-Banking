/*
* savings.cpp
*
* Created on: 6/2/2021
* Author: David Silva
*/

#include <iomanip>
#include <iostream>
#include "savings.h"
using namespace std;

//constructor 
Savings::Savings(double investment, double monthDeposit,
    double rate, int years) {
    this->initialDeposit = investment;
    this->monthlyDeposit = monthDeposit;
    this->interestRate = rate;
    this->numYears = years;
}

//destructor
Savings::~Savings() {}

//output report without additional monthly deposits
void Savings::reportNoMonthlyDeposits() {
    //heading
    cout << "   Balance and Interest Without Additional Monthly Deposits" << endl;
    cout << "==========================================================================" << endl;
    //table heading
    cout << setw(10) << "Year"
        << setw(20) << "Year End Balance"
        << setw(35) << "Year End Earned Interest Rate" << endl;
    cout << "--------------------------------------------------------------------------" << endl;

    //iterate through given years and calculate interest earned
    int currentYear = 1;
    double yearEndBalance = this->initialDeposit;

    while (currentYear <= this->numYears) {
        //interest calculation
        double interestEarned = yearEndBalance * this->interestRate / 100;
        //add to year end balance
        yearEndBalance += interestEarned;
        //output result for each year
        cout << right << setw(10) << currentYear << fixed << setprecision(2)
            << setw(20) << yearEndBalance
            << setw(35) << interestEarned << endl;
        //increase year by one
        currentYear++;
    }
}

//output report with additional monthly deposits
void Savings::reportWithMonthlyDeposits() {
    //heading
    cout << "   Balance and Interest With Additional Monthly Deposits" << endl;
    cout << "==========================================================================" << endl;
    //table heading
    cout << setw(10) << "Year"
        << setw(20) << "Year End Balance"
        << setw(35) << "Year End Earned Interest Rate" << endl;
    cout << "--------------------------------------------------------------------------" << endl;
    //iterate through given years and calculate interest earned
    int currentYear = 1;
    double yearEndBalance = this->initialDeposit;

    while (currentYear <= this->numYears) {
        //calulate interest monthly and calculate compound interest
        int month = 1;
        double interestEarned = 0.0;
        double monthEndBalance = yearEndBalance;

        while (month <= 12) {
            //add monthly deposit
            monthEndBalance += this->monthlyDeposit;
            //calculate monthly interest
            double monthlyInterest = monthEndBalance * this->interestRate / (100 * 12);
            //add monthly interest to yearly interest
            interestEarned += monthlyInterest;
            //add interest to month end balance
            monthEndBalance += monthlyInterest;
            //increase month by one
            month++;
        }

        //after 12 months
        yearEndBalance = monthEndBalance;
        //output final results
        cout << right << setw(10) << currentYear << fixed << setprecision(2)
            << setw(20) << yearEndBalance
            << setw(35) << interestEarned << endl;
        //increase year by one
        currentYear++;
    }
}
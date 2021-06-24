/*
* savings.h
*
* Created on: 6/2/2021
* Author: David Silva
*/

#ifndef SAVINGS_H_
#define SAVINGS_H_

class Savings {
public:
    Savings(double investment, double monthDeposit, double rate, int years);
    virtual ~Savings();
    void reportNoMonthlyDeposits();
    void reportWithMonthlyDeposits();

private:
    double initialDeposit;
    double monthlyDeposit;
    double interestRate;
    int numYears;
};

#endif
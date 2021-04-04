/*******************************************************************
** Program: assignment1.cpp
** Author: Senna Titcomb
** Date: 01/19/2020
** Description: Calculate gross income and taxes
** Input: monthly salary, number of months worked in a year, cost of a car, number of cars sold, number of misconducts, tax year, and state
** Output: Gross income, tax, and remainder
*******************************************************************/

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <ctime>

using namespace std;

int main()
{
    float monthsalary = 0;
    int monthsyr = 0;
    float carcost = 0;
    int carssold = 0;
    int misconduct = 0;
    int taxyr = 0;
    char state = ' ';
    float annual = 0;
    float profit = 0;
    float deduce = 0;

    srand(time(NULL));
/*
 * * Here I am just asking the user for inputs
 * */
    cout << "Please enter the monthly salary." << endl;
    cin >> monthsalary;
    cout << "Please enter the number of  months worked in a year." << endl;
    cin >> monthsyr;
    cout << "Please enter the cost of a car." << endl;
    cin >> carcost;
    cout << "Please enter the number of cars sold." << endl;
    cin >> carssold;
    cout << "Please enter the number of misconducts observed." << endl;
    cin >> misconduct;
    cout << "Please enter the tax year." << endl;
    cin >> taxyr;
    cout << "Please enter the state, A, B, or C." << endl;
    cin >> state;
/*
 * * Below are the calculations for the annual salary, profit, and deductions
 * */
    annual = monthsalary * monthsyr;
    float avgcost = 0;
    float diff = 0;
    float start = 0;
    start = carcost * 1.05;
    diff = (carcost * 1.1) - start;
    avgcost = ((rand() / (float) RAND_MAX) * diff) + start;
    cout << "Average cost: " << avgcost <<endl;
    profit = carssold * (avgcost - carcost);

    if (misconduct > 0) {
       deduce = 100 * pow (2,(misconduct-1));
    }

    float grossincome = annual + (0.02 * profit) - deduce;
    float tax = 0;

/*
 * * Below are the cases for each of the tax years and the states accordingly.
 * * The tax calculations are also conducted.
 * */

    if (taxyr == 1) {

       switch(state) {
           case 'A' :
             tax = 0.06 * grossincome;

           break;

           case 'B' :
             if (grossincome >=  2000 and grossincome <= 10000) {
                tax = 100;
             } else if (grossincome > 10000) {
                tax = 0.1 * (grossincome - 10000);
                tax = tax + 100;
             }
           break;

           case 'C' :
             if (grossincome >= 0 and grossincome <= 3500) {
                tax = 0.05 * grossincome;
             } else if (grossincome > 3500 and grossincome <= 9000) {
                tax = 0.07 * (grossincome - 3500);
                tax += 175;
             } else if (grossincome > 9000 and grossincome <= 125000) {
                tax = 0.09 * (grossincome - 9000);
                tax += 560;
             } else {
                tax = 0.099 * (grossincome - 125000);
                tax += 11000;
             }
           break;
        }

    } else if (taxyr == 2) {
          switch(state) {
           case 'A' :
             tax = 0.08 * grossincome;

           break;

           case 'B' :
             if (grossincome >=  2500 and grossincome <= 10000) {
                tax = 115;
             } else if (grossincome > 10000) {
                tax = 0.105 * (grossincome - 10000);
                tax = tax + 115;

             }
           break;

           case 'C' :
             if (grossincome >= 0 and grossincome <= 3450) {
                tax = 0.05 * grossincome;
             } else if (grossincome > 3450 and grossincome <= 8700) {
                tax = 0.07 * (grossincome - 3450);
                tax = tax + 172.5;
             } else if (grossincome > 8700 and grossincome <= 125000) {
                tax = 0.09 * (grossincome - 8700);
                tax = tax + 540;
             } else {
                tax = 0.099 * (grossincome - 125000);
                tax = tax + 11007;
             }
           break;
        }


    }

cout << "This is your gross income: " << grossincome << endl << "This is your tax: " << tax << endl << "This is the remainder: " << (grossincome - tax) << endl;
}

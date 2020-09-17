//VE280 Project 1: How Much Car Can You Afford? 
//Last update: 2020/9/17
//Author: Hang Jiang

#include <iostream>
#include <iomanip>
#include "io.h"
using namespace std;
int main(){

    int m, y;
    double r;
    //m -- monthly payment
    //y -- duration of loan
    //r -- yearly interest

    //Get Parameters
    m=GetParam("Please enter the monthly payment: ", 1, 100000);
    r=GetParam("Please enter the interest rate: ", 0, 1);
    y=GetParam("Please enter the duration of the loan, in years: ", 1, 100);

    //Print the Header
    PrintHeader();
    //Calculate and Print Monthly Data
    y=y*12;
    double P=m;
    double I=0, B=0;
    /*
    P -- Principal
    I -- Interest
    B -- Balance
    */

    do
    {
        P=(m-B*r/12)/(1+r/12);
        B=B+P;
        I=B*r/12;
        PrintMonthlyData(y, P, I, B);
        y--;
        //Calculate each month's data by reversed induction from the last month

    } while (y>0);
    

    return 0;
}

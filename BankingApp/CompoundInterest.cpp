#include <iostream>
#include <iomanip>
#include "CompoundInterest.h"
#include "cmath"
using namespace std;




CompoundInterest::CompoundInterest() {}

CompoundInterest::CompoundInterest(int month, double openingAmount, double monthlyDeposit, double interest) {
	this->m_month = month * 12;
	this->m_openingAmount = openingAmount;
	this->m_monthlyDeposit = monthlyDeposit;
	this->m_interest = interest;
}

void CompoundInterest::SetOpeningAmount(double t_amount) {
	this->m_openingAmount = t_amount;
}
double CompoundInterest::GetOpeningAmount() const {
	return this->m_openingAmount;
}
void CompoundInterest::SetMonthlyDeposit(double t_amount) {
	this->m_monthlyDeposit = t_amount;
}
double CompoundInterest::GetMonthlyDeposit() const {
	return this->m_monthlyDeposit;
}
void CompoundInterest::SetInterest(double t_amount) {
	this->m_interest = t_amount;
}
double CompoundInterest::GetInterest() const {
	return this->m_interest;
}
void CompoundInterest::DisplayMenu() {
	cout << setw(40) << setfill('*') << "" << endl;
	cout << setw(12) << setfill('*') << "" << " Data Input " << setw(16) << setfill('*') << "" << endl;

	// Prompt the user for input for each menu option
	cout << "Initial Investment Amount: $";
	cin >> this->m_openingAmount;


	while(cin.fail()) {
		cin.clear();
		cin.ignore(10000, '\n');
		cout << "Invalid input. \nPlease enter a dollar amount";
		cin >> this->m_openingAmount;
	}

	cout << "Monthly Deposit: $";
	cin >> this->m_monthlyDeposit;


	while(cin.fail()) {
		cin.clear();
		cin.ignore(10000, '\n');
		cout << "Invalid input. \nPlease enter a How much money you are going to deposit monthly";
		cin >> this->m_monthlyDeposit;
	}

	cout << "Annual interest: %";
	cin >> this->m_interest;

	while(cin.fail()) {
		cin.clear();
		cin.ignore(10000, '\n');
		cout << "Invalid input. \nPlease enter a valid annual interest percentage";
		cin >> this->m_interest;
	}


	cout << "Number of Years: ";
	cin >> this->m_month;

	while(cin.fail()) {
		cin.clear();
		cin.ignore(10000, '\n');
		cout << "Invalid input. \nPlease enter the amount of years for this investment";
		cin >> this->m_month;
	}


	// Set the total deposits
	this->m_totalDeposits = this->m_openingAmount + this->m_monthlyDeposit;
	cout << endl << endl;
}

void CompoundInterest::DisplayYearEndReport() {
	// Get the opening amount
	double balance = this->m_openingAmount;
	// A variable that would be use as a pass by reference and will get updated values
	double interestEarned = 0;
	// A variable that would be use as a pass by reference and will get updated values
	double endBalance = 0;
	// A variable to hold the cumulative monthly interest earned
	double yearEndInterest = 0;
	cout << setw(62) << setfill('*') << "" << endl;
	cout << setw(4) << setfill('*') << "" << " Year-End Balances (No Additional Monthly Deposits) " << setw(4) << setfill('*') << "" << endl;
	cout << setw(10) << setfill(' ') << "Year" << setw(28) << setfill(' ') << "Year-End Balance" << setw(24) << setfill(' ') << "Earned Interest" << endl;
	cout << setw(10) << setfill('-') << "" << setw(20) << setfill('-') << "" << setw(32) << setfill('-') << "" << endl;
	// since the this month variable holds the amount of years gotten from the menu we times it times 12 to get the amount of months
	int months = this->m_month * 12;
	// this will be used for displaying the year in the report
	int year = 1;
	// This will hold the previous year interest so we can substract it to the yearEarnInterest to get the correct yearly interestEarned
	double prevYearInterest = 0.0;
	for (int month = 1; month <= months; month++) {
		// calculate the monthly interest
		m_CaclulateMonthlyInterest(balance, interestEarned, endBalance);
		// acumulate the monthly interest
		yearEndInterest += interestEarned;
		// setting the balance to the endBalance from the monthly interest calculation
		balance = endBalance;

		// If we got to a year equivalent in months
		if (month % 12 == 0) {

			// print the report
			cout<< fixed << setprecision(2) << setw(10) << setfill(' ') << year << setw(20) << setfill(' ') << "$" << endBalance << setw(20) << setfill(' ') << "$" << (yearEndInterest - prevYearInterest)<< endl;
			// increase the year to display in the report
			year++;
			// record the yearEndInterest to the prevYearInterest so we can subtract it from yearEndInterest and get the yearEndInterest per year
			prevYearInterest = yearEndInterest;
			// set the closing balance to end balance
			this->m_closingBalance = endBalance;
		}
	}
	cout << endl << endl;
}

void CompoundInterest::DisplayMonthlyDepositReport() {
    // Get the opening amount
	double balance = this->m_openingAmount;
	// A variable that would be used as a pass by reference and will get updated values
	double interestEarned = 0;
	// A variable that would be used as a pass by reference and will get updated values
	double endBalance = 0;
	// A variable to hold the cumulative monthly interest earned
	double yearEndInterest = 0;
	cout << setw(63) << setfill('*') << "" << endl;
	cout << setw(4) << setfill('*') << "" << " Year-End Balances (With Additional Monthly Deposits) " << setw(4) << setfill('*') << "" << endl;
	cout << setw(10) << setfill(' ') << "Year" << setw(28) << setfill(' ') << "Year-End Balance" << setw(24) << setfill(' ') << "Earned Interest" << endl;
	cout << setw(10) << setfill('-') << "" << setw(20) << setfill('-') << "" << setw(33) << setfill('-') << "" << endl;
	// since the this month variable holds the amount of years gotten from the menu we times it times 12 to get the amount of months
	int months = this->m_month * 12;
	// this will be used for displaying the year in the report
	int year = 1;
	// This will hold the previous year interest so we can substract it to the yearEarnInterest to get the correct yearly interestEarned
	double prevYearInterest = 0.0;

	for (int month = 1; month <= months; month++) {
		// add the monthly deposit to the balance
		balance += this->m_monthlyDeposit;
		// calculate the monthly interest
		m_CaclulateMonthlyInterest(balance, interestEarned, endBalance);
		// acumulate the monthly interest
		yearEndInterest += interestEarned;
		// setting the balance to the endBalance from the monthly interest calculation
		balance = endBalance;

		// If we got to a year equivalent in months
		if (month % 12 == 0) {

			if (year == 1) {
				// print the report
				cout << fixed << setprecision(2) << setw(10) << setfill(' ') << year << setw(20) << setfill(' ') << "$" << endBalance << setw(21) << setfill(' ') << "$" << (yearEndInterest - prevYearInterest) << endl;
			}
			else {
				// print the report
				cout << fixed << setprecision(2) << setw(10) << setfill(' ') << year << setw(20) << setfill(' ') << "$" << endBalance << setw(20) << setfill(' ') << "$" << (yearEndInterest - prevYearInterest) << endl;
			}
			// increase the year to display in the report
			year++;
			// record the yearEndInterest to the prevYearInterest so we can subtract it from yearEndInterest and get the yearEndInterest per year
			prevYearInterest = yearEndInterest;
			// set the closing balance to end balance
			this->m_closingBalance = endBalance;
		}
	}
	cout << endl << endl;
}

void CompoundInterest::DisplayReports() {
	DisplayYearEndReport();
	DisplayMonthlyDepositReport();
}

void CompoundInterest::m_CaclulateMonthlyInterest(double& t_initialBalance,double& t_earnedInterest, double& t_totalBalance) {
	
	t_earnedInterest = t_initialBalance * ((this->m_interest / 100) / 12);
	t_totalBalance = t_initialBalance + t_earnedInterest;
}

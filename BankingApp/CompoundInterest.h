#ifndef COMPOUNDINTEREST_H
#define COMPOUNDINTEREST_H

class CompoundInterest
{
public:
	CompoundInterest();// Default constructor
	CompoundInterest(int month, double openingAmount, double monthlyDeposit, double interest);// Parameterize constructor
	// Getters and Setters
	void SetOpeningAmount(double t_amount);
	double GetOpeningAmount() const;
	void SetMonthlyDeposit(double t_amount);
	double GetMonthlyDeposit() const;
	void SetInterest(double t_amount);
	double GetInterest() const;

	void DisplayMenu();
	void DisplayYearEndReport();
	void DisplayMonthlyDepositReport();
	void DisplayReports();
private:
	int m_month; //The number of months based on user input in the �Number of Years� field
	double m_openingAmount; // The initial amount to open the account
	double m_monthlyDeposit; //  The monthly amount to be deposited into the account
	double m_totalDeposits; // The sum of the initial deposit and the monthly deposits
	double m_interest; // Annual interest rate
	double m_closingBalance; // The sum of the total deposit plus the interest
	void m_CaclulateMonthlyInterest(double& t_initialBalance,double& t_earnedInterest, double& t_totalBalance);
};
#endif

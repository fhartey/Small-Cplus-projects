/*
 * Account.h
 *
 *  Created on: Sep 22, 2020
 *      Author: fran
 */

#ifndef ACCOUNT_H_
#define ACCOUNT_H_
#include <string>
#include <vector>
#include <ctime>
using namespace std;
class Account {

private:

	time_t now = time(0);
	char *dt = ctime(&now);

public:

	enum AccountType {
		Checking = 0, Savings = 1
	};

	string date;
	string name;
	double CurrentBalance;
	double Withdrawl;
	double Deposit;

	Account(AccountType name, double CurrentBalance, double Deposit,
			double Withdrawl);
	static string getAccountTypeName(Account::AccountType type);
	//double GetCurrentBalnce(std::vector<double> x);
};

#endif /* ACCOUNT_H_ */

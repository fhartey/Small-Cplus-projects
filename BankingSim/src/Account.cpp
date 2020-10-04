/*
 * Account.cpp
 *
 *  Created on: Sep 22, 2020
 *      Author: fran
 */

#include<vector>
#include<string>
#include<ctime>
#include<iostream>
#include "Account.h"
using namespace std;

Account::Account(Account::AccountType name, double CurrentBalance,
		double Deposit, double Withdrawl) {

	Account::name = getAccountTypeName(name);
	Account::CurrentBalance = CurrentBalance;
	Account::Deposit = Deposit;
	Account::Withdrawl = Withdrawl;
	Account::date = Account::dt;

}

string Account::getAccountTypeName(Account::AccountType type) {
	string accountname[] = { "Checking", "Savings" };
	return accountname[type];
}

/*double Account::GetCurrentBalnce(std::vector<double> x) {
	double sum = 0;
	if (x.size() == 0) {
		return 0;
	} else {
		for (int i = 0; i < x.size(); i++) {
			sum = sum + x[i];

		}
		return sum;
	}
}

*/

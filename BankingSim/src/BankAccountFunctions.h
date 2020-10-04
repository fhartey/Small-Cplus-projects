/*
 * BankAccountFunctions.h
 *
 *  Created on: Sep 22, 2020
 *      Author: fran
 */

#ifndef BANKACCOUNTFUNCTIONS_H_
#define BANKACCOUNTFUNCTIONS_H_
#include <string>
#include<vector>
#include "Account.h"
using namespace std;
class BankAccountFunctions {
public:
	enum Transaction {Deposit, Withdrawal};

	double CheckingORSavings(vector<Account *> a, Account::AccountType type,
			double addon);



	void GetAccountHistory(std::vector<Account *> a, Account::AccountType type);


	void MakeTransaction(std::vector<Account *> &a, Account::AccountType type,
			double amount, BankAccountFunctions::Transaction);
};



#endif /* BANKACCOUNTFUNCTIONS_H_ */

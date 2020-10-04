/*
 * BankAccountFunctions.cpp
 *
 *  Created on: Sep 22, 2020
 *      Author: fran
 */

#include <string>
#include<iostream>
#include<vector>
#include "Account.h"
#include "BankAccountFunctions.h"
using namespace std;

double BankAccountFunctions::CheckingORSavings(vector<Account*> a,
		Account::AccountType type, double addon) {

	if (a.size() == 0) {
		return addon;

	} else {

		int LastCurrentBalance = -1;
		for (int i = 0; i < a.size(); i++) {

			if (a[i]->name == Account::getAccountTypeName(type)) {
				LastCurrentBalance = i;

			}
		}
		if (LastCurrentBalance == -1) {

			return addon;
		} else {

			return a[LastCurrentBalance]->CurrentBalance + addon;
		}
	}
}

void BankAccountFunctions::GetAccountHistory(std::vector<Account*> a,
		Account::AccountType type) {

	for (int i = 0; i < a.size(); i++) {
		if (a[i]->name == Account::getAccountTypeName(type)) {
			cout << "name: " << a[i]->name << " Balance at that time: "
					<< a[i]->CurrentBalance << " depisot: " << a[i]->Deposit
					<< " Withdrawled: " << a[i]->Withdrawl << " Date: "
					<< a[i]->date << endl;
		}

	}
}

void BankAccountFunctions::MakeTransaction(std::vector<Account*> &a,
		Account::AccountType type, double amount,
		BankAccountFunctions::Transaction Trantype) {
	if (Trantype == Transaction::Deposit && amount != 0) {

		amount < 0 ?
				a.push_back(
						new Account { type,   (a, type, -amount),
								-amount, 0 }) :
				a.push_back(
						new Account { type, CheckingORSavings(a, type, amount),
								amount, 0 });

	} else if (Trantype == Transaction::Withdrawal && amount != 0) {
		amount < 0 ?
				a.push_back(
						new Account { type, CheckingORSavings(a, type, amount),
								0, amount }) :
				a.push_back(
						new Account { type, CheckingORSavings(a, type, -amount),
								0, -amount });
	}

	else {

		cout << "sorry cannot enter zero as amount try again" << endl;
		double x = 0;
		std::cin >> x;
		BankAccountFunctions::MakeTransaction(a, type, x, Trantype);

	}

}


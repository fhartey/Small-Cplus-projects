//============================================================================
// Name        : BankingSim.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include<vector>
#include<string>

#include <iostream>
#include <iomanip>
#include <ctime>
#include <chrono>

#include "Account.h"
#include "BankAccountFunctions.h"
using namespace std;

int main() {

	BankAccountFunctions AHFunc;
	std::vector<Account *> obj1;


	/*AHFunc.MakeTransaction(obj1, Account::Checking, 50, BankAccountFunctions::Withdrawal);
	AHFunc.MakeTransaction(obj1, Account::Savings, 40, BankAccountFunctions::Deposit);
	AHFunc.MakeTransaction(obj1, Account::Checking, 20, BankAccountFunctions::Withdrawal);
	AHFunc.MakeTransaction(obj1, Account::Savings, -5, BankAccountFunctions::Deposit);
	AHFunc.MakeTransaction(obj1, Account::Checking, 10, BankAccountFunctions::Withdrawal);

	AHFunc.MakeTransaction(obj1, Account::Checking, 5, BankAccountFunctions::Deposit); // for withdrawls just say please enter a number less then zero

	AHFunc.MakeTransaction(obj1, Account::Savings, -60,BankAccountFunctions::Withdrawal);
	//AHFunc.MakeTransaction(obj1, Account::Savings, 0, BankAccountFunctions::Deposit);

	cout<< "********************************" << endl;
	//Account::GetAccountHistory(obj1, Account::Savings);
	AHFunc.GetAccountHistory(obj1, Account::Savings);
	cout<< "$$$$$$$$$$$$$$$$$$" << endl;
	AHFunc.GetAccountHistory(obj1, Account::Checking); */

	cout<< "PRESS TO SELECT ACCOUNT" << endl;
	cout<< "Checking -> 1" << endl;
	cout<< "Savings  -> 2" << endl;
	while (true) {

		double Amount = 0;
		int Userinput = 0;
		cin >> Userinput;
		switch (Userinput) {
		case 1:
			cout << "PRESS" << endl;
			cout << "Deposit               -> 1" << endl;
			cout << "Withdrawal            -> 2" << endl;
			cout << "Check Account History -> 3" << endl;

			cin >> Userinput;
			switch (Userinput) {

			case 1:
				cout << "please enter the amount you would like to deposit"
						<< endl;
				cin >> Amount;
				AHFunc.MakeTransaction(obj1, Account::Checking, Amount,
						BankAccountFunctions::Deposit);
				break;
			case 2:
				cout << "please enter the amount you would like to withdrawal"
						<< endl;
				cin >> Amount;
				AHFunc.MakeTransaction(obj1, Account::Checking, Amount,
						BankAccountFunctions::Withdrawal);
				break;
			case 3:
				cout << "********Checking Account History********" << endl;
				AHFunc.GetAccountHistory(obj1, Account::Checking);
				break;
			}
			break;

		case 2:
			cout << "PRESS" << endl;
			cout << "Deposit               -> 1" << endl;
			cout << "Withdrawal            -> 2" << endl;
			cout << "Check Account History -> 3" << endl;

			cin >> Userinput;
			switch (Userinput) {

			case 1:
				cout << "please enter the amount you would like to deposit"
						<< endl;
				cin >> Amount;
				AHFunc.MakeTransaction(obj1, Account::Savings, Amount,
						BankAccountFunctions::Deposit);
				break;
			case 2:
				cout << "please enter the amount you would like to withdrawal"
						<< endl;
				cin >> Amount;
				AHFunc.MakeTransaction(obj1, Account::Savings, Amount,
						BankAccountFunctions::Withdrawal);
				break;
			case 3:
				cout << "********Savings Account History********" << endl;
				AHFunc.GetAccountHistory(obj1, Account::Savings);
				break;
			}

			break;
		}

		cout << "PRESS TO SELECT ACCOUNT" << endl;
		cout << "Checking -> 1" << endl;
		cout << "Savings  -> 2" << endl;
	}



	return 0;
}


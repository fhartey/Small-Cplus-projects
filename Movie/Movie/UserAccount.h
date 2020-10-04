#pragma once
#include <iostream>
#include <algorithm>
#include<array>
#include<vector>
#include <map>
#include <list>
#include<vector>

using namespace std;

class UserAccount {

public:
	struct TicketsOwned {
		int id;
		string moviename;
		int seatkey;
		string seatvalue;
	};
	std::vector<TicketsOwned> userstickets;
	UserAccount(std::vector<TicketsOwned> userstickets);

	void ShowUserTickets(UserAccount user);

	void AddUserTicket(UserAccount &user, string MovieName, int seatkey, string seatvalue);

	UserAccount RefundUserTicket(UserAccount &user, int ticketid);
};
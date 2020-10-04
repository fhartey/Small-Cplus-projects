#include <iostream>
#include <algorithm>
#include<array>
#include<vector>
#include <map>
#include <list>
#include "TicketSystem.h"
#include"UserAccount.h"
using namespace std;


UserAccount::UserAccount(std::vector<TicketsOwned> userstickets) {
	this->userstickets = userstickets;

	}



	void UserAccount::ShowUserTickets(UserAccount user) {
	
		for (auto const &x : user.userstickets) {
			std::cout <<"ID: "<< x.id <<" MovieName: " << x.moviename << " SeatKey Value: " << x.seatkey << " SeatNumberValue: " << x.seatvalue << endl;
	
		}

	}

	void UserAccount::AddUserTicket(UserAccount& user, string MovieName, int seatkey, string seatvalue)
	{
		int  id = user.userstickets.size();
		user.userstickets.push_back({id, MovieName, seatkey, seatvalue});
	}

	

		UserAccount  UserAccount::RefundUserTicket(UserAccount& user,  int ticketid) {
		UserAccount usercopy = user;
		usercopy.userstickets.clear();
		int counter = 0;

		for (auto const& x : user.userstickets) {
			if (x.id == ticketid) {
				usercopy.userstickets.push_back({ x.id,x.moviename,x.seatkey,x.seatvalue });
				user.userstickets.erase(user.userstickets.begin() + counter);
				return usercopy;
			}
			counter++;
		}
		return usercopy;
	}


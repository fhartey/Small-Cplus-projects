//============================================================================
// Name        : Movie.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <algorithm>
#include<array>
#include<vector>
#include <map>
#include <list>
#include "TicketSystem.h"
#include"MoviesPlaying.h"
#include"UserAccount.h"
using namespace std;

 
int main() {



	TicketSystem obj; // are ticket system obj
	std::list<TicketSystem*> objmov; // list for movies

	vector<UserAccount::TicketsOwned> UT;
	UserAccount userobj(UT); // are user account
	
	


	MoviesPlaying::AddMoving(objmov, 0, "bugslife", "10:00 AM", 25.89);
	MoviesPlaying::AddMoving(objmov, 1, "bugslife", "12:00 PM", 30.00);
	MoviesPlaying::AddMoving(objmov, 2, "dog", "11:00Pm", 25.89);


	
	std::cout << "Select 1 to purschae a ticket" << endl
		<< "Select 2 to view current movies and seats" << endl
		<< "Select 3 to refund your ticket" << endl
		<< "Select 4 to view your tickets" << endl
		<< "Select 5 to View the gross profit of the theather" << endl;
	int userinput = 0;
	while (std::cin >> userinput) {
	
		switch (userinput) {
		case 1:
		{
			obj.ShowMoviesPlaying(objmov);

			std::cout << "please slect number for movie want to see" << endl;
			std::cin >> userinput;
			std::cout << "please selecy your seat number" << endl;

			TicketSystem* Tptr = obj.ShowSeats(objmov, userinput);
			std::cout << "***************************" << endl;

			std::cout << "please select the number you want for  your seat" << endl;
			string seatnum;
			std::cin >> seatnum;
			std::cout << "**************" << endl;
			int seatkey = Tptr->PurscahseTicket(seatnum, Tptr->movieprice); 

			if (seatkey != -1) {
				userobj.AddUserTicket(userobj, Tptr->moviename, seatkey, seatnum);
				cout << "your ticket has been purshcase" << endl;
			}
			else {
				cout << "sorry this seat is either not avaible or wrong num"
					<< endl;
			}
			
			break;
		}
		case 2:
		{
			obj.ShowMoviesPlaying(objmov);
			std::cout << "please slect number for movie want to see" << endl;
			std::cin >> userinput;
			obj.ShowSeats(objmov, userinput);

			break;
		}
		case 3:{
			cout << "select the movie id of which movie you would like to refund" << endl;
			userobj.ShowUserTickets(userobj);
			cin >> userinput;

			UserAccount UAptr = userobj.RefundUserTicket(userobj, userinput);
			if ( UAptr.userstickets.size() != 0) {
				obj.RefundTicket(objmov, UAptr.userstickets[0].seatkey, UAptr.userstickets[0].seatvalue, UAptr.userstickets[0].moviename);
					
			}
			else {
				cout << "sorry what you chose was not a ID" << endl;
			}
			

			break;
		}
		case 4: {
			userobj.ShowUserTickets(userobj);
			
			break;
		}
		case 5: {
			cout << "The current gross profit of the movie theather is: " << TicketSystem::GetGrossProfit() <<endl;
			
			break;
		}

		default:
			std::cout << "sorry whatever you put doesnt exist" << endl;
			break;
	
		}

		std::cout << "Select 1 to purschae a ticket" << endl
			<< "Select 2 to view current movies and seats" << endl
			<< "Select 3 to refund your ticket" << endl
			<< "Select 4 to view your tickets" << endl
			<< "Select 5 to View the gross profit of the theather" << endl;
	}

	return 0;
}
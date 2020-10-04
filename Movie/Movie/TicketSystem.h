#pragma once

#include <iostream>
#include <algorithm>
#include<array>
#include<vector>
#include <map>
#include <list>
#include "UserAccount.h"

using namespace std;

class TicketSystem {
private:
	TicketSystem* FindMovie(std::list<TicketSystem*> ticketlist, std::string moviename);
	static double GrossProfit;
public:

	string moviename;
	int movieid;
	double movieprice;
	string movietime;
	std::map<int, string>  seats = {
   { 1, "A1" }, { 2, "A2" },  { 3, "A3" },  { 4, "A4" },  { 5, "A5" },{ 6, "A6" },
   {7, "B1" }, { 8, "B2" },  { 9, "B3" },  { 10, "B4" },  { 11, "B5" },  { 12, "B6" },
   { 13, "C1" }, { 14, "C2" },  { 15, "C3" },  { 16, "C4" },  { 17, "C5" },  { 18, "C6" },
   { 19, "D1" }, { 20, "D2" },  { 21, "D3" },  { 22, "D4" },  { 23, "D5" },  { 24, "D6" },
   { 25, "E1" }, { 26, "E2" },  { 27, "E3" },  { 28, "E4" },  { 29, "E5" },  { 30, "E6" }
	};


	TicketSystem();

	void RefundTicket( std::list<TicketSystem*> &ticketlist, int key, string value, string moviename);

	int PurscahseTicket(string UsersSeatValue, double priceseat);

	static double GetGrossProfit();

	void ShowMoviesPlaying(std::list<TicketSystem*> ticketlist);

	TicketSystem* ShowSeats(std::list<TicketSystem*> ticketlist, int MovieId);

	void ShowSeats();

};

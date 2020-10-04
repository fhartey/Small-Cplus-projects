
#include <iostream>
#include <algorithm>
#include<array>
#include<vector>
#include <map>
#include <list>
#include "TicketSystem.h"

using namespace std;



	string moviename;
	int movieid;
	double TicketSystem::GrossProfit = 0;
	// static varibles need class::varname, https://stackoverflow.com/questions/5373107/how-to-implement-static-class-member-functions-in-cpp-file
	// keep as refernce not using now 
	/*
	 std::map<int, string> TicketSystem::seats = {
		{ 1, "A1" }, { 2, "A2" },  { 3, "A3" },  { 4, "A4" },  { 5, "A5" },{ 6, "A6" },
		{7, "B1" }, { 8, "B2" },  { 9, "B3" },  { 10, "B4" },  { 11, "B5" },  { 12, "B6" },
		{ 13, "C1" }, { 14, "C2" },  { 15, "C3" },  { 16, "C4" },  { 17, "C5" },  { 18, "C6" },
		{ 19, "D1" }, { 20, "D2" },  { 21, "D3" },  { 22, "D4" },  { 23, "D5" },  { 24, "D6" },
		{ 25, "E1" }, { 26, "E2" },  { 27, "E3" },  { 28, "E4" },  { 29, "E5" },  { 30, "E6" }

	}; */




	TicketSystem::TicketSystem() {

	}

	double TicketSystem::GetGrossProfit() {
		return TicketSystem::GrossProfit;
		
	}

	 void TicketSystem::RefundTicket(std::list<TicketSystem*> &ticketlist, int key, string value, string moviename){
		 FindMovie(ticketlist, moviename)->seats[key] = value;
		 GrossProfit = GrossProfit - FindMovie(ticketlist, moviename)->movieprice;
	}

	int TicketSystem::PurscahseTicket(string UsersSeatValue, double priceseat) {
		for (int i = 0; i < seats.size(); i++) {

			if (seats[i] == UsersSeatValue) {
				seats[i] = "X";
			    GrossProfit = GrossProfit + priceseat;
				return i;
			}
		}
		return -1;
	}

	TicketSystem* TicketSystem::FindMovie(std::list<TicketSystem*> ticketlist, std::string moviename)
	{
		for (auto const& i : ticketlist) {
			if (i->moviename == moviename) {
				// return move id pointer
				return i;

			}

		}
		//return false;
	}

	 void TicketSystem::ShowMoviesPlaying(std::list<TicketSystem*> ticketlist) {

		for (auto const& i : ticketlist) {
			cout << i->movieid << " : " << i->moviename <<" Time: "<< i->movietime << " Price: " << i->movieprice << endl;
		}

	}
	TicketSystem* TicketSystem::ShowSeats(std::list<TicketSystem*> ticketlist, int MovieId) {

		for (auto const& i : ticketlist) {
			if (i->movieid == MovieId) {
				i->ShowSeats();
				return i;

			}

		}

	}



	void TicketSystem::ShowSeats() {

		cout << "|" << seats[1] << "|" << seats[2] << "|" << seats[3] << "|"
			<< seats[4] << "|" << seats[5] << "|" << seats[6] << "|"
			<< endl;
		cout << "|" << seats[7] << "|" << seats[8] << "|" << seats[9] << "|"
			<< seats[10] << "|" << seats[11] << "|" << seats[12] << "|"
			<< endl;
		cout << "|" << seats[13] << "|" << seats[14] << "|" << seats[15] << "|"
			<< seats[16] << "|" << seats[17] << "|" << seats[18] << "|"
			<< endl;
		cout << "|" << seats[19] << "|" << seats[20] << "|" << seats[21] << "|"
			<< seats[22] << "|" << seats[23] << "|" << seats[24] << "|"
			<< endl;
		cout << "|" << seats[25] << "|" << seats[26] << "|" << seats[27] << "|"
			<< seats[28] << "|" << seats[29] << "|" << seats[30] << "|"
			<< endl;
	}


#pragma once
#include <iostream>
#include <algorithm>
#include<array>
#include<vector>
#include <map>
#include <list>
#include "TicketSystem.h"
using namespace std;

class MoviesPlaying : public TicketSystem {
private:
	static TicketSystem* tempMovie;
public:
	static void AddMoving(std::list<TicketSystem*>& objmov, int movieid, string moviename, string movietime, double movieprice);
	MoviesPlaying(int movieid, string moviename, string movietime, double movieprice);

};

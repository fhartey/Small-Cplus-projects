#include <iostream>
#include <algorithm>
#include<array>
#include<vector>
#include <map>
#include <list>
#include "MoviesPlaying.h"
using namespace std;


TicketSystem* MoviesPlaying::tempMovie = nullptr;

MoviesPlaying::MoviesPlaying( int movieid, string moviename, string movietime, double movieprice)
{
	this->movieid =  movieid;
	this->moviename = moviename;
	this->movietime = movietime;
	this->movieprice = movieprice;

 
}


void MoviesPlaying::AddMoving(std::list<TicketSystem*>& objmov, int movieid, string moviename, string movietime, double movieprice) {
	tempMovie = new MoviesPlaying(movieid, moviename, movietime, movieprice);
	objmov.push_back(tempMovie);
}

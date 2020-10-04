//============================================================================
// Name        : chapter.cpp
// Author      : dfdf
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <ios>
#include <string>
#include "median.h"
using namespace std;

struct Student_info{
	string name;
	double midterm, final;
	vector<double> homewoork;
};



// figure out how and why this works with sort
bool compare(const Student_info& x, const Student_info& y){
	cout<< "inside comX: " << x.name <<endl;
	cout<< "inside comy: " << y.name <<endl;
	return x.name < y.name;
}

int main() {
	vector<Student_info> si;

	cout << "!!!Hello !!!" << endl; // prints !!!Hello World!!!
	vector<double> hey = {2,14.6,12,1,5,6.7,39}; // 1 2 5 6.7 12 14.6
	si.push_back({"jeff", 30, 80, hey}); // have to send data in like a point {}
	si.push_back({"zeff", 30, 80, hey});
	si.push_back({"aeff", 30, 80, hey});
	si.push_back({"deff", 30, 80, hey});

	sort(si.begin(), si.end(), compare);

	cout<< median1(hey) << endl;
	cout<< si[0].name<< endl;
	cout<< si[1].name<< endl;
	cout<< si[2].name<< endl;
	cout<< si[3].name<< endl;

	cout << "struct : " << endl;
	return 0;
}


//============================================================================
// Name        : Basicpratice.cpp
// Author      : dfdf
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<double> finshed;
struct Math{

	double x, y;

};



// figure out how and why this works with sort
bool compare(const Math& x, const Math& y){
	//cout<< "inside comX: " << x.x <<endl;
	//cout<< "inside comy: " << y.y <<endl;


	return x.x < y.x || x.x == y.x && x.y < y.y ;
}

// figure out how and why this works with sort
bool compareY(const Math& x, const Math& y){
	//cout<< "inside comX: " << x.x <<endl;
	//cout<< "inside comy: " << y.y <<endl;
	return x.x == y.x && x.y < y.y;;
}



void myfunction (const Math& x) {  // function:
  std::cout << "," << x.x << " : " << x.y << endl;
  finshed.push_back( x.x + x.y);

}




int main() {

	vector<Math> si;
	si.push_back({2,3});
	si.push_back({4,7});
	si.push_back({5,8});
	si.push_back({3,3});
	si.push_back({8,9});
	si.push_back({5,1});
	vector<double> F1 = {12,34,5,2,0,3,4,66};

	for (int i = 0; i < si.size(); i++){
		cout << "current values X: " << si[i].x << " Y: " << si[i].y << endl;

	}
	cout<< "end a new "<< endl;
	std::sort(si.begin(), si.end(), compare);

	for (int i = 0; i < si.size(); i++){
		cout << "current values X: " << si[i].x << " Y: " << si[i].y << endl;

	}

	cout<< "end a new 2 "<< endl;
		std::sort(si.begin(), si.end(), compareY);

		for (int i = 0; i < si.size(); i++){
			cout << "current values X: " << si[i].x << " Y: " << si[i].y << endl;

		}



		cout<< "end a new 3 "<< endl;
		//	std::sort(si.begin(), si.end(), add);
		cout<< endl;

			for_each (si.begin(), si.end(), myfunction);
			cout<< endl;


			for (int i = 0; i < finshed.size(); i++){
					cout << "current values finshed : " << finshed[i] << endl;

				}

	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	return 0;
}

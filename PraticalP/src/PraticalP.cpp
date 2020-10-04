//============================================================================
// Name        : PraticalP.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include<list>
#include <algorithm>
#include<vector>
using namespace std;

// what we use to call the rest
struct sShape {

	uint32_t nMaxNodes = 0; // putting the var here


	int getnum(){
		return nMaxNodes;
	}
};
struct Line : sShape{
public:
	Line(){
		cout<< "this is a line"<< endl;
		 nMaxNodes = 2; // sets to 2
	}
};

struct Box : sShape{

public:
	Box(){

		cout<< "this is a box" << endl;
		 nMaxNodes = 4; // sets to 1
	}
};

bool compare(sShape* x){

	cout<< "current node "<<x->nMaxNodes << endl ;
	return true;
}
int main() {
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	int x = 0;
	std::list<sShape*> listshape; // basically allowing us to use mutople classes has one instead of have many instances of it
	sShape* tempShape = nullptr;
	while(cin >> x){
		switch(x){
		case 1:
			tempShape = new Box();
			listshape.push_back(tempShape);
			break;
		case 2:
			tempShape = new Line();
						listshape.push_back(tempShape); // temp shape can now being any shape then added to this list ig this was not
						// dervied from sShape, then we wouldnt be able to add in any shape we want
		break;


		}


			// understand what this is
		for (auto const& i : listshape) {

		    cout<< "for auto way : " << i->nMaxNodes<< endl;
		}


		for(list<sShape *>::iterator it = listshape.begin(); it != listshape.end(); ++it)
		{
			sShape * ptr = *it;
			cout<< "litteral way : "<< ptr->nMaxNodes << endl;

		}

		std::for_each(listshape.begin(), listshape.end(), compare);


	}
	return 0;
}

//============================================================================
// Name        : morePointers.cpp
// Author      : dfdf
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <ios>
#include <string>
using namespace std;

struct sSomebaseobject{

	// virtual if i am subclass and if any of my childern happen to override
	// this method please call the childs method instead
	// (		sSomebaseobject** psomearray = new sSomebaseobject*[5])
	virtual const char* IdentifyYourself(){

		return "BaseObject";
	}
};

struct sSomeobjectA : public sSomebaseobject {

	 const char* IdentifyYourself(){
		return "Subject A";

	}

};

struct sSomeobjectB : public sSomebaseobject {

	const char* IdentifyYourself(){
		return "Subject B";

	}

};

int main() {

	sSomebaseobject ob_base;
	sSomeobjectA ob_baseA;
	sSomeobjectB ob_baseB;


	cout<< ob_base.IdentifyYourself() << endl;
	cout<< ob_baseA.IdentifyYourself() << endl;
	cout<< ob_baseB.IdentifyYourself() << endl;

	cout<< "***********************" << endl;
	cout<< "***********************" << endl;

	// this is legal however it will return base object, we need the
	// virtual keywords to tell it to return object A identify yourself
	sSomebaseobject** psomearray = new sSomebaseobject*[5] ; // creating a array of base objects

	psomearray[0] = new sSomeobjectA();
	psomearray[1] = new sSomeobjectB();
	psomearray[2] = new sSomeobjectB();
	psomearray[3] = new sSomebaseobject();
	psomearray[4] = new sSomeobjectA();

	for(int i = 0; i < 5; i++){
		cout<< psomearray[i]->IdentifyYourself() <<endl;
	}

	//clean up after your self;
	for(int i = 0; i < 5; i++){
			delete psomearray[i];

		}
	delete psomearray;

	return 0;
}

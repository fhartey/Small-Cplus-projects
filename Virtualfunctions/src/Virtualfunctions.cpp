//============================================================================
// Name        : Virtualfunctions.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

class Animal {
public:
	virtual void animalSound(){
		cout<< "this is a generic function" << endl;;

	}

	// it wanted a destructor when calling vitrual function
	 virtual ~Animal()
	    { cout<<"Destructing base \n" << endl;; }

};

class Dog : public Animal {

public:
	void animalSound(){

		cout<< "woof" <<endl;
	}
};
int main() {
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	Animal *obj;
	obj = new Dog();
	obj->animalSound();


	Animal *obj2 = new Animal();
	obj2->animalSound();
	delete obj2;
	delete obj;

	// for some reason the virtual desctructor seems to only destruct when we call delete key
	// not when we end the prpgram;
	return 0;
}

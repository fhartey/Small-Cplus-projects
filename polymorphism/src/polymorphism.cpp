//============================================================================
// Name        : polymorphism.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;




// class A and B is example of runtime polymorphism

//Function overriding is an example of Runtime polymorphism.
//Function Overriding: When child class declares a method, which is already present in
//the parent class then this is called function overriding, here child class overrides the parent class.
class A{
public:
	void disp(){
		cout<< "super class function" << endl;
	}
};
class B : public A {

public:
	void disp(){

		cout<< "subclass function" << endl;
	}
};


// class add is a compile time polymorphism
class Add {

public:
	int sum(int num1, int num2){
		return num1 + num2;
	}

	int sum(int num1, int num2, int num3){
		return num1 + num2 + num3;

	}

	int dosome(int num){

		return num;
	}

	//this can work for return types, however

	/*
	 * double dosome(double num){

			return num;
		}
	 * */
	// would not have worked
	double dosome(double num){

			return num;
		}
};
int main() {
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	Add obj;
	cout<< "output: " << obj.sum(10, 20) << endl;
	cout<< "output : " << obj.sum(10, 22, 33) << endl;

	cout<< "overloading do some int: " << obj.dosome(5.4) << endl;

	// runtime polymorphism
	A objA;
	objA.disp();

	B objB;
	objB.disp();

	// to call the overiden function base class
	A _objbToa = B();

	cout<< "will now get A's Base class"  << endl;
	_objbToa.disp();
	cout<< endl;
	// or also


	return 0;
}

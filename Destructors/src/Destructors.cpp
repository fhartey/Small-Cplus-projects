//============================================================================
// Name        : Destructors.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;


class HelloWorld{
private :
	int a;
public:
	HelloWorld(int a){
		this->a = a;
		cout<<"Constructor is called" << endl;

	}


	HelloWorld(){

		// instresting for defuly constuctors it wants the initilazed value
		// most likely the same as the above one
		this->a = 9;
		cout<< "Default constructor" << endl;
	}
	~HelloWorld(){
		cout<< "Destructor is called" << endl;

	}

	void Display(){
		cout<< "Hellow world!" << endl;

	}
	int geta(){

		return a;
	}

};
int main() {
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!

	HelloWorld obj(5);
	HelloWorld* obj1 = new HelloWorld;

	//cout<< obj.geta() <<endl;
	//obj.Display();
	cout<< "obj1 : " << obj1->geta() << endl;
	*obj1 = obj;
	cout<< "obj1 : " << obj1->geta() << endl;
	delete obj1;
	cout<< "obj1 : " << obj1->geta() << endl;
	cout<< "dddddd" <<endl; // desctructo getting called at the end of the return
	return 0;
}

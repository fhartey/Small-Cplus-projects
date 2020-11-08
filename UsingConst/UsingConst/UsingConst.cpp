#include <iostream>
using namespace std;

//https://www.youtube.com/watch?v=4fJBrditnJU

class Test {

private:
    int value;
    int  age;

    // allows for a var to be modify in const function
    mutable int CanBeMod;
public:


    Test() : value(0) {};


    Test(int v) :value(v)
    {};

    // once you create const function it can not modify any of the class/ it can only read things from the class
    int getValue() const {
        // these are illegal once the function is const because you cannot assgin values in a const function;
       // value = 100;
       // age = 100;


       // if var is mutable can be modify good for debuging purposes or unless you really need a var to be modify
        CanBeMod = 9;
        return value;
    }

    // obviously cannot declare this const since we will need to wrtie to the class
    void SetValue(int x) {

        value = x;
    }

    void showNonConstDisplay() {
        value = 2;
        cout << "hello world i am non const" << endl;

    }
    void display() const {
        cout << "hello i am display function" << endl;

    }

    int getAge() const {

        return age;

    }

};


// we sent the ref to const because at this point we do not want to edit anything out of
// since its ref we dont have to make a copy of it, which would take alot longer 
void ShowTest(const Test& _test) {

    //test.setage, and showNonConstDisplay() not allowed  
   // _test.setAge(3);

   //_test.showNonConstDisplay();
    cout << _test.getAge() << endl;
};

//############################

// if you look inside show non const display it change value to 2
// since we called by reference it will also change are obj value to 2
void ShowTestNonconst(Test& _test) {

    // this is why it could be dangerous to pass by ref
    _test.showNonConstDisplay();
};

int main() {
    std::cout << "Hello World!\n";

    // createing const var will make is so you can no longer change the varibale must alway stay with what you initi as.
    int a = 5;

    a = 2;

    const int b = 3;
    // this would be error
    // b = 1;

    //######################################

    int c = 90;
    const int* ptr = new int;

    //once const is used on a pointer it can no longer switch to be  initi with  cannot modify the contents of that pointer 
    // ptr = 2 would be modify the contents of the pointer
    //*ptr = 2;

    // however it is okay to change the pointer to an adress of something else, we just cannot change the contents of the pointers data
    ptr = &c;

    //##########################

    int d = 29;
    int* const ptr2 = new int;

    // once const is after * we can now change the contents of th the pointer 
    *ptr2 = 2;

    // However we cannot resgin the actual pointer it self to point to something else
    //ptr2 = &d;


    //############################

    int f = 34;
    const int* const ptr3 = new int;

    // now both can not be changed
    //*ptr3 = 2;

    //ptr3 = &f;


    //##################################
    Test t(30);

    cout << t.getValue() << endl;;

    // so only const object can call const voids
    // and non const objs can call non const voids
    // constant objs are initi at the time of declartion.
    const Test Ct;
    Ct.display();


    Test t2;
    t2.showNonConstDisplay();
    t2.getValue();
    t2.getAge();
}
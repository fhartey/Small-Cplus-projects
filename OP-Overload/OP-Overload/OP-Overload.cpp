#include <iostream>
#include <string>
#include <vector>
#include <cctype>

using namespace std;

class WholeNumber {

public:
    string enterin;
    int userenternum;
    ~WholeNumber() {
        cout << "your obj was destroyed" << endl;

    }

    // copy constructor good to have for other things
    WholeNumber(const WholeNumber& t)
    {
        this->enterin = t.enterin;
        this->userenternum = t.userenternum;
    };

    // copy operator
    WholeNumber& operator=(const WholeNumber& rhs) {
        this->userenternum = rhs.userenternum;
        this->enterin = rhs.enterin;
        return *this;
    };

    //https://stackoverflow.com/questions/52680748/initialize-object-with-value-using-operator-in-c
    WholeNumber(int userenternum) {
        this->userenternum = userenternum;

    }


    WholeNumber() {}

    WholeNumber operator+(WholeNumber& rhs) {
        return   (this->userenternum + rhs.userenternum);
    };

    string operator=(string rhs) {
        return (this->enterin = rhs);

    };


    string operator+(string rhs) {
        return   (this->enterin + rhs);
    };

    int operator=(int rhs) {

        return (this->userenternum = rhs);
    };

    int operator+(int rhs) {
        return (this->userenternum + rhs);
    };

    int operator*(int rhs) {
        return   (this->userenternum * rhs);
    };


    int operator/(int rhs) {
        return   (this->userenternum / rhs);
    };

    int operator-(int rhs) {
        return   (this->userenternum - rhs);
    };

};


ostream& operator<<(ostream& os, const WholeNumber& wn)
{

    os << "crueent string: " << wn.enterin << endl << "user enter number : " << wn.userenternum << endl;
    return os;
}
int main() {
    string heyu = "f";

    WholeNumber mynum;
    mynum = " 1 2 3";

    mynum = mynum + heyu + " ddd " + "eiur";
    mynum = 1 - 3;
    WholeNumber a = 4;
    a = "my name is a";
    //a = 3 * 2;
    cout << a << endl;
    a = a + 2;
    cout << a << endl;
    a = a * 2;
    cout << a << endl;
    a = a / 2;
    cout << mynum << endl;
    cout << a << endl;



    WholeNumber mynumber = 20 + 2;
    WholeNumber num3 = mynumber + 10;
    cout << mynumber;
    mynumber = mynumber + a + num3 + 9;


    cout << mynumber;

    WholeNumber e = mynumber;
    WholeNumber i(e);
}
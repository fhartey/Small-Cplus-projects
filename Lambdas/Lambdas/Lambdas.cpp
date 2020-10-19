#include <iostream>
#include <vector>
#include <algorithm>
#include<functional>
using namespace std;
// https://stackoverflow.com/questions/7627098/what-is-a-lambda-expression-in-c11
int op_increase(int i) { return ++i; }

void function1(vector<int>& x) {

    std::transform(x.begin(), x.end(), x.begin(), [](int a) {
        //cout<< "a " << a << endl;
        return  a < 30 ? 0 : a;

        });

}

void func3(vector<double>& v, double& epsilon) {
    std::transform(v.begin(), v.end(), v.begin(), [&](double d) -> double // -> what it will return if -> int it will turn the double into an int
        {
            epsilon = 10;
            if (d < epsilon) {

                return 0;
            }
            else {
                return d;
            }



        });

}

// smart pointers
int main() {
    std::vector<int> foo;
    std::vector<int> bar;

    // set some values:
    for (int i = 1; i < 6; i++)
        foo.push_back(i * 10);                         // foo: 10 20 30 40 50

    function1(foo);

    for (auto const& a : foo) {
        cout << "new a: " << a << endl;

    }

    vector<double> vecd;
    vecd.push_back(12.2);
    vecd.push_back(20.2);
    vecd.push_back(34.2);
    vecd.push_back(67.2);

    double var1 = 45;
    func3(vecd, var1);
    for (auto const& a : vecd) {
        cout << "new a: " << a << endl;

    }

    cout << "var2: " << var1 << endl;

}
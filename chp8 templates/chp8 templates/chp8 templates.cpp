#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include<list>
#include <array>
#include <ctype.h>

using namespace std;

template<class Instring, class Outlist>
Outlist split(Instring str, Outlist& dest) {
    string::iterator it = str.begin();
    string copystring;
 
    while (it != str.end()) {
        //ignore leading blanks
        if (isspace(*it)) {
            dest.push_back(copystring);
            copystring = "";

        }
        else {
            copystring = copystring + *it;
        }
        it++;
    }

    dest.push_back(copystring); // get the last string left
    return dest;
}



// begin and end are input iterators
// which are only use for reading elements
template<class In, class Out>
Out copy2(In begin, In end, Out dest) {
    while (begin != end)
    {
        /*
        *Another way for say this
        * *dest = * begin;
        * dest++;
        * begin++;
        */
        *dest++ = *begin++;

    }

    return dest;

}

template<class T>
T median(std::vector<T> v) {

    // come back to this and understand more

    // typedef is defining a new type for use in your code, like a short
    //typename here is letting the compiler know that value_type


    //the :: is the scope of the type. It is kind of like "is in" so size_type

    typedef typename vector<T>::size_type vec_sz;

    vec_sz size = v.size();
    if (size == 0) {
        throw domain_error("median of an empty vector");
    }

    sort(v.begin(), v.end());
    vec_sz mid = size / 2;

    return size % 2 == 0 ? (v[mid] + v[mid - 1]) / 2 : v[mid];

}



int main() {

    std::cout << "Hello World!\n" << endl;


    vector<double> numdouble;
    numdouble.push_back(2.9);
    numdouble.push_back(3.9);
    cout << median(numdouble) << endl;

    vector<int> numint;
    numint.push_back(4);
    numint.push_back(10);
    cout << median(numint) << endl;

    // std::algo copy function the same as are copy 2 function
    int myints[] = { 10,20,30,40,50,60,70 };
    std::vector<int> myvector(7);
    std::copy(myints, myints + 7, myvector.begin());


    // if you ever use std::copy with two vectors the output vector needs to be the same excat size as the input vector
    vector<int> copy(2);
    copy2(numint.begin(), numint.end(), copy.begin());
    cout << "copy size: " << copy.size() << endl;
    for (auto const& x : copy) {
        int i = 0;
        i++;
        cout << i << " : Copy vector number:" << x << endl;

    }



    // split template 
    const string examplesplit = "hello world, how are you";
    list<string> Lstring;

    vector<string> vecString;
    int hey = 9;
    std::array<string, 5> hh;


    split(examplesplit, vecString);
    split(examplesplit, Lstring);

    for (auto const& x : vecString) {
        cout << "Vec String: " << x << endl;

    }

    for (auto const& x : Lstring) {
        cout << "List string: " << x << endl;
    }

}
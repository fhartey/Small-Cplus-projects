#include <iostream>
#include <string>
using namespace std;


int main() {
    char* str = new char[6]; // Give str a memory address.
    str[0] = 'H';
    str[1] = 'E';
    str[2] = 'L';
    str[3] = 'L';
    str[4] = 'O';

    cout << str[0] << str[1] << str[2] << str[3] << str[4] << endl;

    cout << str[0] << " : " << (void*)&str[0] << endl;
    cout << str[1] << " : " << (void*)&str[1] << endl;
    cout << str[2] << " : " << (void*)&str[2] << endl;
    cout << str[3] << " : " << (void*)&str[3] << endl;
    cout << str[4] << " : " << (void*)&str[4] << endl;

    //cout<< 0x148ce70 << endl;
    char* hey = new char[6]; // Give str a memory address.


    hey = str;


    cout << hey[0] << " : " << (void*)&hey[0] << endl;
    cout << hey[1] << " : " << (void*)&hey[1] << endl;
    cout << hey[2] << " : " << (void*)&hey[2] << endl;
    cout << hey[3] << " : " << (void*)&hey[3] << endl;
    cout << hey[4] << " : " << (void*)&hey[4] << endl;



    // if this delete is commented out then str, never gets address delete
    // will cause mem leak the beg address will never be deleted
     //delete [] str; // Remove the first comment marking in this line to correct.

    str = new char[60]; /* Give str another memory address with
                                                        the first one gone forever.*/

    str[0] = 'W';
    str[1] = 'O';
    str[2] = 'R';
    str[3] = 'L';
    str[4] = 'D';

    cout << str[0] << str[1] << str[2] << str[3] << str[4] << endl;

    cout << str[0] << " : " << (void*)&str[0] << endl;
    cout << str[1] << " : " << (void*)&str[1] << endl;
    cout << str[2] << " : " << (void*)&str[2] << endl;
    cout << str[3] << " : " << (void*)&str[3] << endl;
    cout << str[4] << " : " << (void*)&str[4] << endl;



    cout << hey[0] << " : " << (void*)&hey[0] << endl;
    cout << hey[1] << " : " << (void*)&hey[1] << endl;
    cout << hey[2] << " : " << (void*)&hey[2] << endl;
    cout << hey[3] << " : " << (void*)&hey[3] << endl;
    cout << hey[4] << " : " << (void*)&hey[4] << endl;

    delete[] str; // This deletes the 60 bytes, not just the first 30.
}
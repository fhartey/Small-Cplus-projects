#include <iostream>
#include <string>
#include <map>
#include <random>
#include <bitset>
#include <vector>
#include <algorithm>
using namespace std;



class compress {

private:



    int StoredBitsIndex = 0;
    vector<compress> StoredBits;

    const int TextLegnthBits = 15; // padd out the string in bits sections
    const int DivideByCompress = 16; // should equal the bits you want to dvivde by
    const int SubIndex = 15; // sub the compress map string when adding a 1 or zero
    int CurrentIndex = 0;


    void CheckSymbol(const char _symbol, const int counter) {
        compress _compress;
        _compress.Id = _symbol;
        for (auto const& x : StoredBits) {
            if (x.Id == _compress.Id) {
                _compress.IdBits = x.IdBits;
                CompressIt(counter, _compress);
            }
        }
        CompressIt(counter, _compress);

    };

    bool CompressIt(const int counter, compress& _compress) {
        // if the ID.s match grad the bits that were stored inside the vec
        for (auto& x : StoredBits) {
            if (x.Id == _compress.Id) {
                std::bitset<16> _currentbit(_compress.IdBits);
                _currentbit[SubIndex - counter] = 1;
                _compress.IdBits = _currentbit.to_ulong();
                x.IdBits = _compress.IdBits;
                return true;
            }
        }
        std::bitset<16> _currentbit(_compress.IdBits);
        _currentbit[SubIndex - counter] = 1;
        _compress.IdBits = _currentbit.to_ulong();
        StoredBits.push_back({ _compress });
        return true;
    }


    bool PaddBits(vector<compress>& _compress, long index)
    {
        std::bitset<16> _currentbits(_compress[index].IdBits);
        // shift the bits over until we no longer get a zero
        if (_currentbits[0] == 0) {
            //lastdigit = num / 10;
            _currentbits = _currentbits >> 1;
            _compress[index].IdBits = _currentbits.to_ulong();
            _compress[index].Padding++;
            return PaddBits(_compress, index);
        }
        else {
            index++;
        }
        if (index == _compress.size()) {

            Reset();
            return true;
        }
        else {
            return PaddBits(_compress, index);
        }

    }

    void Reset() {
        CurrentIndex = 0;
        for (auto& x : StoredBits)
        {
            FinalStoredBits.push_back({ x.Id, x.IdBits, x.Padding, StoredBitsIndex });
        }

        StoredBits.clear();
        StoredBitsIndex++;
    }



public:
    char Id;
    long IdBits;
    long Padding;
    long index;
    vector<compress> FinalStoredBits;
    compress(char Id, long IdBits, long Padding, long index) : Id(Id), IdBits(IdBits), Padding(Padding), index(index) {};
    compress() : Id(), IdBits(0), Padding(0), index(0) {};


    void readin(const string _text) {
        std::string::const_iterator it = _text.begin();
        long counter = 0;
        while (it != _text.end()) {

            // cout << "Symbol: "<< *it << endl;
            if (counter > TextLegnthBits) {
                counter = 0;
                PaddBits(StoredBits, 0);
            }
            // make the call here to send it into function
            CheckSymbol(*it, counter);
            it++;
            counter++;
            CurrentIndex++;
        }
        PaddBits(StoredBits, 0);


    };



    void debug() {
        int index = 0;
        int charin = 0;
        cout << "HHHHH" << endl;
        /*for (auto const&x : FinalStoredBits){
        cout << x.Id ;

        }*/

        for (auto& x : FinalStoredBits) {
            if (index <= x.index) {
                cout << "index" << index << endl;
                index++;
            }
            charin = x.Id; // use this to get the chars into their int form
         // remove bits not nescerally since its only one will only need padded number
            if (x.IdBits == 1 && x.Padding != 0) {

                cout << "Id: " << x.Id << " | " << x.Padding << endl;
            }
            else if (x.Padding == 0) {

                cout << "Id: " << x.Id << " : " << x.IdBits << endl;
            }
            else {

                cout << "Id: " << x.Id << " : " << x.IdBits << " | " << x.Padding << endl;
            }
        }


        /*
        for (auto  &x : FinalStoredBits){
          if(index <= x.index){
            cout<< index << ",";
            index++;
          }
           charin= x.Id; // use this to get the chars into their int form

           if(x.IdBits == 1 && x.Padding != 0){

          cout <<x.Id <<  "|" << x.Padding  << "/";
          }
          else if(x.Padding == 0 ){

              cout <<x.Id << ":" <<x.IdBits << "/" ;
          }
           else {

          cout<<x.Id << ":" <<x.IdBits << "|" << x.Padding << "/";
          }

        }
        */

    }


};


class Decompress {

public:
    vector<compress> Comp;
    Decompress(vector<compress> Comp) : Comp(Comp) {}
    string FinalString;
    
    const long bitsfulled = 0xffffffffffffffff; // 64bitset of 1's
    const int bitsempty = 0x00; // set bits to zero
    void CharToint(Decompress& _decompress) {
        int zeronum = 0x0000;

        // used to see if we went through all posible areas of where char could be
        std::bitset<16> _checkbitindex(zeronum);
        char CharArray[17];
        vector<char> vecchar; // store the chars inside here

        for (auto& x : _decompress.Comp) {

            std::bitset<16> _currentbits(x.IdBits);
            for (int i = 0; i <= 15; i++) {
                if (_currentbits[i] == 1) {
                    _checkbitindex[i] = 1; //storing 1 there so we know its place is taken
                    CharArray[i] = x.Id; // setting the id to char array in its correct 
                }
            }
            // if check index equals all ones need to
            // dump the char reset it 32 bits has been filled
            if (_checkbitindex == bitsfulled) {
                for (int i = 15; i >= 0; i--) {

                    vecchar.push_back(CharArray[i]);
                    CharArray[i] = '\0';

                }
                _checkbitindex = bitsempty;
            }
        }
        // any left over bits pushing back into the vec
        for (int i = 15; i >= 0; i--) {
            vecchar.push_back(CharArray[i]);
        }

        //TODO put this in debug method just print out the string
        for (auto const& x : vecchar) {

            cout << x;
        }
    };


    bool UnPaddBits(Decompress& _decompress, int index, int SizeCounter, int CurrentIndex)
    {
        if (SizeCounter == _decompress.Comp.size()) {
            CharToint(_decompress);
            return false;
        }
        // probabyl delete this code piece becaue this doesnt looked used// get rid of current index
        if (CurrentIndex != _decompress.Comp[index].index) {
            CurrentIndex++;
        }
        std::bitset<16> _currentbits(_decompress.Comp[index].IdBits);
        _currentbits = _currentbits << _decompress.Comp[index].Padding;
        _decompress.Comp[index].IdBits = _currentbits.to_ulong();
        _decompress.Comp[index].Padding = 0;
        index++;
        SizeCounter++;
        return UnPaddBits(_decompress, index, SizeCounter, CurrentIndex);
    }


    void debug(Decompress& _decompress) {
        int index = 0;
        int charin = 0;
        for (auto& x : _decompress.Comp) {
            if (index <= x.index) {
                cout << "index" << index << endl;
                index++;
            }
            charin = x.Id; // use this to get the chars into their int form
            cout << "Id: " << charin << " : " << x.IdBits << " : " << x.Padding << endl;

        }
    }

};




int main() {

    compress c;
    c.readin("hey how are you");
    c.debug();
    // Decompress D(c.FinalStoredBits);
    // D.UnPaddBits(D, 0, 0, 0);
    // D.debug(D);
     // cout << "hello" << endl;
}
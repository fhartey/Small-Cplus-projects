#include <iostream>
#include <vector>
#include <string>
#include <bitset>
using namespace std;
class Cpu {

public:

    unsigned short A = 0x0f; // max 16 bit // need to be 8
    unsigned short F = 0xff;
    unsigned short B = 0x00;
    unsigned short D = 0x00;
    unsigned short H = 0x00;
    unsigned short C = 0x00;
    unsigned short E = 0x00;
    unsigned short L = 0x00;
    unsigned short SP = 0x00;
    unsigned short PC = 0x00;

    // copy two regs together 16 bits
    unsigned int AF() { return CombineTwoReg(A, F); };
    unsigned int BC() { return CombineTwoReg(B, C); };
    unsigned int DE() { return CombineTwoReg(D, E); };
    unsigned int HL() { return CombineTwoReg(H, L); };



    int CombineTwoReg(unsigned short a, unsigned short b) {
        std::bitset<16> _bitA(a), _bitB(b);
        _bitA = _bitA << 8; // shift 8 bits over
        _bitA = _bitA | _bitB; // or together two regs
        //cout << "bit A: " << _bitA << " bit b: "<< _bitB << endl;
        return _bitA.to_ulong();
    }


    void SetZeroFlag() {
        std::bitset<16> _currentbit(F);
        _currentbit[7] == 1 ? _currentbit[7] = 0 : _currentbit[7] = 1;
        F = _currentbit.to_ulong();

    }

    void SetSubFlag() {
        std::bitset<16> _currentbit(F);
        _currentbit[6] == 1 ? _currentbit[6] = 0 : _currentbit[6] = 1;
        F = _currentbit.to_ulong();

    }


    void SetHalfCarryFlag() {
        std::bitset<16> _currentbit(F);
        _currentbit[5] == 1 ? _currentbit[5] = 0 : _currentbit[5] = 1;
        F = _currentbit.to_ulong();

    }

    void SetCaryFlag() {
        std::bitset<16> _currentbit(F);
        _currentbit[4] == 1 ? _currentbit[4] = 0 : _currentbit[4] = 1;
        F = _currentbit.to_ulong();

    }
};
int main() {

    Cpu r;
    std::cout << "Hello World!\n";
    r.SetZeroFlag();
    r.SetCaryFlag();
    r.SetHalfCarryFlag();
    r.SetSubFlag();
    cout << "ddddd" << endl;
    cout << "rf: " << r.F << endl;
    std::bitset<8> y(r.F);
    cout << y << endl;


    //r.SetZeroFlag();
    cout << "aaaaa" << endl;
    cout << "rf: " << r.F << endl;

    cout << y << endl;
    // cout << "bitset: " << " af: " << r.AF << endl;;
    r.CombineTwoReg(r.A, r.F);
    //r.AF = r.CombineTwoReg( r.A, r.F);
    std::bitset<16> t(r.AF());
    cout << "bitset: " << t << " af: " << r.AF() << endl;;
}
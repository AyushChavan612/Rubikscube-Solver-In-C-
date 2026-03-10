#ifndef Rubikscube_hpp
#define Rubikscube_hpp

#include<iostream>
using namespace std;

class Rubikscube{
public:
    static constexpr char Face[6] = {'W' , 'G' , 'R' , 'B' , 'O' , 'Y'};
    
    void printPartial(int face);

    void print();
    
    virtual char getColor(int face, int row, int col) = 0;

    bool isSolved();

    virtual void rotateFace(int face) = 0;

    virtual void L()=0;

    virtual void L2()=0;

    virtual void Lprime()=0;

    virtual void R()=0;

    virtual void R2()=0;

    virtual void Rprime()=0;

    virtual void F()=0;

    virtual void F2()=0; 

    virtual void Fprime()=0;

    virtual void B()=0;

    virtual void B2()=0;

    virtual void Bprime()=0;

    virtual void U()=0;

    virtual void U2()=0;

    virtual void Uprime()=0;

    virtual void D()=0;

    virtual void D2()=0;

    virtual void Dprime()=0;

};

#endif
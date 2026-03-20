#ifndef Rubikscube_hpp
#define Rubikscube_hpp

#include<iostream>
#include<vector>
using namespace std;

class Rubikscube{
public:
    static constexpr char Face[6] = {'W' , 'G' , 'R' , 'B' , 'O' , 'Y'};

      // cornerMap[Slot][StickerIndex] -> {Face, Row, Col}
    static constexpr int cornerMap[8][3][3] = {
        {{0, 2, 0}, {1, 0, 2}, {2, 0, 0}}, // 0: White-Green-Red (Top-Left-Front)
        {{0, 2, 2}, {2, 0, 2}, {3, 0, 0}}, // 1: White-Red-Blue (Top-Front-Right)
        {{2, 2, 0}, {1, 2, 2}, {5, 0, 0}}, // 2: Red-Green-Yellow (Front-Left-Bottom)
        {{2, 2, 2}, {5, 0, 2}, {3, 2, 0}}, // 3: Red-Yellow-Blue (Front-Bottom-Right)
        {{0, 0, 2}, {3, 0, 2}, {4, 0, 0}}, // 4: White-Blue-Orange (Top-Right-Back)
        {{0, 0, 0}, {4, 0, 2}, {1, 0, 0}}, // 5: White-Orange-Green (Top-Back-Left)
        {{4, 2, 0}, {3, 2, 2}, {5, 2, 2}}, // 6: Orange-Blue-Yellow (Back-Right-Bottom)
        {{4, 2, 2}, {5, 2, 0}, {1, 2, 0}}  // 7: Orange-Yellow-Green (Back-Bottom-Left)
    };

    // cornerOrientations[CornerID][Twist] -> {Color0, Color1, Color2}
    static constexpr int cornerOrientations[8][3][3] = {
        {{0, 1, 2}, {2, 0, 1}, {1, 2, 0}}, // 0: White, Green, Red
        {{0, 2, 3}, {3, 0, 2}, {2, 3, 0}}, // 1: White, Red, Blue
        {{2, 1, 5}, {5, 2, 1}, {1, 5, 2}}, // 2: Red, Green, Yellow
        {{2, 5, 3}, {3, 2, 5}, {5, 3, 2}}, // 3: Red, Yellow, Blue
        {{0, 3, 4}, {4, 0, 3}, {3, 4, 0}}, // 4: White, Blue, Orange
        {{0, 4, 1}, {1, 0, 4}, {4, 1, 0}}, // 5: White, Orange, Green
        {{4, 3, 5}, {5, 4, 3}, {3, 5, 4}}, // 6: Orange, Blue, Yellow
        {{4, 5, 1}, {1, 4, 5}, {5, 1, 4}}  // 7: Orange, Yellow, Green
    };

    pair<vector<int>, vector<int>> res = {vector<int>(8), vector<int>(8)};
    vector<int> cornerNo = {7, 13, 38, 44, 25, 19, 56, 50};

    enum class Move {
        U, UPRIME, U2,
        D, DPRIME, D2,
        L, LPRIME, L2,
        R, RPRIME, R2,
        F, FPRIME, F2,
        B, BPRIME, B2, 
        stop
    };

    static int getNumber(char color);
    
    void printPartial(int face);

    void print();

    string getMove(int num);

    void performMove(Move move);

    void invertMove(Move move);
    
    void scrambleCube(int num);

    pair<vector<int>,vector<int>>& getPermutationAndOrientation();
    
    virtual char getColor(int face, int row, int col) const = 0;

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

    virtual void setCorner(int cornerNo, int actualCorner, int orientation)=0;
};

#endif

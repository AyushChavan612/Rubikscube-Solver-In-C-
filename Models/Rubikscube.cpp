#include "Rubikscube.hpp"
#include <vector>
#include <random>
#include <chrono>

void Rubikscube::printPartial(int face){
    for(int row = 0; row < 3; ++row){

            for(int temp = 0; temp < 3; ++temp){
                cout << "  ";
            }
            
            cout << " ";

            for(int color = 0; color < 3; ++color){
                cout << getColor(face,row,color) << " ";
            }

            cout << endl;
    }
    cout << endl;
}

void Rubikscube::print() {

       printPartial(0);
        
        for(int row = 0; row < 3; ++row){
            for(int face = 1; face <= 4; ++face){
                for(int col = 0; col < 3; ++col){
                    cout << getColor(face , row , col) << " ";
                }
                cout << " ";
            }
            cout << endl;
        }
        
        cout << endl;
        printPartial(5);

        cout << endl;
}

bool Rubikscube::isSolved(){
    for(int i = 0; i < 6; ++i){
        for(int j = 0; j < 3; ++j){
            for(int k = 0; k < 3; ++k){
                if(getColor(i , j , k) != Face[i]){
                    return false;
                }
            }
        }
    }
    return true;
}

int Rubikscube::getNumber(char color){
    switch (color)
    {
        case 'W':
            return 0;
        case 'G' :
            return 1;
        case 'R' :
            return 2;
        case 'B' :
            return 3;
        case 'O' :
            return 4;
        case 'Y' :
            return 5;
    }
}

void Rubikscube::performMove(Move move){
      switch (move)
      {
        case Move::U : 
            this->U();
            break;
        case Move::U2 : 
            this->U2();
            break;
        case Move::UPRIME : 
            this->Uprime();
            break;
        case Move::L : 
            this->L();
            break;
        case Move::L2 : 
            this->L2();
            break;
        case Move::LPRIME : 
            this->Lprime();
            break;
        case Move::F : 
            this->F();
            break;
        case Move::F2 : 
            this->F2();
            break;
        case Move::FPRIME : 
            this->Fprime();
            break;
        case Move::R : 
            this->R();
            break;
        case Move::R2 : 
            this->R2();
            break;
        case Move::RPRIME : 
            this->Rprime();
            break;
        case Move::B : 
            this->B();
            break;
        case Move::B2 : 
            this->B2();
            break;
        case Move::BPRIME : 
            this->Bprime();
            break;
        case Move::D : 
            this->D();
            break;
        case Move::D2 : 
            this->D2();
            break;
        case Move::DPRIME : 
            this->Dprime();
            break;
      }
}

void Rubikscube::invertMove(Move move){
      switch (move)
      {
        case Move::U : 
            this->Uprime();
            break;
        case Move::U2 : 
            this->U2();
            break;
        case Move::UPRIME : 
            this->U();
            break;
        case Move::L : 
            this->Lprime();
            break;
        case Move::L2 : 
            this->L2();
            break;
        case Move::LPRIME : 
            this->L();
            break;
        case Move::F : 
            this->Fprime();
            break;
        case Move::F2 : 
            this->F2();
            break;
        case Move::FPRIME : 
            this->F();
            break;
        case Move::R : 
            this->Rprime();
            break;
        case Move::R2 : 
            this->R2();
            break;
        case Move::RPRIME : 
            this->R();
            break;
        case Move::B : 
            this->Bprime();
            break;
        case Move::B2 : 
            this->B2();
            break;
        case Move::BPRIME : 
            this->B();
            break;
        case Move::D : 
            this->Dprime();
            break;
        case Move::D2 : 
            this->D2();
            break;
        case Move::DPRIME : 
            this->D();
            break;
      }
}


void Rubikscube::scrambleCube(int num) {
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    
    int prevFace = -1; 
    int movesApplied = 0;
    
    while(movesApplied < num) {
        int randomMove = rng() % 18;
        int currentFace = randomMove / 3;
        
        if(currentFace != prevFace) {
            this->performMove(static_cast<Rubikscube::Move>(randomMove));
            prevFace = currentFace;
            movesApplied++;
        }
    }
}

 pair<vector<int>,vector<int>>& Rubikscube::getCornerPermutationAndOrientation() {
        res.first.clear();
        res.second.clear();

        for(int i = 0; i < 8; ++i) {
            int mask = 0;
            vector<int> corner;
            
            for(int j = 0; j < 3; ++j) {
                const int* coordinates = cornerMap[i][j]; 
                
                char color = this->getColor(coordinates[0], coordinates[1], coordinates[2]);
                int num = this->getNumber(color);
                
                mask = mask | (1 << num);
                corner.push_back(num);
            }
            
            int cornerNum = -1;
            for(int j = 0; j < 8; ++j) {
                if(cornerNo[j] == mask) {
                    cornerNum = j;
                    break;
                }
            }
            res.first.push_back(cornerNum);
            
            for(int j = 0; j < 3; ++j) {
                bool flag = true; 
                for(int k = 0; k < 3; ++k) {
                    if(cornerOrientations[cornerNum][j][k] != corner[k]) {
                        flag = false;
                        break;
                    }
                }
                if(flag) {
                    res.second.push_back(j);
                    break;
                }
            }
        }
         
        return res;
}

pair<vector<int>,vector<int>>& Rubikscube::getEdgePermutationAndOrientation(){
     res.first.clear();
     res.second.clear();

     for(int edge = 0; edge < 12; ++edge){
         int mask=0;

         vector<int> colors;
         for(int i = 0; i < 2; ++i){
            const int* coordinates = edgeMap[edge][i];
            char color = this -> getColor(coordinates[0],coordinates[1],coordinates[2]);
            int num = this -> getNumber(color);
            colors.push_back(num);
            mask = mask | (1 << num);
         }

         int idx;
         for(int i = 0; i < 12; ++i){
            if(mask == Rubikscube::edgeNo[i]){
                idx=i;
                break;
            }
         }

         res.first.push_back(idx);

         for(int i = 0; i < 2; ++i){
            bool flag = true;
            for(int j = 0; j < 2; ++j){
                if(Rubikscube::edgeOrientation[idx][i][j] != colors[j]){
                    flag = false;
                    break;
                }
            }
            if(flag){
                res.second.push_back(i);
                break;
            }
         }
     }

     return res;    
}
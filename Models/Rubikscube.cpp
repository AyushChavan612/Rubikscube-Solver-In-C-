#include "Rubikscube.hpp"

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
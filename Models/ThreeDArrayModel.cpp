#include "Rubikscube.hpp"

class ThreeDArrayModel : public Rubikscube {
private:
    char cube[6][3][3]; 
public:
     ThreeDArrayModel(){
        for(int i = 0; i < 6; ++i){
            for(int j = 0; j < 3; ++j){
                for(int k = 0; k < 3; ++k){
                    this->cube[i][j][k] = Face[i];
                }
            }
        }
     }

     char getColor(int face , int row , int col) const override {
         return cube[face][row][col];
     }

     void rotateFace(int face) override {
         char tempCube[3][3];
         for(int j = 0; j < 3; ++j){
                for(int k = 0; k < 3; ++k){
                    tempCube[j][k] = this->cube[face][j][k];
                }
          }

          for(int j = 0; j < 3; ++j){
                for(int k = 0; k < 3; ++k){
                    this -> cube[face][j][k] = tempCube[abs(2-k)][j];
                }
           }
     }

     void L() override {
         char temp[3];
         this -> rotateFace(1);

         for(int i = 0; i < 3; ++i){
             temp[i] = this->cube[0][i][0];
         }
         for(int i = 2; i >= 0; --i){
            this -> cube[0][abs(i-2)][0] = this->cube[4][i][2];
         }
         for(int i = 0;i < 3; ++i){
             this->cube[4][i][2] = this->cube[5][abs(i-2)][0];
         }
         for(int i = 0;i < 3; ++i){
            this->cube[5][i][0] = this->cube[2][i][0];
         }
         for(int i = 0;i < 3; ++i){
            this->cube[2][i][0] = temp[i];
         }
     }

     void L2() override {
        this->L();
        this->L();
     }

     void Lprime() override {
        this -> L2();
        this -> L();
     }

     void U() override {
         char temp[3];
         this -> rotateFace(0);

         for(int i = 0; i < 3; ++i){
            temp[i] = this -> cube[4][0][i];
         }
         for(int i = 0; i < 3; ++i){
            this -> cube[4][0][i] = this -> cube[1][0][i];
         }
         for(int i = 0; i < 3; ++i){
            this -> cube[1][0][i] = this -> cube[2][0][i];
         }
         for(int i = 0; i < 3; ++i){
            this -> cube[2][0][i] = this -> cube[3][0][i];
         }
         for(int i = 0; i < 3; ++i){
            this -> cube[3][0][i] = temp[i];
         }
     }

     void U2() override {
        this->U();
        this->U();
     }

     void Uprime() override {
        this -> U2();
        this -> U();
     }

     void F() override {
         char temp[3];
         this -> rotateFace(2);

         for(int i = 0; i < 3; ++i){
            temp[i] = this -> cube[0][2][i];
         }
         for(int i = 0; i < 3; ++i){
            this -> cube[0][2][i] = this -> cube[1][abs(2-i)][2];
         }
         for(int i = 0; i < 3; ++i){
            this -> cube[1][i][2] = this -> cube[5][0][i];
         }
         for(int i = 0; i < 3; ++i){
            this -> cube[5][0][i] = this -> cube[3][abs(2-i)][0];
         }
         for(int i = 0; i < 3; ++i){
            this -> cube[3][i][0] = temp[i];
         }
     }

     void F2() override {
        this->F();
        this->F();
     }

     void Fprime() override {
        this -> F2();
        this -> F();
     }

     void R() override {
         char temp[3];
         this -> rotateFace(3);

         for(int i = 0; i < 3; ++i){
            temp[i] = this -> cube[0][i][2];
         }
         for(int i = 0; i < 3; ++i){
            this -> cube[0][i][2] = this -> cube[2][i][2];
         }
         for(int i = 0; i < 3; ++i){
            this -> cube[2][i][2] = this -> cube[5][i][2];
         }
         for(int i = 0; i < 3; ++i){
            this -> cube[5][i][2] = this -> cube[4][abs(2-i)][0];
         }
         for(int i = 0; i < 3; ++i){
            this -> cube[4][abs(2-i)][0] = temp[i];
         }
     }

     void R2() override {
        this->R();
        this->R();
     }

     void Rprime() override {
        this -> R2();
        this -> R();
     }

     void B() override {
         char temp[3];
         this -> rotateFace(4);

         for(int i = 0; i < 3; ++i){
            temp[i] = this -> cube[0][0][i];
         }
         for(int i = 0; i < 3; ++i){
            this -> cube[0][0][i] = this -> cube[3][i][2];
         }
         for(int i = 0; i < 3; ++i){
            this -> cube[3][i][2] = this -> cube[5][2][abs(2-i)];
         }
         for(int i = 0; i < 3; ++i){
            this -> cube[5][2][i] = this -> cube[1][i][0];
         }
         for(int i = 0; i < 3; ++i){
            this -> cube[1][abs(2-i)][0] = temp[i];
         }
     }

     void B2() override {
        this->B();
        this->B();
     }

     void Bprime() override {
        this -> B2();
        this -> B();
     }


     void D() override {
         char temp[3];
         this -> rotateFace(5);

         for(int i = 0; i < 3; ++i){
            temp[i] = this -> cube[2][2][i];
         }
         for(int i = 0; i < 3; ++i){
            this -> cube[2][2][i] = this -> cube[1][2][i];
         }
         for(int i = 0; i < 3; ++i){
            this -> cube[1][2][i] = this -> cube[4][2][i];
         }
         for(int i = 0; i < 3; ++i){
            this -> cube[4][2][i] = this -> cube[3][2][i];
         }
         for(int i = 0; i < 3; ++i){
            this -> cube[3][2][i] = temp[i];
         }
     }

     void D2() override {
        this->D();
        this->D();
     }

     void Dprime() override {
        this -> D2();
        this -> D();
     }

     void setCorner(int cornerNo, int actualCorner, int orientation) {
        const int* color = cornerOrientations[actualCorner][orientation];
        for (int i = 0; i < 3; ++i) {
            int faceIdx = cornerMap[cornerNo][i][0];
            int row     = cornerMap[cornerNo][i][1];
            int col     = cornerMap[cornerNo][i][2];

            this -> cube[faceIdx][row][col] = Rubikscube::Face[color[i]];
        }
    }
     
     bool operator==(const ThreeDArrayModel& other) const {
        for(int face = 0; face < 6; ++face){
			for(int i = 0; i < 3; ++i) {
				for(int j = 0; j < 3; ++j){
					if(this -> cube[face][i][j] != other.cube[face][i][j]){
						return false;
					}
				}
			}
		}
        return true;
    }
};

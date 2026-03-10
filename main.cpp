// #include "Models/ThreeDArrayModel.cpp"
#include "Models/Rubikscube.cpp"
#include "Models/OneDArrayModel.cpp"

int main(){
    OneDArrayModel cube;
    cube.print();
    cube.R();
    cube.print();
    cube.L();
    cube.print();
    cube.R2();
    cube.print();
    cube.Rprime();
    cube.print();
}
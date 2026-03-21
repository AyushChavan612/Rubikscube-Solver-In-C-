#ifndef ASTAR_H
#define ASTAR_H

#include "../Utils/GenericRubiksHash.hpp"
#include "../PatternDatabase/CornerDatabase/CreateCornerDatabase.cpp"
#include<unordered_map>
#include<queue>

template<class T>
class AStar{
private:
    T cube;
    unordered_map<T,int,GenericHash> Dist;
    unordered_map<T,Rubikscube::Move,GenericHash> Parent;
    CornerDB &db;
    
    class Node {
    public:
        T cube;
        int depth;
        int herustic;

        Node(T cube, int depth , int herustic){
            this -> cube = cube;
            this -> depth = depth;
            this -> herustic = herustic;
        }
    };

    class CompareNode{
    public:
        bool operator()(const Node &a , Node &b){
            return (a.depth+a.herustic) > (b.depth+b.herustic);
        } 
    };

public:

    AStar(T cube, CornerDB &db) : cube(cube), db(db) { }

    void solve(){
        if (this->cube.isSolved()) {
            cout << "Cube is already solved!\n";
            return;
        }

        priority_queue<Node,vector<Node>,CompareNode> pq;

        pq.push(Node(this->cube,0,0));
        Parent[this->cube] = Rubikscube::Move::stop;
        Dist[cube] = 0;
        
        Encoder<T> encoder;

        // cout << "hello\n";

        bool flag = false;
        while(!pq.empty()){
            Node node = pq.top();
            pq.pop();

            if(Dist.find(node.cube) != Dist.end()){
                if(Dist[node.cube] < node.depth){
                    continue;
                }
            }

            // cout << "Hello\n";

            for(int i = 0; i < 18; ++i){
                node.cube.performMove(static_cast<Rubikscube::Move>(i));

                int index = encoder.getRank(node.cube);
                // cout << "getting index" << endl;
                int currHerustic = db.getDistance(index);

                // cout << "inside for loop\n";

                if((Dist.find(node.cube) == Dist.end()) || (Dist[node.cube] > node.depth+1)){
                    Dist[node.cube] = node.depth + 1;
                    Parent[node.cube] = static_cast<Rubikscube::Move>(i);
                    pq.push(Node(node.cube,node.depth+1,currHerustic));
                }

                if(node.cube.isSolved()){
                    flag=true;
                    break;
                }
                else {
                    node.cube.invertMove(static_cast<Rubikscube::Move>(i));
                }
            }

            if(flag){
                break;
            }
        }

        // cout << flag << endl;

        if(!flag){
            cout << "Solution not found\n";
            return ;
        }

        printMove();
        Parent.clear();
        Dist.clear();
    }

    void printMove() {
        vector<Rubikscube::Move> moves;
        T tempCube; 

        while (Parent[tempCube] != Rubikscube::Move::stop) {
            moves.push_back(Parent[tempCube]);
            tempCube.invertMove(Parent[tempCube]);
        }

        reverse(moves.begin(), moves.end());
        
        tempCube.print(); 
        for (auto &move : moves) {
            tempCube.performMove(move);
            tempCube.print();
        }
    }
};

#endif

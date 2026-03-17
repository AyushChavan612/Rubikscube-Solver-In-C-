#ifndef BFS_SOLVER
#define BFS_SOLVER

#include <queue>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include "../Utils/GenericRubiksHash.hpp"
#include "../Models/Rubikscube.hpp"

using namespace std;

template <class T>
class Bfs {
private:
    T cube;
    queue<T> q;
    unordered_map<T, Rubikscube::Move, GenericHash> visited;

public:
    Bfs(T cube) {
        this->cube = cube;
    }

    void solve() {
        if (this->cube.isSolved()) {
            cout << "Cube is already solved!\n";
            return;
        }

        q.push(this->cube);
        visited[this->cube] = Rubikscube::Move::stop;

        while (!q.empty()) {
            T node = q.front();
            q.pop();

            bool flag = false;
            for (int i = 0; i < 18; ++i) {
                node.performMove(static_cast<Rubikscube::Move>(i));
                
                if (visited.find(node) == visited.end()) {
                    visited[node] = static_cast<Rubikscube::Move>(i);
                    
                    if (node.isSolved()) {
                        flag = true;
                        break;
                    }
                    q.push(node);
                }
                node.invertMove(static_cast<Rubikscube::Move>(i));
            }
            if (flag) {
                break;
            }
        }

        printMove();
        visited.clear();
    }

    void printMove() {
        vector<Rubikscube::Move> moves;
        T tempCube; 

        while (visited[tempCube] != Rubikscube::Move::stop) {
            moves.push_back(visited[tempCube]);
            tempCube.invertMove(visited[tempCube]);
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
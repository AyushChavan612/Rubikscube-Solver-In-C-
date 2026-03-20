#include "Models/ThreeDArrayModel.cpp"
#include "Models/Rubikscube.cpp"
#include "Models/OneDArrayModel.cpp"
#include "Models/BitBoardModel.cpp"
#include "Solvers/Bfs.hpp"
#include "Solvers/Dfs.hpp"
#include "Solvers/IDDfs.hpp"
#include <chrono>
#include "PatternDatabase/CornerDatabase/CreateCornerDatabase.cpp"
#include "Solvers/AStar.hpp"

using namespace std::chrono;

int main(){
	auto start = high_resolution_clock::now();
    // ThreeDArrayModel cube;
    OneDArrayModel cube;
    // BitBoardModel cube;
    
    cube.scrambleCube(9);

    // Bfs solver(cube); 
    // solver.solve();

    string dbPath = "/home/pacforever/Documents/rubikscube solver in c++/PatternDatabase/Database/corner.pdb";
    
    CornerDB cornerDB(dbPath);
    cornerDB.createDatabase();

    AStar solver(cube,cornerDB);
    solver.solve();
    
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);
    cout << "Execution Time: " << duration.count() << " ms\n";
    return 0;
}

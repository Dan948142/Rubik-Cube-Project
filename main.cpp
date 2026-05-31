/*
Sanskar Sovitkar
*/

#include <bits/stdc++.h>
#include "Model/Cube_3D_Representation.cpp"
#include "Model/Cube_1D_Representation.cpp"
#include "Model/BitBoard_Representation.cpp"

#include "Solver/DFS.h"
#include "Solver/BFS.h"
#include "Solver/IDDFS.h"
#include "Solver/IDASTAR.h"
// #include "PatternDatabases/CornerPatternDatabase.h"
#include "PatternDatabases/CornerDBMaker.h"

using namespace std;

int main() {
    // Cube3D object3DArray;
    // Cube1D object1dArray;
    // RubiksCubeBitboard objectBitboard;

    // object3DArray.print();

    // if (object3DArray.isSolved()) cout << "SOLVED\n\n";
    // else cout << "NOT SOLVED\n\n";

    // if (object1dArray.isSolved()) cout << "SOLVED\n\n";
//     else cout << "NOT SOLVED\n\n";

//     if (objectBitboard.isSolved()) cout << "SOLVED\n\n";
//     else cout << "NOT SOLVED\n\n";

//     objectBitboard.u();
//     object3DArray.u();
//     object1dArray.u();
//     objectBitboard.print();
//     object3DArray.print();
//     object1dArray.print();

//     objectBitboard.l();
//     object3DArray.l();
//     object1dArray.l();
//     objectBitboard.print();
//     object3DArray.print();
//     object1dArray.print();

//     objectBitboard.f();
//     object3DArray.f();
//     object1dArray.f();
//     objectBitboard.print();
//     object3DArray.print();
//     object1dArray.print();

//     objectBitboard.r();
//     object3DArray.r();
//     object1dArray.r();
//     objectBitboard.print();
//     object3DArray.print();
//     object1dArray.print();

//     objectBitboard.b();
//     object3DArray.b();
//     object1dArray.b();
//     objectBitboard.print();
//     object3DArray.print();
//     object1dArray.print();

//     objectBitboard.d();
//     object3DArray.d();
//     object1dArray.d();
//     objectBitboard.print();
//     object3DArray.print();
//     object1dArray.print();

//     if (object3DArray.isSolved()) cout << "SOLVED\n\n";
//     else cout << "NOT SOLVED\n\n";

//     if (object1dArray.isSolved()) cout << "SOLVED\n\n";
//     else cout << "NOT SOLVED\n\n";

//     if (objectBitboard.isSolved()) cout << "SOLVED\n\n";
//     else cout << "NOT SOLVED\n\n";

//     objectBitboard.dPrime();
//     object3DArray.dPrime();
//     object1dArray.dPrime();
//     objectBitboard.print();
//     object3DArray.print();
//     object1dArray.print();

//     objectBitboard.bPrime();
//     object3DArray.bPrime();
//     object1dArray.bPrime();
//     objectBitboard.print();
//     object3DArray.print();
//     object1dArray.print();

//     objectBitboard.rPrime();
//     object3DArray.rPrime();
//     object1dArray.rPrime();
//     objectBitboard.print();
//     object3DArray.print();
//     object1dArray.print();

//     objectBitboard.fPrime();
//     object3DArray.fPrime();
//     object1dArray.fPrime();
//     objectBitboard.print();
//     object3DArray.print();
//     object1dArray.print();

//     objectBitboard.lPrime();
//     object3DArray.lPrime();
//     object1dArray.lPrime();
//     objectBitboard.print();
//     object3DArray.print();
//     object1dArray.print();

//     objectBitboard.uPrime();
//     object3DArray.uPrime();
//     object1dArray.uPrime();
//     objectBitboard.print();
//     object3DArray.print();
//     object1dArray.print();

//     if (object3DArray.isSolved()) cout << "SOLVED\n\n";
//     else cout << "NOT SOLVED\n\n";

//     if (object1dArray.isSolved()) cout << "SOLVED\n\n";
//     else cout << "NOT SOLVED\n\n";

//     if (objectBitboard.isSolved()) cout << "SOLVED\n\n";
//     else cout << "NOT SOLVED\n\n";

//     // Create two Cubes ------------------------------------------------------------------------------------------

//    Cube3D cube1;
//    Cube3D cube2;

//    Cube1D cube1;
//    Cube1D cube2;

//    RubiksCubeBitboard cube1;
//    RubiksCubeBitboard cube2;


// // Equality and assignment of cubes --------------------------------------------------------------------------

//     if(cube1 == cube2) cout << "Is equal\n";
//     else cout << "Not Equal\n";

//     cube1.randomSuffleCube(1);

//     if(cube1 == cube2) cout << "Is equal\n";
//     else cout << "Not Equal\n";

//     cube2 = cube1;

//     if(cube1 == cube2) cout << "Is equal\n";
//     else cout << "Not Equal\n";


// //  Unordered_map of Cubes  ------------------------------------------------------------------------------------


//    unordered_map<Cube3D, bool, Hash3d> mp1;

//    unordered_map<Cube1D, bool, Hash1d> mp1;

//    unordered_map<RubiksCubeBitboard, bool, HashBitboard> mp1;

//    mp1[cube1] = true;
//    cube2.randomSuffleCube(8);
//    if (mp1[cube1]) cout << "Cube1 is present\n";
//    else cout << "Cube1 is not present\n";

//    if (mp1[cube2]) cout << "Cube2 is present\n";
//    else cout << "Cube2 is not present\n";


// DFS Solver Testing __________________________________________________________________________________________
//    Cube3D cube;
//    cube.print();

//    vector<RubikCube::Move> shuffle_moves = cube.randomSuffleCube(6);
//    for (auto move: shuffle_moves) cout << cube.getMove(move) << " ";
//    cout << "\n";
//    cube.print();

//    DFSSolver<Cube3D, Hash3d> dfsSolver(cube, 8);
//    auto solve_moves = dfsSolver.solve();

//    for (auto move: solve_moves) cout << static_cast<int>(move) << " ";
//    cout << "\n";
//    dfsSolver.cube.print();


// BFS Solver -----------------------------------------------------------------------------------------------------
//    RubiksCubeBitboard cube;
//    cube.print();

//    vector<RubikCube::Move> shuffle_moves = cube.randomSuffleCube(6);
//    for(auto move: shuffle_moves) cout << cube.getMove(move) << " ";
//    cout << "\n";
//    cube.print();

//    BFS<RubiksCubeBitboard, HashBitboard> bfsSolver(cube);
//    auto solve_moves = bfsSolver.solve();

//    for(auto move: solve_moves) cout << static_cast<int>(move) << " ";
//    cout << "\n";
//    bfsSolver.cube.print();

// IDDFS Solver ----------------------------------------------------------------------------------------------------
//    RubiksCubeBitboard cube;
//    cube.print();

//    vector<RubikCube::Move> shuffle_moves = cube.randomSuffleCube(7);
//    for (auto move: shuffle_moves) cout << cube.getMove(move) << " ";
//    cout << "\n";
//    cube.print();

//    IDDFSSolver<RubiksCubeBitboard, HashBitboard> iddfsSolver(cube, 7);
//    auto solve_moves = iddfsSolver.solve();

//    for (auto move: solve_moves) cout << static_cast<int>(move) << " ";
//    cout << "\n";
//    iddfsSolver.cube.print();

// IDA* SOLVER ---------------------------------------------------------------------------------------------------
//    RubiksCubeBitboard cube;
//    cube.print();

//    vector<RubikCube::Move> shuffle_moves = cube.randomSuffleCube(5);
//    for (auto move: shuffle_moves) cout << cube.getMove(move) << " ";
//    cout << "\n";
//    cube.print();

//    IDAStarSolver<RubiksCubeBitboard, HashBitboard> idAstarSolver(cube);
//    auto solve_moves = idAstarSolver.solve();
//    for (auto move: solve_moves) cout << static_cast<int>(move) << " ";
//    cout << "\n";
//    idAstarSolver.cube.print();

// CornerPatternDatabase Testing ---------------------------------------------------------------------------------

//    CornerPatternDatabase cornerDB;
//    RubiksCubeBitboard cube;
//    cube.print();

//    cout << (int)cornerDB.getNumMoves(cube) << "\n";

//    cornerDB.setNumMoves(cube, 5);

//    cout << (int)cornerDB.getNumMoves(cube) << "\n";

//    cube.randomSuffleCube(1);
//    cube.print();
//    cout << (int)cornerDB.getNumMoves(cube) << "\n";

//    cornerDB.setNumMoves(cube, 6);

//    cout << (int)cornerDB.getNumMoves(cube) << "\n";


// CornerDBMaker Testing --------------------------------------------------------------------------
    string fileName = "C:\\Users\\user\\CLionProjects\\Rubik-Cube-Solver\\Databases\\cornerDepth5V1.txt";

//    Code to create Corner Database
//    CornerDBMaker dbMaker(fileName, 0x99);
//    dbMaker.bfsAndStore();

    RubiksCubeBitboard cube;
    auto shuffleMoves = cube.randomSuffleCube(13);
    cube.print();
    for (auto move: shuffleMoves) cout << cube.getMove(move) << " ";
    cout << "\n";

    IDAStarSolver<RubiksCubeBitboard, HashBitboard> idaStarSolver(cube, fileName);
    auto moves = idaStarSolver.solve();

    idaStarSolver.cube.print();
    for (auto move: moves) cout << static_cast<int>(move) << " ";
    cout << "\n";

    return 0;
}

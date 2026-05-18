#include "Model/Rubik.h"
#include "DFS.h"
#include <vector>
#include <iostream>

template<typename T, typename H>
class IDDFSSolver{
private:
    int max_search_depth;
    vector<RubikCube::Move> moves;

public:
    T cube;

    IDDFSSolver(T c, int d = 7){
        max_search_depth = d;
        cube = c;
    }

    vector<RubikCube::Move> solve(){
        // used the origional DFS Solver
        for(int i=1;i<=max_search_depth;i++){
            DFSSolver<T, H> dfssolved_cube(cube, i);        // solve this cube using dfs solver with max i depth
            moves = dfssolved_cube.solve();

            if(dfssolved_cube.cube.isSolved()){
                cube = dfssolved_cube.cube;
                break;
            }
        }
        return moves;
    }
    
};

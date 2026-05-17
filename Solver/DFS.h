#include <iostream>
#include <vector>
#include <Model/Rubik.h>
using namespace std;

// Typename T: RubiksCube Representation used (3d, 1d, Bitboard)
// Typename H: Corresponding Hash function

template<typename T, typename H>
class DFSSolver{
private:
    vector<RubikCube::Move> moves;
    int max_search_depth;

    bool dfs(int dep){
        if(cube.isSolved()) return true;
        if(dep > max_search_depth) return false;

        for(int i=0;i<18;i++){
            cube.move(RubikCube::Move(i));
            moves.push_back(RubikCube::Move(i));
            dfs(dep+1);
            cube.invert(RubikCube::Move(i));
            moves.pop_back();
        }
        return false;
    }

public:
    T cube;

    DFSSolver(T c, int d){
        moves.clear();
        cube = c;
        max_search_depth = d;
    }

    vector<RubikCube::Move> solve(){
        dfs(1);
        return moves;
    }
};

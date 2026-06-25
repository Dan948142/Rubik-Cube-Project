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
    unordered_map<T, int, H> visited; 

    bool dfs(int dep){
        if(cube.isSolved()) return true;
        if(dep > max_search_depth) return false;

        if(visited.count(cube) && visited[cube] <= dep){
            return false; 
        }

        visited[cube] = dep;

        for(int i=0;i<18;i++){
            cube.move(RubikCube::Move(i));
            moves.push_back(RubikCube::Move(i));
            if(dfs(dep+1)) return true; 
            cube.invert(RubikCube::Move(i));
            moves.pop_back();
        }
        return false;
    }

public:
    T cube;

    DFSSolver(T c, int d = 15){
        moves.clear();
        cube = c;
        max_search_depth = d;
    }

    vector<RubikCube::Move> solve(){
        visited.clear();
        dfs(1);
        return moves;
    }
};

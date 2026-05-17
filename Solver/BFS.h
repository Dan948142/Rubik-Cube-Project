#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>
#include "Model/Rubik.h"
using namespace std;

template<typename T, typename H>
class BFS{
private:
    vector<RubikCube::Move> moves;
    unordered_map<RubikCube, bool, H> visited;
    unordered_map<RubikCube, RubikCube::Move, H> move_done;

    T bfs(){
        queue<T> q;
        q.push(cube);
        visited[cube] = true;

        while(!q.empty()){
            auto node = q.front(); q.pop();

            if(node.isSolved()) return node;

            for(int i=0;i<18;i++){
                auto curr_move = RubikCube::Move(i);
                node.move(curr_move);   // check if this move performed was not visited already
                if(!visited[node]){
                    visited[node] = true;
                    move_done[node] = curr_move;
                    q.push(node);
                }
                node.invert(curr_move);
            }
        }

        return cube;
    }

public:
    T cube;
    BFS(T c){
        cube = c;
    }

    vector<RubikCube::Move> solve(){
        T solved_cube = bfs();
        assert(solved_cube.isSolved());
        T curr_cube = solved_cube;

        while(!(curr_cube == cube)){
            auto curr_move = move_done[curr_cube];
            moves.push_back(curr_move);
            curr_cube.invert(curr_move);
        }

        cube =solved_cube;
        reverse(moves.begin(), moves.end());
        return moves;
    }
};

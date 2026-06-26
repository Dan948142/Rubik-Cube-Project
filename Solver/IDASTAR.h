#include <iostream>
#include <unordered_map>
#include <queue>
#include "Model/Rubik.h"
#include "PatternDatabases/CornerPatternDatabase.h"

template<typename T, typename H>
class IDAStarSolver{
private:
    CornerPatternDatabase cornerDB;
    vector<RubikCube::Move> moves;
    unordered_map<T, RubikCube::Move, H> move_done;
    unordered_map<T, bool, H> visited;

    struct Node{
        T cube;
        int depth, estimate;
        Node(T c, int d, int e){
            cube = c;
            depth = d;
            estimate = e;
        }
    };

    struct compareCube{
        bool operator()(pair<Node, int> const &p1, pair<Node, int> const &p2){
            auto n1 = p1.first, n2 = p2.first;
            if(n1.depth + n1.estimate == n2.depth + n2.estimate){
                return n1.estimate > n2.estimate;
            } 
            return n1.depth + n1.estimate > n2.depth + n2.estimate;
        }
    };

    void resetStructure(){
        moves.clear();
        move_done.clear();
        visited.clear();
    }

    pair<T, int> IDAStar(int bound){
        priority_queue<pair<Node, int>, vector<pair<Node,int>>, compareCube> pq;

        Node start = Node(cube, 0, cornerDB.getNumMoves(cube));
        pq.push({start, 0});

        int next_bound = 100;

        while(!pq.empty()){
            auto p = pq.top();      pq.pop();
            Node node = p.first;

            if(visited[node.cube]) continue;
            visited[node.cube] = true;

            move_done[node.cube] = RubikCube::Move(p.second);
            if(node.cube.isSolved()) return make_pair(node.cube, bound);

            node.depth++;

            for(int i=0;i<18;i++){
                auto curr_move = RubikCube::Move(i);
                node.cube.move(curr_move);

                if(!visited[node.cube]){
                    node.estimate = cornerDB.getNumMoves(node.cube);

                    if(node.estimate + node.depth > bound){
                        next_bound = min(next_bound, node.estimate+node.depth);
                    }
                    else{
                        pq.push(make_pair(node, i));
                    }
                }
                node.cube.invert(curr_move);
            }
        }
        return make_pair(cube, next_bound);
    }

public:
    T cube;

    IDAStarSolver(T c, string filename){
        cube = c;
        cornerDB.fromFile(filename);
    }

    vector<RubikCube::Move> solve(){
        int bound = 1;
        auto p = IDAStar(bound);

        while(p.second != bound){
            resetStructure();
            bound = p.second;
            p = IDAStar(bound);
        }

        T solved_cube = p.first;
        assert(solved_cube.isSolved());

        T curr_cube = solved_cube;

        while(!(curr_cube == cube)){
            RubikCube::Move curr_move = move_done[curr_cube];
            moves.push_back(curr_move);
            curr_cube.invert(curr_move);
        }
        cube = solved_cube;
        reverse(moves.begin(), moves.end());
        return moves;
    }
    
};

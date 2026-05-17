#include <iostream>
#include <vector>
#include <time.h>
#include <random>
using namespace std;

class RubikCube{
public:
    enum class Face{UP, LEFT, FRONT, RIGHT, BACK, DOWN};
    enum class Color{WHITE, GREEN, RED, YELLOW, ORANGE, BLUE};
    
    enum class Move{
        L, L2, LPRIME,
        R, R2, RPRIME,
        U, U2, UPRIME,
        D, D2, DPRIME,
        F, F2, FPRIME,
        B, B2, BPRIME,
    };

    virtual Color getColor(Face f, unsigned row, unsigned col) const = 0;       // returns color at the given position

    static char getColorChar(Color c);     // return first letter of the character

    virtual bool isSolved() const = 0;   // returns if the cube is solved

    static string getMove(Move ind);    // returns move in string format

    /*
     * Print the Rubik Cube in Planar format.
     *
     * The sides:
     *    U
     *  L F R B
     *    D
     *
     * Color wise:
     *
     *          W W W
     *          W W W
     *          W W W
     *
     *  G G G   R R R   B B B   O O O
     *  G G G   R R R   B B B   O O O
     *  G G G   R R R   B B B   O O O
     *
     *          Y Y Y
     *          Y Y Y
     *          Y Y Y
     *
     * Row and Column Numberings:
     * rx -> row numbering
     * cx -> column numbering
     * bx -> both row and column numbering
     *
     *             b0 c1 c2
     *             r1  .  .
     *             r2  .  .
     *
     *  b0 c1 c2   b0 c1 c2   b0 c1 c2   b0 c1 c2
     *  r1  .  .   r1  .  .   r1  .  .   r1  .  .
     *  r2  .  .   r2  .  .   r2  .  .   r2  .  .
     *
     *             b0 c1 c2
     *             r1  .  .
     *             r2  .  .
     *
     */

    void print() const;

    vector<Move> randomSuffleCube(unsigned int times);      // randomly suffles the cube

    RubikCube& move(Move ind);      // performs the move in the cube

    RubikCube& invert(Move ind);    // invert a move

    // Rotational Moves
    virtual RubikCube &f() = 0;

    virtual RubikCube &fPrime() = 0;

    virtual RubikCube &f2() = 0;

    virtual RubikCube &u() = 0;

    virtual RubikCube &uPrime() = 0;

    virtual RubikCube &u2() = 0;

    virtual RubikCube &l() = 0;

    virtual RubikCube &lPrime() = 0;

    virtual RubikCube &l2() = 0;

    virtual RubikCube &r() = 0;

    virtual RubikCube &d() = 0;

    virtual RubikCube &dPrime() = 0;

    virtual RubikCube &d2() = 0;

    virtual RubikCube &rPrime() = 0;

    virtual RubikCube &r2() = 0;

    virtual RubikCube &b() = 0;

    virtual RubikCube &bPrime() = 0;

    virtual RubikCube &b2() = 0;

    string getCornerColorString(uint8_t ind) const;

    uint8_t getCornerIndex(uint8_t ind) const;

    uint8_t getCornerOrientation(uint8_t ind) const;

};

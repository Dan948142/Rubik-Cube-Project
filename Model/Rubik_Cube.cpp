#include "Rubik.h"
using namespace std;

// return starting color of the color
char RubikCube::getColorChar(Color c){
    switch (c){
    case Color::BLUE:
        return 'B';
    case Color::WHITE:
        return 'W';
    case Color::GREEN:
        return 'G';
    case Color::RED:
        return 'R';
    case Color::YELLOW:
        return 'Y';
    case Color::ORANGE:
        return 'O';
    }
}   

// describing the Move
string RubikCube::getMove(Move ind){
    switch(ind){
        case Move::B: return "B";
        case Move::B2: return "B2";
        case Move::BPRIME: return "BPRIME";
        case Move::L: return "L";
        case Move::L2: return "L2";
        case Move::LPRIME: return "LPRIME";
        case Move::F: return "F";
        case Move::F2: return "F2";
        case Move::FPRIME: return "FPRIME";
        case Move::R: return "R";
        case Move::R2: return "R2";
        case Move::RPRIME: return "RPRIME";
        case Move::U: return "U";
        case Move::U2: return "U2";
        case Move::UPRIME: return "UPRIME";
        case Move::D: return "D";
        case Move::D2: return "D2";
        case Move::DPRIME: return "DPRIME";
    }
}

// Performing a Move, by calling relevant function
RubikCube &RubikCube::move(Move ind){
    switch(ind){
        case Move::L: return this->l();
        case Move::L2: return this->l2();
        case Move::LPRIME: return this->lPrime();
        case Move::R: return this->r();
        case Move::R2: return this->r2();
        case Move::RPRIME: return this->rPrime();
        case Move::U: return this->u();
        case Move::U2: return this->u2();
        case Move::UPRIME: return this->uPrime();
        case Move::D: return this->d();
        case Move::D2: return this->d2();
        case Move::DPRIME: return this->dPrime();
        case Move::F: return this->f();
        case Move::F2: return this->f2();
        case Move::FPRIME: return this->fPrime();
        case Move::B: return this->b();
        case Move::B2: return this->b2();
        case Move::BPRIME: return this->bPrime();
    }
    return *this;
}

RubikCube &RubikCube::invert(Move ind){
    switch(ind){
        case Move::L: return this->lPrime();
        case Move::L2: return this->l2();
        case Move::LPRIME: return this->l();
        case Move::R: return this->rPrime();
        case Move::R2: return this->r2();
        case Move::RPRIME: return this->r();
        case Move::U: return this->uPrime();
        case Move::U2: return this->u2();
        case Move::UPRIME: return this->u();
        case Move::D: return this->dPrime();
        case Move::D2: return this->d2();
        case Move::DPRIME: return this->d();
        case Move::F: return this->fPrime();
        case Move::F2: return this->f2();
        case Move::FPRIME: return this->f();
        case Move::B: return this-bPrime();
        case Move::B2: return this->b2();
        case Move::BPRIME: return this->b();
    }
    return *this;
}

// Printing te Cube
void RubikCube::print() const {

    // printing the complete rubik cube in given format
    cout<<"Rubik Cube\n\n";

    for(int row = 0; row<=2; row++){
        for(int i=0;i<7;i++) cout<<" ";
        // the Upper Face
        for(int col=0;col<=2;col++){
            cout<<getColorChar(getColor(Face::UP, row, col))<<" ";
        }
        cout<<"\n";
    }

    for(int row = 0; row<=2;row++){
        // Left, Front, Right, Back
        for(int col=0;col<=2;col++) cout<<getColorChar(getColor(Face::LEFT, row, col))<<" ";
        cout<<" ";

        for(int col=0;col<=2;col++) cout<<getColorChar(getColor(Face::FRONT, row, col))<<" ";
        cout<<" ";

        for(int col=0;col<=2;col++) cout<<getColorChar(getColor(Face::RIGHT, row, col))<<" ";
        cout<<" ";

        for(int col=0;col<=2;col++) cout<<getColorChar(getColor(Face::BACK, row, col))<<" ";
        cout<<"\n";
    }

    // the down face
    for(int row = 0; row<=2; row++){
        for(int i=0;i<7;i++) cout<<" ";
        // the Upper Face
        for(int col=0;col<=2;col++){
            cout<<getColorChar(getColor(Face::DOWN, row, col))<<" ";
        }
        cout<<"\n";
    }
    cout<<"\n";
}

// randomly Shuffling the Cube
vector<RubikCube::Move> RubikCube::randomSuffleCube(unsigned int times){
    vector<RubikCube::Move> moves_performed;
    srand(time(0));
    for(unsigned int i=0;i<times;i++){
        unsigned int select_move = (rand() % 18);
        moves_performed.push_back(static_cast<Move>(select_move));
        this->move(static_cast<Move>(select_move));
    }
    return moves_performed;
}

// Helper Function returning string of Corner Cubie
string RubikCube::getCornerColorString(uint8_t ind) const {
    string str = "";
    switch(ind){
        // UFR
        case 0:
            str += getColorChar(getColor(Face::UP, 2, 2));
            str += getColorChar(getColor(Face::FRONT, 0, 2));
            str += getColorChar(getColor(Face::RIGHT, 0, 0));
            break;
        // UFL
        case 1:
            str += getColorChar(getColor(Face::UP, 2, 0));
            str += getColorChar(getColor(Face::FRONT, 0, 0));
            str += getColorChar(getColor(Face::LEFT, 0, 2));
            break;
        // UBL
        case 2:
            str += getColorChar(getColor(Face::UP, 0, 0));
            str += getColorChar(getColor(Face::BACK, 0, 2));
            str += getColorChar(getColor(Face::LEFT, 0, 0));
            break;
        // UBR
        case 3:
            str += getColorChar(getColor(Face::UP, 0, 2));
            str += getColorChar(getColor(Face::BACK, 0, 0));
            str += getColorChar(getColor(Face::RIGHT, 0, 2));
            break;
        // DFR
        case 4:
            str += getColorChar(getColor(Face::DOWN, 0, 2));
            str += getColorChar(getColor(Face::FRONT, 2, 2));
            str += getColorChar(getColor(Face::RIGHT, 2, 0));
            break;
        // DFL
        case 5:
            str += getColorChar(getColor(Face::DOWN, 0, 0));
            str += getColorChar(getColor(Face::FRONT, 2, 0));
            str += getColorChar(getColor(Face::LEFT, 2, 2));
            break;
        // DBL
        case 6:
            str += getColorChar(getColor(Face::DOWN, 2, 0));
            str += getColorChar(getColor(Face::BACK, 2, 2));
            str += getColorChar(getColor(Face::LEFT, 2, 0));
            break;
        // DBR          
        case 7:
            str += getColorChar(getColor(Face::DOWN, 2, 2));
            str += getColorChar(getColor(Face::BACK, 2, 0));
            str += getColorChar(getColor(Face::RIGHT, 2, 2));
            break;
    }
    return str;
}

uint8_t RubikCube::getCornerIndex(uint8_t ind) const{
    string corner = getCornerColorString(ind);

    uint8_t ret = 0;
    for(auto c:corner){
        if(c != 'W' and c != 'Y') continue;
       if(c == 'Y') ret |= (1<<2);
    }
    for(auto c:corner){
        if(c != 'R' and c != 'O') continue;
        if(c == 'O') ret |= (1<<1);
    }
    for(auto c:corner){
        if(c != 'B' and c != 'G') continue;
        if(c == 'G') ret |= (1<<0);
    }
    return ret;
}

uint8_t RubikCube::getCornerOrientation(uint8_t ind) const{
    string corner = getCornerColorString(ind);

    string actual_str = "";

    for(auto c:corner){
        if(c != 'W' and c != 'Y') continue;
        actual_str.push_back(c);
    }

    if(corner[1] == actual_str[0]) return 1;
    else if(corner[2] == actual_str[0]) return 2;
    else return 0;
}


#include "Rubik.h"
// Implementation for the Cube as a 3D array
/*
Up → 0 (White)
Left → 1 (Green)
Front → 2 (Red)
Right → 3 (Blue)
Back → 4 (Orange)
Down → 5 (Yellow)
*/
// grid[i][j][k] -> ith side, jth row, kth col

class Cube3D : public RubikCube{
private:
    void rotateFace(int ind) {
        char temp_arr[3][3] = {};
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                temp_arr[i][j] = cube[ind][i][j];
            }
        }

        for (int i = 0; i < 3; i++) cube[ind][0][i] = temp_arr[2 - i][0];
        for (int i = 0; i < 3; i++) cube[ind][i][2] = temp_arr[0][i];
        for (int i = 0; i < 3; i++) cube[ind][2][2 - i] = temp_arr[i][2];
        for (int i = 0; i < 3; i++) cube[ind][2 - i][0] = temp_arr[2][2 - i];
    }

public:
    char cube[6][3][3]{};

    Cube3D(){       // Intialisation of solved cube
        for(int i=0;i<6;i++){
            for(int j=0;j<3;j++){
                for(int k=0;k<3;k++){
                    cube[i][j][k] = getColorChar(Color(i));
                }
            }
        }
    }  

    Color getColor(Face f, unsigned row, unsigned col) const override{
        char ch = cube[(int)f][row][col];

        switch(ch){
            case 'B': return Color::BLUE;
            case 'W': return Color::WHITE;
            case 'R': return Color::RED;
            case 'O': return Color::ORANGE;
            case 'G': return Color::GREEN;
            case 'Y': return Color::YELLOW;
        }
        return Color::WHITE;        // default case
    }

    bool isSolved() const override{
        // basic condition
        for(int i=0;i<6;i++){
            for(int j=0;j<3;j++){
                for(int k=0;k<3;k++){
                    if(this->cube[i][j][k] != getColorChar(Color(i))) return false;     // not matching
                }   
            }
        }
        return true;
    }

    RubikCube &u() override{
        this->rotateFace(0);

        char temp_arr[3] = {};
        for (int i = 0; i < 3; i++) temp_arr[i] = cube[4][0][2 - i];
        for (int i = 0; i < 3; i++) cube[4][0][2 - i] = cube[1][0][2 - i];
        for (int i = 0; i < 3; i++) cube[1][0][2 - i] = cube[2][0][2 - i];
        for (int i = 0; i < 3; i++) cube[2][0][2 - i] = cube[3][0][2 - i];
        for (int i = 0; i < 3; i++) cube[3][0][2 - i] = temp_arr[i];

        return *this;
    }

    RubikCube &u2() override{
        this->u();
        this->u();

        return *this;
    }

    RubikCube &uPrime() override{
        this->u();
        this->u();
        this->u();

        return *this;
    }

    RubikCube &l() override{
        this->rotateFace(1);

        char temp_arr[3] = {};
        for (int i = 0; i < 3; i++) temp_arr[i] = cube[0][i][0];
        for (int i = 0; i < 3; i++) cube[0][i][0] = cube[4][2 - i][2];
        for (int i = 0; i < 3; i++) cube[4][2 - i][2] = cube[5][i][0];
        for (int i = 0; i < 3; i++) cube[5][i][0] = cube[2][i][0];
        for (int i = 0; i < 3; i++) cube[2][i][0] = temp_arr[i];

        return *this;
    }

    RubikCube &l2() override{
        this->l();
        this->l();

        return *this;
    }

    RubikCube &lPrime() override{
        this->l();
        this->l();
        this->l();

        return *this;
    }

    RubikCube &f() override{
        this->rotateFace(2);

        char temp_arr[3] = {};
        for (int i = 0; i < 3; i++) temp_arr[i] = cube[0][2][i];
        for (int i = 0; i < 3; i++) cube[0][2][i] = cube[1][2 - i][2];
        for (int i = 0; i < 3; i++) cube[1][2 - i][2] = cube[5][0][2 - i];
        for (int i = 0; i < 3; i++) cube[5][0][2 - i] = cube[3][i][0];
        for (int i = 0; i < 3; i++) cube[3][i][0] = temp_arr[i];

        return *this;
    }

    RubikCube &f2() override{
        this->f();
        this->f();
        return *this;
    }

    RubikCube &fPrime() override{
        this->f();
        this->f();
        this->f();
        return *this;
    }

    RubikCube &r() override {
        this->rotateFace(3);

        char temp_arr[3] = {};
        for (int i = 0; i < 3; i++) temp_arr[i] = cube[0][2 - i][2];
        for (int i = 0; i < 3; i++) cube[0][2 - i][2] = cube[2][2 - i][2];
        for (int i = 0; i < 3; i++) cube[2][2 - i][2] = cube[5][2 - i][2];
        for (int i = 0; i < 3; i++) cube[5][2 - i][2] = cube[4][i][0];
        for (int i = 0; i < 3; i++) cube[4][i][0] = temp_arr[i];

        return *this;
    }

    RubikCube &rPrime() override {
        this->r();
        this->r();
        this->r();

        return *this;
    }

    RubikCube &r2() override {
        this->r();
        this->r();

        return *this;
    }

    RubikCube &b() override {
        this->rotateFace(4);

        char temp_arr[3] = {};
        for (int i = 0; i < 3; i++) temp_arr[i] = cube[0][0][2 - i];
        for (int i = 0; i < 3; i++) cube[0][0][2 - i] = cube[3][2 - i][2];
        for (int i = 0; i < 3; i++) cube[3][2 - i][2] = cube[5][2][i];
        for (int i = 0; i < 3; i++) cube[5][2][i] = cube[1][i][0];
        for (int i = 0; i < 3; i++) cube[1][i][0] = temp_arr[i];

        return *this;
    }

    RubikCube &bPrime() override {
        this->b();
        this->b();
        this->b();

        return *this;
    }

    RubikCube &b2() override {
        this->b();
        this->b();

        return *this;
    }

    RubikCube &d() override {
        this->rotateFace(5);

        char temp_arr[3] = {};
        for (int i = 0; i < 3; i++) temp_arr[i] = cube[2][2][i];
        for (int i = 0; i < 3; i++) cube[2][2][i] = cube[1][2][i];
        for (int i = 0; i < 3; i++) cube[1][2][i] = cube[4][2][i];
        for (int i = 0; i < 3; i++) cube[4][2][i] = cube[3][2][i];
        for (int i = 0; i < 3; i++) cube[3][2][i] = temp_arr[i];

        return *this;
    }

    RubikCube &dPrime() override {
        this->d();
        this->d();
        this->d();

        return *this;
    }

    RubikCube &d2() override {
        this->d();
        this->d();

        return *this;
    }

    bool operator==(const Cube3D &r1) const {
        for (int i = 0; i < 6; i++) {
            for (int j = 0; j < 3; j++) {
                for (int k = 0; k < 3; k++) {
                    if (r1.cube[i][j][k] != cube[i][j][k]) return false;
                }
            }
        }
        return true;
    }

    Cube3D &operator=(const Cube3D &r1) {
        for (int i = 0; i < 6; i++) {
            for (int j = 0; j < 3; j++) {
                for (int k = 0; k < 3; k++) {
                    cube[i][j][k] = r1.cube[i][j][k];
                }
            }
        }
        return *this;
    }
};

struct Hash3d {
    size_t operator()(const Cube3D &r1) const {
        string str = "";
        for (int i = 0; i < 6; i++) {
            for (int j = 0; j < 3; j++) {
                for (int k = 0; k < 3; k++) {
                    str += r1.cube[i][j][k];
                }
            }
        }
        return hash<string>()(str);
    }

};

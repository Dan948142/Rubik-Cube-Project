#include "Rubik.h"

// cube [i] → color of the i-th cubie side, when indexed sequentially

class Cube1D:public RubikCube{
private:
    static inline int getIndex(int ind, int row, int col){
        return ind*9 + row*3 + col;
    }

    void rotateFace(int ind) {
        char temp_arr[9] = {};
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                temp_arr[i * 3 + j] = cube[getIndex(ind, i, j)];
            }
        }
        for (int i = 0; i < 3; i++) cube[getIndex(ind, 0, i)] = temp_arr[getIndex(0, 2 - i, 0)];
        for (int i = 0; i < 3; i++) cube[getIndex(ind, i, 2)] = temp_arr[getIndex(0, 0, i)];
        for (int i = 0; i < 3; i++) cube[getIndex(ind, 2, 2 - i)] = temp_arr[getIndex(0, i, 2)];
        for (int i = 0; i < 3; i++) cube[getIndex(ind, 2 - i, 0)] = temp_arr[getIndex(0, 2, 2 - i)];
    }

public:
    char cube[54]{};

    Cube1D(){
        for(int i=0;i<6;i++){
            for(int j=0;j<3;j++){
                for(int k=0;k<3;k++){
                    cube[i*9+j*3+k] = getColorChar(Color(i));
                }
            }
        }
    }

    Color getColor(Face f, unsigned row, unsigned col) const override{
        char c = cube[getIndex((int)f, row, col)];

        switch(c){
            case 'B': return Color::BLUE;
            case 'G': return Color::GREEN;
            case 'W': return Color::WHITE;
            case 'Y': return Color::YELLOW;
            case 'R': return Color::RED;
            case 'O': return Color::ORANGE;
        }

        return Color::BLUE;
    }

    bool isSolved() const override{
        for(int i=0;i<6;i++){
            for(int j=0;j<3;j++){
                for(int k=0;k<3;k++){
                    if(this->cube[i*9+j*3+k] != getColorChar(Color(i))) return false;
                }
            }
        }
        return true;
    }

    RubikCube &u() override {
        this->rotateFace(0);

        char temp_arr[3] = {};
        for (int i = 0; i < 3; i++) temp_arr[i] = cube[getIndex(4, 0, 2 - i)];
        for (int i = 0; i < 3; i++) cube[getIndex(4, 0, 2 - i)] = cube[getIndex(1, 0, 2 - i)];
        for (int i = 0; i < 3; i++) cube[getIndex(1, 0, 2 - i)] = cube[getIndex(2, 0, 2 - i)];
        for (int i = 0; i < 3; i++) cube[getIndex(2, 0, 2 - i)] = cube[getIndex(3, 0, 2 - i)];
        for (int i = 0; i < 3; i++) cube[getIndex(3, 0, 2 - i)] = temp_arr[i];

        return *this;
    }

    RubikCube &uPrime() override {
        this->u();
        this->u();
        this->u();

        return *this;
    }

    RubikCube &u2() override {
        this->u();
        this->u();

        return *this;
    }

    RubikCube &l() override {
        this->rotateFace(1);

        char temp_arr[3] = {};
        for (int i = 0; i < 3; i++) temp_arr[i] = cube[getIndex(0, i, 0)];
        for (int i = 0; i < 3; i++) cube[getIndex(0, i, 0)] = cube[getIndex(4, 2 - i, 2)];
        for (int i = 0; i < 3; i++) cube[getIndex(4, 2 - i, 2)] = cube[getIndex(5, i, 0)];
        for (int i = 0; i < 3; i++) cube[getIndex(5, i, 0)] = cube[getIndex(2, i, 0)];
        for (int i = 0; i < 3; i++) cube[getIndex(2, i, 0)] = temp_arr[i];

        return *this;
    }

    RubikCube &lPrime() override {
        this->l();
        this->l();
        this->l();

        return *this;
    }

    RubikCube &l2() override {
        this->l();
        this->l();

        return *this;
    }

    RubikCube &f() override {
        this->rotateFace(2);

        char temp_arr[3] = {};
        for (int i = 0; i < 3; i++) temp_arr[i] = cube[getIndex(0, 2, i)];
        for (int i = 0; i < 3; i++) cube[getIndex(0, 2, i)] = cube[getIndex(1, 2 - i, 2)];
        for (int i = 0; i < 3; i++) cube[getIndex(1, 2 - i, 2)] = cube[getIndex(5, 0, 2 - i)];
        for (int i = 0; i < 3; i++) cube[getIndex(5, 0, 2 - i)] = cube[getIndex(3, i, 0)];
        for (int i = 0; i < 3; i++) cube[getIndex(3, i, 0)] = temp_arr[i];

        return *this;
    }

    RubikCube &fPrime() override {
        this->f();
        this->f();
        this->f();

        return *this;
    }

    RubikCube &f2() override {
        this->f();
        this->f();

        return *this;
    }

    RubikCube &r() override {
        this->rotateFace(3);

        char temp_arr[3] = {};
        for (int i = 0; i < 3; i++) temp_arr[i] = cube[getIndex(0, 2 - i, 2)];
        for (int i = 0; i < 3; i++) cube[getIndex(0, 2 - i, 2)] = cube[getIndex(2, 2 - i, 2)];
        for (int i = 0; i < 3; i++) cube[getIndex(2, 2 - i, 2)] = cube[getIndex(5, 2 - i, 2)];
        for (int i = 0; i < 3; i++) cube[getIndex(5, 2 - i, 2)] = cube[getIndex(4, i, 0)];
        for (int i = 0; i < 3; i++) cube[getIndex(4, i, 0)] = temp_arr[i];

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
        for (int i = 0; i < 3; i++) temp_arr[i] = cube[getIndex(0, 0, 2 - i)];
        for (int i = 0; i < 3; i++) cube[getIndex(0, 0, 2 - i)] = cube[getIndex(3, 2 - i, 2)];
        for (int i = 0; i < 3; i++) cube[getIndex(3, 2 - i, 2)] = cube[getIndex(5, 2, i)];
        for (int i = 0; i < 3; i++) cube[getIndex(5, 2, i)] = cube[getIndex(1, i, 0)];
        for (int i = 0; i < 3; i++) cube[getIndex(1, i, 0)] = temp_arr[i];

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
        for (int i = 0; i < 3; i++) temp_arr[i] = cube[getIndex(2, 2, i)];
        for (int i = 0; i < 3; i++) cube[getIndex(2, 2, i)] = cube[getIndex(1, 2, i)];
        for (int i = 0; i < 3; i++) cube[getIndex(1, 2, i)] = cube[getIndex(4, 2, i)];
        for (int i = 0; i < 3; i++) cube[getIndex(4, 2, i)] = cube[getIndex(3, 2, i)];
        for (int i = 0; i < 3; i++) cube[getIndex(3, 2, i)] = temp_arr[i];

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

    bool operator==(const Cube1D &r1) const {
        for (int i = 0; i < 54; i++) {
            if (cube[i] != r1.cube[i]) return false;
        }
        return true;
    }

    Cube1D &operator=(const Cube1D &r1) {
        for (int i = 0; i < 54; i++) {
            cube[i] = r1.cube[i];
        }
        return *this;
    }

};

struct Hash1d {
    size_t operator()(const Cube1D &r1) const {
        string str = "";
        for (int i = 0; i < 54; i++) str += r1.cube[i];
        return hash<string>()(str);
    }
};

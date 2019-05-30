//
// Created by guy on 5/30/19.
//

#ifndef CUBE_CUBE_H
#define CUBE_CUBE_H
#define maxlen 25
#define minlen 0
#include <iostream>

class Cube {

    int X,Y,Z;

public:
    Cube() : X(1), Y(2), Z(3) {}

    Cube(Cube& a) = default;

    void rotate_x() {
        int tmp_y = Y;
        Y=7-Z;
        Z=tmp_y;
    }

    void rotate_y() {
        int tmp_z = Z;
        Z=7-X;
        X=tmp_z;
    }

    void rotate_z() {
        int tmp_x = X;
        X=7-Y;
        Y=tmp_x;
    }

    static void gen_random(char *s) {
        int len;
        len = rand() % (maxlen - minlen + 1) + minlen;
        static const char alphanum[] =
                "xyz";

        for (int i = 0; i < len; ++i) {
            s[i] = alphanum[rand() % (sizeof(alphanum) - 1)];
        }

        s[len] = 0;
    }

public:

    void UpSide() {
        std::cout << Y << "\n";
    }

    void GetCube() {
        std::cout << "Y:" << Y << "\n";
        std::cout << "X:" << X << "\n";
        std::cout << "Z:" << Z << "\n";
    }

    void RollCube(char* r) {
        char* rotating = r;
        while (*rotating) {
            switch (*rotating) {
                case 'x':
                    rotate_x();
                    break;
                case 'y':
                    rotate_y();
                    break;
                case 'z':
                    rotate_z();
                    break;
                default:
                    throw std::runtime_error("just 3 axis");
            }
            rotating++;
        }
        UpSide();
    }

    void RollCube() {
        char rolling_string[maxlen];
        gen_random(rolling_string);
        RollCube(rolling_string);
    }

};


#endif //CUBE_CUBE_H

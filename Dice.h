//
// Created by GuySadoun on 5/30/19.
//

#ifndef DICE_DICE_H
#define DICE_DICE_H
#define maxlen 25
#define minlen 0

#include <random>
#include <iostream>

class Dice {

    int X,Y,Z;

public:

    Dice() : X(1), Y(2), Z(3) {}

    Dice(Dice& a) = default;

    ~Dice() = default;

private:

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

    void gen_random(char *s) {
        int len;
        std::random_device rd;  //Will be used to obtain a seed for the random number engine
        std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
        std::uniform_int_distribution<> dis1(minlen, maxlen);
        len = dis1(gen);
        static const char alphanum[] = "xyz";
        std::uniform_int_distribution<> dis2(0, sizeof(alphanum)-2);
        for (int i = 0; i < len; ++i) {
            s[i] = alphanum[dis2(gen)];
        }

        s[len] = 0;
    }

public:

    void UpSide() {
        std::cout << Y << "\n";
    }

    void GetCube() {
        std::cout << "Y(up):" << Y << "\n";
        std::cout << "X(right):" << X << "\n";
        std::cout << "Z(left):" << Z << "\n";

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


#endif //DICE_DICE_H

#pragma once
#include "position.h"
#include "field.h"
class Food
{
private:
    /* data */
public:
    Food(/* args */);
    ~Food();
    Position pos = Position(-1, -1);
    char symbol;
    void set_pos(int x, int y);
    void reposition(const Field& field);
    int get_x() const;
    int get_y() const;
    char get_symbol() const;

};

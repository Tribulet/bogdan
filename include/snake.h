#pragma once
#include "position.h"
#include "food.h"
class snake_cls
{
private:
    /* data */
public:
    snake_cls(int x, int y);
    snake_cls();
    ~snake_cls();
    enum { UP, DOWN, LEFT, RIGHT } dir;
    char symbol, head_symbol;
    Position pos[100];
    Position& head;
    int speed;
    int size;
    bool can_turn;

    bool check_food(const Food& food);
    void get_input(const Field& field);
    void move(const Field& field);
    void draw(Field& field);
    int get_x() const;
    int get_y() const;
    char get_symbol() const;
};


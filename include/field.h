#pragma once
#include <iostream>
using namespace std;

class Field
{
private:
    /* data */
public:
    Field(/* args */);
    ~Field();
    char **field;
    static const int height;
    static const int width;
    void print();
    void clear();
    int get_width() const;
    int get_height() const;
    void draw(int y, int x, char what);
};

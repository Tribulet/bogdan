#include "food.h"

Food::Food() : symbol('X')
{
}

Food::~Food()
{
}

void Food::set_pos(int x, int y)
{
    pos.x = x;
    pos.y = y;
}

void Food::reposition(const Field &field)
{
    pos.x = rand() % field.get_width();
    pos.y = rand() % field.get_height();
}

int Food::get_x() const
{
    return pos.x;
}

int Food::get_y() const
{
    return pos.y;
}

char Food::get_symbol() const
{
    return symbol;
}

#include "snake.h"
#include "windows.h"

snake_cls::snake_cls(int x, int y) : symbol('#'), head_symbol('@'), pos(),
                                     speed(1), size(1), dir(RIGHT),
                                     head(pos[0]), can_turn(true)
{
    pos[0].x = x;
    pos[0].y = y;
}
snake_cls::snake_cls() : snake_cls(1, 1) {}

snake_cls::~snake_cls()
{
}

bool snake_cls::check_food(const Food &food)
{
    if (food.get_x() == head.x && food.get_y() == head.y)
    {
        size += 1;
        return true;
    }
    return false;
}

void snake_cls::get_input(const Field &field)
{
     if (GetAsyncKeyState(VK_UP) && dir != DOWN)
     {
         dir = UP;
     }
     if (GetAsyncKeyState(VK_DOWN) && dir != UP)
     {
         dir = DOWN;
     }
     if (GetAsyncKeyState(VK_LEFT) && dir != RIGHT)
     {
         dir = LEFT;
     }
     if (GetAsyncKeyState(VK_RIGHT) && dir != LEFT)
     {
         dir = RIGHT;
    }
}

void snake_cls::move(const Field &field)
{
    Position next = {0, 0};
    switch (dir)
    {
    case UP:
        next.y = -speed;
        break;
    case DOWN:
        next.y = speed;
        break;
    case LEFT:
        next.x = -speed;
        break;
    case RIGHT:
        next.x = speed;
    }
    for (int c = size - 1; c > 0; --c)
    {
        pos[c] = pos[c - 1];
    }
    head.x += next.x;
    head.y += next.y;

    if (head.x < 0 || head.y < 0 || head.x >= field.get_width() || head.y >= field.get_height())
    {
        throw "DEADD!!!!";
    }
}

void snake_cls::draw(Field &field)
{
    for (int c = 0; c < size; ++c)
    {
        if (c == 0)
        {
            field.draw(pos[c].y, pos[c].x, head_symbol);
        }
        else
        {
            field.draw(pos[c].y, pos[c].x, symbol);
        }
    }
}

int snake_cls::get_x() const
{
    return head.x;
}

int snake_cls::get_y() const
{
    return head.y;
}

char snake_cls::get_symbol() const
{
    return symbol;
}

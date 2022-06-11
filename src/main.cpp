#include <iostream>
#include "field.h"
#include "food.h"
#include "snake.h"
#include <windows.h>

using namespace std;

const int Field::height = 24;
const int Field::width = 79;


int main() {
    Field field = Field();
    Food food = Food();
    snake_cls snake = snake_cls();
    field.clear();

    food.set_pos(5, 5);

    while (1) {
        field.clear();

        snake.get_input(field);
        try {
            snake.move(field);
        }
        catch (const char* er) {
            field.clear();
            cerr << er << endl;
            system("pause");
            return -1;
        }
        snake.draw(field);
        field.draw(food.get_y(), food.get_x(), food.get_symbol());


        if (snake.check_food(food)) {
            food.reposition(field);
        }

        field.print();

        Sleep(1000 / 30);
        system("cls");
    }

    return 0;
}
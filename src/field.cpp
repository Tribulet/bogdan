#include "field.h"


Field::Field::Field(/* args */) {
    field = new char* [Field::height];
        for (int c = 0; c < Field::height; ++c) {
            field[c] = new char[Field::width];
        }
}

Field::Field::~Field() {
    for (int c = 0; c < Field::height; ++c) {
            delete[] field[c];
        }
        delete[] field;
}


void Field::Field::print() {
    for (int c = 0; c < height; ++c) {
            for (int r = 0; r < width; ++r) {
                cout << field[c][r];
            }
            cout << endl;
        }
}

void Field::Field::clear() {
    for (int c = 0; c < height; ++c) {
            for (int r = 0; r < width; ++r) {
                field[c][r] = ' ';
            }
        }
}

int Field::Field::get_width() const {
    return width;
}

int Field::Field::get_height() const {
    return height;
}

void Field::Field::draw(int y, int x, char what) {
    field[y][x] = what;
}

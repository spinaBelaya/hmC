#ifndef GAME_FIELD_H
#define GAME_FIELD_H

#include <iostream>


class Cell {
public:
    Cell(int x, int y);
    bool isCorrect() const;

    int x_, y_;
};


class Field {
public:
    Field();

    Field(const Field &obj);

    friend std::ostream &operator<<(std::ostream &out, const Field &f);

    char getCell(const Cell &cell) const;

    int movePiece(const Cell &piece, const Cell &newCell, int playerNum);

    bool canBeat(size_t playerNum) const;

private:
    char field_[8][8];

    int moveMan(const Cell &piece1, const Cell &newCell, int playerNum);

    int moveKing(const Cell &piece1, const Cell &newCell, int playerNum);

    void setCell(const Cell &cell, char c);
};

#endif //GAME_FIELD_H
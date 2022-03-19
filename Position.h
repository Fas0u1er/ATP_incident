#pragma once

struct Position {
    int x, y;

    Position& operator+=(const Position& other);
    Position operator+(const Position& other) const;
    Position& operator*=(int k);
    Position operator*(int k) const;

};
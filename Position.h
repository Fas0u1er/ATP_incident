#pragma once

struct Position {
    int x = 0, y = 0;

    Position& operator+=(const Position& other);
    Position operator+(const Position& other) const;
    Position& operator*=(int k);
    Position operator*(int k) const;
    bool operator!=(const Position& other) const {
        return x != other.x or y != other.y;
    }
    bool operator==(const Position& other) const {
        return x == other.x and y == other.y;
    }

};
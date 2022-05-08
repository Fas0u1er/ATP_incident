#pragma once

#include <ostream>
#include <initializer_list>
struct Position {
    int x = 0; //X means ROW
    int y = 0; //Y means COLUMN
    // Because this way it is easier to access arrays

    Position() = default;
    Position(int x, int y) : x(x), y(y) {}
//    constexpr Position(std::initializer_list<int> p) {
//        static_assert(p.size() == 2);
//    };
    Position& operator+=(const Position& other);
    Position& operator-=(const Position& other);
    Position operator+(const Position& other) const;
    Position operator-(const Position& other) const;
    Position& operator*=(int k);
    Position operator*(int k) const;
    bool operator!=(const Position& other) const;
    bool operator==(const Position& other) const;
    friend std::ostream& operator<<(std::ostream& os, const Position& position);
    Position& rotate(bool clockwise);
};
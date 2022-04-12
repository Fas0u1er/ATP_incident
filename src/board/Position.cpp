
#include "src/board/Position.h"
Position& Position::operator+=(const Position& other) {
    x += other.x;
    y += other.y;
    return *this;
}
Position Position::operator+(const Position& other) const {
    auto answer = *this;
    answer += other;
    return answer;
}
Position& Position::operator*=(int k) {
    x *= k;
    y *= k;
    return *this;
}
Position Position::operator*(int k) const {
    auto answer = *this;
    answer *= k;
    return answer;
}

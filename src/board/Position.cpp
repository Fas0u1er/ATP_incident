#include "Position.h"
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
std::ostream& operator<<(std::ostream& os, const Position& position) {
    os << "x: " << position.x << " y: " << position.y;
    return os;
}
Position& Position::operator-=(const Position& other) {
    x -= other.x;
    y -= other.y;
    return *this;
}
Position Position::operator-(const Position& other) const {
    auto answer = *this;
    answer -= other;
    return answer;
}
bool Position::operator!=(const Position& other) const {
    return x != other.x or y != other.y;
}
bool Position::operator==(const Position& other) const {
    return x == other.x and y == other.y;
}

#pragma once
//todo: rename me?
class Displayer {

public:
    Displayer() = default;
    virtual ~Displayer() = default;
};


class Derived : Displayer {
public:
    int* a = new int(5);
    Derived() = default;
    ~Derived() override = default;
};
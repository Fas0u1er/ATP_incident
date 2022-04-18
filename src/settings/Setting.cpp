#include "Setting.h"

std::string Setting::getDescription() {
    return description;
}

template<>
std::string ConcreteSetting<int>::toString() {
    return std::to_string(value);
}

template<>
std::string ConcreteSetting<std::string>::toString() {
    return value;
}

template<>
std::string ConcreteSetting<std::vector<int>>::toString() {
    std::string result;
    for (auto el: value) {
        result += std::to_string(el) + ' ';
    }
    return result;
}

template<>
bool ConcreteSetting<int>::parseFromInput(std::stringstream& input) {
    if (!input.eof()) {
        std::string temp;
        input >> temp;
        if (temp.empty())
            return false;
        try {
            value = std::stoi(temp);
            return true;
        }
        catch (std::invalid_argument& err) {
            return false;
        }
    }
    return false;
}

template<>
bool ConcreteSetting<std::string>::parseFromInput(std::stringstream& input) {
    if (!input.eof()) {
        std::string temp;
        input >> temp;
        value = temp;
        return true;
    }
    return false;
}

template<>
bool ConcreteSetting<std::vector<int>>::parseFromInput(std::stringstream& input) {
    std::vector <int> result;
    while (!input.eof()) {
        std::string temp;
        input >> temp;
        if (temp.empty())
            break;
        try {
            result.push_back(std::stoi(temp));
        }
        catch (std::invalid_argument& err) {
            return false;
        }
    }
    value = result;
    return true;
}


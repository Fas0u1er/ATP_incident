#pragma once

#include <string>
#include <utility>
#include <vector>
#include <sstream>

class Setting {
public:
    virtual std::string toString() = 0;
    virtual bool parseFromInput(std::stringstream& input) = 0;
protected:
    std::string description;
    Setting(std::string description) : description(std::move(description)) {}
    virtual ~Setting() = default;
public:
    std::string getDescription();
};

template<typename T>
class ConcreteSetting : public Setting {
public:
    bool parseFromInput(std::stringstream& input) override;
    std::string toString() override;

    static_assert(std::is_same_v<T, int> or std::is_same_v<T, std::vector<int>> or std::is_same_v<T, std::string>);
    explicit ConcreteSetting(const std::string& description, T& value) : Setting(description), value(value) {}

    ~ConcreteSetting() override = default;
private:
    T& value;

};

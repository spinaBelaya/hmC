#ifndef GAME_STEP_H
#define GAME_STEP_H

#include <vector>
#include <string>
#include "field.h"

class Step {
public:
    Step(const Cell &firstPos, const Cell &secondPos);

    Step(const std::string &move);

    Step(const std::vector<Cell> &steps);

    Step() = default;

    const Cell &operator[](size_t id) const;

    friend Step operator+(const Step &A, const Step &B);

    size_t size() const;

private:
    std::vector<Cell> steps_;
};


#endif //GAME_STEP_H

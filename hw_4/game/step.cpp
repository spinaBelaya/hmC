#include <stdexcept>
#include "step.h"

Step::Step(const Cell &firstPos, const Cell &secondPos) {
    steps_.push_back(firstPos);
    steps_.push_back(secondPos);
}

Step::Step(const std::vector<Cell> &steps) :
        steps_(std::move(steps)) {}

Step::Step(const std::string &move) {
    if (move.size() < 5 || (move.size() + 1) % 3 != 0)
        return;
    for (size_t i = 0; i < move.size(); i += 3) {
        int x;
        if (std::isupper(move[i]))
            x = move[i] - 'A';
        else
            x = move[i] - 'a';
        int y = move[i + 1] - '1';
        steps_.emplace_back(Cell(x, y));
        if (!steps_.back().isCorrect()) {
            steps_.clear();
            return;
        }
    }
}

const Cell &Step::operator[](size_t id) const {
    if (id < steps_.size())
        return steps_[id];
    throw std::out_of_range("Out of range");
}

Step operator+(const Step &A, const Step &B) {
    std::vector<Cell> ans(A.steps_.size() + B.steps_.size(), Cell(0, 0));
    std::move(A.steps_.begin(), A.steps_.end(), ans.begin());
    std::move(B.steps_.begin(), B.steps_.end(), ans.begin() + A.steps_.size());
    return Step(ans);
}

size_t Step::size() const {
    return steps_.size();
}
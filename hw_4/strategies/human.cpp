#include "human.h"

Human::Human(std::string name) :
        name_(std::move(name)) {
    giveUp_ = false;
}

void Human::onWin() {
    std::cout << "You win!" << std::endl;
}

void Human::onLose() {
    std::cout << "You lose!" << std::endl;
}

Step Human::makeStep(const Field &fld, size_t playerNum) {
    std::cout << name_ << std::endl;
    std::cout << "Field:" << std::endl;
    std::cout << fld;
    std::cout << "Type coordinates: " << std::endl;
    std::string move;
    std::getline(std::cin, move);
    if (move == "I give up") {
        giveUp_ = true;
        return {};
    }
    return Step(move);
}

void Human::onIncorrectStep(const Step &step) const {
    std::cout << "Incorrect step. Try again." << std::endl;
}

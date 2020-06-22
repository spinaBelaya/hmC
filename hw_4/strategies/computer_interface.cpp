#include <cassert>
#include "computer_interface.h"

ComputerInterface::ComputerInterface() :
        winCounter(0),
        loseCounter(0) {
    giveUp_ = false;
}

void ComputerInterface::onWin() {
    ++winCounter;
}

void ComputerInterface::onLose() {
    ++loseCounter;
}

void ComputerInterface::onIncorrectStep(const Step &step) const {
    assert(false);
}

void ComputerInterface::printStat() const {
    std::cout << "Wins:  " << winCounter << std::endl;
    std::cout << "Loses: " << loseCounter << std::endl;
    std::cout << std::endl;
}

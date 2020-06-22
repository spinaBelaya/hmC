#ifndef GAME_COMPUTER1_H
#define GAME_COMPUTER1_H

#include "computer_interface.h"

class Computer1 : public ComputerInterface {
public:
    explicit Computer1(std::string name);

    Step makeStep(const Field &field, size_t playerNum) override;

    void printStat() const override;

private:
    std::string name;
};


#endif //GAME_COMPUTER1_H

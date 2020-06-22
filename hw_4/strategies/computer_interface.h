#ifndef GAME_COMPUTER_INTERFACE_H
#define GAME_COMPUTER_INTERFACE_H


#include "interface.h"

class ComputerInterface : public StrategyInterface {
public:
    ComputerInterface();

    virtual void onIncorrectStep(const Step &step) const override;

    virtual void onLose() override;

    virtual void onWin() override;

    virtual void printStat() const;

private:
    size_t winCounter;
    size_t loseCounter;
};


#endif //GAME_COMPUTER_INTERFACE_H

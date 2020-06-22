#ifndef GAME_HUMAN_H
#define GAME_HUMAN_H


#include "interface.h"

class Human : public StrategyInterface {
public:
    explicit Human(std::string name);

    Step makeStep(const Field &field, size_t playerNum) override;

    void onIncorrectStep(const Step &step) const override;

    void onWin() override;

    void onLose() override;

private:
    std::string name_;
};


#endif //GAME_HUMAN_H

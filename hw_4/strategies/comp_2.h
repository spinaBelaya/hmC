#ifndef GAME_COMPUTER2_H
#define GAME_COMPUTER2_H


#include "computer_interface.h"

class Computer2 : public ComputerInterface {
public:
    explicit Computer2(std::string name);

    Step makeStep(const Field &field, size_t playerNum) override;

    void printStat() const override;

private:
    std::string name;

    std::vector<Step> BeatProcess(const Field &fld, const Cell &obj, size_t playerNum);
};


#endif //GAME_COMPUTER2_H

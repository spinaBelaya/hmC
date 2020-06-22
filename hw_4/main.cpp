#include <iostream>
#include <memory>
#include <time.h>
#include "game/game.h"
#include "strategies/human.h"
#include "strategies/comp_1.h"
#include "strategies/comp_2.h"

int main() {
    std::srand(time(0));
    auto player1 = std::make_shared<Computer1>("Player1");
    auto player2 = std::make_shared<Computer2>("Player2");

    for (int i = 0; i < 1000; i++) {
        Game game(player1, player2);
        game.play();
    }

    player1->printStat();
    player2->printStat();
}

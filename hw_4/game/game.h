#ifndef GAME_GAME_H
#define GAME_GAME_H

#include <vector>
#include <memory>
#include "field.h"
#include "step.h"
#include "../strategies/interface.h"

namespace CheckFunc {
    const std::vector<char> MAN_PIECE({'w', 'b'});
    const std::vector<char> KING_PIECE({'W', 'B'});

    const std::vector<int> MOVE_Y({1, -1});
    const std::vector<int> MOVE_X({1, -1});

    const std::vector<int> KINGS_ROW({7, 0});

    bool isMan(char c);

    bool isKing(char c);

    bool isBlack(char c);

    bool isWhite(char c);

    bool isFriend(char c, size_t playerNum);

    bool isEnemy(char c, size_t playerNum);
}


class Game {
public:
    using Player = std::shared_ptr<StrategyInterface>;

    Game(const Player &player1, const Player &player2);

    ~Game();

    void play();

    //friend std::ostream& operator<<(std::ostream& out, const Game& g) { return out << g.field_;};

private:
    enum GameState {
        WIN,
        IN_PROGRESS
    };

    GameState isWin() const;

    bool applyStep(const Step &step, size_t playerNum);

    Field field_;
    std::vector<Player> players_;
};


#endif //GAME_GAME_H

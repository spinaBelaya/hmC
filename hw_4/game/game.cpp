#include "game.h"

bool CheckFunc::isMan(char c) {
    return (c == 'w' || c == 'b');
}

bool CheckFunc::isKing(char c) {
    return (c == 'W' || c == 'B');
}

bool CheckFunc::isBlack(char c) {
    return (c == 'b' || c == 'B');
}

bool CheckFunc::isWhite(char c) {
    return (c == 'w' || c == 'W');
}

bool CheckFunc::isFriend(char c, size_t playerNum) {
    if (playerNum == 0 && isWhite(c))
        return true;
    if (playerNum == 1 && isBlack(c))
        return true;
    return false;
}

bool CheckFunc::isEnemy(char c, size_t playerNum) {
    if (playerNum == 0 && isBlack(c))
        return true;
    if (playerNum == 1 && isWhite(c))
        return true;
    return false;
}

Game::Game(const Player &player1, const Player &player2) :
        field_() {
    players_.push_back(player1);
    players_.push_back(player2);
}

Game::~Game() {
    for (auto &player:players_)
        player->giveUp_ = false;
}

bool Game::applyStep(const Step &step, size_t playerNum) {
    if (step.size() < 2)
        return false;
    Field newField(field_);
    Cell pos1(step[0]), pos2(step[1]);
    if (newField.canBeat(playerNum)) {
        for (int i = 0; i < step.size() - 1; i++) {
            pos1 = step[i];
            pos2 = step[i + 1];
            if (newField.movePiece(pos1, pos2, playerNum) != 1)
                return false;
        }
    } else {
        if (step.size() > 2 || newField.movePiece(pos1, pos2, playerNum) != 0)
            return false;
    }

    field_ = newField;
    return true;
}

Game::GameState Game::isWin() const {
    int countBlack = 0, countWhite = 0;
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++) {
            char c = field_.getCell(Cell(i, j));
            if (CheckFunc::isBlack(c))
                countBlack++;
            if (CheckFunc::isWhite(c))
                countWhite++;
        }
    if (countBlack == 0 ||
        countWhite == 0 ||
        players_[0]->hasGiveUp() ||
        players_[1]->hasGiveUp())
        return WIN;
    else
        return IN_PROGRESS;
}

void Game::play() {
    size_t counter = 1;
    while (isWin() == IN_PROGRESS) {
        counter = (counter + 1) % 2;
        bool isCorrect = false;
        while (!isCorrect) {
            Step step = players_[counter]->makeStep(field_, counter);
            if (players_[counter]->hasGiveUp()) {
                counter = (counter + 1) % 2;
                break;
            }
            isCorrect = applyStep(step, counter);
            if (!isCorrect) {
                players_[counter]->onIncorrectStep(step);
            }
        }
    }
    for (size_t i = 0; i < players_.size(); ++i) {
        if (i == counter) {
            players_[i]->onWin();
        } else {
            players_[i]->onLose();
        }
    }
}
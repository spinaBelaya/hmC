#include <algorithm>
#include "comp_2.h"
#include "../game/game.h"

Computer2::Computer2(std::string name) :
        name(std::move(name)) {}

Step Computer2::makeStep(const Field &fld, size_t playerNum) {
    std::vector<Cell> pieces;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            Cell tmp(i, j);
            if (CheckFunc::isFriend(fld.getCell(tmp), playerNum))
                pieces.push_back(tmp);
        }
    }

    bool mustBeat = fld.canBeat(playerNum);

    if (!mustBeat) {
        for (const auto &obj:pieces) {
            if (CheckFunc::isMan(fld.getCell(obj))) {
                for (auto dx:CheckFunc::MOVE_X) {
                    int dy = CheckFunc::MOVE_Y[playerNum];
                    Cell next(obj.x_ + dx, obj.y_ + dy);
                    if (next.isCorrect() && fld.getCell(next) == '_')
                        return {obj, next};
                }
            }

            if (CheckFunc::isKing(fld.getCell(obj))) {
                for (auto dx:CheckFunc::MOVE_X) {
                    for (auto dy:CheckFunc::MOVE_Y) {
                        Cell next(obj.x_ + dx, obj.y_ + dy);
                        if (next.isCorrect() &&
                            fld.getCell(next) == '_')
                            return {obj, next};
                    }
                }
            }
        }
        giveUp_ = true;
        return {};
    }

    if (mustBeat) {
        std::vector<Step> ways;
        for (const auto &obj:pieces) {
            std::vector<Step> objWays(std::move(BeatProcess(fld, obj, playerNum)));
            std::move(objWays.begin(), objWays.end(), std::back_inserter(ways));
        }

        std::random_shuffle(ways.begin(), ways.end());
        size_t maxStepLengthId = 0;
        for (int i = 0; i < ways.size(); i++)
            if (ways[i].size() > ways[maxStepLengthId].size())
                maxStepLengthId = i;

        return ways[maxStepLengthId];
    }
}

std::vector<Step> Computer2::BeatProcess(const Field &fld, const Cell &obj, size_t playerNum) {
    std::vector<Step> ways({Step({obj})});

    if (CheckFunc::isMan(fld.getCell(obj))) {
        for (auto dx:CheckFunc::MOVE_X) {
            int dy = CheckFunc::MOVE_Y[playerNum];
            Cell next(obj.x_ + dx, obj.y_ + dy);
            Cell next2(obj.x_ + 2 * dx, obj.y_ + 2 * dy);
            if (next2.isCorrect() &&
                CheckFunc::isEnemy(fld.getCell(next), playerNum) &&
                fld.getCell(next2) == '_') {

                Field newFld(fld);
                newFld.movePiece(obj, next2, playerNum);
                for (auto &&steps:BeatProcess(newFld, next2, playerNum))
                    ways.emplace_back(Step({obj}) + steps);
            }
        }
    }

    if (CheckFunc::isKing(fld.getCell(obj))) {
        for (auto dx:CheckFunc::MOVE_X) {
            for (auto dy:CheckFunc::MOVE_Y) {
                Cell tmp(obj.x_ + dx, obj.y_ + dy);
                while (tmp.isCorrect()) {
                    if (CheckFunc::isFriend(fld.getCell(tmp), playerNum))
                        break;

                    if (CheckFunc::isEnemy(fld.getCell(tmp), playerNum)) {
                        tmp.x_ += dx;
                        tmp.y_ += dy;
                        while (tmp.isCorrect() && fld.getCell(tmp) == '_') {
                            Field newFld(fld);
                            newFld.movePiece(obj, tmp, playerNum);
                            for (auto &&steps:BeatProcess(newFld, tmp, playerNum))
                                ways.push_back(Step({obj}) + steps);
                            tmp.x_ += dx;
                            tmp.y_ += dy;
                        }
                        break;
                    }
                    tmp.x_ += dx;
                    tmp.y_ += dy;
                }
            }
        }
    }

    return ways;
}

void Computer2::printStat() const {
    std::cout << "AI model [" << name << "]: " << std::endl;
    ComputerInterface::printStat();
}

#include "interface.h"

bool
strategy_interface_t::attacked_checkers(const field_t &field, std::set<std::pair<int, int> > &attack_checkers,
                                        std::pair<int, int> current_checker) {
    bool changed = false;

    char letter =  (char) (player_num + 97); //your checker letter
    char u_letter = (char) (player_num + 65); //your checker uppercase letter
    if ((int)(field.fld[current_checker.second][current_checker.first]) >= 97) {
        int change_step[2] = {-1, 1};
        for (auto &i: change_step) {
            for (auto &j: change_step) {
                if (field.fld[current_checker.second + i][current_checker.first + j] != letter &&
                    field.fld[current_checker.second + i][current_checker.first + j] != u_letter &&
                    field.fld[current_checker.second + i][current_checker.first + j] != '+') {
                    if (field.fld[current_checker.second + i * 2][current_checker.first + j * 2] == '+') {
                        attack_checkers.insert(
                                std::pair<size_t, size_t>(current_checker.first, current_checker.second));
                        changed = true;
                    }
                }
            }
        }
    } else if ((int)(field.fld[current_checker.second][current_checker.first]) <= 66){

        size_t max_R = std::max(current_checker.second - 0, 7 - current_checker.second);
        int change_step[2] = {-1, 1};
        for (auto &i: change_step) {
            for (auto &j: change_step) {
                for (int R = 1; R < max_R; ++R) {
                    if (field.fld[current_checker.second + i][current_checker.first + j] != letter &&
                        field.fld[current_checker.second + i][current_checker.first + j] != u_letter &&
                        field.fld[current_checker.second + i][current_checker.first + j] != '+') {
                        if (field.fld[current_checker.second + i * (R + 1)][current_checker.first + j * (R + 1)] !=
                            '+') {
                            break;
                        } else {
                            attack_checkers.insert(
                                    std::pair<size_t, size_t>(current_checker.first, current_checker.second));
                            changed = true;
                            break;
                        }
                    }
                }
            }
        }
    }


    return changed;
}

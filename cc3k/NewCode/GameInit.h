#ifndef GAME_INIT_H
#define GAME_INIT_H

#include <string>

enum class GameResult {
    Win,
    Loss,
    Quit,
    Restart
};

struct ResultCombo {
    GameResult type;
    int finalScore;
};

class GameInit {
public:
    void run();
    std::string getRaceEmoji(char race);
    std::string getRaceName(char race);
};

#endif 

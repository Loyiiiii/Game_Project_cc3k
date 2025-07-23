export module GameInit;
import <iostream>;
import <fstream>;
import <string>;
import <memory>;
import GamePlay;
import PlayerCharacter;
import Global_Constants;
import position;
using namespace std;

export enum class GameResult {
    Win,
    Loss,
    Quit,
    Restart
};

export class GameInit {
public:
    void run();
    string getRaceEmoji(char race);
    string getRaceName(char race);
};

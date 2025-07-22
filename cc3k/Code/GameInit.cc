export module GameInit;
import <iostream>;
import <fstream>;
import <string>;
import <memory>;
import GamePlay;
import Global_Constants;
using namespace std;

export enum class GameResult {
    Win,
    Loss,
    Quit
};

export class GameInit {
public:
    void run();
    string getRaceEmoji(char race);
    string getRaceName(char race);
};

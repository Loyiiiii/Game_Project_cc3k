export module GameInit;
import <iostream>;
import <fstream>;
import <string>;
import GamePlay;
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

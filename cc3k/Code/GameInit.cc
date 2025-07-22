export module GameInit;
import <iostream>;
import <fstream>;
import <string>;
import <memory>;
import GamePlay;
import PlayerCharacter;
import Global_Constants;
using namespace std;

export enum class GameResult {
    Win,
    Loss,
    Quit
};

export class GameInit {
public:
    virtual unique_ptr<PlayerCharacter> curr_game_PC(Position start_pos, Race start_race);
    void run();
    string getRaceEmoji(char race);
    string getRaceName(char race);
};

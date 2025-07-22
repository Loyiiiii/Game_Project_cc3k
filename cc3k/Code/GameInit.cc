export module GameInit;
import <iostream>;
import <fstream>;
import <string>;
import GamePlay;
using namespace std;

export class Game {
    GameBoard* board;
    int curFloor = 0;
    int curCha = 
public:
    Game();
    ~Game();
    void start();
    void newGame();
    void showAsset();

};
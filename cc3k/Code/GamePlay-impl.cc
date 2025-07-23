//仍需和其他模块进行交互查看如何互相使用！！！
/**
module GamePlay;
import <iostream>;
import <fstream>;
import <sstream>;
import <string>;
import <utility>;
import <compare>;
import <vector>;
import <algorithm>;
using namespace std;

void Gameplay::startGame() {
    chooseRace();
    generateFloor();
    mainLoop();
}


void Gameplay::mainLoop() {
    while (!gameOver) {
        render();

        string cmd;
        getline(cin, cmd);

        handleCommand(cmd);
        resolveDeaths();

        if (!frozenEnemies) {
            updateEnemies();
        }

        player->endTurn();
        checkVictoryOrDeath();
    }
}

void Gameplay::handleCommand(const std::string& cmd) {
    if (cmd == "q") {
        gameOver = true;
    } else if (cmd == "r") {
        startGame();
    } else if (cmd == "f") {
        frozenEnemies = !frozenEnemies;
    } else if (isMovement(cmd)) {
        player->move(cmd, *floor);
    } else if (startsWith(cmd, "a ")) {
        player->attack(getDirection(cmd.substr(2)), *floor);
    } else if (startsWith(cmd, "u ")) {
        player->usePotion(getDirection(cmd.substr(2)), *floor);
    } else {
        cout << "Invalid command." << std::endl;
    }
}

void Gameplay::updateEnemies() {
    for (auto& e : floor->getEnemies()) {
        if (e->isAlive()) {
            e->performTurn(*player, *floor);
        }
    }
}

void Gameplay::resolveDeaths() {
    for (auto& e : floor->getEnemies()) {
        if (!e->isAlive()) {
            floor->removeEnemy(e);
            player->gainGoldFrom(e);
        }
    }
}

void Gameplay::checkVictoryOrDeath() {
    if (player->getHP() <= 0) {
        cout << "You died! Game over.\n";
        gameOver = true;
    } else if (player->onStairs() && currentFloor == 5) {
        cout << "You escaped the dungeon! Your final score is: " << player->getScore() << "\n";
        gameOver = true;
    } else if (player->onStairs()) {
        ++currentFloor;
        generateFloor();
    }
}

void Gameplay::render() {
    system("clear");
    floor->display();
    cout << "Race: " << player->getRaceName() << "  HP: " << player->getHP()
              << "  Atk: " << player->getAtk() << "  Def: " << player->getDef()
              << "  Gold: " << player->getGold() << "  Floor: " << currentFloor << "\n";
}


unique_ptr<PlayerCharacter> GameInit::curr_game_PC(Position start_pos, Race start_race) {
    if (start_race == Race::DROW) {
        return make_unique<Drow>(start_pos);
    }
    else if (start_race == Race::VAMPIRE) {
        return make_unique<Vampire>(start_pos);
    }
    else if (start_race == Race::TROLL){
        return make_unique<Troll>(start_pos); 
    }
    else if (start_race == Race::GOBLIN) {
        return make_unique<Goblin>(start_pos); 
    }
    else {
        return make_unique<Shade>(start_pos); 
    }
}
**/






// Gameplay.cc (main game loop)
import <iostream>;
import <string>;
import <vector>;
import GamePlay;
import PlayerCharacter;
import Direction;
import Floor;
import MapPrinter;
import Global_Constants;

using namespace std;

GameResult Gameplay::mainLoop() {
    bool gameOver = false;
    GameResult result = GameResult::Quit; // default if quit

    while (!gameOver) {
        // 1. Display the Game State
        printMap(); // Show the current floor map
        player->printStats(); // Show player HP, Atk, Def, gold, etc.
        cout << "Floor: " << currentFloorNum << endl;
        printMessages(); // Show any queued messages

        // 2. Receive and Parse Player Input
        string command;
        cin >> command;

        Action action;
        Direction dir;

        if (command == "move") {
            string dirStr; cin >> dirStr;
            action = Action::Move;
            dir = parseDirection(dirStr);
        } else if (command == "atk") {
            string dirStr; cin >> dirStr;
            action = Action::Attack;
            dir = parseDirection(dirStr);
        } else if (command == "use") {
            string dirStr; cin >> dirStr;
            action = Action::UsePotion;
            dir = parseDirection(dirStr);
        } else if (command == "q" || command == "quit") {
            action = Action::Quit;
        } else {
            cout << "Invalid command. Try again." << endl;
            continue;
        }

        // 3. Handle Player Action
        switch (action) {
            case Action::Move:
                playerMove(dir);
                break;
            case Action::Attack:
                playerAttack(dir);
                break;
            case Action::UsePotion:
                playerUsePotion(dir);
                break;
            case Action::Quit:
                gameOver = true;
                result = GameResult::Quit;
                continue;
        }

        // 4. Enemy Turn (if not paused)
        if (!enemyFrozen) {
            for (auto &enemy : enemies) {
                if (enemy->isAdjacentTo(*player)) {
                    enemy->attack(*player);
                } else {
                    enemy->moveRandom();
                }
            }
        }

        // 5. Check for End Conditions
        if (player->isDead()) {
            gameOver = true;
            result = GameResult::Loss;
        } else if (player->isAtStairs() && currentFloorNum == FINAL_FLOOR) {
            gameOver = true;
            result = GameResult::Win;
        }

        // 6. Loop or Exit handled by loop condition
    }

    return result;
}

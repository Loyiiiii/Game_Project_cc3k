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
module GamePlay;
import <iostream>;
import <string>;
import <vector>;
import GamePlay;//
import PlayerCharacter;
import Direction;//
import floor;
import MapPrinter;//
import Global_Constants;
import position;
import floor_level;
import potion;

using namespace std;

void Gameplay::setPlayerRace(Race race) {
    if (race == Race::DROW) {
        player = make_unique<Drow>();
    } else if (race == Race::VAMPIRE) {
        player = make_unique<Vampire>();
    } else if (race == Race::TROLL) {
        player = make_unique<Troll>();
    } else if (race == Race::GOBLIN) {
        player = make_unique<Goblin>();
    } else {
        player = make_unique<Shade>();
    }
}

Direction Gameplay::parseDirection(const string& dirStr) {
    if (dirStr == "no") return Direction::N;
    if (dirStr == "so") return Direction::S;
    if (dirStr == "ea") return Direction::E;
    if (dirStr == "we") return Direction::W;
    if (dirStr == "ne") return Direction::NE;
    if (dirStr == "nw") return Direction::NW;
    if (dirStr == "se") return Direction::SE;
    if (dirStr == "sw") return Direction::SW;
    throw invalid_argument("Invalid direction");
}

Position Gameplay::getTargetPosition(Position pos, Direction dir) {
    //Adjust row/col based on your direction enum
    if(dir == Direction::N) return {pos.row - 1, pos.col};
    if(dir == Direction::S) return {pos.row + 1, pos.col};
    if(dir == Direction::E) return {pos.row, pos.col + 1};
    if(dir == Direction::W) return {pos.row, pos.col - 1};
    if(dir == Direction::NE) return {pos.row - 1, pos.col + 1};
    if(dir == Direction::NW) return {pos.row - 1, pos.col - 1};
    if(dir == Direction::SE) return {pos.row + 1, pos.col + 1};
    if(dir == Direction::SW) return {pos.row + 1, pos.col - 1};
    return pos; 
}

GameResult Gameplay::mainLoop() {
    bool gameOver = false;
    GameResult result = GameResult::Quit; // default if quit
    FloorLevel::FloorLevel AllFloorLevel;
    AllFloorLevel = FloorLevel(5);

    while (!gameOver) {
        // 1. Display the Game State
        Floor* CurrFloor = FloorLevel::getCurrentFloor();
        CurrFloor->floor_init(player.get(), "emptyfloor.txt");
        CurrFloor->printMap(player.get()); // Show the current floor map
        //printMap(); // Show the current floor map
        // player->printStats(); // Show player HP, Atk, Def, gold, etc.
        // cout << "Floor: " << currentFloorNum << endl;
        cout << "Floor: " << AllFloorLevel.getCurrentFloorNum() << endl;
        // printMessages(); // Show any queued messages

        // 2. Receive and Parse Player Input
        string command;
        cin >> command;

        Direction dir;
        Position targetPosition;

        if (command == "u") {
            string dirStr;
            cin >> dirStr;
            dir = parseDirection(dirStr);
            targetPosition = getTargetPosition(player->getPosition, dir);
            Cell targetCell = currFloor->getTargetCell(targetPosition.row, targetPosition.col);
            Potion *targetPotion = targetCell.getPotion();
            if (targetPotion) {
                player->drinkPotion(*targetPotion);//here
            }
            continue;
        } else if (command == "a") {
            string dirStr;
            cin >> dirStr;
            dir = parseDirection(dirStr);
            targetPosition = getTargetPosition(player->getPosition, dir);
            player->attack(!Enemy& enemy);//here
            player->takeDamage(!int damage);//here
            continue
        } else if (command == "f") {
            //we need freeze function
            continue;
        } else if (command == "r") {

        } else if (command == "q") {
            break;
        } else if (command == "no" || command == "so" ||
                   command == "ea" || command == "we" ||
                   command == "ne" || command == "nw" ||
                   command == "se" || command == "sw")
        {
            dir = parseDirection(command);
            // Move the player
            Position oldPos = player->getPosition();
            Position newPos = currentFloor->movePlayer(oldPos, dir);
            player->setPosition(newPos);
            continue;
        } else {
            continue;
        }

        /** 
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

        // call movePlayer(Position oldPos, Direction dir)
        **/

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



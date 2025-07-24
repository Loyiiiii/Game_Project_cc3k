module GamePlay;
import <iostream>;
import <string>;
import <vector>;
import PlayerCharacter;
import floor;
import Global_Constants;
import position;
import floor_level;
import potion;

using namespace std;

void Gameplay::setPlayerRace(Race::Race race) {
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
    enemyFrozen = false;

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

        // 2. Receive and Parse Player Input + 3. Handle Player Action
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
                player->drinkPotion(*targetPotion);
                //remove potion logo
                targetCell.removePotion();
            }
        } else if (command == "a") {
            string dirStr;
            cin >> dirStr;
            dir = parseDirection(dirStr);
            targetPosition = getTargetPosition(player->getPosition, dir);
            Cell targetCell = currFloor->getTargetCell(targetPosition.row, targetPosition.col);
            Enemy *targetEnemy = targetCell.getEnemy();
            if (targetEnemy) {
                player->attack(*targetEnemy);
                // check if enemy die
                if (!targetEnemy->is_alive()) {
                    // if so, remove enemy logo
                    targetCell.removeEnemy();
                } 
            }
        } else if (command == "f") {
            cout << "Enemy has been forzen!" << endl;
            enemyFrozen = true;
            //we need freeze function
        } else if (command == "r") {
            result = GameResult::Restart;
            gameOver = true;
            continue;
        } else if (command == "q") {
            gameOver = true;
            result = GameResult::Quit;
            continue;
        } else if (command == "no" || command == "so" ||
                   command == "ea" || command == "we" ||
                   command == "ne" || command == "nw" ||
                   command == "se" || command == "sw")
        {
            dir = parseDirection(command);
            // Move the player
            Position oldPos = player->getPosition();
            Position newPos = CurrFloor->movePlayer(oldPos, dir);
            player->setPosition(newPos);
        } else {
            cout << "Undefined input, please retry..." << endl;
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
        **/

        // 4. Enemy Turn (if not paused)
        if (!enemyFrozen) {
            for (auto &enemy : currFloor->getEnemies()) {
                if (enemy->isAdjacentTo(player->getPosition())) {
                    enemy->attack(*player);
                } else {
                    //enemy->moveRandom();
                }
            }
        }

        //player->takeDamage(targetEnermy->getAtk);

        // 5. Check for End Conditions
        Position stairPosition = CurrFloor->getStairPos();
        Position playerPosition = player->getPosition();

        if (player->isDead()) {
            gameOver = true;
            result = GameResult::Loss;
        } else if ((stairPosition == playerPosition) && (AllFloorLevel.getCurrentFloorNum() == 5)) {
            gameOver = true;
            result = GameResult::Win;
        }  else if (stairPosition == playerPosition) {
            AllFloorLevel.goToNextFloor();
            CurrFloor = AllFloorLevel.getCurrentFloor();
            CurrFloor->floor_init(player.get(), "emptyfloor.txt");
        }

        // 6. Loop or Exit handled by loop condition
    }

    return result;
}



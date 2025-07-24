#include "GamePlay.h"
#include <iostream>
#include <stdexcept>
#include "Drow.h"
#include "Vampire.h"
#include "Troll.h"
#include "Goblin.h"
#include "Shade.h"
#include "FloorLevel.h"
#include "Cell.h"

GamePlay::GamePlay() : enemyFrozen{ false }, player{ nullptr }, allFloorLevel{ nullptr } {}
GamePlay::~GamePlay() {}


// helper function (local)

std::string raceToString(Race race) {
    switch (race) {
        case Race::SHADE: return "Shade";
        case Race::DROW: return "Drow";
        case Race::VAMPIRE: return "Vampire";
        case Race::TROLL: return "Troll";
        case Race::GOBLIN: return "Goblin";
        default: return "Unknown";
    }
}


void printInfo(PlayerCharacter* pc, FloorLevel* floorlevel_ptr) {
    std::cout << "Race: " << raceToString(pc->getRace()) << " Gold: " << pc->getGold() 
              << "                                              "
              << " Floor: " << floorlevel_ptr->getCurrentFloorNum() << std::endl;
    std::cout << "HP: " << pc->getHP() << std::endl;
    std::cout << "Atk: " << pc->getAtk() << std::endl;
    std::cout << "Def: " << pc->getDef() << std::endl;
    std::cout << "Action: " << std::endl;
}


void GamePlay::setPlayerRace(Race race) {
    if (race == Race::DROW) {
        player = std::make_unique<Drow>();
    }
    else if (race == Race::VAMPIRE) {
        player = std::make_unique<Vampire>();
    }
    else if (race == Race::TROLL) {
        player = std::make_unique<Troll>();
    }
    else if (race == Race::GOBLIN) {
        player = std::make_unique<Goblin>();
    }
    else {
        player = std::make_unique<Shade>();
    }
}

void GamePlay::gameInit() {
    allFloorLevel = std::make_unique<FloorLevel>(5);
    allFloorLevel->getCurrentFloor()->floor_init(player.get(), "emptyfloor.txt");
}

Direction GamePlay::parseDirection(const std::string& dirStr) {
    if (dirStr == "no") return Direction::N;
    if (dirStr == "so") return Direction::S;
    if (dirStr == "ea") return Direction::E;
    if (dirStr == "we") return Direction::W;
    if (dirStr == "ne") return Direction::NE;
    if (dirStr == "nw") return Direction::NW;
    if (dirStr == "se") return Direction::SE;
    if (dirStr == "sw") return Direction::SW;
    throw std::invalid_argument("Invalid direction");
}

Position GamePlay::getTargetPosition(Position pos, Direction dir) {
    if (dir == Direction::N) return { pos.row - 1, pos.col };
    if (dir == Direction::S) return { pos.row + 1, pos.col };
    if (dir == Direction::E) return { pos.row, pos.col + 1 };
    if (dir == Direction::W) return { pos.row, pos.col - 1 };
    if (dir == Direction::NE) return { pos.row - 1, pos.col + 1 };
    if (dir == Direction::NW) return { pos.row - 1, pos.col - 1 };
    if (dir == Direction::SE) return { pos.row + 1, pos.col + 1 };
    if (dir == Direction::SW) return { pos.row + 1, pos.col - 1 };
    return pos;
}

GameResult GamePlay::mainLoop() {
    bool gameOver = false;
    GameResult result = GameResult::Quit;

    while (!gameOver) {
        Floor* currentFloor = allFloorLevel->getCurrentFloor();
        currentFloor->printMap(player.get());
        printInfo(player.get(), allFloorLevel.get());
        // std::cout << "Floor: " << allFloorLevel->getCurrentFloorNum() << std::endl;

        std::string command;
        std::cin >> command >> std::endl >> std::endl;

        if (command == "u") {
            std::string dirStr;
            std::cin >> dirStr >> std::endl >> std::endl;
            try {
                Direction dir = parseDirection(dirStr);
                Position targetPosition = getTargetPosition(player->getPosition(), dir);
                Cell& targetCell = currentFloor->getTargetCell(targetPosition.row, targetPosition.col);
                Potion* targetPotion = targetCell.getPotion();
                if (targetPotion) {
                    // if the player is a drow, potion effects are enhanced by 1.5x
                    if (player->getRace() == Race::DROW) {
                        DROW* Drow = dynamic_cast<Drow*>(player.get());
                        if (Drow) {
                            targetPotion.amount = targetPotion->getAmount() * 1.5;
                            player->drinkPotion(*targetPotion);
                            targetCell.removePotion();
                            std::cout << "Drow's potion effect enhanced: " << targetPotion->getAmount() * 1.5 << std::endl; //did not output
                        }
                    } else {
                        player->drinkPotion(*targetPotion);
                        targetCell.removePotion();
                    }
                }
            }
            catch (const std::invalid_argument& e) {
                std::cout << e.what() << std::endl;
            }
        }
        else if (command == "a") {
            std::string dirStr;
            std::cin >> dirStr >> std::endl >> std::endl;
            try {
                Direction dir = parseDirection(dirStr);
                Position targetPosition = getTargetPosition(player->getPosition(), dir);
                Cell& targetCell = currentFloor->getTargetCell(targetPosition.row, targetPosition.col);
                Enemy* targetEnemy = targetCell.getEnemy();
                if (targetEnemy) {
                    player->attack(*targetEnemy);
                    if (!targetEnemy->is_alive()) {
                        targetCell.removeEnemy();
                    }
                }
                // if the player is a vampire, gain 5 HP every attack
                if (player->getRace() == Race::VAMPIRE) {
                    VAMPIRE* Vampire = dynamic_cast<Vampire*>(player.get());
                    if (Vampire) {
                        Vampire->gainHP();
                        std::cout << "Vampire's bloodsucking: +5 HP" << std::endl;  //did not output
                    }
                }
            }
            catch (const std::invalid_argument& e) {
                std::cout << e.what() << std::endl;
            }
        }
        else if (command == "f") {
            enemyFrozen = !enemyFrozen;
            std::cout << "Enemies are " << (enemyFrozen ? "frozen" : "unfrozen") << "!" << std::endl;
        }
        else if (command == "r") {
            return GameResult::Restart;
        }
        else if (command == "q") {
            return GameResult::Quit;
        }
        else {
            try {
                Direction dir = parseDirection(command);
                Position oldPos = player->getPosition();
                Position newPos = currentFloor->movePlayer(oldPos, dir);
                player->setPosition(newPos);
            }
            catch (const std::invalid_argument& e) {
                std::cout << e.what() << std::endl;
                continue;
            }
        }

        // if the player is a troll, gain 5 HP every turn
        if (player->getRace() == Race::TROLL) {
            Troll* troll = dynamic_cast<Troll*>(player.get());
            if (troll) {
                std::cout << "Troll's regeneration: +5 HP (till Max HP)" << std::endl;  //did not output
                troll->gainHP();
            }
        }

        if (!enemyFrozen) {
            auto& enemies = currentFloor->getEnemies();
            for (auto const& enemy : enemies) {
                if (enemy && enemy->is_alive()) {
                    if (enemy->isAdjacentTo(player->getPosition())) {
                        enemy->attack(*player);
                    }
                    else {
                        currentFloor->moveRandom(enemy.get());
                    }
                }
            }
        }

        if (player->getHP() <= 0) {
            gameOver = true;
            result = GameResult::Loss;
        }
        else if (player->getPosition() == currentFloor->getStairPos()) {
            if (allFloorLevel->getCurrentFloorNum() == 5) {
                gameOver = true;
                result = GameResult::Win;
            }
            else {
                allFloorLevel->goToNextFloor(player.get(), "emptyfloor.txt");
            }
        }
    }
    return result;
} 

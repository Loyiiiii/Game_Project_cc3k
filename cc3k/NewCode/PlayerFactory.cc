#include "PlayerFactory.h"
#include <iostream>
#include "Drow.h"
#include "Vampire.h"
#include "Troll.h"
#include "Goblin.h"
#include "Shade.h"

std::unique_ptr<PlayerCharacter> PlayerFactory::createPlayer(Race race, Position start_pos) {
    if (race == Race::DROW) return std::make_unique<Drow>();
    if (race == Race::VAMPIRE) return std::make_unique<Vampire>();
    if (race == Race::TROLL) return std::make_unique<Troll>();
    if (race == Race::GOBLIN) return std::make_unique<Goblin>();
    return std::make_unique<Shade>();
}

Race PlayerFactory::selectRace() {
    std::cout << "Select Your Player Character for the Game: " << std::endl;
    std::cout << "1- Shade" << std::endl;
    std::cout << "2- Drow" << std::endl;
    std::cout << "3- Vampire" << std::endl;
    std::cout << "4- Troll" << std::endl;
    std::cout << "5- Goblin" << std::endl;
    std::cout << "Enter your choice (1-5): ";

    int choice;
    std::cin >> choice;

    if (std::cin.fail() || choice < 1 || choice > 5) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid choice. Defaulting to Shade." << std::endl;
        return Race::SHADE;
    }

    switch (choice) {
    case 1: return Race::SHADE;
    case 2: return Race::DROW;
    case 3: return Race::VAMPIRE;
    case 4: return Race::TROLL;
    case 5: return Race::GOBLIN;
    default: return Race::SHADE;
    }
} 
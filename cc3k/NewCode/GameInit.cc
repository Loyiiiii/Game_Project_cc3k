#include "GameInit.h"
#include <iostream>
#include "GamePlay.h"
#include "Global_Constants.h"

std::string GameInit::getRaceName(char race) {
    if (race == 's' || race == 'S') return "Shade";
    if (race == 'd' || race == 'D') return "Drow";
    if (race == 'v' || race == 'V') return "Vampire";
    if (race == 't' || race == 'T') return "Troll";
    if (race == 'g' || race == 'G') return "Goblin";
    return "Shade";
}

std::string GameInit::getRaceEmoji(char race) {
    if (race == 's' || race == 'S') return "🧙‍♂️";
    if (race == 'd' || race == 'D') return "🧪";
    if (race == 'v' || race == 'V') return "🧛";
    if (race == 't' || race == 'T') return "🛡️";
    if (race == 'g' || race == 'G') return "💰";
    return "🧙‍♂️";
}

void GameInit::run() {
    char raceChar;

    while (true) {
        std::cout << "Choose your race:\n"
            << "s: Shade\n"
            << "d: Drow\n"
            << "v: Vampire\n"
            << "t: Troll\n"
            << "g: Goblin\n"
            << "Enter choice: ";
        std::cin >> raceChar;

        if (raceChar == 's' || raceChar == 'S') {
            std::cout << "Character: Shade \n  HP:125 \n  Atk:25 \n  Def:25 " << std::endl;
        }
        else if (raceChar == 'd' || raceChar == 'D') {
            std::cout << "Character: Drow \n  HP:150 \n  Atk:25 \n  Def:15 " << std::endl;
        }
        else if (raceChar == 'v' || raceChar == 'V') {
            std::cout << "Character: Vampire \n  HP:50 \n  Atk:25 \n  Def:25 " << std::endl;
        }
        else if (raceChar == 't' || raceChar == 'T') {
            std::cout << "Character: Troll \n  HP:120 \n  Atk:25 \n  Def:15 " << std::endl;
        }
        else if (raceChar == 'g' || raceChar == 'G') {
            std::cout << "Character: Goblin \n  HP:110 \n  Atk:15 \n  Def:20 " << std::endl;
        }
        else {
            raceChar = 's';
            std::cout << "The input character is unknown. Switched to Shade." << std::endl;
            std::cout << "Character: Shade \n  HP:125 \n  Atk:25 \n  Def:25 " << std::endl;
        }

        std::string name = getRaceName(raceChar);
        std::string emoji = getRaceEmoji(raceChar);
        std::cout << "\nYou have chosen: " << emoji << " " << name << "! \nAre you sure? (y to confirm, other to reselect): ";
        char choice;
        std::cin >> choice;
        if (choice == 'y' || choice == 'Y') {
            break;
        }
    }

    Race playerRace;
    if (raceChar == 's' || raceChar == 'S') playerRace = Race::SHADE;
    else if (raceChar == 'd' || raceChar == 'D') playerRace = Race::DROW;
    else if (raceChar == 'v' || raceChar == 'V') playerRace = Race::VAMPIRE;
    else if (raceChar == 't' || raceChar == 'T') playerRace = Race::TROLL;
    else if (raceChar == 'g' || raceChar == 'G') playerRace = Race::GOBLIN;
    else playerRace = Race::SHADE;

    while (true) {
        GamePlay gameplay;
        gameplay.setPlayerRace(playerRace);
        gameplay.gameInit();
        GameResult result = gameplay.mainLoop();

        if (result == GameResult::Restart) {
            std::cout << "🔄 Restarting game...\n";
            continue;
        }
        else if (result == GameResult::Win) {
            std::cout << "🏆 Congratulations! You have conquered the dungeon!" << std::endl;
        }
        else if (result == GameResult::Loss) {
            std::cout << "💀 You have fallen in the depths of the dungeon." << std::endl;
        }
        else if (result == GameResult::Quit) {
            std::cout << "🚪 You quit the adventure early. Until next time!" << std::endl;
        }
        break;
    }
} 
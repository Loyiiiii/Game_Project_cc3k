#include "GameInit.h"
#include <iostream>
#include "GamePlay.h"
#include "Global_Constants.h"

std::string GameInit::getRaceName(char race) {
    if (race == 's' || race == 'S') {
        return "Shade";
    } else if (race == 'd' || race == 'D') {
        return "Drow";
    } else if (race == 'v' || race == 'V'){
        return "Vampire";
    } else if (race == 't' || race == 'T') {
        return "Troll";
    } else if (race == 'g' || race == 'G') {
        return "Goblin";
    } else {
        return "Shade";
    }
}

std::string GameInit::getRaceEmoji(char race) {
    if (race == 's' || race == 'S'){
        return "🧙‍";
    } else if (race == 'd' || race == 'D') {
        return "🧪";
    } else if (race == 'v' || race == 'V') {
        return "🧛";
    } else if (race == 't' || race == 'T') {
        return "🛡️";
    } else if (race == 'g' || race == 'G') {
        return "💰";
    } else {
        return "🧙‍";
    }
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
            std::cout << "Special Ability: The settlement of victory gold coins is multiplied by 1.5." << std::endl;
            std::cout << "Difficulty: ⭐⭐" << std::endl;
            std::cout << "📈 Earn extra gold coins after winning, suitable for players who want to get a high score." << std::endl;
        }
        else if (raceChar == 'd' || raceChar == 'D') {
            std::cout << "Character: Drow \n  HP:150 \n  Atk:25 \n  Def:15 " << std::endl;
            std::cout << "Special Ability: The effect of all potions has been reduced to 1.5 times." << std::endl;
            std::cout << "Difficulty: ⭐⭐⭐⭐" << std::endl;
            std::cout << "🧠 High risk, high reward, suitable for skilled players to precisely stack buffs with potions." << std::endl;
        }
        else if (raceChar == 'v' || raceChar == 'V') {
            std::cout << "Character: Vampire \n  HP:50 \n  Atk:25 \n  Def:25 " << std::endl;
            std::cout << "Special Ability: Each successful attack will suck blood +5 HP (no upper limit!)." << std::endl;
            std::cout << "Difficulty: ⭐⭐⭐⭐⭐" << std::endl;
            std::cout << "💉 To stay alive by fighting and sucking blood, it is very suitable for the style of sustaining battles through battles." << std::endl;
        }
        else if (raceChar == 't' || raceChar == 'T') {
            std::cout << "Character: Troll \n  HP:120 \n  Atk:25 \n  Def:15 " << std::endl;
            std::cout << "Special Ability: Automatically restore +5 HP each round (i.e., after the player action)." << std::endl;
            std::cout << "Difficulty: ⭐" << std::endl;
            std::cout << "💪 Tank-type characters, good news for steady players or new players." << std::endl;
        }
        else if (raceChar == 'g' || raceChar == 'G') {
            std::cout << "Character: Goblin \n  HP:110 \n  Atk:15 \n  Def:20 " << std::endl;
            std::cout << "Special Ability: Each time you kill an enemy, you will steal an additional 5 gold." << std::endl;
            std::cout << "Difficulty: ⭐⭐⭐" << std::endl;
            std::cout << "🏴‍☠️ Suitable for cash flow, getting rich by defeating monsters, and can also quickly build economic advantages." << std::endl;
        }
        else {
            raceChar = 's';
            std::cout << "The input character is unknown. It has been automatically switched to the default character for you. You can make a new selection later." << std::endl;
            std::cout << "Character: Shade \n  HP:125 \n  Atk:25 \n  Def:25 " << std::endl;
            std::cout << "Special Ability: The settlement of victory gold coins is multiplied by 1.5." << std::endl;
            std::cout << "Difficulty: ⭐⭐" << std::endl;
            std::cout << "📈 Earn extra gold coins after winning, suitable for players who want to get a high score." << std::endl;
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
        ResultCombo resultCombo;
        resultCombo = gameplay.mainLoop();

        if (resultCombo.type == GameResult::Restart) {
            std::cout << "🔄 Restarting game...\n";
            continue;
        }
        else if (resultCombo.type == GameResult::Win) {
            std::cout << "🏆 Congratulations! You have conquered the dungeon!" << std::endl;
            std::cout << "Your final score is: " << resultCombo.finalScore << std::endl;
            std::cout << "Thank you for playing! 🎮" << std::endl;
        }
        else if (resultCombo.type == GameResult::Loss) {
            std::cout << "💀 You have fallen in the depths of the dungeon." << std::endl;
            std::cout << "Your final score is: " << resultCombo.finalScore << std::endl;
            std::cout << "Better luck next time! 🏰" << std::endl;
        }
        else if (resultCombo.type == GameResult::Quit) {
            std::cout << "🚪 You quit the adventure early. Until next time!" << std::endl;
            break;
        }
        break;
    }
} 

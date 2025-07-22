module GameInit;
import <iostream>;
import <fstream>;
import <string>;
import GamePlay;
using namespace std;

string GameInit::getRaceName(char race) {
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

string GameInit::getRaceEmoji(char race) {
    if (race == 's' || race == 'S'){
        return "🧙‍♂️";
    } else if (race == 'd' || race == 'D') {
        return "🧪";
    } else if (race == 'v' || race == 'V') {
        return "🧛";
    } else if (race == 't' || race == 'T') {
        return "🛡️";
    } else if (race == 'g' || race == 'G') {
        return "💰";
    } else {
        return "🧙‍♂️";
    }
}



void GameInit::run() {
    char raceChar;

    while (true) {
        cout << "Choose your race:\n"
         << "s: Shade\n"
         << "d: Drow\n"
         << "v: Vampire\n"
         << "t: Troll\n"
         << "g: Goblin\n"
         << "Enter choice: ";

        cin >> raceChar;

        if (raceChar == 's' || raceChar == 'S') {
            cout << "Character: Shade \n  HP:125 \n  Atk:25 \n  Def:25 " << endl;
            cout << "Special Ability: The settlement of victory gold coins is multiplied by 1.5." << endl;
            cout << "Difficulty: ⭐⭐" << endl;
            cout << "📈 Earn extra gold coins after winning, suitable for players who want to get a high score." << endl;
        } else if (raceChar == 'd' || raceChar == 'D') {
            cout << "Character: Drow \n  HP:150 \n  Atk:25 \n  Def:15 " << endl;
            cout << "Special Ability: The effect of all potions has been reduced to 1.5 times." << endl;
            cout << "Difficulty: ⭐⭐⭐⭐" << endl;
            cout << "🧠 High risk, high reward, suitable for skilled players to precisely stack buffs with potions." << endl;
        } else if (raceChar == 'v' || raceChar == 'V') {
            cout << "Character: Vampire \n  HP:50 \n  Atk:25 \n  Def:25 " << endl;
            cout << "Special Ability: Each successful attack will suck blood +5 HP (no upper limit!), but therapeutic potions cannot be used." << endl;
            cout << "Difficulty: ⭐⭐⭐⭐⭐" << endl;
            cout << "💉 To stay alive by fighting and sucking blood, it is very suitable for the style of sustaining battles through battles." << endl;
        } else if (raceChar == 't' || raceChar == 'T') {
            cout << "Character: Troll \n  HP:120 \n  Atk:25 \n  Def:15 " << endl;
            cout << "Special Ability: Automatically restore +5 HP each round (i.e., after the player action)." << endl;
            cout << "Difficulty: ⭐" << endl;
            cout << "💪 Tank-type characters, good news for steady players or new players." << endl;
        } else if (raceChar == 'g' || raceChar == 'G') {
            cout << "Character: Goblin \n  HP:110 \n  Atk:15 \n  Def:20 " << endl;
            cout << "Special Ability: Each time you kill an enemy, you will steal an additional 5 gold." << endl;
            cout << "Difficulty: ⭐⭐⭐" << endl;
            cout << "🏴‍☠️ Suitable for cash flow, getting rich by defeating monsters, and can also quickly build economic advantages." << endl;
        } else {
            cout << "The input character is unknown. It has been automatically switched to the default character for you. You can make a new selection later." << endl;
            cout << "Character: Shade \n  HP:125 \n  Atk:25 \n  Def:25 " << endl;
            cout << "Special Ability: The settlement of victory gold coins is multiplied by 1.5." << endl;
            cout << "Difficulty: ⭐⭐" << endl;
            cout << "📈 Earn extra gold coins after winning, suitable for players who want to get a high score." << endl;
        } 

        string name = getRaceName(raceChar);
        string emoji = getRaceEmoji(raceChar);

        cout << "\nYou have chosen: " << raceChar << "! \nAre you sure? (y to confirm, other to reselect): ";
        char choice;
        cin >> choice;

        if (choice == 'y' || choice == 'Y') {
            break;
        }
    }
    

    Gameplay gameplay;
    gameplay.setPlayerRace(raceChar);

    gameplay.gameInit();

    GameResult result = gameplay.mainLoop();

    if (result == GameResult::Win) {
        cout << "🏆 Congratulations! You have conquered the dungeon!" << endl;
    } else if (result == GameResult::Loss) {
        cout << "💀 You have fallen in the depths of the dungeon." << endl;
    } else if (result == GameResult::Quit) {
        cout << "🚪 You quit the adventure early. Until next time!" << endl;
    } else {
        return 0;
    }
}


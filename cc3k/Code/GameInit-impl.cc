module GameInit;
import <iostream>;
import <fstream>;
import <string>;
import gameboard;
using namespace std;

void Gameplay::gameInit() {
    cout << "Welcome to ChamberCrawler3000!" << endl;
    cout << "Choose your race: s (Shade), d (Drow), v (Vampire), t (Troll), g (Goblin)" << endl;
    
    char r;
    cin >> r;

    PC* base = new BasePC();
    if (r == 'd') {
        player = make_unique<DrowPC>(base);
    } else if (r == 'v') {
        player = make_unique<VampirePC>(base);
    } else if (r == 't') {
        player = make_unique<TrollPC>(base);
    } else if (r == 'g') {
        player = make_unique<GoblinPC>(base);
    } else {
        player = make_unique<ShadePC>(base);
    }

    currentFloor = 1;
    gameOver = false;
    frozenEnemies = false;

    floor = make_unique<Floor>();
    floor->generate(player.get(), currentFloor);

    render();

    cout << "Action: Player character has spawned." << endl;
}

void GameInit::run() {
        cout << "Choose your race:\n"
         << "s: Shade\n"
         << "d: Drow\n"
         << "v: Vampire\n"
         << "t: Troll\n"
         << "g: Goblin\n"
         << "Enter choice: ";

    char raceChar;
    cin >> raceChar;

    if (raceChar == "s" && raceChaar == "S") {
        cout << "Character: Shade \n  HP:125 \n  Atk:25 \n  Def:25 " << endl;
    } else if (raceChar == "d" && raceChaar == "D") {
        cout << "Character: Drow \n  HP:150 \n  Atk:25 \n  Def:15 " << endl;
    } else if (raceChar == "v" && raceChaar == "V") {
        cout << "Character: Vampire \n  HP:50 \n  Atk:25 \n  Def:25 " << endl;
    } else if (raceChar == "t" && raceChaar == "T") {
        cout << "Character: Troll \n  HP:120 \n  Atk:25 \n  Def:15 " << endl;
    } else if (raceChar == "g" && raceChaar == "G") {
        cout << "Character: Goblin \n  HP:110 \n  Atk:15 \n  Def:20 " << endl;
    } else {
        cout << "The input character is unknown. It has been automatically switched to the default character for you. You can make a new selection later." << endl;
        cout << "Character: Shade \n  HP:125 \n  Atk:25 \n  Def:25 " << endl;
    }

    Gameplay gameplay;
    gameplay.setPlayerRace(raceChar);

    gameplay.gameInit();

    GameResult result = gameplay.mainLoop();

    switch (result) {
        case GameResult::Win:
            cout << "🏆 Congratulations! You have conquered the dungeon!" << endl;
            break;
        case GameResult::Loss:
            cout << "💀 You have fallen in the depths of the dungeon." << endl;
            break;
        case GameResult::Quit:
            cout << "🚪 You quit the adventure early. Until next time!" << endl;
            break;
    }
}


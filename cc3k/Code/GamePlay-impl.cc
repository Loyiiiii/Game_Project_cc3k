//仍需和其他模块进行交互查看如何互相使用！！！

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

void Gameplay::chooseRace() {
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


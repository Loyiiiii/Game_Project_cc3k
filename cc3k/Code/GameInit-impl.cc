import <iostream>;
import <memory>;

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

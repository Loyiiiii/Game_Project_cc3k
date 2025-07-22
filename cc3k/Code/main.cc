import <iostream>;
import <fstream>;
import <string>;
import GameInit;
using namespace std;

int main(int argc, char* argv[]) {
    cout << "
        .----------------.  .----------------.  .----------------.  .----------------. 
        | .--------------.| | .--------------.| | .--------------.| | .--------------.|
        | |     ______   || | |     ______   || | |    ______    || | |  ___  ____   ||
        | |   .' ___  |  || | |   .' ___  |  || | |   / ____ `.  || | | |_  ||_  _|  ||
        | |  / .'   \_|  || | |  / .'   \_|  || | |   `'  __) |  || | |   | |_/ /    ||
        | |  | |         || | |  | |         || | |   _  |__ '.  || | |   |  __'.    ||
        | |  \ `.___.'\  || | |  \ `.___.'\  || | |  | \____) |  || | |  _| |  \ \_  ||
        | |   `._____.'  || | |   `._____.'  || | |   \______.'  || | | |____||____| ||
        | |              || | |              || | |              || | |              ||
        | '--------------'| | '--------------'| | '--------------'| | '--------------'|
        '----------------'  '----------------'  '----------------'  '----------------' 
        " << endl << endl;
    cout << "Welcome to CC3K — Chamber Crawler 3000!" << endl;
    cout << "Choose your race, descend the dungeon, and fight your way to victory!\n" << endl;
    
    Game* game = new Game;
        while (true) {
        GameInit NewGame;
        NewGame.run(); 

        cout << "\n💀 Game Over! Would you like to play again? (y/n): ";
        char choice;
        cin >> choice;

        if (choice != 'y' && choice != 'Y') break;
    }
    delete game;
}
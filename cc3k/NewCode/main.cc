#include <iostream>
#include "GameInit.h"

int main(int argc, char* argv[]) {
    std::cout << "        .----------------.  .----------------.  .----------------.  .----------------. " << std::endl;
    std::cout << "        | .--------------.| | .--------------.| | .--------------.| | .--------------.|" << std::endl;
    std::cout << "        | |     ______   || | |     ______   || | |    ______    || | |  ___  ____   ||" << std::endl;
    std::cout << "        | |   .' ___  |  || | |   .' ___  |  || | |   / ____ `.  || | | |_  ||_  _|  ||" << std::endl;
    std::cout << "        | |  / .'   \\_|  || | |  / .'   \\_|  || | |   `'  __) |  || | |   | |_/ /    ||" << std::endl;
    std::cout << "        | |  | |         || | |  | |         || | |   _  |__ '.  || | |   |  __'.    ||" << std::endl;
    std::cout << "        | |  \\ `.___.'\\  || | |  \\ `.___.'\\  || | |  | \\____) |  || | |  _| |  \\ \\_  ||" << std::endl;
    std::cout << "        | |   `._____.'  || | |   `._____.'  || | |   \\______.'  || | | |____||____| ||" << std::endl;
    std::cout << "        | |              || | |              || | |              || | |              ||" << std::endl;
    std::cout << "        | '--------------'| | '--------------'| | '--------------'| | '--------------'|" << std::endl;
    std::cout << "        '----------------'  '----------------'  '----------------'  '----------------' " << std::endl << std::endl;
    std::cout << "Welcome to CC3K — Chamber Crawler 3000!" << std::endl;
    std::cout << "Choose your race, descend the dungeon, and fight your way to victory!\\n" << std::endl;

    while (true) {
        GameInit NewGame;
        NewGame.run();

        std::cout << "\nGame Over! Would you like to play again? (y to confirm, other to exit): ";
        char choice;
        std::cin >> choice;

        if (choice != 'y' && choice != 'Y') {
            break;
        }
    }
    std::cout << "\nThank you for playing ChamberCrawler3000!" << std::endl;
    return 0;
} 

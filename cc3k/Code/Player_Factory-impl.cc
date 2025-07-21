module Player_Factory;
import <memory>;
import PlayerCharacter;


std::unique_ptr<PlayerCharacter> player_factory::curr_game_PC(Position start_pos, Race start_race) {
    if (start_race == Race::DROW) {
        return std::make_unique<Drow>(start_pos);
    }
    else if (start_race == Race::VAMPIRE) {
        return std::make_unique<Vampire>(start_pos);
    }
    else if (start_race == Race::TROLL){
        return std::make_unique<Troll>(start_pos); 
    }
    else if (start_race == Race::GOBLIN) {
        return std::make_unique<Goblin>(start_pos); 
    }
    else {
        return std::make_unique<Shade>(start_pos); 
    }
}

void player_factory::select_PlayerCharacter() {
    std::cout << "Select Your Player Character for the Game: " << std::endl;
    std::cout << "1- Shade" << std::endl;
    std::cout << "2- Drow" << std::endl;
    std::cout << "3- Vampire" << std::endl;
    std::cout << "4- Troll" << std::endl;
    std::cout << "5- Goblin" << std::endl;
    std::cout << "Enter your choice (1-5): ";
    std::cout << "NOTE: If you enter an invalid choice, you will be assigned Shade as your character." << std::endl;
}

Race player_factory::UserChoice() {
    int choice_entered = 0; 
    if (std::cin >> choice_entered) {
        if (choice_entered < 1 || choice_entered > 5) {
            std::cout << "ERROR: Not a valid choice" << std::endl;
            std::cout << "Your Character for the Game is - Shade" << std::endl;
            return Race::SHADE;
        }
        else if (choice_entered == 1) {
            return Race::SHADE;
        }
        else if (choice_entered == 2) {
            return Race::DROW;
        }
        else if (choice_entered == 3) {
            return Race::VAMPIRE;
        }
        else if (choice_entered == 4) {
            return Race::TROLL;
        }
        else {
            return Race::GOBLIN;
        }
    }
    else {
        std::cin.clear();
        std::cin.ignore();
        return Race::SHADE; 
    }
}

// at the start of the game, we should call 
// 1. select_PlayerCharacter()
// 2. UserChoice() -> this will return the Race of the Player Character
// 3. based on the Race, we will create the Player Character with the start_pos 
// by calling curr_game_PC(Position start_pos, Race start_race)


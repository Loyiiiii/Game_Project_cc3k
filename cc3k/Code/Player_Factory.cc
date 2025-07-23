export module Player_Factory;
import <memory>;
import PlayerCharacter;
import Global_Constants;
import position;


export class player_factory {
    public:
        virtual std::unique_ptr<PlayerCharacter> curr_game_PC(Position start_pos, Race start_race);
        void select_PlayerCharacter();
        Race UserChoice();
};

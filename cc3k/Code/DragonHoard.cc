export module dragon_hoard;

import gold;

export class DragonHoard : public Gold {
public:
    DragonHoard(); // Constructor to initialize Dragon Hoard with a specific value and pickability
    // Dragon Hoard is initially unpickable, but can be made pickable later
};

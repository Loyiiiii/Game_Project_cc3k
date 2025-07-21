export module marchant_hoard;

import gold;

export class MerchantHoard : public Gold {
public:
    MerchantHoard(); // Constructor to initialize merchant hoard with a value of 4 and unpickable status
    // Merchant Hoard is initially unpickable, but can be made pickable later
};

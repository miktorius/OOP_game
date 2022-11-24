#ifndef LOSE_WEIGHT
#define LOSE_WEIGHT

#include "../eventCategories/eventPlayer.hpp"

class eventLoseWeight : public playerEvent {
    void execute(Controller& ctrl);
};

#endif
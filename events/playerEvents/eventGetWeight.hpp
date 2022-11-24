#ifndef GET_WEIGHT
#define GET_WEIGHT

#include "../eventCategories/eventPlayer.hpp"

class eventGetWeight : public playerEvent {
    void execute(Controller& ctrl);
};

#endif
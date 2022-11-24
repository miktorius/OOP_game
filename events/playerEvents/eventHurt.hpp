#ifndef EVENT_HURT
#define EVENT_HURT

#include "../eventCategories/eventPlayer.hpp"

class eventHurt: public playerEvent{
    void execute(Controller& ctrl);
};

#endif
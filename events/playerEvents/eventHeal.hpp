#ifndef EVENT_HEAL
#define EVENT_HEAL
#include "../eventCategories/eventPlayer.hpp"

class eventHeal: public playerEvent{
public:
    void execute(Controller& ctrl);
};

#endif

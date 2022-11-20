#ifndef EVENT_HEAL
#define EVENT_HEAL
#include "../eventPlayer.hpp"

class eventHeal: public playerEvent{
public:
    void execute(Controller& ctrl);
};

#endif

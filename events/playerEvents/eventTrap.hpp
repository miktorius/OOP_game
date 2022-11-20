#ifndef EVENT_TRAP
#define EVENT_TRAP
#include "../eventPlayer.hpp"

class eventTrap: public playerEvent{
    void execute(Controller& ctrl);
};

#endif
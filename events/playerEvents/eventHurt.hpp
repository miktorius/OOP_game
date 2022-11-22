#ifndef EVENT_TRAP
#define EVENT_TRAP

#include "../eventCategories/eventPlayer.hpp"

class eventHurt: public playerEvent{
    void execute(Controller& ctrl);
    char getSymbol();
private:
    char sym = '~';
};

#endif
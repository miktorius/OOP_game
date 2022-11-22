#ifndef EVENT_TRAP
#define EVENT_TRAP

#include "../eventCategories/eventMap.hpp"

class eventTrap : public eventMap {
    void execute(Controller& ctrl);
    char getSymbol();
private:
    char sym = '?';
};

#endif
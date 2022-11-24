#ifndef EVENT_VICTORY
#define EVENT_VICTORY

#include "../eventCategories/eventState.hpp"

class eventVictory : public eventState{
public:
    void execute(Controller& ctrl);
};

#endif
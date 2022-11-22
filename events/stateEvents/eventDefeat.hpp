#ifndef EVENT_DEFEAT
#define EVENT_DEFEAT

#include "../eventCategories/eventState.hpp"

class eventDefeat : public eventState {
public:
    void execute(Controller& ctrl);
    char getSymbol();
private:
    char sym = '!';
};

#endif
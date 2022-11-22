#ifndef CONTROLLER_HPP
#define CONTROLLER_HPP

 class Controller;

#include "../entities/player.hpp"
#include "../utils/vector2i.hpp"
#include "../graphics/field_view.hpp"
#include "mediator.hpp"
#include "../utils/gameState.hpp"
#include "statemediator.hpp"

class Controller {
public:
    Controller(Mediator *mediator, int w, int h);
    Controller(Mediator *mediator);
    Player& getPlayer();
    void run();
    void onCommand(UserCommand cmd);
    StateMediator* getStateMediator();
    void onStateChange(GameState newState);
private:
    Field *field;
    Player player;
    Mediator *mediator;
    GameState gameState;
    StateMediator *stateMediator;
    int w,h;
};

#endif
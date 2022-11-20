#ifndef CONTROLLER_HPP
#define CONTROLLER_HPP

class Controller;

#include "../entities/player.hpp"
#include "../utils/vector2i.hpp"
#include "../graphics/field_view.hpp"
#include "mediator.hpp"

class Controller {
public:
    Controller(Mediator *mediator, int w, int h);
    Controller(Mediator *mediator);
    Player& getPlayer();
    void run();
    void onCommand(UserCommand cmd);
private:
    Field *field;
    Player player;
    Mediator *mediator;
    int w,h;
};

#endif
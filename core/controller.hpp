#ifndef CONTROLLER_HPP
#define CONTROLLER_HPP
class Controller;
#include "../map/field.hpp"
#include "../entities/player.hpp"
#include "../utils/vector2i.hpp"
#include "../graphics/field_view.hpp"
#include "mediator.hpp"

class Controller {
public:
    Controller(Mediator *mediator, int w, int h);
    Controller(Mediator *mediator);
    void run();
    void onCommand(UserCommand cmd);
private:
    Field field;
    Player player;
    Mediator *mediator;
    FieldView view;
    int w,h;
};

#endif
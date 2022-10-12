#ifndef CONTROLLER_HPP
#define CONTROLLER_HPP
class Controller;
#include "../map/field.hpp"
#include "../entities/player.hpp"
#include "../utils/vector2i.hpp"
#include "../graphics/field_view.hpp"
#include "game_mediator.hpp"

class Controller {
public:
    Controller(GameMediator *mediator, int w, int h);
    void run();
    void onCommand(UserCommand cmd);
private:
    Field field;
    Player player;
    Vector2i playerPosition;
    GameMediator *mediator;
    FieldView view;
    int w,h;
};

#endif
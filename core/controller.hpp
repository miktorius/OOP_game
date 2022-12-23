#ifndef CONTROLLER_HPP
#define CONTROLLER_HPP

 class Controller;

#include "../entities/player.hpp"
#include "../utils/vector2i.hpp"
#include "../graphics/field_view.hpp"
#include "mediator.hpp"
#include "../utils/gameState.hpp"
#include "statemediator.hpp"
#include "../log/observable.hpp"

class Controller : public Observable{
public:
    Controller(Mediator *mediator, int w, int h);
    Controller(Mediator *mediator);

    Player& getPlayer();
    Field* getField();
    StateMediator* getStateMediator();

    void run();
    void onCommand(UserCommand cmd);
    void onStateChange(GameState newState);
    void setSize(Vector2i size);
    void setState(GameState state);
    GameState getState();
    //std::string playerToString() const;

    void loadMapConfig();
    void saveMapConfig();

private:
    Field *field;
    Player player;
    Mediator *mediator;
    GameState gameState;
    StateMediator *stateMediator;
    int w,h;
};

#endif
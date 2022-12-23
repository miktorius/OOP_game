#include "controller.hpp"
#include <iostream>
#include <stdlib.h>
#include <sstream>
#include "../map/field.hpp"
#include "../graphics/field_view.hpp"
#include "../utils/vector2i.hpp"
#include "../utils/level_type.hpp"

#include "../events/playerEvents/eventHeal.hpp"
#include "../events/playerEvents/eventHurt.hpp"
#include "../events/playerEvents/eventGetWeight.hpp"
#include "../events/playerEvents/eventLoseWeight.hpp"
#include "../events/stateEvents/eventVictory.hpp"
#include "../events/stateEvents/eventDefeat.hpp"
#include "../events/mapEvents/eventTrap.hpp"

#include "../log/messages/player_messages.hpp"
#include "../log/messages/game_state_messages.hpp"

#include "../map/generation/map_generator.hpp"
#include "../map/generation/rules/field_size_rule.hpp"
#include "../map/generation/rules/damage_position_rule.hpp"
#include "../map/generation/rules/obstacles_rule.hpp"
#include "../map/generation/rules/player_position_rule.hpp"
#include "../map/generation/rules/win_position_rule.hpp"

#include "../map/save/file_map_saver.hpp"
#include "../map/save/save_file_loader.hpp"

#include "../exceptions/loading_map_exception.hpp"

Controller::Controller(Mediator *mediator, int w, int h) 
    : player(Player()), 
    mediator(mediator),
    gameState(GameState::Playing){}

Controller::Controller(Mediator *mediator) 
    : player(Player()),
    mediator(mediator),
    gameState(GameState::Playing){}

void Controller::run() {

    Level chosen;
    std::cout << "Choose level (1,2) : ";
    int c;
    std:: cin >> c;
    switch(c){
    case 1:
        chosen = Level::ONE;
        break;
    case 2:
        chosen = Level::TWO;
        break;  
    default:
        system("cls");
        std::cout << "Input error. Choose level (1,2) :";
        std::cin >> c;
    }

    if (chosen == Level::ONE) {
        MapGenerator <
            FieldSizeRule<15,10>,
            ObstaclesRule<ObstaclesVariant::ROOMS>,
            PlayerPositionRule<1,1>,
            WinEventPositionRule<15-2,10-2>,
            DamageEventRule<20>
        > gena;
        field = gena.generate();
    }
    else if (chosen == Level::TWO) {
        MapGenerator <
            FieldSizeRule<8,12>,
            ObstaclesRule<ObstaclesVariant::SPIRAL>,
     		WinEventPositionRule<(8-1)/2,12/2>,
            PlayerPositionRule<1,1>
        > gena;
        field = gena.generate();
    }

    // std::cout << field->toString();

    //system("cls");
    notify(GameStateMessages::gameStart());
    FieldView::drawField(*field, field->getPlayerPosition(), player);
}

Player& Controller::getPlayer(){
    return player;
}

Field* Controller::getField(){
    return field;
}

StateMediator* Controller::getStateMediator() {
    return stateMediator;
}

GameState Controller::getState(){
    return gameState;
}

void Controller::setState(GameState state) {
    gameState = state;
}

void Controller::onStateChange(GameState newState) {
    system("cls");

    setState(newState);
    if (getState() == GameState::Win) {
        notify(GameStateMessages::gameVictory());
        std::cout << "You won!\n";
    }
    else if(getState() == GameState::Loss){
        notify(GameStateMessages::gameDefeat());
        std::cout << "You lost!\n";
    }
    notify(GameStateMessages::gameEnd());
    mediator->endGame();
}

void Controller::onCommand(UserCommand cmd){
    Vector2i tmpPos = field->getPlayerPosition();
    switch(cmd) {
    case UserCommand::UP:
        tmpPos.y -= 1;
        break;
    case UserCommand::LEFT:
        tmpPos.x -= 1;
        break;
    case UserCommand::DOWN:
        tmpPos.y += 1;
        break;
    case UserCommand::RIGHT:
        tmpPos.x += 1;
        break;
    case UserCommand::ESC:
        system("cls");
        notify(GameStateMessages::gameEnd());
        mediator->endGame();
        break;
    case UserCommand::LOAD:
        std::cout << "Got load cmd\n";
        loadMapConfig();
        tmpPos = field->getPlayerPosition();
        break;
    case UserCommand::SAVE: // blyat
    std::cout << "Got save cmd\n";
        saveMapConfig();
        break;
    }
    if (cmd == UserCommand::ESC) {
    }
    else {
        //system("cls");
        auto size = field->getSize();
        tmpPos.x = (tmpPos.x + size.x) % size.x;
        tmpPos.y = (tmpPos.y + size.y) % size.y;
        if (field->getCellPassability(tmpPos)){
            field->setPlayerPosition(tmpPos);
            notify(PlayerMessages::changedPosition(tmpPos));
            field->activateCellEvent(tmpPos, *this);
        }
        else { notify(PlayerMessages::triedToPassSolidCell(tmpPos)); }
        if (player.getHP() == 0) { onStateChange(GameState::Loss); }
        if (gameState == GameState::Playing){ FieldView::drawField(*field, field->getPlayerPosition(), player); }
    }
}

void Controller::loadMapConfig(){
    std::string filename;
    std::cout << "Enter filename: ";
    std::cin >> filename;  
    try{
        SaveFileLoader loader(filename);
        field = loader.loadMap(player);
    }
    catch (const Exceptions::LoadingMapException& ex) {
        std::cout << ex.what() << "\n";
    }
}

// try to compile

void Controller::saveMapConfig() {

    FileMapSaver saver;
    std::string saveName;
    std::cout << "Enter save name: ";
    std::cin >> saveName;  
    saver.saveMap(*field, saveName, player);
}
    

// std::string Controller::playerToString() const {
//         std::stringstream sstr;

//     sstr << "{Player}\n" << player->creature << '\n' << player->position.x << " " << player->position.y << '\n';
//     return sstr.str();

// }
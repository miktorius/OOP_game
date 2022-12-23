#ifndef ENTITY_HPP
#define ENTITY_HPP

#include "../utils/saveable_component.hpp"

class Entity : public SaveableComponent{
public:
    Entity(
        int hp, int weight, int damage,
        int maxhp, int maxweight
    );

    void setHP( int hp );
    void setDamage( int damage );
    void setWeight( int weight );

    int getHP() const;
    int getDamage() const;
    int getWeight() const;

    int getMaxHP() const;
    int getMaxWeight() const;

    std::string toString() const;
    static Entity fromString(std::string str);

private:
    int hp,
        weight,
        damage;
    int maxhp,
        maxweight;
};

#endif
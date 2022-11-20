#include "entity.hpp"

Entity::Entity(
        int hp, int weight, int damage,
        int maxhp, int maxweight
    ) : hp(hp), weight(weight), damage(damage), maxhp(maxhp), maxweight(maxweight) {}

void Entity::setHP( int newhp ) {hp = newhp;}
void Entity::setDamage( int newdamage ) {damage = newdamage;}
void Entity::setWeight( int newweight ) {weight = newweight;}

int Entity::getHP() const {return hp;}
int Entity::getDamage() const {return damage;}
int Entity::getWeight() const {return weight;}

int Entity::getMaxHP() const {return maxhp;}
int Entity::getMaxWeight() const {return maxweight;}
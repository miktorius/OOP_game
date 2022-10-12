#include "entity.hpp"

Entity::Entity(
        int hp, int weight, int damage,
        int maxhp, int maxweight
    ) : hp(hp), weight(weight), damage(damage), maxhp(maxhp), maxweight(maxweight) {}

void Entity::set_hp( int hp ) {hp = hp;}
void Entity::set_damage( int damage ) {damage = damage;}
void Entity::set_weight( int weight ) {weight = weight;}

int Entity::get_hp() const {return hp;}
int Entity::get_damage() const {return damage;}
int Entity::get_weight() const {return weight;}

int Entity::get_max_hp() const {return maxhp;}
int Entity::get_max_weight() const {return maxweight;}
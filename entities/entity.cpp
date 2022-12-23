#include "entity.hpp"
#include "../utils/string_utilities.hpp"
#include <map>

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

std::string Entity::toString() const {
    std::stringstream stream;
    stream << "<Entity hp={ " << hp << "/" << maxhp 
        << "} weight={" << weight << "/" << maxweight
        << "}>"; 
    return stream.str();
}

Entity Entity::fromString(std::string slon) {
    std::map<std::string, std::string> mp = StringUtilities::stringToMap(slon);
    auto hps = StringUtilities::findTwoInts(mp["hp"]);
    auto weights = StringUtilities::findTwoInts(mp["weight"]);

    Entity result(hps.first, weights.first, 10, hps.second, weights.second);
    result.setHP(hps.first);
    result.setWeight(weights.first);

    return result;
}
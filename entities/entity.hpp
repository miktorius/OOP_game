#ifndef ENTITY_HPP
#define ENTITY_HPP

class Entity {
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
private:
    int hp,
        weight,
        damage;
    int maxhp,
        maxweight;
};

#endif
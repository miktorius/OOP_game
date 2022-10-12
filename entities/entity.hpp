#ifndef ENTITY_HPP
#define ENTITY_HPP

class Entity {
public:
    Entity(
        int hp, int weight, int damage,
        int maxhp, int maxweight
    );

    void set_hp( int hp );
    void set_damage( int damage );
    void set_weight( int weight );

    int get_hp() const;
    int get_damage() const;
    int get_weight() const;

    int get_max_hp() const;
    int get_max_weight() const;
private:
    int hp,
        weight,
        damage;
    int maxhp,
        maxweight;
};

#endif
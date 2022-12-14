#ifndef FIELD_SIZE_RULE_HPP
#define FIELD_SIZE_RULE_HPP

#include "../../field.hpp"


template <int x, int y>
class FieldSizeRule {
public:
    static void changeMap(Field &field) {
        field.setSize({x, y});
    }
};



#endif
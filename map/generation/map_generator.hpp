#ifndef MAP_GENERATOR_HPP
#define MAP_GENERATOR_HPP

#include "../field.hpp"
#include "../../core/controller.hpp"
#include "rules/field_size_rule.hpp"


template <typename ... Rules>
class MapGenerator {
public:
    MapGenerator(MapGenerator&&) = delete;
    MapGenerator(const MapGenerator&) = delete;
    MapGenerator() : m_field(new Field) {};

    Field* generate() {
        (modifyField<Rules...>());
        return m_field;
    }

private:
    Field *m_field;

    template <typename Rule, typename ... RestRules>
    void modifyField() {
        Rule::changeMap(*m_field);
        if constexpr (sizeof...(RestRules) > 0) {
            modifyField<RestRules...>();
        }
    }
};


#endif
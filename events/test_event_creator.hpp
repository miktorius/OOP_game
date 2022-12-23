#ifndef TEST_EVENT_CREATOR
#define TEST_EVENT_CREATOR

#include "event_creator.hpp"
#include "../map/field.hpp"

class TestEventCreator : public EventCreator {
public:
    TestEventCreator(Field& field);
    Event* fromString(std::string str);
private:
    Field &m_field;
};


#endif
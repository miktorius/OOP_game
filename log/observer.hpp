#ifndef OBSERVER
#define OBSERVER

#include "message.hpp"

class Observer {
public:
    virtual void update(const Message &msg) = 0;
};

#endif
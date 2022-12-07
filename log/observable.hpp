#ifndef OBSERVABLE
#define OBSERVABLE

#include "observer.hpp"
#include <vector>

class Observable {
public:
    void subscribe(Observer *observer);
    void unsubscribe(Observer *observer);
    void notify(const Message &message);
    void copySubscriptions(Observable *other);
private:
    std::vector< Observer * > listeners;
};

#endif
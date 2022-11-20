#ifndef EVENT_HPP
#define EVENT_HPP

class Event {
public:
    virtual void execute();
    // virtual ~Event() = default;
};

#endif
// Event *ev = HealPlayerEvent(...); ev->call(...)
// 
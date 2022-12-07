#ifndef MESSAGE
#define MESSAGE

#include "log_types.hpp"
#include <string>

class Message {
public:
    Message(LogType type, std::string message);

    LogType type() const;
    std::string content() const;

    friend std::ostream& operator<<(std::ostream& stream, const Message &msg);

private:
    LogType m_type;
    std::string m_msg;
};

#endif
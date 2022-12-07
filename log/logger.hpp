#ifndef LOGGER
#define LOGGER

#include"observer.hpp"
#include <map>
#include <vector>

extern const std::map<LogType, std::string> prefix;

class Logger : public Observer {
public:
    virtual ~Logger() = default;
    void addLogType(const LogType &type);
    void deleteLogType(const LogType &type);
protected:
    bool logTypeAvailable(const LogType &type) const;
private:
    std::vector<LogType> m_types;
};

#endif
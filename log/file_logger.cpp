#include "file_logger.hpp"

#include <iostream>

FileLogger::FileLogger(const std::string &filename) {
    file.open(filename);
}

void FileLogger::update(const Message &message) {
    if (logTypeAvailable(message.type()))
        file << message << '\n';
}

FileLogger::~FileLogger() {
    file.close();
}

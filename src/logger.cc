#include <iostream>

#include "logger.hh"

Logger& Logger::log()
{
    static Logger instance;
    return instance;
}

void Logger::log(std::string& s)
{
    std::cerr << s << std::endl;
}

void Logger::log_insert(std::string& name, int id)
{
        std::cerr << "[" << GameClock::clock().getElapsedTime().asSeconds()
            << "]" <<"[" << id << "] -> " << name << std::endl;
}


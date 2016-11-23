#include <iostream>

#include "logger.hh"

Logger& Logger::log()
{
    static Logger instance;
    return instance;
}

void Logger::log(const std::string& s)
{
    std::cerr << s << std::endl;
}

void Logger::log_insert(std::string& name, int id)
{
        std::cerr << "[" << GameClock::clock().getElapsedTime().asSeconds()
            << "]" <<"[" << id << "] -> " << name << std::endl;
}

void Logger::log_collision(std::pair<int, int>& ids, const state& state)
{
    std::cerr << tag(ids.first, state) << " collided with "
        << tag(ids.second, state) << std::endl;
}

void Logger::log_score_increase(int id, const state& state)
{
    std::cerr << tag(id, state) << " now has " << state.scores.at(id)
        << " money" << std::endl;
}

std::string tag(int id, const state& state)
{
    return state.names.at(id) + "[" + std::to_string(id) + "]";
}

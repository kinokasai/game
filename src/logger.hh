#pragma once

#include <string>
#include "state.hh"

class Logger
{
    public:
        static Logger& log();
        void log(const std::string& s);
        void log_insert(std::string& name, int id);
        template <typename T>
        void log_insert(std::string& name, std::pair<int, T> value);
        void log_score_increase(int id, const state& state);
        void log_collision(std::pair<int, int>& ids, const state& state);
};

std::string tag(int id, const state& state);

#include "logger.hxx"

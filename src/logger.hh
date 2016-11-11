#pragma once

#include <string>

class Logger
{
    public:
        static Logger& log();
        void log(const std::string& s);
        void log_insert(std::string& name, int id);
        template <typename T>
        void log_insert(std::string& name, std::pair<int, T> value);
};

#include "logger.hxx"

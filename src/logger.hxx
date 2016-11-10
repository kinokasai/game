#pragma once

#include <iostream>

#include "logger.hh"
#include "clock.hh"

template <typename T>
void Logger::log_insert(std::string& name, std::pair<int, T> value)
{
    log_insert(name, value.first);
}

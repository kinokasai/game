#pragma once

#include "logger.hh"

#ifdef DEBUG
  #define LOGI(x, y) do {Logger::log().log_insert(x, y);} while(0);
#else
  #define LOGI(x, y)
#endif

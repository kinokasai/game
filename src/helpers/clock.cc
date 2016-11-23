#include "clock.hh"

sf::Clock& GameClock::clock()
{
    static sf::Clock clock;
    return clock;
}

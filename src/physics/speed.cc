#include <cmath>

#include "speed.hh"

speed make_speed(float mspeed)
{
    speed speed;
    speed.max_speed = mspeed;
    return speed;
}

float get_speed(speed& speed)
{
    float time = speed.clock.getElapsedTime().asMilliseconds();
    return speed.max_speed * fmax(sin(time), 1);
}

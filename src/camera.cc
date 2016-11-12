#include <cmath>

#include "camera.hh"

struct camera make_default_camera(level& level, sf::RenderWindow& window)
{
    struct camera cam;
    cam.x = 0;
    cam.y = 0;
    cam.gap = 50;
    cam.max_x = level.w * level.wall_size;
    cam.max_y = level.h * level.wall_size;
    cam.win_x = window.getSize().x;
    cam.win_y = window.getSize().y;
    return cam;
}

void move_camera(state& state)
{
    auto& cam = state.cam;
    int id = state.player_id;
    float px = state.areas[id].x;
    float py = state.areas[id].y;
    cam.x = fmin(fmax(px - (cam.win_x / 2), 0), cam.max_x - cam.win_x);
    cam.y = fmin(fmax(py - cam.win_y / 2, 0), cam.max_y - cam.win_y);
}

#include <cmath>

#include "camera.hh"
#include "helpers.hh"

struct camera make_default_camera(level& level, sf::RenderWindow& window)
{
    struct camera cam;
    cam.x = 0;
    cam.y = 0;
    cam.gap = 25;
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
    const area& player = state.areas[id];

    /* Smooth scrolling can go to hell */
    cam.x = fmax(player.x + player.w - cam.win_x / 2, 0);
    cam.y = fmax(player.y + player.h - cam.win_y / 2, 0);

    cam.x = fmin(cam.x, cam.max_x - cam.win_x);
    cam.y = fmin(cam.y, cam.max_y - cam.win_y);
}

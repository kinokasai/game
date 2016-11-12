#include "factory.hh"
#include "level.hh"

struct level make_level()
{
    struct level level;
    level.h = 20;
    level.w = 20;
    level.wall_size = 50;
    for (int i = 0; i < 5; ++i)
        level.tilemap.push_back(1);
    for (int i = 5; i < level.h * level.w; ++i)
        level.tilemap.push_back(std::rand()%3);
    return level;
}

void load_level(const level& level, state& state)
{
    auto& tilemap = level.tilemap;
    color color = make_color_hex(0x323232);
    int x = 0;
    int y = 0;
    for (unsigned int i = 0; i < tilemap.size(); ++i)
    {
        x = (i % level.w) * level.wall_size;
        y = (int)(i / level.h) * level.wall_size;
        if (!tilemap[i])
            make_solid_entity(x, y, level.wall_size, level.wall_size, color, state);
    }
}

#include "factory.hh"
#include "level.hh"

struct level make_level()
{
    struct level level;
    level.h = 20;
    level.w = 20;
    for (int i = 0; i < 5; ++i)
        level.tilemap.push_back(0);
    for (int i = 5; i < level.h * level.w; ++i)
        level.tilemap.push_back(std::rand()%2);
    return level;
}

void load_level(const level& level, state& state)
{
    auto& tilemap = level.tilemap;
    color color = make_color_hex(0x323232);
    int w = 50;
    int h = 50;
    int x = 0;
    int y = 0;
    for (unsigned int i = 0; i < tilemap.size(); ++i)
    {
        x = (i % level.w) * w;
        y = (int)(i / level.h) * w;
        if (tilemap[i])
            make_solid_entity(x, y, w, h, color, state);
    }
}

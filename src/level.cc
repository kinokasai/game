#include "factory.hh"
#include "chest.hh"
#include "level.hh"

struct level make_level()
{
    struct level level;
    level.h = 20;
    level.w = 20;
    for (int i = 0; i < 5; ++i)
        level.tilemap.push_back(1);
    for (int i = 5; i < level.h * level.w; ++i)
        level.tilemap.push_back(std::rand()%3);
    for (int i = 0; i < level.chestnum; ++i)
    {
        int x;
        int y;
        do {
            x = std::rand() % level.w;
            y = std::rand() % level.h;
        } while (!level.tilemap[y * level.w + x]);
        level.chest_pos[i*2] = x * level.tile_size + 20;
        level.chest_pos[i*2+1] = y * level.tile_size + 20;
        level.values[i] = std::rand() % 3000;
    }
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
        x = (i % level.w) * level.tile_size;
        y = (int)(i / level.h) * level.tile_size;
        if (!tilemap[i])
            make_wall(x, y, level.tile_size, level.tile_size, color, state);
    }
    for (unsigned int i = 0; i < level.chestnum; ++i)
        make_chest(level.chest_pos[i*2], level.chest_pos[i*2+1],
                level.values[i], state);
}

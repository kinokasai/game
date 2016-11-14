#include "chest.hh"
#include "enemy.hh"
#include "factory.hh"
#include "level.hh"

vectwo get_empty_spot(level& level)
{
    vectwo vec;
    do {
        vec.x = std::rand() % level.w;
        vec.y = std::rand() % level.h;
    } while(!level.tilemap[vec.y * level.w + vec.x]);
    return vec;
}

struct level make_level()
{
    struct level level;
    level.h = 20;
    level.w = 20;
    for (int i = 0; i < 5; ++i)
        level.tilemap.push_back(1);
    for (int i = 5; i < level.h * level.w; ++i)
        level.tilemap.push_back(std::rand() % 3);

    for (int i = 0; i < 10; ++i)
    {
        vectwo vec = get_empty_spot(level);
        vectwo offset = make_vectwo(20, 20);
        level.chest_pos.push_back(add_vectwo(map_to_pixel(level, vec), offset));
        level.values.push_back(std::rand() % 3000);
    }

    for (int i = 0; i < 10; ++i)
    {
        vectwo vec = get_empty_spot(level);
        vectwo offset = make_vectwo(1, 1);
        level.enemy_pos.push_back(add_vectwo(map_to_pixel(level, vec), offset));
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
    for (unsigned int i = 0; i < level.chest_pos.size(); ++i)
        make_chest(level.chest_pos[i].x, level.chest_pos[i].y, level.values[i], state);
    for (auto& pos : level.enemy_pos)
        make_enemy(pos.x, pos.y, state);
}

vectwo map_to_pixel(level& level, const vectwo& v)
{
    return scalar_mult(v, level.tile_size);
}

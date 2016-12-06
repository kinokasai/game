#include <cmath>
#include <functional>

#include "bump.hh"
#include "chest.hh"
#include "vectwo.hh"

sarray<bump_func> init_bumps()
{
    sarray<bump_func> bumps("on_bumps");
    bumps.insert(hash(Type::Player, Type::Guard), bump_player_guard);
    bumps.insert(hash(Type::Player, Type::Wall), bump_player_wall);
    bumps.insert(hash(Type::Player, Type::Chest), bump_player_chest);
    bumps.insert(hash(Type::Chest, Type::Wall), do_nothing);
    bumps.insert(hash(Type::Chest, Type::Chest), do_nothing);
    bumps.insert(hash(Type::Guard, Type::Chest), do_nothing);
    bumps.insert(hash(Type::Guard, Type::Guard), bump_guard_guard);
    bumps.insert(hash(Type::Guard, Type::Wall), bump_guard_wall);
    bumps.insert(hash(Type::Wall, Type::Wall), do_nothing);
    return bumps;
}

int hash(int x, int y)
{
    return x * x + y * y;
}

int hash(std::pair<int, int> ids)
{
    return hash(ids.first, ids.second);
}

void bump_player_chest(type_map& ids, state& state)
{
    int chest_id = ids.find(Type::Chest)->second;
    int player_id = ids.find(Type::Player)->second;
    state.scores[player_id] += state.values[chest_id];
    delete_chest(chest_id, state);
}

void bump_player_guard(type_map& ids, state& state)
{
    std::cout << "You've been \033[31m SAVAGELY DISMEMBERED \033[0m\n";
    state.lost = true;
    //push_back(state, ids.find(Type::Player)->second, ids.find(Type::Guard)->second);
}

void bump_player_wall(type_map& ids, state& state)
{
    push_back(state, ids.find(Type::Player)->second, ids.find(Type::Wall)->second);
}

void bump_guard_guard(type_map& ids, state& state)
{
    auto it = ids.begin();
    int first = it->second;
    int second = (++it)->second;
    push_back(state, first, second);
}

void bump_guard_wall(type_map& ids, state& state)
{
    push_back(state, ids.find(Type::Guard)->second, ids.find(Type::Wall)->second);
}

void bump_wall_wall(type_map& ids, state& state)
{
}

void push_back(state& state, int pushed_id, int solid_id)
{
    auto& pushed_area = state.areas[pushed_id];
    auto& wall_area = state.areas[solid_id];
    vectwo& delta = state.delta_moves[pushed_id];
    pushed_area.move(reverse_vectwo(delta));

    pushed_area.x += delta.x;
    while (detect_bump(pushed_area, wall_area))
        pushed_area.x -= delta.x/fmax(delta.x, -delta.x)/4.0f;

    pushed_area.y += delta.y;
    while (detect_bump(pushed_area, wall_area))
        pushed_area.y -= delta.y/fmax(delta.y, -delta.y)/4.0f;
}

void do_nothing(type_map& ids, state& state)
{
    /* Does nothing */
}

void bump(int xid, int yid, state& state)
{
    type_map type_ids;
    Type xtype = state.types[xid];
    Type ytype = state.types[yid];
    type_ids.insert(std::make_pair(xtype, xid));
    type_ids.insert(std::make_pair(ytype, yid));
    int hash_ = hash(xtype, ytype);
    state.bumps[hash_](type_ids, state);
}

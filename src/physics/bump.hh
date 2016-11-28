#pragma once

#include <unordered_map>
#include "state.hh"
#include "type.hh"

using type_map = std::unordered_multimap<Type, int>;
using bump_func = std::function<void(type_map&, state&)>;

sarray<bump_func> init_bumps();

int hash(int x, int y);
int hash(std::pair<int, int>);

void bump(int xid, int yid, state& state);
void bump_player_chest(type_map& ids, state& state);
void bump_player_guard(type_map& ids, state& state);
void bump_player_wall(type_map& ids, state& state);
void bump_guard_guard(type_map& ids, state& state);
void bump_guard_wall(type_map& ids, state& state);
void bump_wall_wall(type_map& ids, state& state);
void do_nothing(type_map& ids, state& state);
void push_back(state& state, int pushed_id, int solid_id);
inline
char detect_bump(const area& a, const area& two)
{
    return (a.x + a.w >= two.x &&
            two.x + two.w >= a.x) &&
        a.y + a.h >= two.y &&
        two.y + two.h >= a.y;
}

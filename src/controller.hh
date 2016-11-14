#pragma once

#include "ai_component.hh"
#include "pevents.hh"

struct state;

void apply_controls(state& state);
void make_ai_controller(int id, state& state);
void make_player_controller(int id, state& state);
void keyboard_control(int id, state& state);
void random_control(int id, state& state);

#include "state.hh"

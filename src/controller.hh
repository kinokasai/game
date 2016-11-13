#pragma once
#include <functional>
#include <vector>
#include "pevents.hh"
#include "sarray.hh"

struct controller
{
    int id;
    std::function<void(int, std::vector<std::pair<int, PlayerEvent>>&)> control;
};

controller make_controller(bool keyboard, int id, int modif);
controller make_ia_controller();
void control(int id, std::vector<std::pair<int, PlayerEvent>>& pevents);
void keyboard_control(int id, std::vector<std::pair<int, PlayerEvent>>& pevents);
void second_keyboard(int id, std::vector<std::pair<int, PlayerEvent>>& pevents);
void pad_control(int id, std::vector<std::pair<int, PlayerEvent>>& pevents);
void apply_controls(sarray<controller> controllers,
        std::vector<std::pair<int, PlayerEvent>>& pevents);

void random_ia(int id, std::vector<std::pair<int, PlayerEvent>>& pevents);

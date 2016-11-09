#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/Joystick.hpp>
#include "controller.hh"

controller make_controller(bool keyboard, int id)
{
    struct controller controller;
    if (keyboard)
        controller.control = keyboard_control;
    else
    {
        controller.control = pad_control;
        controller.id = id;
    }
    return controller;
}

void keyboard_control(int id, std::vector<std::pair<int, PlayerEvent>>& pevents)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        pevents.push_back(std::make_pair(id, PlayerEvent::Left));
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        pevents.push_back(std::make_pair(id, PlayerEvent::Right));
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        pevents.push_back(std::make_pair(id, PlayerEvent::Up));
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        pevents.push_back(std::make_pair(id, PlayerEvent::Down));
}

void pad_control(int id, std::vector<std::pair<int, PlayerEvent>>& pevents)
{
    id = 0;
    pevents = pevents;
}

void apply_controls(sarray<controller> controllers, std::vector<std::pair<int, PlayerEvent>>& pevents)
{
    for (auto& it : controllers)
    {
        auto id = it.first;
        auto controller = it.second;

        controller.control(id, pevents);
    }
}

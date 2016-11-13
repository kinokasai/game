#include <iostream>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/Joystick.hpp>
#include "controller.hh"

controller make_controller(bool keyboard, int pid, int kid)
{
    struct controller controller;
    if (keyboard)
        controller.control = keyboard_control;
    else
    {
        controller.control = pad_control;
        controller.id = pid;
    }
    if (kid)
        controller.control = second_keyboard;
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
    /* This is dirty programming */
    if (!sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        pevents.push_back(std::make_pair(id, PlayerEvent::Walk));
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        pevents.push_back(std::make_pair(id, PlayerEvent::Run));
}

void second_keyboard(int id, std::vector<std::pair<int, PlayerEvent>>& pevents)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
        pevents.push_back(std::make_pair(id, PlayerEvent::Left));
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        pevents.push_back(std::make_pair(id, PlayerEvent::Right));
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
        pevents.push_back(std::make_pair(id, PlayerEvent::Up));
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
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

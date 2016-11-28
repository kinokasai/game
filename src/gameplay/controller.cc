#include <iostream>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/Joystick.hpp>
#include "controller.hh"
#include "id.hh"

void make_player_controller(int id, state& state)
{
    state.controls.insert(id, keyboard_control);
    state.controlled.push_back(id);
}

void make_ai_controller(int id, state& state)
{
    state.controls.insert(id, random_control);
    ai_component component;
    component.seconds = -2;
    state.ai_components.insert(id, component);
    state.controlled.push_back(id);
}

void apply_controls(state& state)
{
    for (auto &id : state.controlled)
        state.controls[id](id, state);
}

void keyboard_control(int id, state& state)
{
    std::vector<std::pair<int, PlayerEvent>> events;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        events.push_back(std::make_pair(id, PlayerEvent::Left));
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        events.push_back(std::make_pair(id, PlayerEvent::Right));
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        events.push_back(std::make_pair(id, PlayerEvent::Up));
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        events.push_back(std::make_pair(id, PlayerEvent::Down));
    if (events.empty())
        events.push_back(std::make_pair(id, PlayerEvent::Stop));
    else
    {
        /* This is dirty programming */
        if (!sf::Keyboard::isKeyPressed(sf::Keyboard::W))
            events.push_back(std::make_pair(id, PlayerEvent::Walk));
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
            events.push_back(std::make_pair(id, PlayerEvent::Run));
    }
    for (auto &it : events)
        state.pevents.push_back(it);
}

void random_control(int id, state& state)
{
    auto& ai = state.ai_components[id];
    auto time = ai.clock.getElapsedTime().asSeconds();
    if (time - ai.seconds > 1)
    {
        ai.event_x = std::rand() % 3;
        ai.event_y = std::rand() % 3 + 2;
        ai.event_y *= (ai.event_y != 2);
        ai.seconds = time;
        state.pevents.push_back(std::make_pair(id, PlayerEvent::AIWalk));
    }
    if (ai.event_x)
        state.pevents.push_back(
            std::make_pair(id, static_cast<PlayerEvent>(ai.event_x)));
    if (ai.event_y)
        state.pevents.push_back(
            std::make_pair(id, static_cast<PlayerEvent>(ai.event_y)));
}

void inert_control(int id, state& state)
{
}

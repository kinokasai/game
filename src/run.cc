#include <iostream>
#include <SFML/Graphics.hpp>

#include "controller.hh"
#include "level.hh"
#include "physics.hh"
#include "player.hh"
#include "render.hh"
#include "run.hh"
#include "state.hh"

void run(sf::RenderWindow& window)
{
    window.setFramerateLimit(60);
    renderer rendr = init_renderer();
    state state = make_state();
    load_level(make_level(), state);
    make_player(state);
    sf::Event event;
    while (window.isOpen())
    {
        while(window.pollEvent(event))
            if (event.type == sf::Event::Closed ||
                    sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
                window.close();

        apply_controls(state.controllers, state.pevents);
        apply_events(state);
        apply_physics(state.dirs, state.areas, state.speeds);
        draw_entities(rendr, window, state.areas, state.colors);
    }
}

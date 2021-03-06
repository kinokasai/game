#include <iostream>
#include <SFML/Graphics.hpp>

#include "camera.hh"
#include "chest.hh"
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
    make_player(state);
    init_game(state, window);
    sf::Event event;
    while (window.isOpen() && !state.lost)
    {
        while(window.pollEvent(event))
            if (event.type == sf::Event::Closed ||
                    sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
                window.close();

        apply_controls(state);
        apply_events(state);
        apply_physics(state.dirs, state.areas, state.speeds, state.levels[0],
                state.entities, state);
        move_camera(state);
        draw_entities(rendr, window, state.areas, state.colors, state.cam, state);
    }
    print_scores(state);
}

#include <iostream>
#include <SFML/Graphics.hpp>

#include "controller.hh"
#include "state.hh"
#include "render.hh"
#include "run.hh"

void run(sf::RenderWindow& window)
{
    renderer rendr = init_renderer();
    state state = make_state();
    auto controller = make_controller(true, 0);
    state.controllers.insert(std::make_pair(1, controller));
    sf::Event event;
    while (true)
    {
        while(window.pollEvent(event))
            if (event.type == sf::Event::Closed)
            {
                window.close();
                exit(0);
            }
        apply_controls(state.controllers, state.pevents);
        apply_events(state);
        draw_entities(rendr, window, state.areas);
    }
}

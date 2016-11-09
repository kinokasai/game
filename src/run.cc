#include <iostream>
#include <SFML/Graphics.hpp>

#include "state.hh"
#include "render.hh"
#include "run.hh"

void run(sf::RenderWindow& window)
{
    renderer rendr = init_renderer();
    state state = make_state();
    sf::Event event;
    while (true)
    {
        while(window.pollEvent(event))
            if (event.type == sf::Event::Closed)
            {
                window.close();
                exit(0);
            }

        draw_entities(rendr, window, state.areas);
    }
}

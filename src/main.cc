#include <SFML/Graphics.hpp>
#include <iostream>

#include "id.hh"
#include "run.hh"
#include "sarray.hxx"

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600, 32), "Furtive Thief",
      sf::Style::Titlebar | sf::Style::Close);
    run(window);
    return 0;
}

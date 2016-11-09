#include <ctime>
#include <cstdlib>
#include <iostream>
#include <SFML/Graphics.hpp>

#include "id.hh"
#include "run.hh"
#include "sarray.hxx"

int main()
{
    std::srand(std::time(0));
    sf::RenderWindow window(sf::VideoMode(800, 600, 32), "Furtive Thief",
      sf::Style::Titlebar | sf::Style::Close);
    run(window);
    return 0;
}

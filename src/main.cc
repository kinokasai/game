#include <SFML/Graphics.hpp>
#include <iostream>

#include "id.hh"
#include "run.hh"
#include "sarray.hxx"

int main()
{
    sarray<int> val;
    val.insert(std::make_pair(0, 1));
    val.insert(std::make_pair(3, 34));

    for (auto it = val.begin(); it != val.end(); ++it)
        *it = std::pair<int, int>(1, 2);

    for (auto it = val.begin(); it != val.end(); ++it)
        std::cout << it->first << std::endl;

    sf::RenderWindow window(sf::VideoMode(800, 600), "OpenGL");
    run(window);
    return 0;
}

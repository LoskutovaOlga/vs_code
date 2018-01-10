#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

void initShape(sf::CircleShape &shape)
{
    shape.setRadius(200);
    shape.setPosition({200, 100});
    shape.setFillColor(sf::Color(0xEE, 0xC9, 0x00));
    shape.setOutlineColor(sf::Color(0x00, 0x9A, 0xCD));
    shape.setOutlineThickness(5);
}
void pollEvents(sf::RenderWindow &window)
{
    sf::Event event;
    while (window.pollEvent(event))
    {
        switch (event.type)
        {
        case sf::Event::Closed:
            window.close();
            break;
        default:
            break;
        }
    }
}

void redrawFrame(sf::RenderWindow &window, sf::CircleShape &shape, sf::Text &text)
{
    window.clear(sf::Color(0xFF, 0xFF, 0xFF));
    window.draw(shape);
    window.draw(text);
    window.display();
}

int main()
{
    constexpr unsigned WINDOW_WIDTH = 800;
    constexpr unsigned WINDOW_HEIGHT = 600;

    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    sf::RenderWindow window(
        sf::VideoMode({WINDOW_WIDTH, WINDOW_HEIGHT}), "Text",
        sf::Style::Default, settings);

    sf::Font font;
    font.loadFromFile("arial.ttf");

    sf::Text text;
    text.setString("LOI");
    text.setFont(font);
    text.setCharacterSize(100);
    text.setStyle(sf::Text::Bold);
    text.setFillColor(sf::Color::Red);
    text.setPosition(320, 240);

    sf::CircleShape shape;
    initShape(shape);
    while (window.isOpen())
    {
        pollEvents(window);
        redrawFrame(window, shape, text);
    }
}
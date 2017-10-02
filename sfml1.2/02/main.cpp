#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode({200, 180}), "Rectangles and circle");

    window.clear();

    sf::RectangleShape shape1;
    shape1.setSize({10, 150});
    shape1.setPosition({20, 10});
    shape1.setFillColor(sf::Color(0xfF, 0xfF, 0x0F));
    window.draw(shape1);

    sf::RectangleShape shape2;
    shape2.setSize({10, 160});
    shape2.setPosition({60, 10});
    shape2.setFillColor(sf::Color(0xfF, 0xfF, 0x0F));
    window.draw(shape2);

    sf::RectangleShape shape3;
    shape3.setSize({20, 10});
    shape3.setPosition({10, 160});
    shape3.setFillColor(sf::Color(0xfF, 0xfF, 0x0F));
    window.draw(shape3);

    sf::RectangleShape shape4;
    shape4.setSize({40, 10});
    shape4.setPosition({30, 10});
    shape4.setFillColor(sf::Color(0xFF, 0xfF, 0x0F));
    window.draw(shape4);

    sf::RectangleShape shape6;
    shape6.setSize({50, 160});
    shape6.setPosition({80, 10});
    shape6.setFillColor(sf::Color(0xFf, 0xFf, 0x0f));
    window.draw(shape6);

    sf::RectangleShape shape5;
    shape5.setSize({30, 140});
    shape5.setPosition({90, 20});
    shape5.setFillColor(sf::Color(0x00, 0x00, 0x00));
    window.draw(shape5);

    sf::RectangleShape shape7;
    shape7.setSize({10, 160});
    shape7.setPosition({140, 10});
    shape7.setFillColor(sf::Color(0xFf, 0xFf, 0x0f));
    window.draw(shape7);

    sf::RectangleShape shape8;
    shape8.setSize({10, 160});
    shape8.setPosition({178, 10});
    shape8.setRotation(13);
    shape8.setFillColor(sf::Color(0xFf, 0xFf, 0x0f));
    window.draw(shape8);

    sf::RectangleShape shape9;
    shape9.setSize({10, 160});
    shape9.setPosition({180, 10});
    shape9.setFillColor(sf::Color(0xFf, 0xFf, 0x0f));
    window.draw(shape9);

    window.display();

    sf::sleep(sf::seconds(5));
}
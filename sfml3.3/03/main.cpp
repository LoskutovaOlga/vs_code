#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode({160, 160}), "Convex Shapes");
    window.clear();

    sf::ConvexShape trapeze;
    trapeze.setFillColor(sf::Color(0x69, 0x24, 0x1B));
    trapeze.setPosition({10, 60});
    trapeze.setPointCount(4);
    trapeze.setPoint(0, {40, 0});
    trapeze.setPoint(1, {100, 0});
    trapeze.setPoint(3, {0, 30});
    trapeze.setPoint(2, {140, 30});
    window.draw(trapeze);

    sf::CircleShape shape5(5);
    shape5.setPosition({100, 35});
    shape5.setFillColor(sf::Color(0xF7, 0xF7, 0xF7));
    window.draw(shape5);

    sf::CircleShape shape6(7);
    shape6.setPosition({105, 31});
    shape6.setFillColor(sf::Color(0xF7, 0xF7, 0xF7));
    window.draw(shape6);

    sf::CircleShape shape7(10);
    shape7.setPosition({117, 24});
    shape7.setFillColor(sf::Color(0xF7, 0xF7, 0xF7));
    window.draw(shape7);

    sf::CircleShape shape8(12);
    shape8.setPosition({122, 18});
    shape8.setFillColor(sf::Color(0xF7, 0xF7, 0xF7));
    window.draw(shape8);

    sf::RectangleShape shape1;
    shape1.setSize({100, 60});
    shape1.setPosition({30, 90});
    shape1.setFillColor(sf::Color(0x69, 0x39, 0x1B));
    window.draw(shape1);

    sf::RectangleShape shape2;
    shape2.setSize({10, 25});
    shape2.setPosition({90, 55});
    shape2.setFillColor(sf::Color(0x7B, 0x6D, 0x65));
    window.draw(shape2);

    sf::RectangleShape shape3;
    shape3.setSize({20, 10});
    shape3.setPosition({85, 45});
    shape3.setFillColor(sf::Color(0x7B, 0x6D, 0x65));
    window.draw(shape3);

    sf::RectangleShape shape4;
    shape4.setSize({20, 40});
    shape4.setPosition({40, 110});
    shape4.setFillColor(sf::Color(0x9E, 0x44, 0x3D));
    window.draw(shape4);

    
    
   
    window.display();

    sf::sleep(sf::seconds(5));

}
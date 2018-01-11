#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <cmath>
struct Eye
{
    sf::ConvexShape pupil;
    sf::ConvexShape bigBall;
    sf::Vector2f position;
    float rotation = 0;
};

sf::Vector2f toEuclidean(float radiusX, float radiusY, float angle)
{
    return {
        radiusX * std::cos(angle),
        radiusY * std::sin(angle)};
}

float toDegrees(double radians)
{
    return float(double(radians) * 180.0 / M_PI);
}

void updateEyeElements(Eye &Eye)
{
    const sf::Vector2f headOffset = toEuclidean(75, 200, Eye.rotation);
    Eye.pupil.setPosition(Eye.position + headOffset);
}
void initEye(Eye &Eye, float positionX, float positionY)
{
    constexpr int pointCount = 200;

    Eye.position = {positionX, positionY};
    Eye.pupil.setPosition({positionX, positionY});
    Eye.pupil.setFillColor(sf::Color(0xA5, 0x2A, 0x2A));

    const sf::Vector2f PupilRadius = {15.f, 30.f};

    Eye.pupil.setPointCount(pointCount);
    for (int pointNo = 0; pointNo < pointCount; ++pointNo)
    {
        float angle = float(2 * M_PI * pointNo) / float(pointCount);
        sf::Vector2f point = {
            PupilRadius.x * std::sin(angle),
            PupilRadius.y * std::cos(angle)};
        Eye.pupil.setPoint(pointNo, point);
    }

    const sf::Vector2f ellipseRadius = {75.f, 200.f};

    Eye.bigBall.setPosition({positionX, positionY});
    Eye.bigBall.setFillColor(sf::Color(0xFF, 0xFF, 0xFF));

    Eye.bigBall.setPointCount(pointCount);
    for (int pointNo = 0; pointNo < pointCount; ++pointNo)
    {
        float angle = float(2 * M_PI * pointNo) / float(pointCount);
        sf::Vector2f point = {
            ellipseRadius.x * std::sin(angle),
            ellipseRadius.y * std::cos(angle)};
        Eye.bigBall.setPoint(pointNo, point);
    }

    updateEyeElements(Eye);
}

void onMouseMove(const sf::Event::MouseMoveEvent &event, sf::Vector2f &mousePosition)
{
    mousePosition = {float(event.x), float(event.y)};
}

void pollEvents(sf::RenderWindow &window, sf::Vector2f &mousePosition)
{
    sf::Event event;
    while (window.pollEvent(event))
    {
        switch (event.type)
        {
        case sf::Event::Closed:
            window.close();
            break;
        case sf::Event::MouseMoved:
            onMouseMove(event.mouseMove, mousePosition);
            break;
        default:
            break;
        }
    }
}

void update(const sf::Vector2f &mousePosition, Eye &Eye)
{
    const sf::Vector2f delta = mousePosition - Eye.position;
    Eye.rotation = atan2(delta.y, delta.x);
    updateEyeElements(Eye);

    const sf::Vector2f headOffset = toEuclidean(60, 170, Eye.rotation);
    Eye.pupil.setPosition(Eye.position + headOffset);
    if ((std::hypot(delta.x, delta.y) + std::hypot(15, 30)) <= std::hypot(headOffset.x, headOffset.y))
    {
        Eye.pupil.setPosition(mousePosition);
    }
}

void redrawFrame(sf::RenderWindow &window, Eye &Eye2, Eye &Eye1)
{
    window.clear();
    window.draw(Eye1.bigBall);
    window.draw(Eye1.pupil);
    window.draw(Eye2.bigBall);
    window.draw(Eye2.pupil);
    window.display();
}

// Программа рисует в окне стрелку, которая поворачивается вслед за курсором мыши.
int main()
{
    constexpr unsigned WINDOW_WIDTH = 800;
    constexpr unsigned WINDOW_HEIGHT = 600;

    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    sf::RenderWindow window(
        sf::VideoMode({WINDOW_WIDTH, WINDOW_HEIGHT}),
        "Eyes", sf::Style::Default, settings);
    Eye eye1;
    Eye eye2;
    sf::Vector2f mousePosition;

    initEye(eye1, 200, 300);
    initEye(eye2, 500, 300);
    while (window.isOpen())
    {
        pollEvents(window, mousePosition);
        update(mousePosition, eye1);
        update(mousePosition, eye2);
        redrawFrame(window, eye2, eye1);
    }
}

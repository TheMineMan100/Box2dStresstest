#include "Physics.hpp"
#include <vector>
#include <string>
#include "ContactListener.hpp"

using namespace std;
using namespace sf; //for graphics

int main()
{
    RenderWindow window(VideoMode(800, 600), "SFML Works"); //creates a window on the screen that is 800 by 600
    window.setFramerateLimit(60); //sets the game loop to run 60 times per second
    b2World world(b2Vec2(0.0f, 0.0f));
    
    ContactListener* contactListener = new ContactListener();
    world.SetContactListener(contactListener);

    //walls
    physics::createBox(world, 0.0f, 570.0f, 800.0f, 30.0f, b2_staticBody); //floor
    physics::createBox(world, 0.0f, 0.0f, 800.0f, 30.0f, b2_staticBody); //ceiling
    physics::createBox(world, 0.0f, 30.0f, 20.0f, 540.0f, b2_staticBody); //left wall
    physics::createBox(world, 780.0f, 30.0f, 20.0f, 540.0f, b2_staticBody); //right wall
    physics::createBox(world, 30.0f, 370.0f, 100.0f, 10.0f, b2_staticBody); //platform

    Block bigBox = physics::createBox(world, 120.0f, 300.0f, 40.0f, 40.0f);
    Block circle = physics::createCircle(world, 125.0f, 280.0f, 20.0f);

    sf::Vector2f firstPoint = Vector2f(0.0f, 0.0f);
    sf::Vector2f secondPoint = Vector2f(30.0f, 40.0f);
    sf::Vector2f thirdPoint = Vector2f(60.0f, 20.0f);
    vector<sf::Vector2f> point_array = vector<sf::Vector2f>{firstPoint, secondPoint, thirdPoint};
    Block polygon = physics::createPolygon(world, 200.0f, 250.0f, point_array);
    Block polygon2 = physics::createPolygon(world, 200.0f, 150.0f, point_array);

    // Uncomment to show application of impulse on the circle
    circle->ApplyLinearImpulse(b2Vec2(1, -10), circle->GetWorldCenter(), false);

    int amountOfCubes = 0;

    sf::Font font;
    if (!font.loadFromFile("../Arial.ttf"))
    {
        // error...
    }
    sf::Text text;

    text.setFont(font); // font is a sf::Font

    text.setString("Amount of cubes: " + amountOfCubes);

    text.setCharacterSize(26); // in pixels, not points!

    text.setFillColor(sf::Color::Cyan);

    text.setStyle(sf::Text::Bold | sf::Text::Underlined);

    text.setPosition(40.0f, 40.0f);

    while (window.isOpen() && !Keyboard::isKeyPressed(Keyboard::Escape)) //the main game loop, exits if someone closes the window
    {
        Event event; //creates an event object, events include mouse clicks, mouse movements, keyboard presses, etc.
        while (window.pollEvent(event)) //loop that checks for events
        {
            if (event.type == Event::Closed) //checks if window is closed
                window.close();
        }

        if (Mouse::isButtonPressed(Mouse::Left))
        {
            physics::createBox(world, Mouse::getPosition(window).x, Mouse::getPosition(window).y, 10, 10);
            ++amountOfCubes;
        }

        window.clear(); //clears the screen

        text.setString("Amount of cubes: " + std::to_string(amountOfCubes));

        physics::displayWorld(world, window);

        window.draw(text);

        window.display(); //displays everything on the video card to the monitor
    }   //ends the game loop

    return 0;
}

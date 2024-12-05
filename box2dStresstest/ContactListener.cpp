#include "ContactListener.hpp"
#include <SFML/Graphics.hpp>

void ContactListener::BeginContact(b2Contact* contact)
{
    b2Body* bodyA = contact->GetFixtureA()->GetBody();
    b2Body* bodyB = contact->GetFixtureB()->GetBody();
    
    sf::RectangleShape* shapeA = reinterpret_cast<sf::RectangleShape*>(bodyA->GetUserData().pointer);
    shapeA->setFillColor(sf::Color::Red);

    sf::RectangleShape* shapeB = reinterpret_cast<sf::RectangleShape*>(bodyB->GetUserData().pointer);
    shapeB->setFillColor(sf::Color::Red);
}

void ContactListener::EndContact(b2Contact* contact)
{
    b2Body* bodyA = contact->GetFixtureA()->GetBody();
    b2Body* bodyB = contact->GetFixtureB()->GetBody();

    sf::RectangleShape* shapeA = reinterpret_cast<sf::RectangleShape*>(bodyA->GetUserData().pointer);
    shapeA->setFillColor(sf::Color::White);

    sf::RectangleShape* shapeB = reinterpret_cast<sf::RectangleShape*>(bodyB->GetUserData().pointer);
    shapeB->setFillColor(sf::Color::White);
}

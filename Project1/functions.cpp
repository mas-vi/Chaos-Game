#include <iostream>
#include "constants.hpp"
#include "functions.hpp"
#include <random>

// Check if a given point is inside a given rectangle
bool fn::pointInRectangle(sf::Vector2i point, const sf::RectangleShape& rect)
{
    return (point.x >= rect.getPosition().x) &&
        (point.x <= rect.getPosition().x + rect.getSize().x) &&
        (point.y >= rect.getPosition().y) &&
        (point.y <= rect.getPosition().y + rect.getSize().y);
}

// Check if cursor is inside a given rectangle
bool fn::cursorInRectangle(const sf::RectangleShape& rect, const sf::RenderWindow& window)
{
    return fn::pointInRectangle(sf::Mouse::getPosition(window), rect);
}

// Set the size of the button
void fn::Button::setSize(sf::Vector2f size)
{
    m_rectangle.setSize(size);
}

// Get the size of the button
sf::Vector2f const fn::Button::getSize()
{
    return m_rectangle.getSize();
}

// Set the position of the button
void fn::Button::setPosition(sf::Vector2f position)
{
    m_rectangle.setPosition(position);
}

// Get the position of the button
sf::Vector2f const fn::Button::getPosition()
{
    return m_rectangle.getPosition();
}

// Set the fill color of the button
void fn::Button::setFillColor(sf::Color color)
{
    m_rectangle.setFillColor(color);
}

// Get the fill color of the button
sf::Color const fn::Button::getFillColor()
{
    return m_rectangle.getFillColor();
}

// Get a reference to the rectangle shape of the button
sf::RectangleShape& fn::Button::getShape()
{
    return m_rectangle;
}

// Check if the button is being hovered over by the cursor
const bool fn::Button::isHovered(const sf::RenderWindow& window)
{
    return fn::cursorInRectangle(this->getShape(), window);
}

// Generate a random integer between min and max (inclusive)
int fn::randomInt(int min, int max)
{
    std::random_device rd;
    std::mt19937 eng(rd());
    std::uniform_int_distribution<> distr(min, max);
    return distr(eng);
}

// Generate a random point within the main window
sf::Vector2f fn::randomPoint()
{
    return sf::Vector2f(static_cast<float>(fn::randomInt(MAIN_POSITION_X, MAIN_POSITION_X + MAIN_WIDTH)),
        static_cast<float>(fn::randomInt(MAIN_POSITION_Y, MAIN_POSITION_Y + MAIN_HEIGHT)));
}

// To be implemented
void fn::newTriangle(sf::VertexArray& vertices)
{
    // To be implemented
}

// Choose a point based on the location of the cursor
sf::Vertex fn::choosePoint(const sf::RenderWindow& window)
{
    sf::Vertex point;
    point.color = sf::Color::Black;
    point.position = static_cast<sf::Vector2f>(sf::Mouse::getPosition(window));
    return point;
}

// Generate a new point and add it to the vertex array
void fn::generate(sf::VertexArray& vertices)
{
    sf::Vertex edgePoint = vertices[fn::randomInt(0, static_cast<int>(numberOfInitialPoints) - 2)];
    sf::Vertex cursorPoint = vertices[vertices.getVertexCount() - 1];
    sf::Vertex newPoint;
    newPoint.position = sf::Vector2f((edgePoint.position.x + cursorPoint.position.x) / 2,
        (edgePoint.position.y + cursorPoint.position.y) / 2);
    edgePoint.color = sf::Color::Red;
    vertices[vertices.getVertexCount() - 1].color = sf::Color::Black;
    vertices.append(newPoint);
}

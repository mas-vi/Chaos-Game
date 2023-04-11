#include <iostream>
#include "constants.hpp"
#include "functions.hpp"





bool fn::pointInRectangle(sf::Vector2i point, const sf::RectangleShape& rect)
{
	if ((point.x >= rect.getPosition().x) &&
		(point.x <= rect.getPosition().x + rect.getSize().x) &&
		(point.y >= rect.getPosition().y &&
			(point.y <= rect.getPosition().y + rect.getSize().y)
			))
	{
		
		return true;
	}
	else
	{
	
		return false;
	}
}

bool fn::cursorInRectangle(const sf::RectangleShape& rect,const  sf::RenderWindow& window)
{
	if (fn::pointInRectangle(sf::Mouse::getPosition(window), rect))
	{
		
		return true;
	}

	else
	{
		
		return false;
	}
}



void fn::Button::setSize(sf::Vector2f size) {
	m_rectangle.setSize(size);
}

 sf::Vector2f const fn::Button::getSize() {
	return m_rectangle.getSize();
}

void fn::Button::setPosition(sf::Vector2f position) {
	m_rectangle.setSize(position);
}

sf::Vector2f const fn::Button::getPosition() {
	return m_rectangle.getPosition();
}

void fn::Button::setFillColor(sf::Color color) {
	m_rectangle.setFillColor(color);
}
 sf::Color const fn::Button::getFillColor() {
	return m_rectangle.getFillColor();
}

sf::RectangleShape& fn::Button::getShape()
{
	return m_rectangle;
}


const bool fn::Button::isHovered(const  sf::RenderWindow& window)
{
	return(fn::cursorInRectangle(this->getShape(), window));
}


int fn::randomInt(int min, int max)
{
	std::mt19937 eng(std::random_device{}());
	std::uniform_int_distribution<int> distr(min, max);
	return distr(eng);



}

sf::Vector2f fn::randomPoint()
{
	return sf::Vector2f(static_cast<float>(fn::randomInt(MAIN_POSITION_X, MAIN_POSITION_X + MAIN_WIDTH)),
		static_cast<float>(fn::randomInt(MAIN_POSITION_Y, MAIN_POSITION_Y + MAIN_HEIGHT)));
}

void fn::newTriangle(sf::VertexArray& vertices)
{
	
	
	
}

sf::Vertex fn::choosePoint(const sf::RenderWindow& window)
{
	sf::Vertex point{};
	point.color = sf::Color::Black;
	point.position = sf::Vector2f(sf::Mouse::getPosition(window));

	return point;
}


void fn::generate(sf::VertexArray& vertices)
{
	sf::Vertex edgePoint = vertices[randomInt(0, static_cast<size_t>(numberOfInitialPoints)-2)];
	sf::Vertex cursorPoint = vertices[vertices.getVertexCount() - 1];
	sf::Vertex newPoint;
	newPoint.position = sf::Vector2f((edgePoint.position.x + cursorPoint.position.x)/2,
		(edgePoint.position.y+ cursorPoint.position.y) / 2);
	edgePoint.color = sf::Color::Red;
	vertices[vertices.getVertexCount() - 1].color = sf::Color::Black;
	vertices.append(newPoint);
}


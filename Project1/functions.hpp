#pragma once
#include "SFML/Graphics.hpp"
#include <random>

namespace fn {
	bool pointInRectangle(sf::Vector2i point, const sf::RectangleShape& rect);
	bool cursorInRectangle(const sf::RectangleShape& rect, const sf::RenderWindow& window);
	int randomInt(int min, int max);
	sf::Vector2f randomPoint();
	void newTriangle(sf::VertexArray& vertices);
	sf::Vertex choosePoint(const sf::RenderWindow& window);
	void generate(sf::VertexArray& vertices);
	
	

	class Button {
	private:
		sf::RectangleShape m_rectangle{};
		
	public:
		Button(sf::Vector2f size = sf::Vector2f(0, 0)
			, sf::Vector2f position = sf::Vector2f(0, 0),
			sf::Color color = sf::Color::White)
		{
			m_rectangle.setSize(size);
			m_rectangle.setPosition(position);
			m_rectangle.setFillColor(color);
		}
		~Button(){}
		void setSize(sf::Vector2f size);
		sf::Vector2f const getSize();
		void setFillColor(sf::Color color);
		sf::Color const getFillColor();
		void setPosition(sf::Vector2f position);
		sf::Vector2f const getPosition();
		sf::RectangleShape& getShape();
		bool const isHovered(const sf::RenderWindow& window);
	};

}

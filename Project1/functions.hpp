#pragma once
#include "SFML/Graphics.hpp"
#include <random>

namespace fn {
	// Function to check if a given point is within a given rectangle
	bool pointInRectangle(sf::Vector2i point, const sf::RectangleShape& rect);

	// Function to check if the cursor is within a given rectangle on the screen
	bool cursorInRectangle(const sf::RectangleShape& rect, const sf::RenderWindow& window);

	// Function to generate a random integer between min and max (inclusive)
	int randomInt(int min, int max);

	// Function to generate a random point within the main window
	sf::Vector2f randomPoint();

	// Function to generate a new triangle 
	void newTriangle(sf::VertexArray& vertices);

	// Function to choose a point within the main window
	sf::Vertex choosePoint(const sf::RenderWindow& window);

	//Function to generate points within the main window
	void generate(sf::VertexArray& vertices);

	// Define the Button class
	class Button {
	private:
		sf::RectangleShape m_rectangle{}; // Rectangle shape to represent the button

	public:
		// Constructor for the Button class
		Button(sf::Vector2f size = sf::Vector2f(0, 0),
			sf::Vector2f position = sf::Vector2f(0, 0),
			sf::Color color = sf::Color::White)
		{
			m_rectangle.setSize(size);
			m_rectangle.setPosition(position);
			m_rectangle.setFillColor(color);
		}

		// Destructor for the Button class
		~Button() {}

		// Set the size of the button
		void setSize(sf::Vector2f size);

		// Get the size of the button
		sf::Vector2f const getSize();

		// Set the fill color of the button
		void setFillColor(sf::Color color);

		// Get the fill color of the button
		sf::Color const getFillColor();

		// Set the position of the button
		void setPosition(sf::Vector2f position);

		// Get the position of the button
		sf::Vector2f const getPosition();

		// Get a reference to the rectangle shape of the button
		sf::RectangleShape& getShape();

		// Check if the button is currently being hovered over by the cursor
		bool const isHovered(const sf::RenderWindow& window);
	};
}
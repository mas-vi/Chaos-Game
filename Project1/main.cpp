#include <iostream>
#include "SFML/OpenGL.hpp"
#include "constants.hpp"
#include "functions.hpp"

int main()
{
    // Create the window
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), WINDOW_NAME, sf::Style::Close);
    window.setFramerateLimit(120);

    // Create the main rectangle
    sf::RectangleShape mainRect(sf::Vector2f(MAIN_WIDTH, MAIN_HEIGHT));
    mainRect.setPosition(MAIN_POSITION_X, MAIN_POSITION_Y);
    mainRect.setFillColor(sf::Color::White);

    // Create the vertices array
    sf::VertexArray vertices(sf::Points);

    // Create the reset button
    fn::Button resetButton(sf::Vector2f(RESET_BUTTON_DIM, RESET_BUTTON_DIM), sf::Vector2f(RESET_BUTTON_POSITION_X, RESET_BUTTON_POSITION_Y), sf::Color::Red);

    // Initialize play state
    bool play = false;

    while (window.isOpen())
    {
        // Handle events
        sf::Event event;
        while (window.pollEvent(event))
        {
            switch (event.type)
            {
                // Window closed
                case sf::Event::Closed:
                    window.close();
                    break;

                // Key pressed
                case sf::Event::KeyPressed:
                    switch (event.key.code)
                    {
                        // Escape key pressed
                        case sf::Keyboard::Escape:
                            window.close();
                            break;

                        // Space key pressed
                        case sf::Keyboard::Space:
                            play = !play;
                            break;

                        // Default case
                        default:
                            break;
                    }
                    break;

                // Mouse button pressed
                case sf::Event::MouseButtonPressed:
                    // Left button pressed
                    if (event.mouseButton.button == sf::Mouse::Left)
                    {
                        // Add point to vertices array
                        if (fn::cursorInRectangle(mainRect, window) && vertices.getVertexCount() < numberOfInitialPoints)
                        {
                            vertices.append(fn::choosePoint(window));
                            if (vertices.getVertexCount() == numberOfInitialPoints)
                            {
                                vertices[numberOfInitialPoints - 1].color = sf::Color::Red;
                                play = true;
                            }
                        }

                        // Reset button pressed
                        if (resetButton.isHovered(window))
                        {
                            play = false;
                            vertices.clear();
                        }
                    }
                    break;

                // Default case
                default:
                    break;
            }
        }

        // Generate vertices if enough points exist and play is true
        if (vertices.getVertexCount() >= numberOfInitialPoints && play)
        {
            fn::generate(vertices);
        }

        // Draw objects to the window
        window.clear(sf::Color::Black);
        glPointSize(2);
        window.draw(mainRect);
        window.draw(resetButton.getShape());
        window.draw(vertices);
        window.display();
    }

    return 0;
}
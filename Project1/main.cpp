#include <iostream>
#include "SFML/OpenGL.hpp"
#include "constants.hpp"
#include "functions.hpp"





int main()
{
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), WINDOW_NAME.c_str(),sf::Style::Close);
    
    window.setFramerateLimit(120);

    sf::RectangleShape main;

    main.setSize(sf::Vector2f(MAIN_WIDTH,MAIN_HEIGHT));

    main.setPosition(sf::Vector2f(MAIN_POSITION_X, MAIN_POSITION_Y));

    main.setFillColor(sf::Color::White);

    sf::VertexArray vertices(sf::Points);

    fn::Button reset_button(sf::Vector2f(RESET_BUTTON_DIM, RESET_BUTTON_DIM),
        sf::Vector2f(RESET_BUTTON_POSITION_X,RESET_BUTTON_POSITION_Y),sf::Color::Red);

    bool play = false;
    
    
 


    
    while (window.isOpen())
    {
        
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == event.KeyPressed)
            {
                switch (event.key.code)
                {
                case sf::Keyboard::Escape:
                    window.close();
                    break;
                case sf::Keyboard::Space:
                    play = !play;
                    break;

                default:
                    break;
                }

            }
            
            if (event.type == sf::Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    if (fn::cursorInRectangle(main, window) && vertices.getVertexCount() < numberOfInitialPoints)
                    {
                        vertices.append(fn::choosePoint(window));
                        if (vertices.getVertexCount() == numberOfInitialPoints)
                        {
                            vertices[static_cast<size_t>(numberOfInitialPoints) - 1].color = sf::Color::Red;
                            play = true;
                        }
                    }
                    if (reset_button.isHovered(window))
                    {
                        play = false;
                        vertices.clear();

                    }
                    
                }

            }
            
        }
        
       
        if (vertices.getVertexCount() >=numberOfInitialPoints && play)
        {
            fn::generate(vertices);
        }
        
        
        

        window.clear(sf::Color::Black);
        glPointSize(2);

        window.draw(main);
        window.draw(reset_button.getShape());
        window.draw(vertices);
        


        window.display();
    }

    return 0;
}
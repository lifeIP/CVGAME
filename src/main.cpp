#include "SFML/Graphics.hpp"

#include "blocks/empty/EmptyBlock.hpp"


int main()
{
    sf::RenderWindow window(sf::VideoMode::getDesktopMode(), "CVGAME");
    

    // sf::RectangleShape rect(sf::Vector2f(50.f, 50.f));
    // rect.setFillColor(sf::Color::Green);
    blocks::empty::EmptyBlock *emptyBlock = new blocks::empty::EmptyBlock(sf::Vector2f(0.f, 0.f), sf::Vector2f(400.f, 300.f));

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::EventType::KeyPressed){
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
                    window.close();
                }
            }
            emptyBlock->eventDragBlock(window, event);  
        }

        window.clear(sf::Color(0, 0, 0));

        

        // window.draw(*button);
        emptyBlock->draw(window);
        window.display();
    }

    return 0;
}
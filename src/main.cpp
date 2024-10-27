#include "SFML/Graphics.hpp"

#include "components/buttons/rect/RectButton.hpp"
#include "blocks/empty/EmptyBlock.hpp"


int main()
{
    sf::RenderWindow window(sf::VideoMode::getDesktopMode(), "CVGAME");
    

    // sf::RectangleShape rect(sf::Vector2f(50.f, 50.f));
    // rect.setFillColor(sf::Color::Green);
    blocks::empty::EmptyBlock *emptyBlock = new blocks::empty::EmptyBlock(sf::Vector2f(0.f, 0.f), sf::Vector2f(400.f, 300.f));
    components::buttons::RectButton *rectButton = new components::buttons::RectButton(sf::Vector2f(0, 0), sf::Vector2f(100, 50));
    rectButton->setColorPushed(sf::Color(0, 255, 0));
    rectButton->setColorFocused(sf::Color(255, 0, 0));
    rectButton->setColorDefault(sf::Color(217, 217, 217));

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
            emptyBlock->events(window, event);
            
            rectButton->events(window, event);
            rectButton->handler();
        }

        window.clear(sf::Color(0, 0, 0));

        

        // window.draw(*button);
        emptyBlock->draw(window);
        rectButton->draw(window);
        window.display();
    }

    return 0;
}
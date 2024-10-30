#include "SFML/Graphics.hpp"

#include "components/buttons/rect/RectButton.hpp"
#include "blocks/empty/EmptyBlock.hpp"

#include <memory>
#include <vector>
#include <iostream>
#include <string>

int main()
{
    sf::RenderWindow window(sf::VideoMode::getDesktopMode(), "CVGAME");
    

    // sf::RectangleShape rect(sf::Vector2f(50.f, 50.f));
    // rect.setFillColor(sf::Color::Green);
    
    std::unique_ptr<blocks::empty::EmptyBlock> eb(new blocks::empty::EmptyBlock(sf::Vector2f(150.f, 150.f), sf::Vector2f(400.f, 300.f)));
    
    

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
            
            if(bool(eb)){
                if(eb.get()->events(window, event) != 0)
                {
                    std::cout << "events" << std::endl; 
                    eb.reset(NULL);
                    std::cout << "events1" << std::endl;
                }
            }
        }

        window.clear(sf::Color(0, 0, 0));

        if(bool(eb)){
            std::cout << "eb" << std::endl;
            eb.get()->draw(window);
            std::cout << "eb2" << std::endl;
        }

        window.display();
    }

    return 0;
}
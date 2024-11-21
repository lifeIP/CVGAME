#include "SFML/Graphics.hpp"

#include "components/buttons/rect/RectButton.hpp"
#include "components/buttons/circle/CircleIconButton/CircleIconButton.hpp"
#include "components/visual/ShowCVImage/ShowCVImage.hpp"
#include "blocks/empty/EmptyBlock.hpp"



#include <opencv2/core.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

#include <memory>
#include <vector>
#include <iostream>
#include <string>

int main()
{
    sf::RenderWindow window(sf::VideoMode::getDesktopMode(), "CVGAME");
    
    // components::visual::ShowCVImage * cvImg = new components::visual::ShowCVImage(sf::Vector2f(150.f, 150.f), sf::Vector2f(400.f, 300.f));
    // sf::RectangleShape rect(sf::Vector2f(50.f, 50.f));
    // rect.setFillColor(sf::Color::Green);
    
    std::unique_ptr<components::visual::ShowCVImage> eb(new components::visual::ShowCVImage(sf::Vector2f(150.f, 150.f), sf::Vector2f(400.f, 300.f)));
    // components::buttons::CircleIconButton *button = new components::buttons::CircleIconButton(sf::Vector2f(50, 50), std::string("./src/textures/free-icon-settings.png"), 150., 150);
    

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
            // button->events(window, event);
            // std::cout << "events id: " << button->handler() << std::endl;

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
            // std::cout << "eb" << std::endl;
            eb.get()->draw(window);
            // std::cout << "eb2" << std::endl;
        }
        // button->draw(window);
        window.display();
    }

    return 0;
}
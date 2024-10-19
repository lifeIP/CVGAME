#include "SFML/Graphics.hpp"

#include "blocks/inputs/CameraInput/CameraInput.hpp"

int main()
{
    sf::RenderWindow window(sf::VideoMode(640, 480), "SFML works!");
    

    // sf::RectangleShape rect(sf::Vector2f(50.f, 50.f));
    // rect.setFillColor(sf::Color::Green);

    blocks::inputs::CameraInput cam_0(0);
    cam_0.setPosition(sf::Vector2f(100.0, 50.0));
    cam_0.setSize(sf::Vector2f(150.0, 150.0));
    cam_0.setFillColor(sf::Color(50, 50, 50));

    

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
            cam_0.eventDragBlock(window, event);        
        }

        window.clear();

        
        cam_0.updateFrame();
        
        window.draw(cam_0);
        window.display();
    }

    return 0;
}
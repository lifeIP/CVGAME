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

    const int countOfBlocks = 2;
    std::vector<blocks::empty::EmptyBlock*> eb;
    eb.push_back(new components::visual::ShowCVImage(sf::Vector2f(150.f, 150.f), sf::Vector2f(400.f, 300.f)));
    eb.push_back(new components::visual::ShowCVImage(sf::Vector2f(550.f, 150.f), sf::Vector2f(400.f, 300.f)));


    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::EventType::KeyPressed)
            {
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
                {
                    window.close();
                }
            }
            

            for (int i = 0; i < eb.size(); i++)
            {
                if (eb.at(i)->events(window, event) != 0)
                {
                    eb.at(i)->~EmptyBlock();
                    eb.erase(eb.begin() + i);
                }
            }
        }

        window.clear(sf::Color(50, 50, 50));

        for (int i = 0; i < eb.size(); i++)
        {
            eb.at(i)->draw(window);
        }
        window.display();
    }

    return 0;
}
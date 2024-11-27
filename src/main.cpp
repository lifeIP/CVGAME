#include "SFML/Graphics.hpp"

#include "components/buttons/rect/RectButton.hpp"
#include "components/buttons/circle/CircleIconButton/CircleIconButton.hpp"
#include "components/visual/ShowCVImage/ShowCVImage.hpp"
#include "blocks/empty/EmptyBlock.hpp"
#include "manager/BloksManager.hpp"

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

    manager::BloksManager mgr;

    std::vector<blocks::empty::EmptyBlock*> eb;
    eb.push_back(new components::visual::ShowCVImage(sf::Vector2f(10.f, 10.f), sf::Vector2f(400.f, 300.f)));
    eb.push_back(new components::visual::ShowCVImage(sf::Vector2f(460.f, 10.f), sf::Vector2f(400.f, 300.f)));
    eb.push_back(new blocks::empty::EmptyBlock(sf::Vector2f(910.f, 10.f), sf::Vector2f(400.f, 300.f)));

    // eb.at(0)->setEnableSettings(false);


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
                bool eb_events = eb.at(i)->moveEvent(window, event);
                bool eb_events_1 = eb.at(i)->closeEvent(window, event);
                bool eb_events_2 = eb.at(i)->rightAddButtonEvent(window, event);
                bool eb_events_3 = eb.at(i)->bottomAddButtonEvent(window, event);
                bool eb_events_4 = eb.at(i)->settingsButtonEvent(window, event);

                if(eb_events_1){
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
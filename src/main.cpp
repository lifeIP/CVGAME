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

    std::vector<blocks::empty::EmptyBlock*> eb;
    eb.push_back(new components::visual::ShowCVImage(sf::Vector2f(150.f, 150.f), sf::Vector2f(400.f, 300.f)));
    eb.push_back(new components::visual::ShowCVImage(sf::Vector2f(550.f, 150.f), sf::Vector2f(400.f, 300.f)));
    eb.push_back(new components::visual::ShowCVImage(sf::Vector2f(950.f, 150.f), sf::Vector2f(400.f, 300.f)));



    while (window.isOpen())
    {


        unsigned render_queue[eb.size()]={};
        for(int i = 0; i < eb.size(); i++) render_queue[i] = i;

        std::sort(render_queue, render_queue + eb.size(), [&](int a, int b){
            return eb.at(a)->getPriority(eb.at(a)->mBlockId) < eb.at(b)->getPriority(eb.at(b)->mBlockId);
        });


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
                int eb_events = eb.at(render_queue[i])->events(window, event);
                if (eb_events == 2){
                    break;
                }
                else if (eb_events == -1)
                {
                    eb.at(render_queue[i])->~EmptyBlock();
                    eb.erase(eb.begin() + render_queue[i]);

                    render_queue[eb.size()]={};
                    for(int i = 0; i < eb.size(); i++) render_queue[i] = i;

                    std::sort(render_queue, render_queue + eb.size(), [&](int a, int b){
                        // std::cout << eb.at(a)->mBlockId << " " << eb.at(b)->mBlockId << std::endl;
                        return eb.at(a)->getPriority(eb.at(a)->mBlockId) > eb.at(b)->getPriority(eb.at(b)->mBlockId);
                    });
                    break;
                }

                // else if (eb_events == 1){
                //     std::cout << render_queue[i] << " menu" << std::endl;
                // }
                // std::cout << eb.size() << std::endl;
            }
        }

        window.clear(sf::Color(50, 50, 50));

        for (int i = 0; i < eb.size(); i++)
        {
            eb.at(render_queue[i])->draw(window);
        }
        window.display();
    }

    return 0;
}
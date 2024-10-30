#include "EmptyBlock.hpp"

#include "../../components/buttons/void/VoidButton.hpp"
#include "../../components/buttons/circle/CircleButton.hpp"
#include "../../components/buttons/circle/CircleAddButton/CircleAddButton.hpp"
#include "../../components/buttons/rect/RectButton.hpp"

#include "SFML/Graphics/Drawable.hpp"
#include "SFML/Graphics/Sprite.hpp"
#include "SFML/Graphics/Image.hpp"
#include "SFML/Graphics/Texture.hpp"
#include "SFML/Graphics/Rect.hpp"
#include "SFML/Graphics/RenderTarget.hpp"
#include "SFML/Graphics.hpp"

#include <iostream>

namespace blocks
{
    namespace empty
    {

        void EmptyBlock::draw(sf::RenderWindow& window)
        {
            window.draw(*mHeader);
            window.draw(*mBody);
            mAddButton->draw(window);
            mExitButton->draw(window);
        }


        EmptyBlock::EmptyBlock(const sf::Vector2f &position, const sf::Vector2f &size) 
        {

            oldPos = new sf::Vector2i(0, 0);

            mHeaderSize = 40.f;
            
            mHeader = new sf::RectangleShape(sf::Vector2f(size.x, mHeaderSize));
            mHeader->setPosition(sf::Vector2f(position.x, position.y));
            mHeader->setFillColor(sf::Color(34, 249, 61));

            mBody = new sf::RectangleShape(sf::Vector2f(size.x, size.y - mHeaderSize));
            mBody->setPosition(sf::Vector2f(position.x, position.y + mHeaderSize));
            mBody->setFillColor(sf::Color(29, 21, 21));

            mAddButton = new components::buttons::CircleAddButton(sf::Vector2f(position.x + (size.x)/2 - 40.f, position.y + (size.y - mHeaderSize)/2 - 20), 80.f, 100);
            mAddButton->setColorPushed(sf::Color(0, 255, 0));
            mAddButton->setColorFocused(sf::Color(255, 0, 0));
            mAddButton->setColorDefault(sf::Color(217, 217, 217));

            mExitButton = new components::buttons::RectButton(
                sf::Vector2f(position.x + size.x - 40, position.y + mHeaderSize - 39), 
                sf::Vector2f(39, 38));

            mExitButton->setColorPushed(sf::Color(255, 10, 10));
            mExitButton->setColorFocused(sf::Color(250, 0, 0));
            mExitButton->setColorDefault(sf::Color(200, 0, 0));
            mExitButton->setTextColor(sf::Color(255, 255, 255));
            mExitButton->setString(sf::String("X"));

        }

        EmptyBlock::~EmptyBlock()
        {
            delete mHeader;
            delete mBody;

            mAddButton->~CircleAddButton();
            // delete mAddButton;
            
            // mExitButton->~RectButton();
            // delete mExitButton;

            delete oldPos;

            std::cout << "~EmptyBlock" << std::endl;
        }

        void EmptyBlock::move(const sf::Vector2f &steps){
            mHeader->move(steps);
            mBody->move(steps);
            mAddButton->move(steps);
            mExitButton->move(steps);
        }

        int EmptyBlock::events(const sf::Window &relativeTo, const sf::Event &event)
        {
            if (event.type == sf::Event::EventType::MouseButtonPressed){
                if(event.mouseButton.button == sf::Mouse::Left && !isSelected){
                    auto mb = event.mouseButton;
                    if(mHeader->getGlobalBounds().contains(mb.x, mb.y)){
                        *oldPos = sf::Vector2i(mb.x, mb.y);
                        isSelected = true;
                    }
                }
            }
            else if (event.type == sf::Event::EventType::MouseButtonReleased){
                if(event.mouseButton.button == sf::Mouse::Left && isSelected){
                    isSelected = false;
                }
            }
            else if (event.type == sf::Event::EventType::MouseMoved){
                
                auto mm = event.mouseMove;
            
                if(isSelected)
                {
                    sf::Vector2f diff = sf::Vector2f(
                        oldPos->x - mm.x,
                        oldPos->y - mm.y
                    );
                    *oldPos = sf::Vector2i(mm.x, mm.y);
                    
                    move(sf::Vector2f(- diff.x, - diff.y));
                }
            }
            mAddButton->events(relativeTo, event);
            mAddButton->handler();

            mExitButton->events(relativeTo, event);
            
            if (mExitButton->handler() == 2 || mExitButton->handler() == 3)
            {
                return -1;
            }
            return 0;
        }
    }
}
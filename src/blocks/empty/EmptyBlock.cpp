#include "EmptyBlock.hpp"
#include "../../components/buttons/circle/CircleAddButton.hpp"

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
        }

        EmptyBlock::EmptyBlock(const sf::Vector2f &position, const sf::Vector2f &size) 
        {

            oldPos = new sf::Vector2i(0, 0);

            mHeaderSize = 20.f;
            
            mHeader = new sf::RectangleShape(sf::Vector2f(size.x, mHeaderSize));
            mHeader->setPosition(sf::Vector2f(position.x, position.y));
            mHeader->setFillColor(sf::Color(34, 249, 61));

            mBody = new sf::RectangleShape(sf::Vector2f(size.x, size.y - mHeaderSize));
            mBody->setPosition(sf::Vector2f(position.x, position.y + mHeaderSize));
            mBody->setFillColor(sf::Color(29, 21, 21));

            mAddButton = new components::buttons::CircleAddButton(sf::Vector2f(position.x + (size.x)/2 - 40.f, position.y + (size.y - mHeaderSize)/2 - 20), 80.f, 100);
        }

        EmptyBlock::~EmptyBlock()
        {
        }

        void EmptyBlock::move(const sf::Vector2f &steps){
            mHeader->move(steps);
            mBody->move(steps);
            mAddButton->move(steps);
        }

        bool EmptyBlock::eventDragBlock(const sf::Window &relativeTo, const sf::Event &event)
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
            return isSelected;
        }
    }
}
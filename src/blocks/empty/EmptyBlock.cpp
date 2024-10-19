#include "EmptyBlock.hpp"

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
        EmptyBlock::EmptyBlock(){
            mHeaderSize = 25.f;
            isSelected = false;
            mHeader.setFillColor(sf::Color(255, 255, 255));
        }

        EmptyBlock::~EmptyBlock(){
        }

        
        void EmptyBlock::setPosition(const sf::Vector2f& position){
            mHeader.setPosition(position);
            mRect.setPosition(sf::Vector2f(position.x, position.y + mHeaderSize));
        }

        sf::Vector2f EmptyBlock::getPosition(){
            return mHeader.getPosition();
        }


        void EmptyBlock::setSize(const sf::Vector2f& size){
            mHeader.setSize(sf::Vector2f(size.x, mHeaderSize));
            mRect.setSize(size);
        }

        sf::Vector2f EmptyBlock::getSize(){
            return sf::Vector2f(mHeader.getSize().x, mHeader.getSize().y + mHeaderSize);
        }


        void EmptyBlock::setFillColor(const sf::Color& fillColor){
            mRect.setFillColor(fillColor);
        }

        void EmptyBlock::draw(sf::RenderTarget &target, sf::RenderStates states) const
        {
            target.draw(mHeader, states);
            target.draw(mRect, states);
        }

        bool EmptyBlock::eventMouseInHeader(const sf::Window &relativeTo){
            if( mHeader.getGlobalBounds().contains( sf::Mouse::getPosition(relativeTo).x, sf::Mouse::getPosition(relativeTo).y)){
                return true;
            }
            else{
                return false;
            }
        }

        void EmptyBlock::move(sf::Vector2f steps){
            mHeader.move(steps);
            mRect.move(steps);
        }

        bool EmptyBlock::eventDragBlock(const sf::Window &relativeTo, const sf::Event &event){
            if (event.type == sf::Event::EventType::MouseButtonPressed){
                if(event.mouseButton.button == sf::Mouse::Left && !isSelected){
                    auto mb = event.mouseButton;
                    if(mHeader.getGlobalBounds().contains(mb.x, mb.y)){
                        oldPos.x = mb.x;
                        oldPos.y = mb.y;
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
                        oldPos.x - mm.x,
                        oldPos.y - mm.y
                    );
                    oldPos = sf::Vector2i(mm.x, mm.y);
                    
                    move(sf::Vector2f(- diff.x, - diff.y));
                }
            }
            return isSelected;
        }
    }
}
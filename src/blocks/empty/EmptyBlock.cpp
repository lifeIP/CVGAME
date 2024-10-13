#include "EmptyBlock.hpp"

#include "SFML/Graphics/Drawable.hpp"
#include "SFML/Graphics/Sprite.hpp"
#include "SFML/Graphics/Image.hpp"
#include "SFML/Graphics/Texture.hpp"
#include "SFML/Graphics/Rect.hpp"
#include "SFML/Graphics/RenderTarget.hpp"
#include "SFML/Graphics.hpp"

namespace blocks
{
    namespace empty
    {
        EmptyBlock::EmptyBlock(){
        }

        EmptyBlock::~EmptyBlock(){
        }

        void EmptyBlock::setPosition(const sf::Vector2f& position){
            mRect.setPosition(position);
        }

        void EmptyBlock::setSize(const sf::Vector2f& size){
            mRect.setSize(size);
        }
        void EmptyBlock::setFillColor(const sf::Color& fillColor){
            mRect.setFillColor(fillColor);
        }

        void EmptyBlock::draw(sf::RenderTarget &target, sf::RenderStates states) const
        {
            target.draw(mRect, states);
        }
    }
}
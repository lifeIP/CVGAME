#pragma once

#include "../empty/EmptyBlock.hpp"
#include "../../components/buttons/circle/CircleAddButton/CircleAddButton.hpp"


#include "SFML/Graphics/Drawable.hpp"
#include "SFML/Graphics/Sprite.hpp"
#include "SFML/Graphics/Image.hpp"
#include "SFML/Graphics/Texture.hpp"
#include "SFML/Graphics/Rect.hpp"
#include "SFML/Graphics.hpp"

namespace blocks
{
    namespace input
    {
        class MatInputBlock: public blocks::empty::EmptyBlock
        {
        protected:

        public:
            MatInputBlock(const sf::Vector2f &position, const sf::Vector2f &size);
            ~MatInputBlock();
            
            virtual int events(const sf::Window &relativeTo, const sf::Event &event) override;
            virtual void move(const sf::Vector2f &steps) override;
            virtual void draw(sf::RenderWindow& window) override;
        };
    }
}
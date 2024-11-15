#pragma once

#include "../../components/buttons/circle/CircleIconButton/CircleIconButton.hpp"
#include "../../components/buttons/rect/RectButton.hpp"

#include "SFML/Graphics/Drawable.hpp"
#include "SFML/Graphics/Sprite.hpp"
#include "SFML/Graphics/Image.hpp"
#include "SFML/Graphics/Texture.hpp"
#include "SFML/Graphics/Rect.hpp"
#include "SFML/Graphics.hpp"

namespace blocks
{
    namespace empty
    {
        class EmptyBlock
        {
        public:
            EmptyBlock(const sf::Vector2f &position, const sf::Vector2f &size);
            virtual ~EmptyBlock();



            virtual int events(const sf::Window &relativeTo, const sf::Event &event);
            virtual void move(const sf::Vector2f &steps);
            virtual void draw(sf::RenderWindow& window);

        private: 
            bool isSelected;
            float mHeaderSize;
            sf::Vector2i *oldPos;
            components::buttons::CircleIconButton *mIconButton;
            components::buttons::RectButton *mExitButton;
        protected:
            sf::RectangleShape *mHeader;
            sf::RectangleShape *mBody;
        };
    }
}

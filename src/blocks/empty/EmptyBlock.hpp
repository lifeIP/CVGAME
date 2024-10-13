#pragma once

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
        class EmptyBlock : public sf::Drawable
        {
        public:
            EmptyBlock();
            virtual ~EmptyBlock();
            virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;

            void setSize(const sf::Vector2f& size);
            void setPosition(const sf::Vector2f& position);
            void setFillColor(const sf::Color& fillColor);

            enum Direction
            {
                Down,
                Left,
                Right,
                Up
            }; 
            void move(Direction direction, float speed = 0.01);

        protected:
            sf::RectangleShape mRect;
            sf::Vector2f mPosition;
        };
    }
}

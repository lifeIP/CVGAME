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

            virtual void setSize(const sf::Vector2f& size);
            virtual sf::Vector2f getSize();

            virtual void setPosition(const sf::Vector2f& position);
            virtual sf::Vector2f getPosition();

            void setFillColor(const sf::Color& fillColor);

            virtual void move(sf::Vector2f steps);


            bool eventMouseInHeader(const sf::Window &relativeTo);

            bool eventDragBlock(const sf::Window &relativeTo, const sf::Event &event);
            

        private: 
            bool isSelected;
            sf::Vector2i oldPos;
        protected:
            float mHeaderSize;

            sf::RectangleShape mHeader;
            sf::RectangleShape mRect;
        };
    }
}

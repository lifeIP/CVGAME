#pragma once

#include "SFML/Graphics/Drawable.hpp"
#include "SFML/Graphics/Sprite.hpp"
#include "SFML/Graphics/Image.hpp"
#include "SFML/Graphics/Texture.hpp"
#include "SFML/Graphics/Rect.hpp"
#include "SFML/Graphics.hpp"

namespace components
{
    namespace buttons
    {
        class VoidButton
        {
        protected:
            sf::Vector2f *mPosition;
            sf::Vector2f *mSize;
            bool mIsPressed;
            bool mIsReleased;
            bool mIsActive;
            
        public:
            VoidButton(/* args */);
            VoidButton(const sf::Vector2f& position, const sf::Vector2f& size);

            ~VoidButton();

            bool isPressed();
            bool isReleased();
            bool isActive();

            virtual void move(const sf::Vector2f &steps) = 0;
            void setPosition(const sf::Vector2f &position);
            void setSize(const sf::Vector2f &size);

            virtual void getButtonStatus(sf::RenderWindow& window, sf::Event& event);
            virtual void draw(sf::RenderWindow& window) = 0;
        };
    }
}
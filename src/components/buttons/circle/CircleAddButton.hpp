#pragma once

#include "../void/VoidButton.hpp"

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
        class CircleAddButton: VoidButton
        {
        private:
            sf::CircleShape *mCircleShape;
            sf::RectangleShape *mVerticalRectangleShape;
            sf::RectangleShape *mHorizontalRectangleShape;

        public:
            CircleAddButton(const sf::Vector2f &position, const float size, const std::size_t &pointCount);

            ~CircleAddButton();
            
            virtual void move(const sf::Vector2f &steps);
            virtual void draw(sf::RenderWindow& window);
            virtual void events(const sf::Window& window, const sf::Event& event);
        };
    }
}

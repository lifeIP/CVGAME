#include "CircleAddButton.hpp"

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
        void CircleAddButton::move(const sf::Vector2f &steps)
        {
            CircleButton::move(steps);
         
            mVerticalRectangleShape->move(steps);
            mHorizontalRectangleShape->move(steps);
        }

        void CircleAddButton::setColorCross(const sf::Color &color)
        {
            mVerticalRectangleShape->setFillColor(color);
            mHorizontalRectangleShape->setFillColor(color);
        }

        sf::Color CircleAddButton::getColorCross() const
        {
            return mVerticalRectangleShape->getFillColor();
        }

        void CircleAddButton::setPosition(const sf::Vector2f &position)
        {
            CircleButton::setPosition(position);

            sf::Vector2f center(position.x + CircleButton::getSize().x / 2, position.y + CircleButton::getSize().x / 2);
            
            mVerticalRectangleShape->setPosition(sf::Vector2f(center.x - (CircleButton::getSize().x * 0.1) / 2, center.y - (CircleButton::getSize().x * 0.75) / 2));
            mHorizontalRectangleShape->setPosition(sf::Vector2f(center.x - (CircleButton::getSize().x * 0.75) / 2, center.y - (CircleButton::getSize().x * 0.1) / 2));
        }

        void CircleAddButton::setSize(const sf::Vector2f &size)
        {
            CircleButton::setSize(size);

            sf::Vector2f center(CircleButton::getPosition().x + size.x / 2, CircleButton::getPosition().y + size.x / 2);

            mVerticalRectangleShape->setSize(sf::Vector2f(size.x * 0.1, size.x * 0.75));
            mHorizontalRectangleShape->setSize(sf::Vector2f(size.x * 0.75, size.x * 0.1));
        }

        CircleAddButton::CircleAddButton(const sf::Vector2f &position, const float size, const std::size_t &pointCount) : CircleButton(position, size, pointCount)
        {
            sf::Vector2f center(position.x + size / 2, position.y + size / 2);

            mVerticalRectangleShape = new sf::RectangleShape(sf::Vector2f(size * 0.1, size * 0.75));
            mVerticalRectangleShape->setPosition(sf::Vector2f(center.x - (size * 0.1) / 2, center.y - (size * 0.75) / 2));
            mVerticalRectangleShape->setFillColor(sf::Color(2, 233, 29));

            mHorizontalRectangleShape = new sf::RectangleShape(sf::Vector2f(size * 0.75, size * 0.1));
            mHorizontalRectangleShape->setPosition(sf::Vector2f(center.x - (size * 0.75) / 2, center.y - (size * 0.1) / 2));
            mHorizontalRectangleShape->setFillColor(sf::Color(2, 233, 29));
        }

        CircleAddButton::~CircleAddButton()
        {
            delete mVerticalRectangleShape;
            delete mHorizontalRectangleShape;
            CircleButton::~CircleButton();
        }

        int CircleAddButton::handler()
        {
            return CircleButton::handler();
        }

        void CircleAddButton::draw(sf::RenderWindow &window)
        {
            CircleButton::draw(window);
            window.draw(*mVerticalRectangleShape);
            window.draw(*mHorizontalRectangleShape);
        }

        void CircleAddButton::events(const sf::Window &window, const sf::Event &event)
        {
            CircleButton::events(window, event);
        }
    }
}
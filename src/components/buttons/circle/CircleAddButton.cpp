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
            mCircleShape->move(steps);
            mVerticalRectangleShape->move(steps);
            mHorizontalRectangleShape->move(steps);
        }

        CircleAddButton::CircleAddButton(const sf::Vector2f &position, const float size, const std::size_t &pointCount) : VoidButton()
        {
            mCircleShape = new sf::CircleShape(size / 2, pointCount);
            mCircleShape->setPointCount(pointCount);
            mCircleShape->setPosition(position);
            mCircleShape->setFillColor(sf::Color(217, 217, 217));

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
            delete mCircleShape;
            delete mVerticalRectangleShape;
            delete mHorizontalRectangleShape;
        }

        void CircleAddButton::draw(sf::RenderWindow &window)
        {
            window.draw(*mCircleShape);
            window.draw(*mVerticalRectangleShape);
            window.draw(*mHorizontalRectangleShape);
        }





        void CircleAddButton::events(const sf::Window &window, const sf::Event &event)
        {
            
            if (mCircleShape->getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y))
            {
                if (event.type == sf::Event::EventType::MouseButtonPressed){
                    mIsPressed = true;
                    mCircleShape->setFillColor(sf::Color(180, 255, 180));
                }
                else if (event.type == sf::Event::EventType::MouseButtonReleased){
                    mIsReleased = true;
                    mCircleShape->setFillColor(sf::Color(217, 217, 217));
                }
                else{
                    if (!isReleased() && !isPressed()){
                        mCircleShape->setFillColor(sf::Color(180, 217, 217));
                    }
                }
            }
            else{
                mCircleShape->setFillColor(sf::Color(217, 217, 217));
            }
            
        }
    }
}
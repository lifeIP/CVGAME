#include "../void/VoidButton.hpp"
#include "./CircleButton.hpp"

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
        CircleButton::CircleButton(const sf::Vector2f &position, const float size, const std::size_t &pointCount): VoidButton()
        {
            mCircleShape = new sf::CircleShape(size / 2, pointCount);
            mCircleShape->setPointCount(pointCount);
            mCircleShape->setPosition(position);
            mCircleShape->setFillColor(mColorDefault);
        }

        CircleButton::~CircleButton()
        {
            delete mCircleShape;
        }

        void CircleButton::move(const sf::Vector2f &steps)
        {
            mCircleShape->move(steps);
        }

        void CircleButton::setPosition(const sf::Vector2f &position)
        {
            mPosition = position;
            mCircleShape->setPosition(position);
        }

        sf::Vector2f CircleButton::getPosition() const
        {
            return mPosition;
        }

        void CircleButton::setSize(const sf::Vector2f &size)
        {
            mSize = size;
            mCircleShape->setRadius(size.x);
        }

        sf::Vector2f CircleButton::getSize() const
        {
            return mSize;
        }

        int CircleButton::handler()
        {
            if(isPressed() && isReleased()){
                mIsPressed = false;
                mIsReleased = false;
                return 3;
            }
            else if (isPressed())
            {
                return 2;
            }
            else if (isReleased())
            {
                return 1;
            }
            else return 0;
        }

        void CircleButton::events(const sf::Window& window, const sf::Event& event)
        {
            if (mCircleShape->getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y))
            {
                if (event.type == sf::Event::EventType::MouseButtonPressed){
                    mIsPressed = true;
                    mCircleShape->setFillColor(mColorPushed);
                }
                else if (event.type == sf::Event::EventType::MouseButtonReleased){
                    mIsReleased = true;
                    mCircleShape->setFillColor(mColorDefault);
                }
                else{
                    if (!isReleased() && !isPressed()){
                        mCircleShape->setFillColor(mColorFocused);
                    }
                }
            }
            else{
                mCircleShape->setFillColor(mColorDefault);
            }
        }

        void CircleButton::draw(sf::RenderWindow& window)
        {
            window.draw(*mCircleShape);
        }
    }
}

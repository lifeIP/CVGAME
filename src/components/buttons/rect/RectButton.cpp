#include "RectButton.hpp"
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
        RectButton::RectButton(const sf::Vector2f &position, const sf::Vector2f &size): VoidButton()
        {
            mBody = new sf::RectangleShape(size);

            setSize(size);
            setPosition(position);

            mBody->setFillColor(mColorDefault);
        }

        RectButton::~RectButton()
        {
            delete mBody;
        }

        void RectButton::move(const sf::Vector2f &steps)
        {
            mBody->move(steps);
            
            VoidButton::setPosition(mBody->getPosition());
        }

        void RectButton::setPosition(const sf::Vector2f &position)
        {
            VoidButton::setPosition(position);
            mBody->setPosition(position);
        }

        sf::Vector2f RectButton::getPosition() const
        {
            return VoidButton::getPosition();
        }

        void RectButton::setSize(const sf::Vector2f &size)
        {
            VoidButton::setSize(size);
            mBody->setSize(size);
        }

        sf::Vector2f RectButton::getSize() const
        {
            return VoidButton::getSize();
        }

        int RectButton::handler()
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

        void RectButton::events(const sf::Window& window, const sf::Event& event)
        {
            if (mBody->getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y))
            {
                if (event.type == sf::Event::EventType::MouseButtonPressed){
                    mIsPressed = true;
                    mBody->setFillColor(mColorPushed);
                }
                else if (event.type == sf::Event::EventType::MouseButtonReleased){
                    mIsReleased = true;
                    mBody->setFillColor(mColorDefault);
                }
                else{
                    if (!isReleased() && !isPressed()){
                        mBody->setFillColor(mColorFocused);
                    }
                }
            }
            else{
                mBody->setFillColor(mColorDefault);
            }
        }

        void RectButton::draw(sf::RenderWindow& window)
        {
            window.draw(*mBody);
        }
    }
}

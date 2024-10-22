#include "VoidButton.hpp"

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
        bool VoidButton::isPressed()
        {
            return mIsPressed;
        }
        bool VoidButton::isReleased()
        {
            return mIsReleased;
        }
        bool VoidButton::isActive()
        {
            return mIsReleased;
        }

        VoidButton::VoidButton(/* args */)
        {
            mPosition = new sf::Vector2f(0.0, 0.0);
            mSize = new sf::Vector2f(0.0, 0.0);
            mIsPressed = false;
            mIsReleased = false;
            mIsActive = false;
        }

        VoidButton::VoidButton(const sf::Vector2f &position, const sf::Vector2f &size)
        {
            mPosition = new sf::Vector2f(position);
            mSize = new sf::Vector2f(size);
            mIsPressed = false;
            mIsReleased = false;
            mIsActive = true;
        }

        void VoidButton::setPosition(const sf::Vector2f &position)
        {
            *mPosition = position;   
        }
        void VoidButton::setSize(const sf::Vector2f &size)
        {
            *mSize = size;
        }

        void VoidButton::getButtonStatus(sf::RenderWindow& window, sf::Event& event){

        }

        VoidButton::~VoidButton()
        {
            delete mPosition;
            delete mSize;
        }
    }
}
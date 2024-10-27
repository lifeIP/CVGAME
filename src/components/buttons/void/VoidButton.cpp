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


        void VoidButton::setPosition(const sf::Vector2f &position)
        {
            mPosition = position;
        }

        sf::Vector2f VoidButton::getPosition() const
        {
            return mPosition;
        }

        void VoidButton::setSize(const sf::Vector2f &size)
        {
            mSize = size;
        }

        sf::Vector2f VoidButton::getSize() const
        {
            return mPosition;
        }

        void VoidButton::setColorPushed(const sf::Color &color)
        {
            mColorPushed = color;
        }

        sf::Color VoidButton::getColorPushed() const
        {
            return mColorPushed;
        }


        void VoidButton::setColorDefault(const sf::Color &color)
        {
            mColorDefault = color;
        }

        sf::Color VoidButton::getColorDefault() const
        {
            return mColorDefault;
        }


        void VoidButton::setColorFocused(const sf::Color &color)
        {
            mColorFocused = color;
        }

        sf::Color VoidButton::getColorFocused() const
        {
            return mColorFocused;
        }


        

        VoidButton::VoidButton()
        {
            mIsPressed = false;
            mIsReleased = false;
            mIsActive = true;
        }

        VoidButton::~VoidButton()
        {

        }
    }
}
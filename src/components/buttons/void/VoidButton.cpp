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



        void VoidButton::setColorPushed(const sf::Color &color)
        {
            this->mColorPushed = color;
        }

        sf::Color VoidButton::getColorPushed() const
        {
            return this->mColorPushed;
        }


        void VoidButton::setColorDefault(const sf::Color &color)
        {
            this->mColorDefault = color;
        }

        sf::Color VoidButton::getColorDefault() const
        {
            return this->mColorDefault;
        }


        void VoidButton::setColorFocused(const sf::Color &color)
        {
            this->mColorFocused = color;
        }

        sf::Color VoidButton::getColorFocused() const
        {
            return this->mColorFocused;
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
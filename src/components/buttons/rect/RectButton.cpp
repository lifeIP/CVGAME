#include "RectButton.hpp"
#include "../void/VoidButton.hpp"

#include "SFML/Graphics/Drawable.hpp"
#include "SFML/Graphics/Sprite.hpp"
#include "SFML/Graphics/Image.hpp"
#include "SFML/Graphics/Texture.hpp"
#include "SFML/Graphics/Rect.hpp"
#include "SFML/Graphics/Text.hpp"
#include "SFML/Graphics/Font.hpp"
#include "SFML/Graphics.hpp"

#include <iostream>

namespace components
{
    namespace buttons
    {
        RectButton::RectButton(const sf::Vector2f &position, const sf::Vector2f &size): VoidButton()
        {
            mFont = new sf::Font();

            // Load it from a file
            if (!mFont->loadFromFile("src/components/buttons/rect/arial.ttf"))
            {
                std::cout << "ERROR arial.ttf" << std::endl;
            }   
            mBody = new sf::RectangleShape(size);
            mText = new sf::Text();

            mText->setString(sf::String("button"));
            mText->setCharacterSize(25);
            mText->setFillColor(sf::Color(255, 0, 0));
            mText->setFont(*mFont);

            setSize(size);
            setPosition(position);

            mBody->setFillColor(mColorDefault);
            
            float width = mText->getLocalBounds().width;
            float height = mText->getLocalBounds().height;
            mText->setPosition(sf::Vector2f(position.x + (size.x / 2) - (width / 2), 
                                            position.y + (size.y / 2) - height ));
        }

        RectButton::~RectButton()
        {
            delete mBody;
            delete mText;
        }



        void RectButton::setFont(const sf::String& string)
        {
            mFont->loadFromFile(string);
            mText->setFont(*mFont);
        }

        sf::Font RectButton::getFont() const
        {
            return *mFont;
        }



        void RectButton::setString(const sf::String& string)
        {
            mText->setString(string);
            
            sf::Vector2f position = sf::Vector2f(mBody->getPosition());
            sf::Vector2f size = sf::Vector2f(mBody->getSize());

            float width = mText->getLocalBounds().width;
            float height = mText->getLocalBounds().height;
            mText->setPosition(sf::Vector2f(position.x + (size.x / 2) - (width / 2), 
                                            position.y + (size.y / 2) - height ));
        }

        sf::String RectButton::getString() const
        {
            return mText->getString();
        }



        void RectButton::setCharacterSize(unsigned int size)
        {
            mText->setCharacterSize(size);
        }

        unsigned int RectButton::getCharacterSize() const
        {
            return mText->getCharacterSize();
        }



        void RectButton::setTextColor(const sf::Color &color)
        {
            mText->setFillColor(color);
        }

        sf::Color RectButton::getTextColor() const
        {
            return mText->getFillColor();
        }



        void RectButton::setBorderColor(const sf::Color &color)
        {
            mBody->setOutlineColor(color);
        }

        sf::Color RectButton::getBorderColor() const
        {
            return mBody->getOutlineColor();
        }



        void RectButton::setOutlineThickness(const float &thickness)
        {
            mBody->setOutlineThickness(thickness);
        }

        float RectButton::getOutlineThickness() const
        {
            return mBody->getOutlineThickness();
        }




        void RectButton::move(const sf::Vector2f &steps)
        {
            mBody->move(steps);
            mText->move(steps);
            
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
            window.draw(*mText);
        }
    }
}

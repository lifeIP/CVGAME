#include "CircleIconButton.hpp"
#include "../CircleButton.hpp"

#include "SFML/Graphics/Drawable.hpp"
#include "SFML/Graphics/Sprite.hpp"
#include "SFML/Graphics/Image.hpp"
#include "SFML/Graphics/Texture.hpp"
#include "SFML/Graphics/Rect.hpp"
#include "SFML/Graphics.hpp"

#include <iostream>

namespace components
{
    namespace buttons
    {

        CircleIconButton::CircleIconButton(
            const sf::Vector2f &position, 
            const std::string &imagePath, 
            const float size,
            const std::size_t &pointCount): 
        CircleButton(position, size, pointCount)
        {
            mImage = new sf::Image();
            mTexture = new sf::Texture();
            mSprite = new sf::Sprite();

            if(mImage->loadFromFile(imagePath))//загружаем в него файл
            {
                std::cout << "ERROR mImage" << std::endl;
            }   

            CircleIconButton::setColorDefault(sf::Color(255, 255, 255));
            

            mTexture->loadFromImage(*mImage);
            sf::Vector2u tsize = mTexture->getSize();
            sf::Vector2f scale = sf::Vector2f(size / mTexture->getSize().x - 0.005, size / mTexture->getSize().y - 0.005);
            
            // sprite->setTextureRect(sf::IntRect(sf::Vector2i(position.x, position.y), sf::Vector2i(size, size)));
            mSprite->setTexture(*mTexture);
            mSprite->setScale(scale);
            
            
            // mTexture->getSize().x / 2
            // sprite->setPosition();    
            mSprite->setPosition(sf::Vector2f(position.x + tsize.x * 0.0025, position.y + tsize.y * 0.0025));
        }

        CircleIconButton::~CircleIconButton(){
            delete mSprite;
            delete mTexture;
            delete mImage;
        }

        void CircleIconButton::events(const sf::Window& window, const sf::Event& event) {
            CircleButton::events(window, event);
        }

        int CircleIconButton::handler(){
            return CircleButton::handler();
        }

        void CircleIconButton::move(const sf::Vector2f &steps){
            CircleButton::move(steps);
            mSprite->move(steps);
        }

        void CircleIconButton::setSize(const sf::Vector2f &size){
            CircleButton::setSize(size);
            sf::Vector2f scale = sf::Vector2f(size.x / mTexture->getSize().x, size.x / mTexture->getSize().y);
            
            mSprite->setTexture(*mTexture);
            mSprite->setScale(scale);
        }

        void CircleIconButton::setPosition(const sf::Vector2f &position){
            CircleButton::setPosition(position);
            mSprite->setPosition(position);
        }

        void CircleIconButton::draw(sf::RenderWindow &window)
        {
            CircleButton::draw(window);
            window.draw(*mSprite);
            // window.draw(*mVerticalRectangleShape);
            // window.draw(*mHorizontalRectangleShape);
        }
    }
}
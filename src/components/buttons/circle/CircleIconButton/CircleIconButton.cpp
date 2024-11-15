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
            image = new sf::Image();
            texture = new sf::Texture();
            sprite = new sf::Sprite();

            if(image->loadFromFile(imagePath))//загружаем в него файл
            {
                std::cout << "ERROR image" << std::endl;
            }   

            CircleIconButton::setColorDefault(sf::Color(255, 255, 255));
            

            texture->loadFromImage(*image);
            sf::Vector2u tsize = texture->getSize();
            sf::Vector2f scale = sf::Vector2f(size / texture->getSize().x - 0.005, size / texture->getSize().y - 0.005);
            
            // sprite->setTextureRect(sf::IntRect(sf::Vector2i(position.x, position.y), sf::Vector2i(size, size)));
            sprite->setTexture(*texture);
            sprite->setScale(scale);
            
            
            // texture->getSize().x / 2
            // sprite->setPosition();    
            sprite->setPosition(sf::Vector2f(position.x + tsize.x * 0.0025, position.y + tsize.y * 0.0025));
        }

        CircleIconButton::~CircleIconButton(){

        }

        void CircleIconButton::events(const sf::Window& window, const sf::Event& event) {
            CircleButton::events(window, event);
        }

        int CircleIconButton::handler(){
            return CircleButton::handler();
        }

        void CircleIconButton::move(const sf::Vector2f &steps){
            CircleButton::move(steps);
            sprite->move(steps);
        }

        void CircleIconButton::setSize(const sf::Vector2f &size){
            CircleButton::setSize(size);
            sf::Vector2f scale = sf::Vector2f(size.x / texture->getSize().x, size.x / texture->getSize().y);
            
            sprite->setTexture(*texture);
            sprite->setScale(scale);
        }

        void CircleIconButton::setPosition(const sf::Vector2f &position){
            CircleButton::setPosition(position);
            sprite->setPosition(position);
        }

        void CircleIconButton::draw(sf::RenderWindow &window)
        {
            CircleButton::draw(window);
            window.draw(*sprite);
            // window.draw(*mVerticalRectangleShape);
            // window.draw(*mHorizontalRectangleShape);
        }
    }
}
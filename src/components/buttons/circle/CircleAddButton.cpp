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
        
        CircleAddButton::CircleAddButton(const sf::Vector2f &position, const float size, const std::size_t &pointCount): VoidButton(position, sf::Vector2f(size, size))
        {
            mCircleShape = new sf::CircleShape(size / 2, pointCount);
            mCircleShape->setPointCount(pointCount);
            mCircleShape->setPosition(position);
            mCircleShape->setFillColor(sf::Color(217, 217, 217));

            sf::Vector2f center(position.x + size / 2, position.y + size / 2);

            mVerticalRectangleShape = new sf::RectangleShape(sf::Vector2f(mSize->x * 0.1, mSize->y * 0.75));
            mVerticalRectangleShape->setPosition(sf::Vector2f(center.x - (mSize->x * 0.1)/2, center.y - (mSize->y * 0.75)/2 ));
            mVerticalRectangleShape->setFillColor(sf::Color(2, 233, 29));

            mHorizontalRectangleShape = new sf::RectangleShape(sf::Vector2f(mSize->x * 0.75, mSize->y * 0.1));
            mHorizontalRectangleShape->setPosition(sf::Vector2f(center.x - (mSize->x * 0.75)/2, center.y - (mSize->y * 0.1)/2 ));
            mHorizontalRectangleShape->setFillColor(sf::Color(2, 233, 29));
        }
        
        CircleAddButton::~CircleAddButton()
        {
            delete mCircleShape;
            delete mVerticalRectangleShape;
            delete mHorizontalRectangleShape;
        }

        void CircleAddButton::draw(sf::RenderWindow& window)
        {
            window.draw(*mCircleShape);
            window.draw(*mVerticalRectangleShape);
            window.draw(*mHorizontalRectangleShape);
        }

        void CircleAddButton::getButtonStatus(sf::RenderWindow& window, sf::Event& event){
        }
    }
}
#pragma once

#include "../../components/buttons/circle/CircleIconButton/CircleIconButton.hpp"
#include "../../components/buttons/rect/RectButton.hpp"

#include "SFML/Graphics/Drawable.hpp"
#include "SFML/Graphics/Sprite.hpp"
#include "SFML/Graphics/Image.hpp"
#include "SFML/Graphics/Texture.hpp"
#include "SFML/Graphics/Rect.hpp"
#include "SFML/Graphics.hpp"

namespace blocks
{
    namespace empty
    {
        class EmptyBlock
        {
        public:
            EmptyBlock(const sf::Vector2f &position, const sf::Vector2f &size);
            virtual ~EmptyBlock();


            virtual void move(const sf::Vector2f &steps);
            virtual void draw(sf::RenderWindow& window);

            virtual void setPosition(const sf::Vector2f &position);
            virtual sf::Vector2f getPosition() const;

            virtual void setSize(const sf::Vector2f &size);
            virtual sf::Vector2f getSize() const;

            virtual void setHeaderSize(const float &headerSize);
            virtual float getHeaderSize() const;

            void setEnableSettings(bool enableSettings);
        
            void moveAble(bool moveable);
            
            virtual bool moveEvent(const sf::Window &relativeTo, const sf::Event &event);
            virtual bool closeEvent(const sf::Window &relativeTo, const sf::Event &event);
            virtual bool rightAddButtonEvent(const sf::Window &relativeTo, const sf::Event &event);
            virtual bool bottomAddButtonEvent(const sf::Window &relativeTo, const sf::Event &event);
            virtual bool settingsButtonEvent(const sf::Window &relativeTo, const sf::Event &event);

        public:
            const long mBlockId;
        private: 
            bool isSelected;
            sf::Vector2i *oldPos;
            
            components::buttons::CircleIconButton *mIconButton;
            components::buttons::CircleIconButton *mIconButtonRight;
            components::buttons::CircleIconButton *mIconButtonDown;

            components::buttons::RectButton *mExitButton;
            bool moveable;
        protected:
            sf::RectangleShape *mHeader;
            sf::RectangleShape *mBody;
            float mHeaderSize;
            bool withSettings;
        };
    }
}

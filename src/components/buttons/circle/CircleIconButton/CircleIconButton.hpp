#pragma once

#include "../CircleButton.hpp"

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
        class CircleIconButton: public CircleButton
        {

        private:
            sf::Sprite *mSprite;
            sf::Texture *mTexture;
            sf::Image *mImage;
        public:
            CircleIconButton(const sf::Vector2f &position, const std::string &imagePath, const float size, const std::size_t &pointCount);
            ~CircleIconButton();
            

            /// @brief Функция для перемещения кнопки
            /// @param steps Шаг перемещения
            virtual void move(const sf::Vector2f &steps) override;


            /// @brief Задает позицию кнопки
            virtual void setPosition(const sf::Vector2f &position) override;


            /// @brief Задает размер кнопки
            virtual void setSize(const sf::Vector2f &size) override;


            /// @brief Функция для обработки нажатия и отпускания кнопки.
            /// @brief Данную функцию можно не вызывать, а обрабатывать нажатия самому
            /// @brief используя isPressed, isReleased
            virtual int handler() override;


            /// @brief Функция для обработки событий. Должна вызываться в блоке обработки событий
            virtual void events(const sf::Window& window, const sf::Event& event) override;
            

            virtual void draw(sf::RenderWindow& window) override;
        };

    }
}
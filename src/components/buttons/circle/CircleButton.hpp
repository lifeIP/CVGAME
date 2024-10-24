#pragma once

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
        class CircleButton: public VoidButton
        {
        protected:
            sf::CircleShape *mCircleShape;

        public:
            CircleButton(const sf::Vector2f &position, const float size, const std::size_t &pointCount);
            ~CircleButton();

            /// @brief Функция для перемещения кнопки
            /// @param steps Шаг перемещения
            virtual void move(const sf::Vector2f &steps) override;


            /// @brief Задает позицию кнопки
            virtual void setPosition(const sf::Vector2f &position) override;
            /// @brief Возвращает позицию кнопки
            virtual sf::Vector2f getPosition() const;


            /// @brief Задает размер кнопки
            virtual void setSize(const sf::Vector2f &size) override;
            /// @brief Возвращает размер кнопки
            virtual sf::Vector2f getSize() const override;


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
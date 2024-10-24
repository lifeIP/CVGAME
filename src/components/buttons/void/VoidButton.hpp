#pragma once

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
        class VoidButton
        {
        protected:
            bool mIsPressed;
            bool mIsReleased;
            bool mIsActive;
            sf::Color mColorPushed;
            sf::Color mColorDefault;
            sf::Color mColorFocused;
            sf::Vector2f mPosition;
            sf::Vector2f mSize;
            
        public:

            /// @brief Конструктор пустой кнопки. Явлется просто шаблоном кнопок. 
            /// @brief Только для наследования. Просто так не используется.
            VoidButton();

            ~VoidButton();

            

            /// @brief Функция возвращает значение состояния. Обязательно надо обработать.
            /// @return true если кнопка нажата иначе false 
            bool isPressed();

            /// @brief Функция возвращает значение состояния. Обязательно надо обработать.
            /// @return true если кнопка отпущена иначе false 
            bool isReleased();
            
            /// @brief Функция возвращает значение состояния. Обязательно надо обработать.
            /// @return true если кнопка активна иначе false 
            bool isActive();



            /// @brief Устанавливает цвет которым красится кнопка при нажатии.
            virtual void setColorPushed(const sf::Color &color);
            /// @brief Возвращает цвет которым красится кнопка при нажатии.
            virtual sf::Color getColorPushed() const;



            /// @brief Устанавливает цвет которым красится кнопка в состоянии покоя.
            virtual void setColorDefault(const sf::Color &color);
            /// @brief Возвращает цвет которым красится кнопка в состоянии покоя.
            virtual sf::Color getColorDefault() const;



            /// @brief Устанавливает цвет которым красится кнопка когда пользователь направляет на неё курсором мыши.
            virtual void setColorFocused(const sf::Color &color);
            /// @brief Возвращает значение цвета которым красится кнопка когда пользователь направляет на неё курсором мыши.
            virtual sf::Color getColorFocused() const;


            /// @brief Функция для перемещения кнопки
            /// @param steps Шаг перемещения
            virtual void move(const sf::Vector2f &steps) = 0;


            /// @brief Задает позицию кнопки
            virtual void setPosition(const sf::Vector2f &position) = 0;
            /// @brief Возвращает позицию кнопки
            virtual sf::Vector2f getPosition() const = 0;


            /// @brief Задает размер кнопки
            virtual void setSize(const sf::Vector2f &size) = 0;
            /// @brief Возвращает размер кнопки
            virtual sf::Vector2f getSize() const  = 0;


            /// @brief Функция для обработки нажатия и отпускания кнопки.
            /// @brief Данную функцию можно не вызывать, а обрабатывать нажатия самому
            /// @brief используя isPressed, isReleased
            virtual int handler() = 0;


            /// @brief Функция для обработки событий. Должна вызываться в блоке обработки событий
            virtual void events(const sf::Window& window, const sf::Event& event) = 0;
            

            virtual void draw(sf::RenderWindow& window) = 0;
        };
    }
}
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
        class RectButton: public VoidButton
        {
        protected:
            sf::RectangleShape *mBody;
            sf::Text *mText;
            sf::Font *mFont;

        public:
            RectButton(const sf::Vector2f &position, const sf::Vector2f &size);
            ~RectButton();

            /// @brief Функция для перемещения кнопки
            /// @param steps Шаг перемещения
            virtual void move(const sf::Vector2f &steps) override;



            /// @brief Функция для установки шрифта
            void setFont(const sf::String& string);
            /// @brief Функция для получения установленного шрифта 
            sf::Font getFont() const;



            /// @brief Функция для установки текста отображаемого на кнопке
            void setString(const sf::String& string);
            /// @brief Функция для получения текста отображаемого на кнопке
            sf::String getString() const;



            /// @brief Функция для установки размера букв отображаемого текста  
            void setCharacterSize(unsigned int size);
            /// @brief Функция для получения размера букв отображаемого текста
            unsigned int getCharacterSize() const;



            /// @brief Функция для установки цвета отображаемого текста
            void setTextColor(const sf::Color &color);
            /// @brief Функция для получения цвета отображаемого текста
            sf::Color getTextColor() const;



            /// @brief Функция для установки цвета оконтовки кнопки
            void setBorderColor(const sf::Color &color);
            /// @brief Функция для получения цвета оконтовки кнопки
            sf::Color getBorderColor() const;



            /// @brief Функция для установки толщины оконтовки кнопки
            void setOutlineThickness(const float &thickness);
            /// @brief Функция для получения толщины оконтовки кнопки 
            float getOutlineThickness() const;
    

            /// @brief Задает позицию кнопки
            virtual void setPosition(const sf::Vector2f &position) override;
            /// @brief Возвращает позицию кнопки
            virtual sf::Vector2f getPosition() const override;


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
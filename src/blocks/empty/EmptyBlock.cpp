#include "EmptyBlock.hpp"

#include "../../components/buttons/void/VoidButton.hpp"
#include "../../components/buttons/circle/CircleButton.hpp"
#include "../../components/buttons/circle/CircleAddButton/CircleAddButton.hpp"
#include "../../components/buttons/rect/RectButton.hpp"

#include "SFML/Graphics/Drawable.hpp"
#include "SFML/Graphics/Sprite.hpp"
#include "SFML/Graphics/Image.hpp"
#include "SFML/Graphics/Texture.hpp"
#include "SFML/Graphics/Rect.hpp"
#include "SFML/Graphics/RenderTarget.hpp"
#include "SFML/Graphics.hpp"

#include <iostream>
#include <string>
#include <chrono>

namespace blocks
{
    namespace empty
    {

        void EmptyBlock::draw(sf::RenderWindow &window)
        {
            window.draw(*mHeader);
            window.draw(*mBody);

            if (withSettings)
            {
                mIconButton->draw(window);
            }
            mIconButtonRight->draw(window);
            mIconButtonDown->draw(window);
            mExitButton->draw(window);
        }

        void EmptyBlock::addPriority(long mBlockId)
        {
            for (int i = 0; i < priority.size(); i++)
                if (priority.at(i).blockId == mBlockId)
                {
                    priority.at(i).priority = std::time(nullptr);
                    break;
                }
        }

        long EmptyBlock::getPriority(long blockId)
        {
            for (int i = 0; i < priority.size(); i++)
                if (priority.at(i).blockId == blockId)
                    return priority.at(i).priority;
            return 0;
        }

        void EmptyBlock::moveAble(bool moveable)
        {
            moveable = moveable;
        }

        EmptyBlock::EmptyBlock(const sf::Vector2f &position, const sf::Vector2f &size) : mBlockId(
                                                                                             std::chrono::system_clock::now().time_since_epoch().count())
        {
            moveable = false;

            std::time_t result = std::time(nullptr);
            Priority prior;
            prior.blockId = mBlockId;
            prior.priority = result;
            veryHighPriorityId = mBlockId;

            priority.push_back(prior);

            withSettings = true;
            oldPos = new sf::Vector2i(0, 0);

            mHeaderSize = 48.f;

            mHeader = new sf::RectangleShape(sf::Vector2f(size.x, mHeaderSize));
            mHeader->setPosition(sf::Vector2f(position.x, position.y));
            mHeader->setFillColor(sf::Color(34, 249, 61));

            mBody = new sf::RectangleShape(sf::Vector2f(size.x, size.y - mHeaderSize));
            mBody->setPosition(sf::Vector2f(position.x, position.y + mHeaderSize));
            mBody->setFillColor(sf::Color(29, 21, 21));

            mExitButton = new components::buttons::RectButton(
                sf::Vector2f(position.x + size.x - 44, position.y + mHeaderSize - 43),
                sf::Vector2f(39, 38));

            mExitButton->setColorPushed(sf::Color(255, 10, 10));
            mExitButton->setColorFocused(sf::Color(250, 0, 0));
            mExitButton->setColorDefault(sf::Color(200, 0, 0));
            mExitButton->setTextColor(sf::Color(255, 255, 255));
            mExitButton->setString(sf::String("X"));





            mIconButton = new components::buttons::CircleIconButton(
                sf::Vector2f(position.x + 5, position.y + mHeaderSize - 43),
                std::string("./src/textures/free-icon-settings.png"),
                35.f,
                150);

            mIconButton->setColorPushed(sf::Color(215, 215, 215));
            mIconButton->setColorFocused(sf::Color(255, 0, 0));
            mIconButton->setColorDefault(sf::Color(0, 255, 0));



            mIconButtonRight = new components::buttons::CircleIconButton(
                sf::Vector2f(position.x + size.x + 5, position.y + size.y / 2),
                std::string("./src/textures/free-icon-expand-6020534.png"),
                35.f,
                150);

            mIconButtonRight->setColorPushed(sf::Color(215, 215, 215));
            mIconButtonRight->setColorFocused(sf::Color(255, 0, 0));
            mIconButtonRight->setColorDefault(sf::Color(0, 255, 0));



            mIconButtonDown = new components::buttons::CircleIconButton(
                sf::Vector2f(position.x + size.x / 2, position.y + size.y + 5),
                std::string("./src/textures/free-icon-turn-around-6020549.png"),
                35.f,
                150);

            mIconButtonDown->setColorPushed(sf::Color(215, 215, 215));
            mIconButtonDown->setColorFocused(sf::Color(255, 0, 0));
            mIconButtonDown->setColorDefault(sf::Color(0, 255, 0));

        }

        EmptyBlock::~EmptyBlock()
        {
            for (int i = 0; i < priority.size(); i++)
            {
                if (priority.at(i).blockId == mBlockId)
                {
                    priority.erase(priority.begin() + i);
                    break;
                }
            }

            delete mHeader;
            delete mBody;

            mIconButton->~CircleIconButton();
            mExitButton->~RectButton();

            delete oldPos;

            std::cout << "~EmptyBlock" << std::endl;
        }

        void EmptyBlock::move(const sf::Vector2f &steps)
        {
            mHeader->move(steps);
            mBody->move(steps);
            mIconButton->move(steps);
            mIconButtonRight->move(steps);
            mIconButtonDown->move(steps);
            mExitButton->move(steps);
        }

        int EmptyBlock::events(const sf::Window &relativeTo, const sf::Event &event)
        {

            if (event.type == sf::Event::EventType::MouseButtonPressed)
            {

                if (event.mouseButton.button == sf::Mouse::Left && !isSelected)
                {
                    if (mHeader->getGlobalBounds().contains(sf::Mouse::getPosition(relativeTo).x, sf::Mouse::getPosition(relativeTo).y))
                    {
                        if (moveable)
                        {
                            *oldPos = sf::Vector2i(sf::Mouse::getPosition(relativeTo).x, sf::Mouse::getPosition(relativeTo).y);

                            for (int i = 0; i < priority.size(); i++)
                            {
                                // std::cout << priority.at(i).blockId << " " << mBlockId << std::endl;
                                if (priority.at(i).blockId == mBlockId)
                                {
                                    priority.at(i).priority = std::time(nullptr);
                                    break;
                                }
                            }
                            isSelected = true;
                        }

                        veryHighPriorityId = mBlockId;
                        mExitButton->events(relativeTo, event);
                        return 2;
                    }
                }
            }
            else if (event.type == sf::Event::EventType::MouseButtonReleased)
            {
                if (moveable)
                {
                    if (event.mouseButton.button == sf::Mouse::Left && isSelected)
                    {
                        isSelected = false;
                        return 2;
                    }
                }
            }

            if (veryHighPriorityId == mBlockId &&
                (mHeader->getGlobalBounds().contains(sf::Mouse::getPosition(relativeTo).x, sf::Mouse::getPosition(relativeTo).y)))
            {
                if (event.type == sf::Event::EventType::MouseMoved)
                {
                    if (moveable)
                    {
                        if (isSelected)
                        {
                            sf::Vector2f diff = sf::Vector2f(
                                oldPos->x - sf::Mouse::getPosition(relativeTo).x,
                                oldPos->y - sf::Mouse::getPosition(relativeTo).y);
                            *oldPos = sf::Vector2i(sf::Mouse::getPosition(relativeTo).x, sf::Mouse::getPosition(relativeTo).y);

                            move(sf::Vector2f(-diff.x, -diff.y));
                        }
                    }
                }

                if (withSettings)
                {
                    mIconButton->events(relativeTo, event);
                    if (mIconButton->handler() == 1 || mIconButton->handler() == 3)
                    {
                        return 1;
                    }
                }
                
                if (mExitButton->handler() != 0)
                {
                    return -1;
                }
            }
            mIconButtonRight->events(relativeTo, event);
            if (mIconButtonRight->handler() == 1 || mIconButtonRight->handler() == 3)
            {
                return 6;
            }
            mIconButtonDown->events(relativeTo, event);
            if (mIconButtonDown->handler() == 1 || mIconButtonDown->handler() == 3)
            {
                return 7;
            }
            return 0;
        }

        void EmptyBlock::setPosition(const sf::Vector2f &position)
        {
            mHeader->setPosition(sf::Vector2f(position.x, position.y));
            mBody->setPosition(sf::Vector2f(position.x, position.y + mHeaderSize));
            mExitButton->setPosition(sf::Vector2f(position.x + mBody->getSize().x - 44, position.y + mHeaderSize - 43));

            if (withSettings)
                mIconButton->setPosition(sf::Vector2f(position.x + 5, position.y + mHeaderSize - 43));
        }

        sf::Vector2f EmptyBlock::getPosition() const
        {
            return mHeader->getPosition();
        }

        void EmptyBlock::setSize(const sf::Vector2f &size)
        {
            mHeader->setSize(sf::Vector2f(size.x, mHeaderSize));
            mBody->setSize(sf::Vector2f(size.x, size.y - mHeaderSize));
        }

        sf::Vector2f EmptyBlock::getSize() const
        {
            return sf::Vector2f(mBody->getSize().x, mBody->getSize().y + mHeaderSize);
        }

        void EmptyBlock::setHeaderSize(const float &headerSize)
        {
            mHeaderSize = headerSize;
        }

        float EmptyBlock::getHeaderSize() const
        {
            return mHeaderSize;
        }

        void EmptyBlock::setEnableSettings(bool enableSettings)
        {
            withSettings = enableSettings;
        }
    }
}
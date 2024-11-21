#pragma once

#include "../empty/EmptyBlock.hpp"
#include "../../components/buttons/circle/CircleAddButton/CircleAddButton.hpp"

#include <opencv2/core.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

#include "SFML/Graphics/Drawable.hpp"
#include "SFML/Graphics/Sprite.hpp"
#include "SFML/Graphics/Image.hpp"
#include "SFML/Graphics/Texture.hpp"
#include "SFML/Graphics/Rect.hpp"
#include "SFML/Graphics.hpp"

namespace blocks
{
    namespace input
    {
        class MatInputBlock: public blocks::empty::EmptyBlock
        {
        protected:

        public:
            MatInputBlock(const sf::Vector2f &position, const sf::Vector2f &size);
            ~MatInputBlock();
            
            void setMat(const cv::Mat &mat);
            void setMatSize(const sf::Vector2u &size);
            void setMatPosition(const sf::Vector2u &size);


            virtual int events(const sf::Window &relativeTo, const sf::Event &event) override;
            virtual void move(const sf::Vector2f &steps) override;
            virtual void draw(sf::RenderWindow& window) override;
        };

        MatInputBlock::MatInputBlock(const sf::Vector2f &position, const sf::Vector2f &size): EmptyBlock(position, size) {

        }

        MatInputBlock::~MatInputBlock(){
            
        }
        int MatInputBlock::events(const sf::Window &relativeTo, const sf::Event &event){

        }
        void MatInputBlock::move(const sf::Vector2f &steps){

        }
        void MatInputBlock::draw(sf::RenderWindow& window){
            EmptyBlock::draw(window);

        }
    }
}
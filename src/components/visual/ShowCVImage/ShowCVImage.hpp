#pragma once

#include "../../../blocks/empty/EmptyBlock.hpp"

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

namespace components
{
    namespace visual
    {
        class ShowCVImage: public blocks::empty::EmptyBlock
        {
        private:
            sf::Sprite *mSprite;
            sf::Image *mImage;
            sf::Texture *mTexture;
        public:
            ShowCVImage(const sf::Vector2f &position, const sf::Vector2f &size);
            ~ShowCVImage();

            void setMat(const cv::Mat &mat);

            virtual void move(const sf::Vector2f &steps);
            virtual int events(const sf::Window &relativeTo, const sf::Event &event);
            virtual void draw(sf::RenderWindow& window);
        };
    }
}
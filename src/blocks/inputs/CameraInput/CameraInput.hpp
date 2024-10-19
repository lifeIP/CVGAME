#pragma once

#include "../../empty/EmptyBlock.hpp"

#include "SFML/Graphics/Drawable.hpp"
#include "SFML/Graphics/Sprite.hpp"
#include "SFML/Graphics/Image.hpp"
#include "SFML/Graphics/Texture.hpp"

#include <opencv2/core.hpp>
#include <opencv2/videoio.hpp>

#include <memory>

namespace blocks
{
    namespace inputs
    {
        class CameraInput: public blocks::empty::EmptyBlock {
        public:

            CameraInput(const int cameraIndex);
            virtual ~CameraInput();
            virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

            void update();
            void updateFrame();

            virtual void setSize(const sf::Vector2f& size);
            virtual void setPosition(const sf::Vector2f& position);
            
        private:
            sf::RectangleShape mShape;

            const int mCameraIndex;
            cv::VideoCapture mCap;
            
            sf::Image mImage;
            sf::Texture mTexture;
            
            std::shared_ptr<cv::Mat> mFrameRGB;
            cv::Mat mFrameRGBA;
        };   
    }
}
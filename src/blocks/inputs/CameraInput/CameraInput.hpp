#pragma once


#include "SFML/Graphics/Drawable.hpp"
#include "SFML/Graphics/Sprite.hpp"
#include "SFML/Graphics/Image.hpp"
#include "SFML/Graphics/Texture.hpp"

#include <opencv2/core.hpp>
#include <opencv2/videoio.hpp>

namespace blocks
{
    namespace inputs
    {
        class CameraInput: public sf::Drawable {
        public:

            CameraInput(const int cameraIndex);
            virtual ~CameraInput();
            virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

            void updateFrame();

        private:
            sf::Sprite mSprite;
            const int mCameraIndex;
            cv::VideoCapture mCap;
            sf::Image mImage;
            sf::Texture mTexture;
        };   
    }
}
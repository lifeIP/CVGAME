#include "CameraInput.hpp"

#include "SFML/Graphics/Drawable.hpp"
#include "SFML/Graphics/Sprite.hpp"
#include "SFML/Graphics/Image.hpp"
#include "SFML/Graphics/Texture.hpp"
#include "SFML/Graphics/Rect.hpp"
#include "SFML/Graphics/RenderTarget.hpp"

#include <opencv2/core.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

#include <iostream>

namespace blocks
{
    namespace inputs
    {
        CameraInput::CameraInput(const int cameraIndex) : mCameraIndex(cameraIndex)
        {
            mCap.open(mCameraIndex);
        }

        CameraInput::~CameraInput()
        {
        }

        void CameraInput::updateFrame()
        {
            cv::Mat mFrameRGB, mFrameRGBA;

            mCap >> mFrameRGB;
            if (!mFrameRGB.empty())
            {
                cv::cvtColor(mFrameRGB, mFrameRGBA, cv::COLOR_BGR2RGBA);
                mImage.create(mFrameRGBA.cols, mFrameRGBA.rows, mFrameRGBA.ptr());
                if (mTexture.loadFromImage(mImage))
                {
                    std::cout << "shape" << mFrameRGB.size() << "\n";
                    mSprite.setTexture(mTexture);
                }
            }
        }

        void CameraInput::draw(sf::RenderTarget &target, sf::RenderStates states) const
        {
            target.draw(mSprite, states);
        }
    }
}
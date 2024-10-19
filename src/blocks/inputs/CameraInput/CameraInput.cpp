#include "CameraInput.hpp"
#include "../../empty/EmptyBlock.hpp"

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

#include <memory>
#include <iostream>

namespace blocks
{
    namespace inputs
    {
        CameraInput::CameraInput(const int cameraIndex) : blocks::empty::EmptyBlock(), mCameraIndex{cameraIndex}
        {
            mCap.open(mCameraIndex);
        }

        CameraInput::~CameraInput()
        {
        }

        void CameraInput::update()
        {
            cv::Mat temp;
            mCap >> temp;

            mFrameRGB = std::make_shared<cv::Mat>(temp);
        }
        void CameraInput::updateFrame()
        {
            update();

            mShape.setPosition(sf::Vector2f(mRect.getPosition().x, mRect.getPosition().y));

            if (!mFrameRGB.get()->empty())
            {
                cv::cvtColor(*mFrameRGB.get(), mFrameRGBA, cv::COLOR_BGR2RGBA);
                mImage.create(mFrameRGBA.cols, mFrameRGBA.rows, mFrameRGBA.ptr());
                if (mTexture.loadFromImage(mImage))
                {
                    mShape.setTexture(&mTexture);
                }
            }
        }

        void CameraInput::setSize(const sf::Vector2f &size)
        {
            blocks::empty::EmptyBlock::setSize(size);
            mShape.setSize(size);
        }
        void CameraInput::setPosition(const sf::Vector2f &position)
        {
            blocks::empty::EmptyBlock::setPosition(position);
            mShape.setPosition(sf::Vector2f(position.x, position.y + mHeaderSize));
        }

        void CameraInput::draw(sf::RenderTarget &target, sf::RenderStates states) const
        {
            target.draw(mHeader, states);
            target.draw(mRect, states);
            target.draw(mShape, states);
        }
    }
}
#include "ShowCVImage.hpp"

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

#include <iostream>

namespace components
{
    namespace visual
    {
        
        void ShowCVImage::move(const sf::Vector2f &steps){
            blocks::empty::EmptyBlock::move(steps);
            mSprite->move(steps);
        }

        int ShowCVImage::events(const sf::Window &relativeTo, const sf::Event &event){
            return blocks::empty::EmptyBlock::events(relativeTo, event);
        }

        void ShowCVImage::draw(sf::RenderWindow &window)
        {
            sf::Vector2f scale = sf::Vector2f((getSize().x - 20) / mTexture->getSize().x, (getSize().y - mHeaderSize - 20) / mTexture->getSize().y);
            mSprite->setScale(scale);
            mSprite->setTexture(*mTexture);

            blocks::empty::EmptyBlock::draw(window);
            window.draw(*mSprite);
        }

        void ShowCVImage::setMat(const cv::Mat &mFrameRGB)
        {
            cv::Mat mFrameRGBA;

            if (!mFrameRGB.empty())
            {
                cv::cvtColor(mFrameRGB, mFrameRGBA, cv::COLOR_BGR2RGBA);
                mImage->create(mFrameRGBA.cols, mFrameRGBA.rows, mFrameRGBA.ptr());
                if (mTexture->loadFromImage(*mImage))
                {
                    mSprite->setTexture(*mTexture);
                }
            }
        }

        ShowCVImage::ShowCVImage(const sf::Vector2f &position, const sf::Vector2f &size) : blocks::empty::EmptyBlock(position, size)
        {
            mSprite = new sf::Sprite();
            mImage = new sf::Image();
            mTexture = new sf::Texture();

            mSprite->setPosition(sf::Vector2f(position.x + 10, position.y + mHeaderSize + 10));


            

            cv::Mat mFrameRGB, mFrameRGBA;
            
            mFrameRGB = cv::imread("./src/textures/No_Image_Available.jpg");

            if (!mFrameRGB.empty())
            {
                cv::cvtColor(mFrameRGB, mFrameRGBA, cv::COLOR_BGR2RGBA);
                mImage->create(mFrameRGBA.cols, mFrameRGBA.rows, mFrameRGBA.ptr());
                if (mTexture->loadFromImage(*mImage))
                {
                    mSprite->setTexture(*mTexture);
                }
            }
        }

        ShowCVImage::~ShowCVImage()
        {
            std::cout << "~ShowCVImage" << std::endl;
            delete mSprite;
            delete mImage;
            delete mTexture;
        }
    }
}
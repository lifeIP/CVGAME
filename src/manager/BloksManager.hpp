
#include "SFML/Graphics/Drawable.hpp"
#include "SFML/Graphics/Sprite.hpp"
#include "SFML/Graphics/Image.hpp"
#include "SFML/Graphics/Texture.hpp"
#include "SFML/Graphics/Rect.hpp"
#include "SFML/Graphics.hpp"

#include <opencv2/core.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

#include <iostream>
#include "../libs/json-develop/single_include/nlohmann/json.hpp"
#include "../blocks/empty/EmptyBlock.hpp"
#include "../components/visual/ShowCVImage/ShowCVImage.hpp"


namespace manager
{   
    class BloksManager
    {
    private:
        
        std::vector<blocks::empty::EmptyBlock*> mBlocks;
        sf::Vector2f mBlockSize;

        sf::Vector2f mBlockPosition;
        sf::Vector2f mMargins;

    public:
        BloksManager(/* args */);
        virtual ~BloksManager();

        void addBlock(unsigned int column, unsigned int row);

        virtual void draw(sf::RenderWindow& window);
    };
    

    void BloksManager::addBlock(unsigned int column, unsigned int row){
        mBlockPosition = sf::Vector2f(mBlockSize.x * column + mMargins.x * column, mBlockSize.y * row + mMargins.y * row);
        mBlocks.push_back(new components::visual::ShowCVImage(mBlockPosition, mBlockSize));
    }

    BloksManager::BloksManager()
    {
        mBlockSize = sf::Vector2f(400, 300);
        mMargins = sf::Vector2f(45, 45);
        mBlockPosition = sf::Vector2f(0, 0);
    }
    
    BloksManager::~BloksManager()
    {
    }
    
    void BloksManager::draw(sf::RenderWindow& window){
        for (int i = 0; i < mBlocks.size(); i++)
        {
            mBlocks.at(i)->draw(window);
        }
    }
}

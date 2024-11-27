
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

namespace manager
{   
    class BloksManager
    {
    private:
        sf::Vector2f mPosition;
        sf::Vector2f mSize;
        std::vector<blocks::empty::EmptyBlock*> mBlocks;
    public:
        BloksManager(/* args */);
        ~BloksManager();
    };
    
    BloksManager::BloksManager(/* args */)
    {
        nlohmann::json j = {
            {"pi", 3.141},
            {"all", "no"}
        };
        std::cout << j << std::endl;
    }
    
    BloksManager::~BloksManager()
    {
    }
    
}

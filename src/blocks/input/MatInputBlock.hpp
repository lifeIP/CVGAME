#pragma once

#include "../../components/buttons/circle/CircleAddButton/CircleAddButton.hpp"
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
        class MatInputBlock
        {
        protected:

        public:
            MatInputBlock(/* args */);
            ~MatInputBlock();
        };
        
        MatInputBlock::MatInputBlock(/* args */)
        {
        }
        
        MatInputBlock::~MatInputBlock()
        {
        }       
    }
}
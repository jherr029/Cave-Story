#include "../headers/sprite.h"
#include "../headers/graphics.h"
#include "../headers/global.h"

Sprite::Sprite( )
{

}

Sprite::Sprite( Graphics &graphics, const std::string &filePath, int sourceX, int sourceY, int width, int height, float posX, float posY ) :
        _x(posX),
        _y(posY)
{
    this->_sourceRect.x = sourceX;
    this->_sourceRect.y = sourceY;
    this->_sourceRect.w = width;
    this->_sourceRect.h = height;

    this->_spriteSheet = SDL_CreateTextureFromSurface( graphics.getRenderer( ), graphics.loadImage(filePath) );

    if ( this->_spriteSheet == NULL )
    {
        printf( "\nError: Unable to load image" );
    }
}

Sprite::~Sprite( )
{

}

void Sprite::draw( Graphics &graphics, int x, int y )
{
    SDL_Rect destinationRectangle = { x, y, static_cast<int>(this->_sourceRect.w * global::SPRITE_SCALE), static_cast<int>(this->_sourceRect.h * global::SPRITE_SCALE) };

    graphics.blitSurface( this->_spriteSheet, &this->_sourceRect, &destinationRectangle );
}

void Sprite::update( )
{

}

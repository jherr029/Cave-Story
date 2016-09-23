#include <SDL2/SDL.h>

#include "../headers/graphics.h"
#include "../headers/global.h"

/* Graphics class
 * Holds all information dealing with graphics for the game
 */

Graphics::Graphics( )
{
     SDL_CreateWindowAndRenderer( global::SCREEN_WIDTH, global::SCREEN_HEIGHT, 0, &this->_window, &this->_renderer );

     SDL_SetWindowTitle( this->_window, "Cavestory");
}

Graphics::~Graphics( )
{
     SDL_DestroyWindow( this->_window );
}

SDL_Surface* Graphics::loadImage( const std::string &filePath )
{
     if ( this->_spriteSheets.count( filePath ) == 0 )
     {
          this->_spriteSheets[filePath] = IMG_Load( filePath.c_str( ) );
     }

     return this->_spriteSheets[filePath];
}

void Graphics::blitSurface( SDL_Texture* texture, SDL_Rect* sourceRectangle, SDL_Rect* destinationRectangler )
{
     SDL_RenderCopy( this->_renderer, texture, sourceRectangle, destinationRectangler );
}

void Graphics::flip( )
{
     SDL_RenderPresent( this->_renderer );
}

void Graphics::clear( )
{
     SDL_RenderClear( this->_renderer );
}

SDL_Renderer* Graphics::getRenderer( ) const
{
     return this->_renderer;
}








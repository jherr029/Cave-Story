#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <map>
#include <string>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL.h>

struct SDL_Window;
struct SDL_Renderer;

class Graphics
{
     public:
          Graphics( );
          ~Graphics( );

          /* SDL_Surface* loadImage
           * loads an image into the _spriteSheets map if it doesn't already
           * exist
           * As a result, each image will only ever be loaded once
           */

          SDL_Surface* loadImage( const std::string &filePath );

          void blitSurface( SDL_Texture* source, SDL_Rect* sourceRectangle, SDL_Rect* destinationRectangler);
 

          void flip( );

          void clear( );

          SDL_Renderer* getRenderer() const;
     private:

          SDL_Window* _window;
          SDL_Renderer* _renderer;

          std::map<std::string, SDL_Surface*> _spriteSheets;

};


#endif

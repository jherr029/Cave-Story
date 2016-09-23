#ifndef ANIMATEDSPRITE_H
#define ANIMATEDSPRITE_H

// forward declare??
class Graphics;

#include "global.h"
#include "sprite.h"
#include <map>
#include <string>
#include <vector>

/* Animatedsprite class 
 * holds logic for animating sprites
 */


class AnimatedSprite : public Sprite
{
    public:
        AnimatedSprite( );
        AnimatedSprite( Graphics &graphics, const std::string &filePath, int sourceX, int sourceY,
                int width, int height, float posX, float posY, float timeToUpdate );


        /* void playAnimation
         * PLays the animation provided if its not already playing
         */

        void playAnimation( std::string animation, bool once = false );

        /* void update
         * update the animated sprite ( timer )
         */

        void update( int elapsedTime );

        /* void draw
         * draw the sprite to the screen
         */

        void draw( Graphics &graphics, int x, int y );

    protected:

        double _timeToUpdate;
        bool _currentAnimationOnce;
        std::string _currentAnimation;

        /* void addAnimation
         * Adds an animation to the map of animation for the sprite
         */

        void addAnimation( int frames, int x, int y, std::string name, int width, int height, 
                Vector2 offset );

        /* void resetAnimation
         * resets all animations associated with this sprite
         */

        void resetAnimation( );

        /* void stopAnimation
         * stops the current animation
         */

        void stopAnimation( );

        /* void setVisible
         * changes the visibility of the animated sprite
         */

        void setVisible( bool visible );

        /* void animationDone
         * logic that happens when an animation ends
         */

        virtual void animationDone( std::string currentAnimation ) = 0;

        /* void setup animation
         * a required function that sets up all animations for a sprite
         */

        virtual void setupAnimation( ) = 0;

    private:

        std::map< std::string, std::vector<SDL_Rect> > _animations;
        std::map< std::string, Vector2 > _offsets;

        int _frameIndex;
        double _timeElapsed;
        bool _visible;

};

#endif

#include <functional>
#include <emscripten.h>
#include <SDL.h>
#include <SDL2/SDL_image.h>
#include <emscripten/html5.h>
#define GL_GLEXT_PROTOTYPES 1
#include <SDL_opengles2.h>
#include "engine/game.h"
//include all .cpp files here in order for emcc to find and compile them using #paragma once
//to prevent linking errors
#include "engine/game.cpp"
#include "engine/assetManager/assetManager.cpp"


EM_JS(int, canvas_get_width, (), {
  return window.innerWidth;
});

EM_JS(int, canvas_get_height, (), {
  return window.innerHeight;
});


// an example of something we will control from the javascript side
bool background_is_black = true;

extern "C" void EMSCRIPTEN_KEEPALIVE toggle_background_color() { background_is_black = !background_is_black; };

std::function<void()> loop;
void main_loop() { loop(); }

int main()
{
    game * Game = new game(canvas_get_width(), canvas_get_height());
    
    //ss
    loop = [&]
    {
        Game->Render();
        Game->background_is_black = background_is_black;
    };

    emscripten_set_main_loop(main_loop, 0, true);

    return EXIT_SUCCESS;
}

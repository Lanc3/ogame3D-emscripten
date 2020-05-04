#pragma once
#include <functional>
#include <emscripten.h>
#include <SDL.h>
#include <SDL2/SDL_image.h>
#include <emscripten/html5.h>
#define GL_GLEXT_PROTOTYPES 1
#include <SDL_opengles2.h>
#include "assetManager/assetManager.h"
#include "sceneManager/sceneManager.h"

// the function called by the javascript code


class game
{
public:

game(int innerWidth, int innerHeight);
~game();
void Render();
void Update();
SDL_Window* m_Window;
SDL_Renderer* m_Renderer;
bool background_is_black;

private:
int loadImage(SDL_Renderer* renderer, const char* fileName);
int result = 0;
int m_innerWidth,m_innerHeight;
assetManager * m_assetManager;

};
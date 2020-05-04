#include "game.h"
using namespace std;



game::game(int innerWidth, int innerHeight) 
{
    
    m_innerWidth = innerWidth;
    m_innerHeight = innerHeight;
    SDL_CreateWindowAndRenderer(m_innerWidth, m_innerHeight, 0, &m_Window, &m_Renderer);
   
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 2);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 0);
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);

    m_assetManager = new assetManager(m_Renderer);

    m_assetManager->addAssetToBeLoaded("test","assets/icon_frame.png");

    m_assetManager->loadAssetsFromQueue();
    
}
game::~game()
{

}
void game::Update()
{
    
}

void game::Render()
{
       // Clear the screen
        if( background_is_black )
            glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        else
            glClearColor(0.9f, 0.9f, 0.9f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        SDL_Rect dest = {.x = 100, .y = 0, .w = 200, .h = 200};
        SDL_RenderCopy(m_Renderer, m_assetManager->getAsset("test"), NULL, &dest);
        SDL_RenderPresent(m_Renderer);
        SDL_GL_SwapWindow(m_Window);
}

int game::loadImage(SDL_Renderer* renderer, const char* fileName)
{
  
    //tetsfdsfasdsdasdsd
  return result;
}
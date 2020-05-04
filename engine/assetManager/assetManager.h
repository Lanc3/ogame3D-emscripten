#pragma once
#include "asset.h"
#include <functional>
#include <vector>
#include <map>
#include <SDL.h>
#include <SDL2/SDL_image.h>
#include <emscripten/html5.h>
#include <SDL_opengles2.h>



using namespace std;

class assetManager
{
    public:
    assetManager(SDL_Renderer * renderer);
    void addAssetToBeLoaded(string keyName, const char* fileDirectory);
    void loadAssetsFromQueue();
    SDL_Texture * getAsset(string keyName);
    private:
    void loadAsset(asset * newAsset);
    vector<asset *> m_assetQueue;
    int m_AmountOfAssets = 0;
    SDL_Renderer * m_Renderer;
    map<string , SDL_Texture *> sprites;
};
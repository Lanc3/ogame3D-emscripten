#include "assetManager.h"

assetManager::assetManager(SDL_Renderer * renderer)
{
    m_Renderer = renderer;
}

void assetManager::addAssetToBeLoaded(string keyName, const char* fileDirectory)
{
    m_assetQueue.push_back(new asset(keyName,fileDirectory));
}

void assetManager::loadAssetsFromQueue()
{
    for(auto & assets : m_assetQueue)
    {
        loadAsset(assets);
    }
}

void assetManager::loadAsset(asset * newAsset)
{
    
    SDL_Surface * img = IMG_Load(newAsset->getFileDirectory());
    if (!img)
    {
        printf("IMG_Load: %s\n", IMG_GetError());
        
    }
    else
    {
        SDL_Texture * texture = SDL_CreateTextureFromSurface(m_Renderer,img);
        sprites[newAsset->getKeyName()] = texture;
    }
}

SDL_Texture * assetManager::getAsset(string keyName)
{
    return sprites[keyName];
}
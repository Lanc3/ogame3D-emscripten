#include "scene.h"
scene::scene(string sceneName)
{
    m_sceneName = sceneName;
}

scene::~scene()
{

}

void scene::start()
{
    m_isAlive = true;
}

void scene::stop()
{
    m_isAlive = false;
}

void scene::goToScene(string sceneName)
{
    m_isAlive = false;
    m_transitionSceneName = sceneName;
}

void scene::setSceneAlive()
{
    m_transitionSceneName = "";
    m_isAlive = true;
}

void scene::setSceneDead()
{
    m_isAlive = false;
}

bool scene::isSceneAlive()
{
    return m_isAlive;
}

string scene::checkNextScene()
{
    return m_transitionSceneName;
}

string scene::getSceneName()
{
    return m_sceneName;
}



#include "sceneManager.h"

sceneManager::sceneManager()
{
    m_currentScene = nullptr;
}
sceneManager::~sceneManager()
{
    delete m_currentScene;
}

void sceneManager::update()
{
    if(m_currentScene != nullptr || m_currentScene != NULL)
    {
        m_currentScene->update();
        if(!m_currentScene->isSceneAlive())
        {
            m_currentScene->stop();
            m_currentScene->setSceneDead();
            m_currentScene = m_sceneList[m_currentScene->checkNextScene()];
            m_currentScene->setSceneAlive();
            m_currentScene->start();
        }
    }
}

void sceneManager::render()
{
    if (m_currentScene != nullptr)
	{
		m_currentScene->render();
	}
}

void sceneManager::handleInput()
{
    if (m_currentScene != nullptr)
	{
		m_currentScene->handleInput();
	}
}
void sceneManager::addScene(scene * newScene)
{
    m_sceneList[newScene->getSceneName()]= newScene;
}

void sceneManager::changeScene(string name)
{
    if (m_currentScene == nullptr)
	{
		m_currentScene = m_sceneList[name];
		m_currentScene->start();
	}
	if (m_currentScene != nullptr)
	{
		m_currentScene->stop();
		m_currentScene = m_sceneList[name];
		m_currentScene->start();
	}
}

scene * sceneManager::getCurrentScene()
{
    return m_currentScene;
}
#include "scene.h"
#include <map>

class sceneManager
{
    public:
    sceneManager();
    ~sceneManager();

    void update();
    void render();
    void handleInput();
    void addScene(scene* newScene);
    void changeScene(string name);
    scene* getCurrentScene();

    private:
    scene * m_currentScene;
    map<string,scene *> m_sceneList;
};
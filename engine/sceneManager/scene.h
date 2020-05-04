#include <string>

using namespace std;

class scene
{
    public:
    scene(string name);
    ~scene();
    virtual void update();
    virtual void render();
    virtual void handleInput();
    virtual void start();
    virtual void stop();
    void setSceneAlive();
    void setSceneDead();
    void goToScene(string sceneName);
    bool isSceneAlive();
    string checkNextScene();
    string getSceneName();
    private:
    string m_sceneName;
    string m_transitionSceneName;
    bool m_isAlive;
};
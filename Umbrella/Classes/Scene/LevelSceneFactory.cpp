#include "LevelSceneFactory.cpp"

Scene* LevelSceneFactory::createScene() {
    return NULL;
}

Scene* LevelSceneFactory::createScene(string args) {
    return new LevelScene(args);
}
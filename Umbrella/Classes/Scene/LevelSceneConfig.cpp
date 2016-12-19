#include "LevelSceneConfig.h"

// define config values
LevelSceneConfig::LevelSceneConfig() {

	BACKGROUND_MUSIC[begin_scene] = "Telepopmusik - Breathe.mp3";
	BACKGROUND_MUSIC[end_scene] = "Melissa Williamson - Room of Angel.mp3";
	BACKGROUND_MUSIC[level_1_scene] = "Blue Six - Music And Wine.mp3";
	BACKGROUND_MUSIC[level_2_scene] = "Blue Six - Music And Wine.mp3";
	BACKGROUND_MUSIC[level_3_scene] = "Blue Six - Music And Wine.mp3";
	BACKGROUND_MUSIC[level_4_scene] = "Blue Six - Music And Wine.mp3";
	BACKGROUND_MUSIC[level_5_scene] = "Blue Six - Music And Wine.mp3";
	BACKGROUND_MUSIC[level_6_scene] = "Blue Six - Music And Wine.mp3";

	NEXT_SCENE[begin_scene] = level_1_scene;
	NEXT_SCENE[level_1_scene] = level_2_scene;
	NEXT_SCENE[level_2_scene] = level_3_scene;
	NEXT_SCENE[level_3_scene] = level_4_scene;
	NEXT_SCENE[level_4_scene] = level_5_scene;
	NEXT_SCENE[level_5_scene] = level_6_scene;
	NEXT_SCENE[level_6_scene] = end_scene;

	BACKGROUND_IMG_1[level_1_scene] = "Level1SceneBG1.png";
	BACKGROUND_IMG_1[level_2_scene] = "Level246SceneBG1.png";
	BACKGROUND_IMG_1[level_3_scene] = "Level35SceneBG1.png";
	BACKGROUND_IMG_1[level_4_scene] = "Level246SceneBG1.png";
	BACKGROUND_IMG_1[level_5_scene] = "Level35SceneBG1.png";
	BACKGROUND_IMG_1[level_6_scene] = "Level246SceneBG1.png";

	BACKGROUND_IMG_2[level_1_scene] = "Level1SceneBG2.png";
	BACKGROUND_IMG_2[level_2_scene] = "Level246SceneBG2.png";
	BACKGROUND_IMG_2[level_3_scene] = "Level35SceneBG2.png";
	BACKGROUND_IMG_2[level_4_scene] = "Level246SceneBG2.png";
	BACKGROUND_IMG_2[level_5_scene] = "Level35SceneBG2.png";
	BACKGROUND_IMG_2[level_6_scene] = "Level246SceneBG2.png";

	TITLE_IMG[level_1_scene] = "Level1SceneTitle.png";
	TITLE_IMG[level_2_scene] = "Level2SceneTitle.png";
	TITLE_IMG[level_3_scene] = "Level3SceneTitle.png";
	TITLE_IMG[level_4_scene] = "Level4SceneTitle.png";
	TITLE_IMG[level_5_scene] = "Level5SceneTitle.png";
	TITLE_IMG[level_6_scene] = "Level6SceneTitle.png";

	UMBRELLA_IMG[level_1_scene] = "Umbrella1.png";
	UMBRELLA_IMG[level_2_scene] = "Umbrella2.png";
	UMBRELLA_IMG[level_3_scene] = "Umbrella3.png";
	UMBRELLA_IMG[level_4_scene] = "Umbrella4.png";
	UMBRELLA_IMG[level_5_scene] = "Umbrella5.png";
	UMBRELLA_IMG[level_6_scene] = "Umbrella6.png";

	UMBRELLA_PURITY[level_1_scene] = 1000;
	UMBRELLA_PURITY[level_2_scene] = 1000;
	UMBRELLA_PURITY[level_3_scene] = 800;
	UMBRELLA_PURITY[level_4_scene] = 1500;
	UMBRELLA_PURITY[level_5_scene] = 1000;
	UMBRELLA_PURITY[level_6_scene] = 800;

	TIME_LIMIT[level_1_scene] = 303.0f;
	TIME_LIMIT[level_2_scene] = 183.0f;
	TIME_LIMIT[level_3_scene] = 183.0f;
	TIME_LIMIT[level_4_scene] = 123.0f;
	TIME_LIMIT[level_5_scene] = 183.0f;
	TIME_LIMIT[level_6_scene] = 123.0f;
}
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

	BACKGROUND_IMG_1[begin_scene] = "Level1SceneBG1.png";
	BACKGROUND_IMG_1
		BACKGROUND_IMG_1

	BACKGROUND_IMG_2[begin_scene] = "Level1SceneBG2.png";

	TITLE_IMG[begin_scene] = "Level1SceneTitle.png";

	UMBRELLA_IMG[begin_scene] = "Umbrella1.png";

	UMBRELLA_PURITY[begin_scene] = 1000;

	TIME_LIMIT[begin_scene] = 303.0f;
}
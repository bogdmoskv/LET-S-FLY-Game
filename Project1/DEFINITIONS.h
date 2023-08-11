#pragma once

#define SCREEN_WIDTH 576
#define SCREEN_HEIGHT 768
#define SPLASH_STATE_SHOW_TIME 3.0

#define ICON_FILEPATH "Resources/images/icon.png"

#define LOADING_SCENE_BACKGROUND_FILEPATH "Resources/images/Loading Background.png"
#define MAIN_MENU_BACKGROUND_FILEPATH "Resources/images/sky.png"
#define GAME_BACKGROUND_FILEPATH "Resources/images/sky.png"
#define GAME_OVER_BACKGROUND_FILEPATH "Resources/images/sky.png"

#define GAME_TITLE_FILEPATH "Resources/images/title.png"
#define PLAY_BUTTON_FILEPATH "Resources/images/PlayButton.png"

#define MOUNTAIN_FILEPATH "Resources/images/Mountain.png"
#define CLOUD_FILEPATH "Resources/images/Cloud.png"

#define SCORING_OBSTACLE_FILEPATH "Resources/images/InvisibleScoringObstacle.png"

#define PLANE_FRAME1_FILEPATH "Resources/images/plane.png"

#define FLAPPY_FONT_FILEPATH "Resources/fonts/calibri.ttf"

#define GAME_OVER_TITLE_FILEPATH "Resources/images/Game-Over-Title.png"
#define GAME_OVER_BODY_FILEPATH "Resources/images/Game-Over-Body.png"


#define HIT_SOUND_FILEPATH "Resources/audio/Vzryv.wav"
#define POINT_SOUND_FILEPATH "Resources/audio/Coin.wav"
#define WING_SOUND_FILEPATH "Resources/audio/Wing.wav"
#define BACKGROUND_SOUND_FILEPATH "Resources/audio/Backgr.wav"

#define PIPE_MOVEMENT_SPEED 200.0f
#define PIPE_SPAWN_FREQUENCY 3.5f 

#define PLANE_STATE_STILL 1
#define PLANE_STATE_FALLING 2
#define PLANE_STATE_FLYING 3

#define GRAVITY 85.0f

#define FLYING_SPEED 350.0f

#define FLYING_DURATION 0.10f

#define ROTATION_SPEED 25.0f

enum GameStates{
	eReady,
	ePlaying,
	eGameOver
};

#define FLASH_SPEED 1500.0f

#define TIME_BEFORE_GAME_OVER_APPEARS 1.5f
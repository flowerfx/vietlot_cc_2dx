#ifndef __MAIN_GAME_H__
#define __MAIN_GAME_H__

#include "cocos2d.h"
#include "DisplayView.h"
#include "SoundManager.h"
#define USE_FAKE_DATA
class MainGame : public cocos2d::Layer
{
private:
	static MainGame * p_Instance;

	bool	_IsInitialized;
	int		_loadingStep;  
public:
	// implement the "static node()" method manually
	CREATE_FUNC(MainGame);
	// Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
	virtual bool init();
	// there's no 'id' in cpp, so we recommend returning the class instance pointer
	static cocos2d::Scene* scene();
	//
	static MainGame * GetInstance()
	{
		if (!p_Instance)
		{
			p_Instance = new MainGame();
		}
		return p_Instance;
	}
	MainGame();
	~MainGame();
	//
	void EndScence();
	//update and main method
	virtual void update(float dt);
	//
	bool InitTheGame(float dt);

	bool InitLoadingScreen();
	//
	//method with cocos2d engine

	void InitForFirstScence(cocos2d::Director * d)
	{
		d->runWithScene(MainGame::scene());
	}

};

#define GameMgr MainGame::GetInstance()

#endif //__MAIN_GAME_H__

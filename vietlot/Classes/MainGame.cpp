#include "MainGame.h"
#include "Menu/MenuManager.h"
#include "InputManager.h"
#if USE_CC_AUDIO
#include "SoundManager.h"
#endif
#include "FXFlatform/XFlatform.h" //for the cross flatform wp8/android/ios
#include "ObjectTexture.h"
#include "FileManager.h"
#include "Social/SocialManager.h"

//#include "Profiler.h"

using namespace Utility;
USING_NS_CC;

MainGame * MainGame::p_Instance = NULL;

MainGame::MainGame()
{
	this->retain();
	_MenuMgr = new MenuManager();
	_loadingStep = 0;
}


MainGame::~MainGame()
{
	SAFE_DELETE(_MenuMgr);
	//_profile_font->release();
	this->autorelease();
}

bool MainGame::init()
{
	_IsInitialized = false;
	//
	Utility::InitSizeGame();
	//
    InitTheGame(0.f);
	//
	this->scheduleUpdate();
	//
	return true;
}
//virtual bool update();
// there's no 'id' in cpp, so we recommend returning the class instance pointer
cocos2d::Scene* MainGame::scene()
{
	// 'scene' is an autorelease object
	cocos2d::Scene *scene = cocos2d::Scene::create();
	// 'layer' is an autorelease object
	MainGame *layer = MainGame::create();
	layer->setName("main_game");
	// add layer as a child to scene
	scene->addChild(layer);
	// return the scene
	return scene;
}

bool MainGame::InitLoadingScreen()
{
	return true;
}

bool MainGame::InitTheGame(float dt)
{
	if (_loadingStep == 0)
	{

#ifdef USE_ZIP
		cocos2d::FileUtils::getInstance()->AddZipFilePath("iWin.zip");
#endif
		//
		InputMgr->init();

		DataDir("Vietlot/");

        //Director::getInstance()->InitModuleRKFile();
		InitValue();
		XMLMgr->OnLoaderXML();

		XMLMgr->OnLoadXMLData<Utility::xml::LoadDataXML>("language", 
			std::mem_fn(&Utility::xml::LoadDataXML::OnLoadListLangXML), XMLMgr);
        
		//load save file
	//	File::SaveMgr->LoadTheGameSave(SAVE_NAME);
		//load texture
		XMLMgr->OnLoadXMLData<Utility::xml::LoadDataXML>("texture", 
			std::mem_fn(&Utility::xml::LoadDataXML::OnLoadTextureAtlasDecXML), XMLMgr);
		//load template
		XMLMgr->OnLoadXMLData<Utility::xml::LoadDataXML>("TemplateDec",
			std::mem_fn(&Utility::xml::LoadDataXML::OnLoadWidgetTemplateDecXML), XMLMgr);
		//load widget com dec
		XMLMgr->OnLoadXMLData<Utility::xml::LoadDataXML>("WidgetComDec",
			std::mem_fn(&Utility::xml::LoadDataXML::OnLoadUIWidgetComXML), XMLMgr);

		TextureMgr->LoadTextureAtlas("atlas_GUI");
		TextureMgr->LoadFont();
		SocialMgr->Init();

		_MenuMgr->Init();

		RKString set_load = "loading";
		XMLMgr->OnLoadXMLData1("UIWidget_table",
			[&, set_load](TiXmlDocument * objectXMl) 
		{
			XMLMgr->OnLoadUIWidgetDecTableXML(objectXMl, set_load); 
		});	
		_MenuMgr->InitDetailScreen(MENU_LAYER::LOADING_MENU);
		//
		_loadingStep++;

		_MenuMgr->SetStateLoading(_loadingStep);
		return false;
	}
	else
	{
        //here to call dismiss Splash screen on android
        
		_loadingStep = _MenuMgr->GetStateLoading();
        if(_loadingStep == 1)
        {
            _MenuMgr->SwitchToMenu(MENU_LAYER::LOADING_MENU);
        }
		if (_loadingStep < 10)
		{
			return false;
		}
	}
	return true;
}


void MainGame::update(float dt)
{

	if (!_IsInitialized)
	{
		if (XFlatform::IsAtLogoState() == true)
		{
			return;
		}
		//	
		bool res = InitTheGame(dt);

		if (res)
		{
			_IsInitialized = true;

		}
	}

	if(_loadingStep >= 1)
	{	
		if (_MenuMgr)
		{
			_MenuMgr->Update(dt);
		}
		/*if (!_profile_font->getParent())
			getParent()->addChild(_profile_font, 9999)*/;
		//_profile_font->setText(GetProfiler()->getResult());

		InputMgr->update(dt);

		//
		//GlobalService::onUpdate(dt);
	}
}


void MainGame::EndScence()
{
	this->unscheduleUpdate();
}

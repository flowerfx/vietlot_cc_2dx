#include "LoadingMenu.h"


#include "RKThread_Code/RKThreadWrapper.h"

LoadingMenu::LoadingMenu()
{

	_current_state_loading = -1;
	_state_load_resource = 0;

	_thread_load_xml = nullptr;
	_finish_load_xml = false;

	_state_load = 0;
}


LoadingMenu::~LoadingMenu()
{
	SAFE_DELETE(_thread_load_xml)
}

int LoadingMenu::Init()
{
	RKString _menu = "loading_menu";
	float cur_ratio = GetGameSize().width / GetGameSize().height;
	if (cur_ratio > 480) //ipad ratio
	{
		//_menu = "login_screen_small_size";
	}
	//create 2 icon on load and off load
	
	InitMenuWidgetEntity(_menu);
	InitComponent();
	return 1;
}

int	LoadingMenu::InitComponent()
{
	return 1;
}

void LoadingMenu::LoadXMLFile()
{
	PWARN1("THREAD : LOAD SOUND");
	/*XMLMgr->OnLoadXMLData1("sound_dec", [&](TiXmlDocument * objectXMl) {
		XMLMgr->OnLoadListSoundDecXML(objectXMl); });*/

    PWARN1("THREAD : LOAD LANGUAGE");
    //set language
    int lang_idx_select = LANGUAGE_TYPE::LANG_VI;
	//MenuMgr->GetDataSaveInt(STR_SAVE_LANGUAGE, lang_idx_select);
    LangMgr->SetNewLanguage((LANGUAGE_TYPE)lang_idx_select);
    //
    //
    PWARN1("THREAD: LOAD XML SET LOGIN ");
    RKString set_load = "login";
    XMLMgr->OnLoadXMLData1("UIWidget_table",
                           [&, set_load](TiXmlDocument * objectXMl)
                           {
                               XMLMgr->OnLoadUIWidgetDecTableXML(objectXMl, set_load);
                           });
    //
    PWARN1("THREAD: LOAD XML SET main_0 ");
    set_load = "main_0";
    XMLMgr->OnLoadXMLData1("UIWidget_table",
                           [&, set_load](TiXmlDocument * objectXMl)
                           {
                               XMLMgr->OnLoadUIWidgetDecTableXML(objectXMl, set_load);
                           });
    PWARN1("THREAD: LOAD XML FINISH");
    _finish_load_xml = true;
}

void LoadingMenu::StartThreadLoadXML()
{
	SAFE_DELETE(_thread_load_xml)
	_thread_load_xml = new ThreadWrapper();
	_thread_load_xml->CreateThreadWrapper("thread_load_xml",
		([](void * data) -> uint32
	{
		LoadingMenu * scr = (LoadingMenu*)data;
		scr->_thread_load_xml->OnCheckUpdateThreadWrapper
		([scr]()
		{
            scr->LoadXMLFile();
		});
		return 1;
	}), (void*)this);
}

int LoadingMenu::Update(float dt)
{
	if (BaseMenu::Update(dt) == 0)
	{
		return 0;
	}

	if (_current_state_loading < 5)
	{
		// 5 frame first is show the flash screen
		_current_state_loading++;
	}
	else if (_current_state_loading == 5)
	{  
		#if CC_TARGET_PLATFORM == CC_PLATFORM_WINRT
				if (WPPlatform::WPHelper::hideImageLoadGame)
				{
					WPPlatform::WPHelper::hideImageLoadGame();
				}
		#endif
		_state_load++;
        _current_state_loading++;
	}
	else if (_current_state_loading == 6)
	{
		_state_load_resource = 1;
		//StartThreadLoadXML();
		_state_load++;
		_current_state_loading++;
    }
	else if (_current_state_loading == 7)
	{
        if(!_finish_load_xml)
        {
            LoadXMLFile();
        }
		auto table_xml = XMLMgr->GetTableXMLLoad();
		auto table_screen = MenuMgr->GetTableScreenLoad();

		if (table_screen.size() > table_xml.size())
		{
			PASSERT2(false, "table_screen must be smaller or equal with table_xml");
		}
		else
		{
			if (table_screen.size() == table_xml.size())
			{
				if (_finish_load_xml)
				{
                 
					_state_load_resource = 2;
					_current_state_loading++;
				}
				else
				{
					CCLOG("MAIN THREAD : ON WAITING XML LOAD");
				}
			}
			else
			{
				int last_screen_init = table_screen.size();
				int next_screen_init = table_xml[last_screen_init];
				MenuMgr->InitDetailScreen((MENU_LAYER)next_screen_init);
				_state_load++;
			}
		}
	}
	else if (_current_state_loading == 8)
	{
		GetSound->InitSoundEngine();
		_current_state_loading ++ ;
	}
	else if (_current_state_loading == 9)
	{
		_current_state_loading++;

		//MenuMgr->SwitchToMenu(LOGIN_SCREEN, LOADING_SCREEN);
	}
    else if (_current_state_loading == 11)
	{
		_current_state_loading++;
	}
	else if (_current_state_loading == 12)
	{
		_current_state_loading++;
	}
	else if (_current_state_loading == 13)
	{ 
		_current_state_loading = 100;
	}

	return 1;
}


void LoadingMenu::OnProcessWidgetChild(const RKString & name, UI_TYPE type_widget, WidgetEntity * _widget)
{
}

void LoadingMenu::OnDeactiveCurrentMenu()
{
	MenuMgr->CloseCurrentMenu(LOADING_MENU);
	//p_menu_show_next = MENU_NONE;
}


int LoadingMenu::GetStateLoading()
{
	return _current_state_loading;
}

void LoadingMenu::SetStateLoading(int state)
{
	_current_state_loading = state;
}

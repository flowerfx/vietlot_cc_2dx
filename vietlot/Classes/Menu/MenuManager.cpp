#include "MenuManager.h"
#include <iostream>
#include "MainGame.h"
#include "FileManager.h"


#include "LoadingMenu.h"
#include "MainMenu.h"
MenuManager * MenuManager::m_instance = nullptr;
MenuManager::MenuManager()
{
	RegisterMenuUI();

	p_IsPopUpAppear = false;
	_table_menu_load.clear();
	_common_menu = nullptr;
}

MenuManager::~MenuManager()
{
	_list_menu.clear();


	//weak pointer do not delete
	_common_menu = nullptr;
	_table_menu_load.clear();
}

int  MenuManager::Init()
{
	return 1;
}

int	MenuManager::InitDetailScreen(MENU_LAYER id_screen)
{
	if (id_screen < LOADING_MENU || id_screen >= MENU_COUNT)
	{
		PASSERT2(false, "id out of stack");
		return -1;
	}
	if (_list_menu.find(id_screen) != _list_menu.end())
		return id_screen;


	auto val = s_factory_menu_entity.CreateNewProduct((MENU_LAYER)id_screen);
	if (val)
	{
		val->Init();
		_list_menu.insert(std::pair<MENU_LAYER, BaseMenu*>((MENU_LAYER)id_screen, val));
		_table_menu_load.push_back(id_screen);
		if (id_screen == MENU_LAYER::COMMON_MENU)
		{
			_common_menu = val;
			//push to the top screen logic cocos2dx
			_common_menu->push_layer_to_main_scene(100);
		}
		return id_screen;
	}
	return -1;
}

void MenuManager::Update(float dt)
{
	for (int i = _list_current_active_menu.size() - 1; i >= 0; i--)
	{
		auto ui = _list_menu.at(_list_current_active_menu.at(i));
		ui->SetIdxMenuData(i);
		ui->Update(dt);
	}
	if (_common_menu)
	{
		_common_menu->Update(dt);
	}
}


void MenuManager::SwitchToMenu(MENU_LAYER m, MENU_LAYER from_menu)
{
	if (m == from_menu)
		return;

	if (m != MENU_LAYER::MENU_NONE)
	{
        if(from_menu == MENU_LAYER::MENU_NONE)
        {
			ShowCurrentMenu(m, (int)from_menu);
        }

		if (from_menu!= MENU_LAYER::MENU_NONE && GetMenuUI(from_menu)->GetMenuComeFrom() != m)
		{
			GetMenuUI(m)->SetMenuComFrom(from_menu);
		}
		else if (from_menu == MENU_LAYER::MENU_NONE && GetMenuUI(m)->GetMenuComeFrom() != MENU_LAYER::MENU_NONE)
		{
			GetMenuUI(m)->SetMenuComFrom(from_menu);
		}
	}
	//
	if (from_menu != MENU_LAYER::MENU_NONE)
	{
		GetMenuUI(from_menu)->OnHide();
        GetMenuUI(from_menu)->SetMenuShowNext(m);
	}
}

void MenuManager::CloseCurrentMenu(MENU_LAYER m)
{
    auto next_menu = GetMenuUI(m)->GetMenuShowNext();
    ShowCurrentMenu(next_menu, 0);
	DeActiveUI(m);
}

void MenuManager::ShowCurrentMenu(MENU_LAYER m, int idx)
{
    if(m == MENU_LAYER::MENU_NONE)
    {
        return;
    }
	SetActiveUI(m, idx);
    GetMenuUI(m)->OnShow();
}

void MenuManager::SetActiveUI(MENU_LAYER layer, int idx)
{
	if (idx == -1)
		idx = _list_current_active_menu.size();
	else
		idx = 0;
    if(_list_current_active_menu.size() > 0 && _list_current_active_menu.at(idx) == layer)
    {
        return;
    }
    
	_list_current_active_menu.insert(_list_current_active_menu.begin() + idx , layer);
}

void MenuManager::DeActiveUI(MENU_LAYER layer)
{
	int idx = -1;
	for (size_t i = 0; i < _list_current_active_menu.size(); i++)
	{
		if (_list_current_active_menu.at(i) == layer)
		{
			idx = (int)i;
			break;
		}
	}
	if (idx > -1)
	{
		//GetMenuUI(layer)->SetMenuComFrom(MENU_LAYER::MENU_NONE);
		_list_current_active_menu.erase(_list_current_active_menu.begin() + idx);
	}
}

void MenuManager::PushMenuToTop(MENU_LAYER layer)
{
	int idx_contain = -1;
	for (size_t i = 0; i < _list_current_active_menu.size(); i++)
	{
		if (_list_current_active_menu.at(i) == layer)
		{
			idx_contain = i;
			break;
		}
	}

	if (idx_contain == -1)
		return;

	//remove in stack
	_list_current_active_menu.erase(_list_current_active_menu.begin() + idx_contain);

	//add to top of stack
	_list_current_active_menu.insert(_list_current_active_menu.begin(), layer);
}

BaseMenu*  MenuManager::GetCurrentMenuUI()
{
	if (_list_current_active_menu.size() > 0)
	{
		return GetMenuUI(_list_current_active_menu[0]);
	}
	else
	{
		return nullptr;
	}
}

MENU_LAYER MenuManager::GetCurrentMenuUI(int idx)
{
	if (_list_current_active_menu.size() > 0)
	{
		if ((size_t)idx < _list_current_active_menu.size())
		{
			return _list_current_active_menu.at(idx);
		}
		else
		{
			PASSERT2((size_t)idx < _list_current_active_menu.size(), "idx out of layer stack");
			return _list_current_active_menu.at(0);
		}

	}
	else
	{
		return MENU_LAYER::MENU_NONE;
	}
}

void MenuManager::RegisterMenuUI()
{
	s_factory_menu_entity.RegisterProduct<LoadingMenu>(MENU_LAYER::LOADING_MENU);
	s_factory_menu_entity.RegisterProduct<CommonMenu>(MENU_LAYER::COMMON_MENU);
	s_factory_menu_entity.RegisterProduct<MainMenu>(MENU_LAYER::MAIN_MENU);
}

BaseMenu * MenuManager::GetMenuUI(MENU_LAYER name)
{
	if (_list_menu.size() > 0 && _list_menu.find(name) != _list_menu.end())
	{
		return _list_menu.at(name);
	}
	return nullptr;
}

void MenuManager::OnShowDialog(
	const RKString & title ,
	const RKString & str ,
	TYPE_DIALOG type ,
	const std::function<void(const char * str, const char* btn_name)> & func,
	const std::function<void(const char * str, const char* btn_name)> & func1,
	const std::function<void(const char * str, const char* btn_name)> & func2, 
	const RKString & title_1 ,
	const RKString & title_2 )
{

	static_cast<CommonMenu*>(_common_menu)->OnShowDialog(
		title,
		str,
		type,
		func,
		func1,
		func2,
		title_1,
		title_2);
}

void MenuManager::OnShowWaitingDialog()
{
	OnShowDialog("notice", "please_wait", TYPE_DIALOG::DIALOG_WAITING_BUTTON);
}

void MenuManager::OnShowErrorDialog(const RKString &  msg)
{
	OnShowDialog("error", msg, TYPE_DIALOG::DIALOG_ONE_BUTTON  , nullptr, nullptr, nullptr, "ok");
}

void MenuManager::OnShowOKDialog(const RKString &  msg)
{
	OnShowDialog("notice", msg, TYPE_DIALOG::DIALOG_ONE_BUTTON  , nullptr, nullptr, nullptr, "ok");
}

void MenuManager::OnHideDialog()
{
	static_cast<CommonMenu*>(_common_menu)->OnHideDialog();
}

bool MenuManager::ChangeLanguage(LANGUAGE_TYPE lang)
{
	RKString name_lang = XMLMgr->GetLangDecByType(lang)->name_id;

	bool result = LangMgr->SetNewLanguage(lang);
	if (result)
	{
		for (auto it = _list_menu.begin(); it != _list_menu.end(); it++)
		{
			it->second->onLanguageChanged(lang);
		}
	}
	return result;
}

int MenuManager::GetStateLoading()
{
	return static_cast<LoadingMenu*>(GetMenuUI(MENU_LAYER::LOADING_MENU))->GetStateLoading();
}

void MenuManager::SetStateLoading(int state)
{
	static_cast<LoadingMenu*>(GetMenuUI(MENU_LAYER::LOADING_MENU))->SetStateLoading(state);
}

void MenuManager::setHaveBackkey()
{
	/*if (Platform::isWebviewShow())
	{
		Platform::closeWebview();
	}
	else
	{
		if (GetCommonScr->HaveAnyLayerShow())
		{
			this->PushEvent([this]() {
				GetCommonScr->OnKeyBack();
			});
		}
		else
		{
			this->PushEvent([this]() {
				this->GetMenuUI(GetCurrentMenuUI())->OnKeyBack();
			});
		}
	}*/
}

void MenuManager::SaveDataInt(RKString name, int data)
{
	File::SaveMgr->GetDataSave()->SetIntByName(name, data);
}

bool  MenuManager::GetDataSaveInt(RKString name, int & result)
{
	return File::SaveMgr->GetDataSave()->GetIntByName(name, result);
}

bool MenuManager::RemoveDataSaveInt(RKString name)
{
	return File::SaveMgr->GetDataSave()->RemoveIntByName(name);
}

void MenuManager::SaveDataFloat(RKString name, float data)
{
	File::SaveMgr->GetDataSave()->SetFloatByName(name, data);
}

bool MenuManager::GetDataSaveFloat(RKString name , float & result)
{
	return File::SaveMgr->GetDataSave()->GetFloatByName(name , result);
}

bool MenuManager::RemoveDataSaveFloat(RKString name)
{
	return File::SaveMgr->GetDataSave()->RemoveFloatByName(name);
}

void MenuManager::SaveDataString(RKString name, RKString data)
{
	File::SaveMgr->GetDataSave()->SetCharByName(name, data);
}

bool MenuManager::GetDataSaveString(RKString name , RKString & result)
{
	return File::SaveMgr->GetDataSave()->GetCharByName(name , result);
}

bool MenuManager::RemoveDataSaveString(RKString name)
{
	return File::SaveMgr->GetDataSave()->RemoveCharByName(name);
}

void MenuManager::SaveTheGame(RKString name_save)
{
	File::SaveMgr->SaveTheGameSave(name_save);
}

const std::vector<int> & MenuManager::GetTableScreenLoad()
{
	return _table_menu_load;
}

void MenuManager::PushEvent(const std::function<void(void)> & func)
{
  //  p_list_event.push_back(func);
}

BaseMenu * MenuManager::GetCommonMenu()
{
	return _common_menu;
}
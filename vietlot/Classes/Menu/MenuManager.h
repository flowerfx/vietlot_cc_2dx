#ifndef __MENU_MANAGER_H__
#define __MENU_MANAGER_H__

#include "BaseMenu.h"
#include "MainGame.h"
#include "Factory.h"
#include "cocos2d.h"


class MenuManager
{
private:
	//
	bool p_IsPopUpAppear;
	//menu list
	//for loading menu
	std::vector<int>						_table_menu_load;
	//current active menu
	std::vector<MENU_LAYER>					_list_current_active_menu;
	//current list menu handle
	std::map<MENU_LAYER, BaseMenu*>			_list_menu;
	//factory
	Factory::FactoryWithIndex<BaseMenu>		s_factory_menu_entity;
	
	//create a weak pointer to handle common screen
	//BaseScreen*	  p_common_screen;
protected:

	void SetActiveUI(MENU_LAYER layer, int idx = -1);
	void DeActiveUI(MENU_LAYER layer);
	void RegisterMenuUI();
	void LoadTextureAsGame(int id_game);
public:
	//load game list xml
	void LoadXMLListGame(TiXmlDocument * p_objectXML);
 
    void PushEvent(const std::function<void(void)> & func);
public:
	MenuManager();
	virtual ~MenuManager();

	MENU_LAYER GetCurrentMenuUI(int idx = 0);
	BaseMenu*  GetCurrentMenuUI();

	void  SwitchToMenu(MENU_LAYER target_menu, MENU_LAYER from_menu = MENU_LAYER::MENU_NONE);
	void  CloseCurrentMenu(MENU_LAYER m);
    void  ShowCurrentMenu(MENU_LAYER m, int idx =-1);

	BaseMenu* GetMenuUI(MENU_LAYER name);


	int		Init();
	int		InitDetailScreen(MENU_LAYER id_screen);

	void	Update(float dt);

	//call popup from menu mgr
	void OnShowDialog(
		const RKString & title = "", 
		const RKString & str = "",
					  TYPE_DIALOG type = (TYPE_DIALOG)0, 
					  const std::function<void(const char * str, const char* btn_name)> & func = nullptr,
					  const std::function<void(const char * str, const char* btn_name)> & func1 = nullptr,
					  const std::function<void(const char * str, const char* btn_name)> & func2 = nullptr,
		const RKString & title_1 = "",
		const RKString & title_2 = "");

	void OnShowWaitingDialog();
	void OnShowErrorDialog(const RKString &  msg);
	void OnShowOKDialog(const RKString &  msg);
	void OnHideDialog();

	void PushMenuToTop(MENU_LAYER layer);
	//change language all menu
	bool ChangeLanguage(LANGUAGE_TYPE lang);
	//state loading
	int GetStateLoading();
	void SetStateLoading(int state);



	void SaveDataInt(RKString name, int data);
	bool GetDataSaveInt(RKString name, int &result);
	bool RemoveDataSaveInt(RKString name);
	void SaveDataFloat(RKString name, float data);
	bool GetDataSaveFloat(RKString name , float &result);
	bool RemoveDataSaveFloat(RKString name);
	void SaveDataString(RKString name, RKString data);
	bool GetDataSaveString(RKString name , RKString & result);
	bool RemoveDataSaveString(RKString name);

	void SaveTheGame(RKString name_save = SAVE_NAME);


	const std::vector<int> & GetTableScreenLoad();

public:

	//happen when have backkey
	void setHaveBackkey();

	
};

#define ScrMgr ScreenManager::GetInstance()
#define GetCommonScr static_cast<CommonScreen*>(ScreenManager::GetInstance()->GetCommonScreen())

#endif //__MENU_MANAGER_H__


#include "MainMenu.h"


MainMenu::MainMenu()
{
	_menu_type = MAIN_MENU;
}

MainMenu::~MainMenu()
{
	
}

int MainMenu::Init()
{
	//override the list view table default with the iwinlistview table
	//
	RKString _menu = "main_menu";
	InitMenuWidgetEntity(_menu);
	InitComponent();
	return 1;
}



int	MainMenu::InitComponent()
{
	return 1;
}



int MainMenu::Update(float dt)
{
	if (BaseMenu::Update(dt) == 0)
	{
		return 0;
	}

	return 1;
}


void MainMenu::OnProcessWidgetChild(const RKString & name, UI_TYPE type_widget, WidgetEntity * _widget)
{

}

void MainMenu::OnDeactiveCurrentMenu()
{
	
	MenuMgr->CloseCurrentMenu(_menu_type);
	_menu_show_next = MENU_NONE;
}

#ifndef __MAIN_MENU_H__
#define __MAIN_MENU_H__

#include "MenuManager.h"


class MainMenu : public BaseMenu
{

public:
	MainMenu();
	virtual ~MainMenu();

	virtual  int	Init()																	override;
	virtual  int	InitComponent()															override;
	virtual  int	Update(float dt)														override;

	virtual void	OnProcessWidgetChild(const RKString & name, UI_TYPE type_widget, WidgetEntity * _widget)override;
	virtual void	OnDeactiveCurrentMenu()													override;
	
};

#endif //__COMMON_SCREEN_H__

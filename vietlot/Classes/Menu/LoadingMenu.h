#ifndef __LOADING_MENU_H__
#define __LOADING_MENU_H__


#include "MenuManager.h"

namespace RKUtils
{
	class ThreadWrapper;
}

class LoadingMenu : public BaseMenu
{
private:
	int _current_state_loading;
	int _state_load_resource;
private:
	ThreadWrapper *		_thread_load_xml;
	bool				_finish_load_xml;
	int					_state_load;

	void				StartThreadLoadXML();
public:
	LoadingMenu();
	virtual ~LoadingMenu();

	virtual  int	Init()																	override;
	virtual  int	InitComponent()															override;
	virtual  int	Update(float dt)														override;

	virtual void OnProcessWidgetChild(const RKString & name, UI_TYPE type_widget, WidgetEntity * _widget)override;
	virtual void OnDeactiveCurrentMenu()													override;
 
	int GetStateLoading();
	void SetStateLoading(int state);
    
    void LoadXMLFile();

};

#endif //__LOADING_MENU_H__


#ifndef __BASE_MENU_H__
#define __BASE_MENU_H__

#include "UI/Menu.h"
#include "Utils.h"
using namespace RKUtils;
using namespace Utility;
using namespace Utility::UI_Widget;

enum TYPE_DIALOG
{
	DIALOG_NONE = 0,
	DIALOG_ONE_BUTTON,
	DIALOG_TWO_BUTTON,
	DIALOG_ZERO_BUTTON,
	DIALOG_LOGOUT_ACC,
	DIALOG_WAITING_BUTTON,
	DIALOG_ZERO_BUTTON_WAIT,
	DIALOG_COUNT
};

enum MENU_LAYER
{
	MENU_NONE = 0,

	LOADING_MENU,

	MENU_COUNT
};
class BaseMenu;
#define TIME_ACTION 0.5f
struct EventQueue
{
    std::function<void(BaseMenu* scr)> event_action;
    float time_action;
	bool isDone;
public:
    EventQueue()
    {
        event_action = nullptr;
        time_action = 0.f;
		isDone = false;
    }
    EventQueue(const std::function<void(BaseMenu* scr)> & action, float time)
    {
        event_action = action;
        time_action = time;
		isDone = false;
    }
    virtual ~EventQueue()
    {
        event_action = nullptr;
        time_action = 0.f;
    }
    
};

class BaseMenu : public MenuEntity
{
protected:

	MENU_LAYER				_menu_come_from; 
    MENU_LAYER				_menu_show_next;

	//event queue in game
	std::vector<EventQueue>	_list_event;

public:
	BaseMenu();
	virtual ~BaseMenu();

	virtual  int	Init();
	virtual  int	InitComponent();
	virtual  int	Update(float dt) override;
	virtual void	VisitMenu(Renderer *renderer, const Mat4& transform, uint32_t flags)	override;
	virtual void	DrawMenu(Renderer *renderer, const Mat4& transform, uint32_t flags)		override;
	virtual void	OnFinishFadeAtCurrentIdx(int idx, STATUS_MENU status)					override;

	virtual void	OnDeactiveCurrentMenu() override;
	virtual void	OnBeginFadeIn()			override;
	virtual void	OnFadeInComplete()		override;

	
	void SetMenuComFrom(MENU_LAYER menu){ _menu_come_from = menu; }
	MENU_LAYER GetMenuComeFrom() { return _menu_come_from; }
    
    void SetMenuShowNext(MENU_LAYER menu) {_menu_show_next = menu; }
    MENU_LAYER GetMenuShowNext() { return _menu_show_next; }

	void OnCallBackProcess(const RKString & str);
	virtual void OnProcess(const RKString & str);

	virtual void CheckTouchOutSideWidget(const cocos2d::Point & p, WidgetEntity * panel, const std::function<void(void)> & func);

	virtual void ClearComponent();
	virtual void OnKeyBack();

	//for the event
	void PushEvent(const std::function<void(BaseMenu* scr)> & event_action, float time=0.f );

protected:

	void HandleEvent(float dt);
};

#endif //__BASE_MENU_H__


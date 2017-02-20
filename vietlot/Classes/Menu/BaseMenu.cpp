#include "BaseMenu.h"
#include "RKThread_Code/RKThreadWrapper.h"
#include "MainGame.h"

BaseMenu::BaseMenu()
{
	_menu_come_from = MENU_LAYER::MENU_NONE;
    _menu_show_next= MENU_LAYER::MENU_NONE;

	_list_event.clear();

}

BaseMenu::~BaseMenu()
{
	_list_event.clear();
}

int BaseMenu::Init()
{
	return 1;
}

int	BaseMenu::InitComponent()
{
	return 1;
}



int BaseMenu::Update(float dt)
{

	if (p_IsStopUpdate)
	{
		return 0;
	}

	MenuEntity::onUpdateMenuWidget(dt);

	HandleEvent(dt);

	return 1;
}

void BaseMenu::VisitMenu(Renderer *renderer, const Mat4& transform, uint32_t flags)
{
	onVisitMenuWidget(renderer, transform, flags);
}

void BaseMenu::DrawMenu(Renderer *renderer, const Mat4& transform, uint32_t flags)
{
	onDrawMenuWidget(renderer, transform, flags);
}

void BaseMenu::OnFinishFadeAtCurrentIdx(int idx, STATUS_MENU status)
{
	OnAllProcessFinishFadeIdx(idx, p_max_idx_process_first, status);
}


void BaseMenu::OnDeactiveCurrentMenu()
{
	
}


void BaseMenu::OnBeginFadeIn()
{

}

void BaseMenu::OnFadeInComplete()
{

}


void BaseMenu::OnCallBackProcess(const RKString & str)
{
	OnProcess(str);
}

void BaseMenu::OnProcess(const RKString & str)
{
	//abstract class not handle this function
}



void BaseMenu::CheckTouchOutSideWidget(const cocos2d::Point & p, WidgetEntity * panel, const std::function<void(void)> & func)
{
	if (panel->Visible())
	{
        ActionProcess * ac = panel->GetParentWidget();
        if(ac == nullptr)
        {
            ac = panel->GetParentLayer();
            PASSERT2(ac != nullptr , "the layer parent is null, check the code again !");
        }
        
		Vec2 world_pos = ac->GetResource()->convertToWorldSpace(panel->GetPosition_Middle());
		cocos2d::Rect rect_panel_ =
			cocos2d::Rect(
				world_pos.x - panel->GetSize().x / 2,
				world_pos.y - panel->GetSize().y / 2,
				panel->GetSize().x, panel->GetSize().y);
		if (!rect_panel_.containsPoint(p))
		{
			func();
		}
	}
}

void BaseMenu::ClearComponent()
{
	//abstrast class not handle this function
}

void BaseMenu::OnKeyBack()
{
	
}

void BaseMenu::HandleEvent(float dt)
{
	if (_list_event.size() > 0)
	{
        float time = _list_event[0].time_action;
        time-= dt;
        _list_event[0].time_action = time;
        if(time <= 0)
        {
			_list_event[0].event_action(this);
			_list_event.erase(_list_event.begin());
        }
	}
}

void BaseMenu::PushEvent(const std::function<void(BaseMenu* scr)> & event_action, float time)
{
	_list_event.push_back(EventQueue(event_action, time));	
}
#include "CommonMenu.h"

#include "CommonMenu/TopLayer.h"

CommonMenu::CommonMenu()
{
	_menu_type = COMMON_MENU;
	_screen_come_from = nullptr;
	_list_common_layer.clear();
}

CommonMenu::~CommonMenu()
{
	_screen_come_from = nullptr;

	SAFE_DELETE_MAP(_list_common_layer)
}

int CommonMenu::Init()
{
	//override the list view table default with the iwinlistview table
	//
	RKString _menu = "common_menu";
	InitMenuWidgetEntity(_menu);
	InitComponent();
	return 1;
}

void CommonMenu::RegisterCommonLayer()
{
	//_facetory_common_layer.RegisterProduct<DialogLayer>(COMMON_LAYER::DIALOG_LAYER);
	_facetory_common_layer.RegisterProduct<TopLayer>(COMMON_LAYER::TOP_LAYER);
}

int	CommonMenu::InitComponent()
{
	//
	p_IdxMenuData = 0;
	RegisterCommonLayer();
	//create and init list layer common
	for (int i = COMMON_LAYER::DIALOG_LAYER; i < COMMON_LAYER::LAYER_COUNT; i++)
	{
		auto val = _facetory_common_layer.CreateNewProduct((COMMON_LAYER)i);
		if (val)
		{
			val->InitLayer(this);
			_list_common_layer.insert({ (COMMON_LAYER)i , val });
		}
	}
	

	return 1;
}

CommonLayer* CommonMenu::GetLayer(COMMON_LAYER layer)
{
	if (_list_common_layer.find(layer) != _list_common_layer.end())
	{
		return _list_common_layer.at(layer);
	}
	return nullptr;
}

int CommonMenu::Update(float dt)
{
	if (BaseMenu::Update(dt) == 0)
	{
		return 0;
	}

	for (auto it : _list_common_layer)
	{
		it.second->Update(dt);
	}

	return 1;
}


void CommonMenu::OnProcessWidgetChild(const RKString & name, UI_TYPE type_widget, WidgetEntity * _widget)
{
	for (auto it : _list_common_layer)
	{
		bool res = it.second->ProcessWidget(name, type_widget, _widget);
		if (res)
		{
			return;
		}
	}
}

void CommonMenu::OnDeactiveCurrentMenu()
{
	PASSERT2(false, "this is the specific screen that always show on top screen and not list in the list screen UI of screen manager");
	return;

	MenuMgr->CloseCurrentMenu(_menu_type);
	_menu_show_next = MENU_NONE;
}


void CommonMenu::OnTouchMenuBegin(const cocos2d::Point & p)
{
	//static_cast<LeaderboardLayer*>(GetLayer(LEADERBOARD_LAYER))->LB_OnTouchMenuBegin(p);

	//static_cast<EmoBoardLayer*>(GetLayer(EMOTION_LAYER))->CheckTouchMenuBegin(p);
}

//common layer
void CommonMenu::OnShowLayer(COMMON_LAYER layer)
{
	//confirm code
	//change pass layer
	//tutorial
	//lucky circle
	//emotion board
	GetLayer(layer)->OnShowLayer();
}

void CommonMenu::OnHideLayer(COMMON_LAYER layer)
{
	//emotion board
	//invite layer
	GetLayer(layer)->OnHideLayer();
}

bool CommonMenu::IsLayerVisible(COMMON_LAYER layer)
{
	return GetLayer(layer)->IsVisibleLayer();
}
//call popup method
void CommonMenu::OnShowDialog(
	const RKString & str_title,
	const RKString & str_message,
	TYPE_DIALOG type,
	const std::function<void(const char *, const char*)> & func,
	const std::function<void(const char *, const char*)> & func1,
	const std::function<void(const char *, const char*)> & func2,
	const RKString & title_btn_0,
	const RKString & title_btn_1
)
{
	//return static_cast<DialogLayer*>(GetLayer(DIALOG_LAYER))->OnShowDialog(
	//	str_title,
	//	str_message,
	//	type,
	//	strCB,
	//	func,
	//	func1,
	//	func2,
	//	title_btn_0,
	//	title_btn_1
	//	);
}


void CommonMenu::OnHideDialog()
{
	//return static_cast<DialogLayer*>(GetLayer(DIALOG_LAYER))->OnHideDialog();
}

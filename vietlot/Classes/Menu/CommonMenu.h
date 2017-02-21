#ifndef __COMMON_MENU_H__
#define __COMMON_MENU_H__

#include "MenuManager.h"


using namespace RKUtils;
using namespace Utility;
using namespace Utility::UI_Widget;
class CommonLayer;

enum COMMON_LAYER
{
	LAYER_NONE = 0,
	DIALOG_LAYER,
	TOP_LAYER,
	LAYER_COUNT
};


class CommonMenu : public BaseMenu
{
private:
	std::map<COMMON_LAYER , CommonLayer*>	_list_common_layer;
	BaseMenu *								_screen_come_from;
	Factory::FactoryWithIndex<CommonLayer>	_facetory_common_layer;
protected:
	void RegisterCommonLayer();
public:
	CommonMenu();
	virtual ~CommonMenu();

	virtual  int	Init()																	override;
	virtual  int	InitComponent()															override;
	virtual  int	Update(float dt)														override;

	virtual void	OnProcessWidgetChild(const RKString & name, UI_TYPE type_widget, WidgetEntity * _widget)override;
	virtual void	OnDeactiveCurrentMenu()													override;
	virtual void	OnTouchMenuBegin(const cocos2d::Point & p)								override;

	CommonLayer*	GetLayer(COMMON_LAYER layer);
public:
	//show general common layer
	void OnShowLayer(COMMON_LAYER layer);
	//hide
	void OnHideLayer(COMMON_LAYER layer);
	//
	bool IsLayerVisible(COMMON_LAYER layer);

	
	//dialog layer
	void OnShowDialog(
		const RKString & str_title = "",
		const RKString & str_message = "",
		TYPE_DIALOG type = TYPE_DIALOG::DIALOG_NONE,
		const std::function<void(const char * call_back, const char* btn_name)> & func = nullptr,
		const std::function<void(const char * call_back, const char* btn_name)> & func1 = nullptr,
		const std::function<void(const char * call_back, const char* btn_name)> & func2 = nullptr,
		const RKString & title_btn_0 = "",
		const RKString & title_btn_1 = ""
	);
	void OnHideDialog();
};

#endif //__COMMON_SCREEN_H__

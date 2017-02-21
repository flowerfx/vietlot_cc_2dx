#ifndef __COMMON_LAYER_H__
#define __COMMON_LAYER_H__

#include "BaseMenu.h"

using namespace Utility;
using namespace Utility::UI_Widget;


class CommonLayer
{
protected:
	BaseMenu * _base_screen;
public:
	CommonLayer();
	virtual ~CommonLayer();
	virtual bool ProcessWidget(const RKString & name, UI_TYPE type_widget, WidgetEntity * _widget);
	virtual void InitLayer(BaseMenu * screen);
	virtual int Update(float dt);
	virtual void OnShowLayer(const std::function<void(void)> & call_back = nullptr);
	virtual void OnHideLayer(const std::function<void(void)> & call_back = nullptr);
	virtual bool IsVisibleLayer() { return false; }
	virtual void Reset();
};

#endif //__INVITE_LAYER_H__


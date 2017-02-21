#ifndef __TOP_LAYER_H__
#define __TOP_LAYER_H__

#include "Menu/CommonLayer.h"

class TopLayer : public CommonLayer
{
public:
	TopLayer();
	virtual ~TopLayer();
private:
	WidgetEntity * _main_layer;

public:
	virtual void InitLayer(BaseMenu * screen)		override;
	virtual bool ProcessWidget(const RKString & name, UI_TYPE type_widget, WidgetEntity * _widget) override;
	virtual void OnShowLayer(const std::function<void(void)> & call_back = nullptr) override;
	virtual int  Update(float dt) override;
	virtual bool IsVisibleLayer() override;
	virtual void OnHideLayer(const std::function<void(void)> & call_back = nullptr) override;
};

#endif //__TOP_LAYER_H__


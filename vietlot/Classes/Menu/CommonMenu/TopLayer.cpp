#include "TopLayer.h"

TopLayer::TopLayer()
{
	
}

TopLayer::~TopLayer()
{

}

int TopLayer::Update(float dt)
{
	if (!_main_layer->Visible())
		return 0;

	return 1;
}

bool TopLayer::ProcessWidget(const RKString & name, UI_TYPE type_widget, WidgetEntity * _widget)
{
	if (!IsVisibleLayer())
		return false;

	if (type_widget == UI_TYPE::UI_BUTTON)
	{
		if (name == "btn_agree_invite")
		{
			
			return true;
		}
		
	}

	return false;
}

void TopLayer::InitLayer(BaseMenu * screen)
{
	CommonLayer::InitLayer(screen);

	_main_layer = screen->GetWidgetChildByName("common_menu.top_layer");
}

void TopLayer::OnShowLayer(const std::function<void(void)> & call_back)
{
	_main_layer->Visible(true);
}

bool TopLayer::IsVisibleLayer()
{
	if (_main_layer)
	{
		return _main_layer->Visible();
	}
	return false;
}

void TopLayer::OnHideLayer(const std::function<void(void)> & call_back)
{
	_main_layer->Visible(false);
}


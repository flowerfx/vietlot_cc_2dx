#ifndef __ACTION_PROCESS_H__
#define __ACTION_PROCESS_H__

#include "../DisplayView.h"
#include "../ObjectTexture.h"

#include "extensions/cocos-ext.h"
#include "ui/CocosGUI.h"

#include "ActionCommand.h"
using namespace RKUtils;
using namespace ui;
namespace Utility
{
	namespace UI_Widget
	{
		enum STATUS_MENU
		{
			M_IDLE = 0,
			M_FADEIN,
			M_FADEOUT
		};

		enum UI_TYPE
		{
			UI_NONE = 0,
			UI_BUTTON,
			UI_PANEL,
			UI_TEXT,
			UI_LOADING_BAR,
			UI_TEXT_FIELD,
			UI_CHECK_BOX,
			UI_SLIDER,
			UI_LISTVIEW,
			UI_SCROLLVIEW,
			UI_PAGEVIEW,
			UI_LAYOUT,
			UI_LAYER,
			UI_RADIO_BTN,
			UI_EDIT_BOX,
			UI_PANEL_CLIPPING,
			UI_TIME_PROCESS,
			UI_LIST_VIEW_TABLE,
			UI_TIME_DIGITAL,
			UI_ANIMATE,
			UI_PARTICLE,
			UI_COUNT
		};
		class MenuEntity;
		class LayerEntity;
		class WidgetEntity;
		class ActionProcess : public Ref
		{
		private:
			cocos2d::Sequence * p_action;
		protected:

			RKString	p_Name;
			UI_TYPE		p_typeUI;
			//action process in game , the fade action process with the parent element
			int p_action_process;
			int p_count_action_process; //use to know wherever all the action fade finish

			float		 p_timeAction;
			bool		 p_Visible;

			xml::BasicDec	p_origin_value;
			xml::BasicDec   p_first_value;

			//
			STATUS_MENU						p_currentStatusMenu;
            std::vector<UI_STATE_FADE_ACTION>	p_l_fd;
			//
			unsigned int					p_index_appear;

			MenuEntity *					menu_point_to;
			LayerEntity *					p_parent_layer;
			WidgetEntity*					p_parent_widget;

			std::map<RKString,ActionCommand *>	p_list_command;

			bool p_IsInteractive;
			bool p_IsStickScreen;
			int	 p_z_order;
			bool p_disable;

			int p_state_scale;
			bool p_update_when_invisible;

		protected:
            Sequence * GetSequenceActionFromList(STATUS_MENU stateFade, std::vector<UI_STATE_FADE_ACTION> l_fd, float time);
			//
			void AddActionFade(UI_STATE_FADE_ACTION fd);

			void RemoveActionFade(UI_STATE_FADE_ACTION fd);

			void ResetActionFade();

			bool ContainActionFade(UI_STATE_FADE_ACTION fd);

			virtual void SetSizeValueXML(xml::UILayerWidgetDec * xml_value);

			virtual void SetPosValueXML(xml::UILayerWidgetDec * xml_value);

			virtual void SetInitPos(xml::UILayerWidgetDec * xml_value);
			virtual void SetInitSize(xml::UILayerWidgetDec * xml_value);
			virtual void SetInitRotate(xml::UILayerWidgetDec * xml_value);

			virtual void SetCommandValueXML(xml::UILayerWidgetDec * xml_value);

			virtual void CloneThis(ActionProcess * p_clone);

		public:
            void ForceFinishAction();
            
			void SetActionFade(unsigned int fd);

            void InitSetFade(std::vector<UI_STATE_FADE_ACTION> l_fd, float time);

			RKString  GetName();

			void SetName(const RKString &  name);

			virtual cocos2d::Node * GetResource() = 0;

			virtual bool SetNewResource(cocos2d::Node * new_resource) = 0;

			virtual void InitParam(const RKString & name, xml::UILayerWidgetDec * xml_value);

			virtual bool SetActionCommandWithName(const RKString & name , CallFunc * func_callback = nullptr);

			virtual bool SetHookCommand(const RKString & name_command, const RKString & idx_act, int idx_squence, int idx_detail, const xml::BasicDec & value, const RKString & name_value);
		
			virtual bool ClearHookCommand(const RKString & name_command, const RKString & idx_act = "", int idx_squence = -1, int idx_detail = -1);

			virtual void ClearChild(int count) = 0;
		public:

#pragma region normal_method
			ActionProcess();
			virtual ~ActionProcess();
			
			virtual bool Visible();
			virtual void Visible(bool b);

			virtual void SetScale(const Vec2 & s);
			virtual Vec2 GetScale();

			virtual Vec2 GetSize();
			virtual void SetSize(const Vec2 & s);

			virtual void SetRotate(float r);
			virtual float GetRotate();

			virtual void SetPosition(const Vec2 & p);
			virtual Vec2 GetPosition();

			virtual void SetOpacity(const RKUtils::BYTE & p);
			virtual const RKUtils::BYTE & GetOpacity();

			virtual void SetColor(const Color3B & p);
			virtual Color3B GetColor();

			unsigned int GetIndexAppear();
			void SetIndexAppear(unsigned int idx);

			const Vec2   GetOriginPos();
			const Vec2   GetFirstPos();
			void SetFirstPos(const Vec2 & p, bool force = true);
			//
			float GetOriginAngle();
			float GetFirstAngle();
			void SetFirstAngle(float p, bool force = true);
			//
			const RKUtils::BYTE  GetOriginAlpha();
			void SetOriginAlpha(const RKUtils::BYTE & p, bool force = false);
			const RKUtils::BYTE  GetFirstAlpha();
			void SetFirstAlpha(const RKUtils::BYTE & p, bool force = true);
			//
			const Color3B  GetOriginColor();
			void SetOriginColor(const Color3B & p, bool force = false);
			const Color3B  GetFirstColor();
			void SetFirstColor(const Color3B & p, bool force = true);
			//
			float GetOriginScale();
			float GetFirstScale();
			void SetFirstSize(const Vec2 & p, bool force = true);
			void SetFirstScale(float p, bool force = true);
			//
			virtual Vec2 GetAnchorPoint();
			virtual void SetAnchorPoint(const Vec2 & p);
			//
			virtual void Draw(Renderer *renderer, const Mat4& transform, uint32_t flags);
			virtual void Visit(Renderer *renderer, const Mat4& transform, uint32_t flags);

			virtual bool Update(float dt) = 0;

			LayerEntity *	GetParentLayer();
			WidgetEntity *	GetParentWidget();
			MenuEntity *	GetMenuParent();

			void			SetParentLayer(LayerEntity * parent);
			void			SetMenuParent(MenuEntity * menu);
			void			SetParentWidget(WidgetEntity * widget);

			UI_TYPE getUIWidgetType();

#pragma endregion normal_method

#pragma region action_process_method
			bool SetActionProcess(const STATUS_MENU & stateFade, bool force_only = false);

			void ActionProcessFinish(const UI_STATE_FADE_ACTION & current_fd);
			void SetResourceRunAction(const UI_STATE_FADE_ACTION & action, int loop, bool reserve, float time = 0.f);
			void SetResourceRunManyAction(const std::vector<Vector<FiniteTimeAction*>> & list_action_);

			Vector<FiniteTimeAction*> CreateListActionFromSingleAction(const UI_STATE_FADE_ACTION & action, int loop, bool reserve, float time = 0.f);

			Sequence * CreateActionFromList(const Vector<ActionInterval*> & list_action);

			bool HaveActionNotFade();

			bool UpdateActionProcess(float dt);

			void RemoveActionByTag(bool IsAll = false);
#pragma endregion action_process_method

			virtual void SetValueFromXML(xml::UILayerWidgetDec * xml_value);

			virtual void SetFirstValueXML(xml::UILayerWidgetDec * xml_value);

			void ResetSizeAndPos(int cur_width, int cur_height);

			virtual void FinishRunAction();
			virtual bool IsAllChildFinishAction();

			virtual void SetInteractive(bool value);
			virtual bool IsInteractive();

			virtual void SetDisable(bool value);
			virtual bool IsDisable();

			virtual void ReloadText();
			Vec2 PositionWithVectorUnit(const Vec2 & vec_unit);

			const Vec2  GetPosition_TopLeft();
			const Vec2  GetPosition_TopRight();
			const Vec2  GetPosition_BottomLeft();
			const Vec2  GetPosition_BottomRight();
			const Vec2  GetPosition_Middle();

			cocos2d::Rect GetBound();
		};
	}
}

#endif //__ACTION_PROCESS_H__


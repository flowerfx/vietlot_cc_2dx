LOCAL_PATH := $(call my-dir)

LOCAL_SHORT_COMMANDS := true

include $(CLEAR_VARS)

LOCAL_MODULE := utility_static

LOCAL_MODULE_FILENAME := libutility 

LOCAL_SRC_FILES := \
./Code/DisplayView.cpp \
./Code/FileManager.cpp \
./Code/InputManager.cpp \
./Code/LanguageMgr.cpp \
./Code/LoadDataXML.cpp \
./Code/ObjectTexture.cpp \
./Code/SoundManager.cpp \
./Code/wTool.cpp \
./Code/Background/BGObject.cpp \
./Code/Background/ObjectBGEntity.cpp \
./Code/FXFlatform/XFlatform.cpp \
./Code/Object/wObject.cpp \
./Code/Social/SocialManager.cpp \
./Code/Social/Downloader/DownloadHandler.cpp \
./Code/Social/GameCenter/GameCenterController.cpp \
./Code/UI/ActionCommand.cpp \
./Code/UI/ActionProcess.cpp \
./Code/UI/LayerEntity.cpp \
./Code/UI/Menu.cpp \
./Code/UI/wAnimationWidget.cpp \
./Code/UI/wButton.cpp \
./Code/UI/wCheckBox.cpp \
./Code/UI/wEditBox.cpp \
./Code/UI/WidgetEntity.cpp \
./Code/UI/wLayout.cpp \
./Code/UI/wListView.cpp \
./Code/UI/wListViewTable.cpp \
./Code/UI/wLoadingBar.cpp \
./Code/UI/wPageView.cpp \
./Code/UI/wPanel.cpp \
./Code/UI/wPanelClipping.cpp \
./Code/UI/wParticle.cpp \
./Code/UI/wRadioBtn.cpp \
./Code/UI/wScrollView.cpp \
./Code/UI/wSlider.cpp \
./Code/UI/wText.cpp \
./Code/UI/wTextField.cpp \
./Code/UI/wTimeDigitalWidget.cpp \
./Code/UI/wTimeProcessWidget.cpp \
./../json/source/json_writer.cpp \
./../json/source/json_value.cpp \
./../json/source/json_reader.cpp 

LOCAL_CFLAGS   :=  -DOS_ANDROID_ -DGAME_ANDROID
LOCAL_EXPORT_CFLAGS   :=  -DOS_ANDROID_ -DGAME_ANDROID
LOCAL_CPPFLAGS += -fexceptions
LOCAL_EXPORT_C_INCLUDES := $(LOCAL_PATH)/Code

LOCAL_C_INCLUDES := $(LOCAL_PATH)/Code
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../json/include
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../RKUtils/Code
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../cocos2dx-lib
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../cocos2dx-lib/cocos
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../cocos2dx-lib/cocos/editor-support 
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../cocos2dx-lib/external
include $(BUILD_STATIC_LIBRARY)
LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

$(call import-add-path,$(LOCAL_PATH)/../../../cocos2dx-lib)
$(call import-add-path,$(LOCAL_PATH)/../../../cocos2dx-lib/external)
$(call import-add-path,$(LOCAL_PATH)/../../../cocos2dx-lib/cocos)
$(call import-add-path,$(LOCAL_PATH)/../../../lib)
$(call import-add-path,$(LOCAL_PATH)/sdkboxlib)

LOCAL_MODULE := cocos2dcpp_shared

LOCAL_MODULE_FILENAME := libcocos2dcpp

LOCAL_SRC_FILES := \
./Classes/MainGame.cpp \
./Classes/AppDelegate.cpp \
hellocpp/sqlite3.c \
#hellocpp/Java_org_cocos2dx_cpp_IwinIapHelper.cpp \
#hellocpp/Java_org_cocos2dx_cpp_AndroidPlatform.cpp \
hellocpp/main.cpp 


LOCAL_C_INCLUDES := $(LOCAL_PATH)/Classes
LOCAL_C_INCLUDES += $(LOCAL_PATH)/hellocpp
LOCAL_C_INCLUDES += $(LOCAL_PATH)/sdkboxlib

# _COCOS_HEADER_ANDROID_BEGIN
# _COCOS_HEADER_ANDROID_END

LOCAL_WHOLE_STATIC_LIBRARIES := PluginFacebook sdkbox PluginSdkboxPlay

LOCAL_STATIC_LIBRARIES := cocos2dx_static
LOCAL_STATIC_LIBRARIES += utility_static
LOCAL_STATIC_LIBRARIES += rkutils_static


# _COCOS_LIB_ANDROID_BEGIN
# _COCOS_LIB_ANDROID_END

include $(BUILD_SHARED_LIBRARY)

$(call import-module,.)
$(call import-module,Utility)
$(call import-module,RKUtils)
#$(call import-module,sdkbox)
#$(call import-module,pluginfacebook)
#$(call import-module,pluginsdkboxplay)


# _COCOS_LIB_IMPORT_ANDROID_BEGIN
# _COCOS_LIB_IMPORT_ANDROID_END
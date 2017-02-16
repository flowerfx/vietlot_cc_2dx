@echo off

 set NDK_ROOT=C:\Users\qchie\AppData\Local\Android\sdk\ndk-bundle
 set ANT_ROOT=D:\soft\android\apache-ant-1.9.6\bin\
 set ANDROID_SDK_ROOT=C:\Users\qchie\AppData\Local\Android\sdk

cls

 xcopy .\..\iwin\Classes .\app\jni\Classes\ /Y/S

cocos compile -m release -p android --android-studio --app-abi armeabi-v7a

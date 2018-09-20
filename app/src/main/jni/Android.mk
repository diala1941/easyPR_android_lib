LOCAL_PATH := $(call my-dir)
include $(CLEAR_VARS)

# OpenCV
OPENCV_CAMERA_MODULES:=on
OPENCV_INSTALL_MODULES:=on
include ../../../../OpenCV-android-sdk/sdk/native/jni/OpenCV.mk

FILE_LIST  :=$(wildcard $(LOCAL_PATH)/src/*/*.cpp)
FILE_LIST  +=$(wildcard $(LOCAL_PATH)/thirdparty/*/*.cpp)
LOCAL_SRC_FILES  :=$(LOCAL_PATH)/main.cpp
LOCAL_SRC_FILES += $(FILE_LIST:$(LOCAL_PATH)/%=%)

LOCAL_C_INCLUDES += $(LOCAL_PATH)
LOCAL_C_INCLUDES += $(LOCAL_PATH)/include
LOCAL_C_INCLUDES += $(LOCAL_PATH)/thirdparty

LOCAL_MODULE     := EasyPR
LOCAL_LDLIBS += -llog
LOCAL_ARM_MODE := arm

include $(BUILD_SHARED_LIBRARY)  


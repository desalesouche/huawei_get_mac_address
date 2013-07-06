# Hack for build
$(shell mkdir -p $(OUT)/obj/SHARED_LIBRARIES/libhwrpc_intermediates)
$(shell touch $(OUT)/obj/SHARED_LIBRARIES/libhwrpc_intermediates/export_includes)


LOCAL_PATH:= $(call my-dir)
include $(CLEAR_VARS)
LOCAL_SRC_FILES := readmac.c
LOCAL_MODULE:= libreadmac
LOCAL_SHARED_LIBRARIES := libcutils libc libhwrpc
LOCAL_MODULE_TAGS := optional

include $(BUILD_SHARED_LIBRARY)


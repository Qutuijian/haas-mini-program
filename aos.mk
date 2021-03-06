NAME := amp

$(NAME)_MBINS_TYPE := kernel
$(NAME)_VERSION := 1.0.0
$(NAME)_SUMMARY := haas amp utils

GLOBAL_CFLAGS  += -DFORCE_SSL_VERIFY

CONFIG_LIB_EXPORT ?= static

$(NAME)_INCLUDES += \
					include/ \
					./include/ \
					./adapter/include/ \
					./adapter/include/peripheral/ \

#####################################################################
$(NAME)_COMPONENTS-y := libamp_adapter
$(NAME)_COMPONENTS-y += libamp_linkkit
$(NAME)_COMPONENTS-y += libamp_ota
$(NAME)_COMPONENTS-y += libamp_http
$(NAME)_COMPONENTS-y += libamp_das
$(NAME)_COMPONENTS-y += libamp_jsengine
$(NAME)_COMPONENTS-y += libamp_main
$(NAME)_COMPONENTS-y += libamp_services
$(NAME)_COMPONENTS-y += libamp_cjson
#$(NAME)_COMPONENTS-y += libamp_ulog
#$(NAME)_COMPONENTS-y += libamp_mbedtls




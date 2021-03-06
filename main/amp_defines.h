/*
 * Copyright (C) 2015-2020 Alibaba Group Holding Limited
 */

#ifndef AMP_DEFINES_H
#define AMP_DEFINES_H

#include "amp_config.h"
#include "amp_system.h"
#include "mbedtls/md5.h"
#include "mbedtls/sha1.h"
#include "mbedtls/aes.h"
#include "mbedtls/des.h"
#include "mbedtls/base64.h"
#include "ulog.h"

typedef enum {
    HAL_SEEK_SET,
    HAL_SEEK_CUR,
    HAL_SEEK_END
} hal_fs_seek_type_t;

/* sdk version */
#define AMP_VERSION_LENGTH  128
#define AMP_VERSION_NUMBER  "1.0.0"
#define AMP_RELEASE_COMMIT  "ceff790"
#define AMP_MODULE_HARDWARE amp_get_module_hardware_version()
#define AMP_MODULE_SOFTWARE amp_get_module_software_version()

/* device infomation */
#define AMP_DEVICE_TOKEN                "_amp_device_token"
#define AMP_DEVICE_TOKEN_VERIFY_FLAG    "_amp_device_token_verify_flag"
#define AMP_DEVICE_TOKEN_LENGTH         64

#define AMP_INTERNAL_PRODUCTKEY         "_amp_internal_productkey"
#define AMP_INTERNAL_PRODUCTSECRET      "_amp_internal_productsecret"
#define AMP_INTERNAL_DEVICENAME         amp_get_device_name()

#define osWaitForever 0xFFFFFFFF /* wait forever timeout value */
#define PLATFORM_WAIT_INFINITE (~0)

/* task stack size */
#define JSENGINE_TASK_STACK_SIZE   1024 * 15

/* task priority */
#define JSE_TSK_PRIORITY        amp_get_default_task_priority() + 5
#define CLI_TSK_PRIORITY        amp_get_default_task_priority() + 7
#define MQTT_TSK_PRIORITY       amp_get_default_task_priority() + 6
#define MQTTHTTP_TSK_PRIORITY   amp_get_default_task_priority() + 4
#define SSDP_TSK_PRIORITY       amp_get_default_task_priority() + 3
#define WEBSOCKET_TSK_PRIORITY  amp_get_default_task_priority() + 4
#define WIFI_TSK_PRIORITY       amp_get_default_task_priority() + 4
#define UPDATE_TSK_PRIORITY     amp_get_default_task_priority() + 6
#define ADDON_TSK_PRIORRITY     amp_get_default_task_priority() + 3

/* log system operation wrapper */
#define amp_debug(mod, fmt, ...)     LOGD(mod, fmt, ##__VA_ARGS__)
#define amp_info(mod, fmt, ...)      LOGI(mod, fmt, ##__VA_ARGS__)
#define amp_warn(mod, fmt, ...)      LOGW(mod, fmt, ##__VA_ARGS__)
#define amp_error(mod, fmt, ...)     LOGE(mod, fmt, ##__VA_ARGS__)
#define amp_fatal(mod, fmt, ...)     LOGF(mod, fmt, ##__VA_ARGS__)

/* JS console stdout */
#if defined(AMP_REPL_ENABLE) && defined(AMP_REPL_STDIO_EXTERNAL)
#define amp_console(fmt, ...)    do { \
        repl_printf(fmt, ##__VA_ARGS__); \
        repl_printf("\r\n"); \
    }while(0)
#else
#define amp_console(fmt, ...)    do { \
        amp_printf(fmt, ##__VA_ARGS__); \
        amp_printf("\r\n"); \
    }while(0)
#endif
/* md5 */
#define amp_md5_context     mbedtls_md5_context
#define amp_md5             mbedtls_md5
#define amp_md5_init        mbedtls_md5_init
#define amp_md5_starts      mbedtls_md5_starts
#define amp_md5_update      mbedtls_md5_update
#define amp_md5_finish      mbedtls_md5_finish
#define amp_md5_free        mbedtls_md5_free

/* sha1 */
#define amp_sha1_context    mbedtls_sha1_context
#define amp_sha1_init       mbedtls_sha1_init
#define amp_sha1_starts     mbedtls_sha1_starts
#define amp_sha1_update     mbedtls_sha1_update
#define amp_sha1_finish     mbedtls_sha1_finish
#define amp_sha1_free       mbedtls_sha1_free

/* aes */
#define AMP_AES_ENCRYPT     MBEDTLS_AES_ENCRYPT
#define AMP_AES_DECRYPT     MBEDTLS_AES_DECRYPT
#define amp_aes_context     mbedtls_aes_context
#define amp_aes_init        mbedtls_aes_init
#define amp_aes_setkey_enc  mbedtls_aes_setkey_enc
#define amp_aes_setkey_dec  mbedtls_aes_setkey_dec
#define amp_aes_crypt_cbc   mbedtls_aes_crypt_cbc
#define amp_aes_free        mbedtls_aes_free

/* des */
#define amp_des_context     mbedtls_des_context
#define amp_des_init        mbedtls_des_init
#define amp_des_setkey_enc  mbedtls_des_setkey_enc
#define amp_des_crypt_ecb   mbedtls_des_crypt_ecb
#define amp_des_free        mbedtls_des_free

/* base64 */
#define amp_base64_encode   mbedtls_base64_encode
#define amp_base64_decode   mbedtls_base64_decode

#endif /* AMP_DEFINES_H */

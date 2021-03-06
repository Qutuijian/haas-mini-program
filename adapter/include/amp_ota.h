/*
 * Copyright (C) 2015-2020 Alibaba Group Holding Limited
 */

#ifndef AMP_OTA_H
#define AMP_OTA_H

/**
 * sys ota upgrade thread function.
 *
 * @param[in]  ctx   device information.
 *
 * @return  0 on success, negative error on failure.
 */
int interval_sys_upgrade_start(void *ctx);

/**
 * submodule ota cb.
 *
 *
 * @param[in]      ctx     submodule information.
 *
 *
 * @return  0 on success, negative error on failure.
 */
int interval_module_upgrade_start(void *ctx);

#endif /* AMP_OTA_H */
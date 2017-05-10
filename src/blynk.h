// Copyright (c) Cesanta Software Limited
// All rights reserved

#ifndef MOS_BLYNK_H_
#define MOS_BLYNK_H_

#include <stdbool.h>

#include "fw/src/mgos_features.h"
#include "fw/src/mgos_init.h"
#include "fw/src/mgos_mongoose.h"

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#define BLYNK_HEADER_SIZE 5

#define BLYNK_RESPONSE 0
#define BLYNK_LOGIN 2
#define BLYNK_PING 6
#define BLYNK_HARDWARE 20

typedef void (*blynk_handler_t)(struct mg_connection *, const char *cmd,
                                int pin, int val, void *user_data);
void blynk_set_handler(blynk_handler_t func, void *user_data);

void blynk_send(struct mg_connection *c, uint8_t type, uint16_t id,
                const void *data, uint16_t len);
void blynk_printf(struct mg_connection *c, uint8_t type, uint16_t id,
                         const char *fmt, ...);
void blynk_init(void);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif

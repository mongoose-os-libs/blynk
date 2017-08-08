/* Copyright (c) Cesanta Software Limited
 * All rights reserved
 */

/*
 * See on GitHub:
 * [mgos_blynk.h](https://github.com/mongoose-os-libs/blynk/blob/master/src/mgos_blynk.h),
 * [mgos_blynk.c](https://github.com/mongoose-os-libs/blynk/blob/master/src/mgos_blynk.c)
 */

#ifndef CS_MOS_LIBS_BLYNK_SRC_MGOS_BLYNK_H_
#define CS_MOS_LIBS_BLYNK_SRC_MGOS_BLYNK_H_

#include <stdbool.h>

#include "mgos_features.h"
#include "mgos_init.h"
#include "mgos_mongoose.h"

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#define BLYNK_HEADER_SIZE 5

/* Blynk event handler signature. */
typedef void (*blynk_handler_t)(struct mg_connection *, const char *cmd,
                                int pin, int val, int id, void *user_data);

/* Set Blynk event handler. */
void blynk_set_handler(blynk_handler_t func, void *user_data);

/* Send data to the Blynk server. `data`, `len` holds a message to send. */
void blynk_send(struct mg_connection *c, uint8_t type, uint16_t id,
                const void *data, uint16_t len);

/* Message types for blynk_send(). */
enum blynk_msg_type {
  BLYNK_RESPONSE = 0,
  BLYNK_LOGIN = 2,
  BLYNK_PING = 6,
  BLYNK_HARDWARE = 20,
};

/* Same as as `blynk_send()`, formats message using `printf()` semantics. */
void blynk_printf(struct mg_connection *c, uint8_t type, uint16_t id,
                  const char *fmt, ...);

/* Send a virtual write command */
void blynk_virtual_write(struct mg_connection *c, int pin, float val, int id);

bool mgos_blynk_init(void);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* CS_MOS_LIBS_BLYNK_SRC_MGOS_BLYNK_H_ */

# Blynk integration for Mongoose OS

This Mongoose OS library allows your device remote control via
the Blynk platform. Device side logic could be implemented in either
C/C++ or JavaScript.

Blynk is a platform with iOS and Android apps to control Arduino,
Raspberry Pi and the likes over the Internet.

## How to use this library

In your Mongoose OS app, edit `mos.yml` file and add a reference to this
library. See an [example blynk app](https://github.com/mongoose-os-apps/blynk)
that does that.

## C/C++ API

<h4>
```c
typedef void (*blynk_handler_t)(struct mg_connection *, const char *cmd,
								int pin, int val, void *user_data);
```
</h4>
Blynk event handler signature.


<h4>
```c
void blynk_set_handler(blynk_handler_t func, void *user_data);
```
</h4>
Set Blynk event handler.

<h4>
```c
void blynk_send(struct mg_connection *c, uint8_t type, uint16_t id,
				const void *data, uint16_t len);
```
</h4>
Send data to the Blynk server. `data`, `len` holds a message to send,
`type` is one of:

```c
#define BLYNK_RESPONSE 0
#define BLYNK_LOGIN 2
#define BLYNK_PING 6
#define BLYNK_HARDWARE 20
```

<h4>
```c
void blynk_printf(struct mg_connection *c, uint8_t type, uint16_t id,
				  const char *fmt, ...);
```
</h4>
Same functionality as `blynk_send()`, but formats a message using `printf()` semantics.


## JavaScript API

<h4>
```javascript
Blynk.send(conn, type, msg);
```
</h4>
Send raw message to Blynk server.

<h4>
```javascript
Blynk.virtualWrite(conn, pin, val);
```
</h4>
</h4>Write to the virtual pin.

<h4>
```javascript
Blynk.setHandler(handler);
```
</h4>
Set handler for the virtual pin reads / writes.

Example:
```javascript
Blynk.setHandler(function(conn, cmd, pin, val) {
  print(cmd, pin, val);
}, null);
```

## Device configuration

This library adds `blynk` configuration section to the device:

```bash
mos config-get blynk
{
  "auth": "YOUR_BLYNK_AUTH_TOKEN",
  "enable": true,
  "server": "blynk-cloud.com:8442"
}
```

In order for your device to authenticate with Blynk cloud, either use
Web UI to change the `blynk.auth` value, or in a terminal:

```bash
mos config-set blynk.auth=YOUR_BLYNK_AUTH_TOKEN
```
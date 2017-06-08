let Blynk = {
  _send: ffi('void blynk_send(void *, int, int, void *, int)'),

  send: function(conn, type, msg) {
    this._send(conn, type, 0, msg, msg.length);
  },

  virtualWrite: function(conn, pin, val) {
    let msg = 'vr\x00' + JSON.stringify(pin) + '\x00' + JSON.stringify(val);
    this.send(conn, 20, msg);
  },

  setHandler: ffi('void blynk_set_handler(void (*)(void *, char *, int, int, userdata), userdata)'),
};

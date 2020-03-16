# ErgoDox plattfot configuration

Ergodox slightly modified qwerty layout. Most modifiers moved to the
thumb cluster or where the thumb can reach. Geared towards programming;
"()\- {}[]" is on the home row for example. Layed out to support
typing in both english and swedish.

## Changelog
* v4 [Nov 2017]: 
  * Fn changed to one shot layer key
  * Right hand got key for Ctrl+Alt
* v3 [Nov 2017]:
  * Control backlight on each hand
  * Right hand switched toggle media to toggle mouse/backlight
* v2 [Nov 2017]:
  * LCD prints current layer name.
  * LCD using constant color backlight
* v1 [Sep 2017]:
  * Updated layout to ergodox infinity
  * Added print screen on the media layer for use as sysreq. See [FAQ](https://docs.qmk.fm/faq_keymap.html#kcsysreq-isnt-working).
  * Updated macros to use SEND_STRING and process_record_user
* v0 [Feb 2017]:
  * Ported configuration from my ergodox-firmware fork
  * Changed space to work as space when tapped and ctrl when hold, same for enter except alt when hold.
  * Added game layer that disables space/ctrl and enter/alt
  * Added macros to insert <> and ""
  * Media layer also can move the mouse
  
Main layer
![Default](https://imgur.com/aOYpYUR.png)
Game layer
![Game](https://imgur.com/zL3Dacx.png)
Symbol layer
![Symbol](https://imgur.com/PvJxB4x.png)
Media layer
![Symbol](https://imgur.com/2eRTYis.png)
Mouse layer
![Symbol](https://imgur.com/t9g3w6g.png)

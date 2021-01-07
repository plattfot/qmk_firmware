# plattfot's keymap for [Kyria](https://github.com/splitkb/kyria)

![Keyboard](https://i.imgur.com/Pvsm973l.jpg)

Designed to be ease of use when programming, typing in both English
and Swedish and navigating around in a tiling window manager, in my
case [sway](https://swaywm.org/). Uses the two rotary encoders (lower
left/right thumb row) as two palm buttons.

This keymap avoids [Mod-tap](https://docs.qmk.fm/#/mod_tap) as they do
not work for me. [Kyria](https://github.com/splitkb/kyria) has enough
thumb keys to make it work without them.

The symbols are split into two layers, one for each hand. Then the
layers are activated by the opposite thumb. Found that having all
symbols on one layer then have one thumb activate them made it awkward
to press keys with the index finger on the same hand.

# Base Layer: Default
```
 // ,-------------------------------------------.                              ,-------------------------------------------.
 // |  Esc   |   Q  |   W  |   E  |   R  |   T  |                              |   Y  |   U  |   I  |   O  |   P  | Del    |
 // |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 // |  Tab   |   A  |   S  |  D   |   F  |   G  |                              |   H  |   J  |   K  |   L  | ;  : | Clotap |
 // |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 // | LShift |   Z  |   X  |   C  |   V  |   B  | Lead | RAISE|  | LOWER|BSpace|   N  |   M  | ,  < | . >  | /  ? | RShift |
 // `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 //                        | MPlay| GUI  | LCtrl| Space| LALT |  | RCtrl| Enter| NAV  | AltGr|LCtrl+|
 //                        |      |      |      |      |      |  |      |      |      |      | Space|
 //                        `----------------------------------'  `----------------------------------'
```

Setup for using the
[EurKey](https://eurkey.steffen.bruentjen.eu/layout.html) layout. As
it's annoying to have to toggle us and swedish layout which shifts
symbols around.

AltGr is used to access the extra keys in the
[EurKey](https://eurkey.steffen.bruentjen.eu/layout.html) layout.

## Notable features on this layer

Left rotary encoder
- Press: play/pause
- Rotate: Volume control

Right rotary encoder
- Press: Ctrl + Space: which is used to activate a region in emacs.
  It's not super awkward to press with the left hand, but this makes
  it a bit easier.

- Rotate: Page up/Page down. Used mouse scrolling at first. But
          scrolling only works in the window where the mouse pointer
          is. Which kind of defeated the purpose of having the scroll
          on the keyboard, as I still needed to move my hand to the
          mouse and then I could just use the scroll on the mouse.

[Leader key](https://docs.qmk.fm/#/feature_leader_key) is mainly used
for jumping between workspaces. Otherwise I would need to use both
hands everytime I need to switch. With the leader key I can jump
between 1-5 with just the left hand.

The close tap (Clotap) key, which I based on a code snippet from a
[reddit post](https://www.reddit.com/r/olkb/comments/citkbx/double_key_press_modifier_qmkwould_work_like/ev9cue8).
When pressed, it will insert the closing equivivalent key and press
`←` (left arrow). For example tapping Clotap then press `(` will
result in the keypresses `()←`, if pressing `"` will result in `""←`.
Really nice to have when programming, it is editor agnostic and saves
me two keypresses (need to press NAV+j for `←`). It also removes the
need for having specific macros for these as I had before.

# Lower Layer: Left symbols
```
 // ,-------------------------------------------.                              ,-------------------------------------------.
 // |        |  !   |  @   |  #   |  $   |  %   |                              |      |      |      |      |      |        |
 // |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 // |        |  |   |  _   |  \   |  -   |  +   |                              |      |      |      |      |      |        |
 // |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 // |        |      |  :   |  (   |  )   |  `   |      |ADJUST|  |      |      |      |      |      |      |      |        |
 // `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 //                        |      |      |      |      |      |  |      |      |      |      |      |
 //                        |      |      |      |      |      |  |      |      |      |      |      |
 //                        `----------------------------------'  `----------------------------------'
```

Symbols for the left hand. 

## Notable features on this layer

Left rotary encoder
- Rotate: Skip next/previous song

# Raise Layer: Right symbols + state keys
```
 // ,-------------------------------------------.                              ,-------------------------------------------.
 // |        |      |      |      |      |      |                              |   ^  |  &   |  *   |  ~   |  ?   |        |
 // |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 // |        |      |      |      |      |      |                              |   =  |  {   |  }   |  [   |  ]   |        |
 // |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 // |        |      |      |      |      |      |      |      |  |ADJUST|      |   "  |  '   |  <   |  >   |  /   |CapsLock|
 // `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 //                        | Mute |      |      |      |      |  |      |      |      |      |Insert|
 //                        |      |      |      |      |      |  |      |      |      |      |      |
 //                        `----------------------------------'  `----------------------------------'
```

Symbols for the right hand.

This layer also includes caps lock and insert.

## Notable features on this layer

Left rotary encoder
- Press: mute

Right rotary encoder
- Press: Toggle insert mode
- Rotate: Scrolling between workspaces in `sway`.

# Navigation Layer: Number keys, navigation
```
 //
 // ,-------------------------------------------.                              ,-------------------------------------------.
 // |        |   1  |  2   |  3   |  4   |  5   |                              |  6   |  7   |  8   |  9   |  0   |        |
 // |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 // |        |      |      |      |      | F11  |                              | F12  | Left | Up   | Down | Right|        |
 // |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 // |        |  F1  | F2   | F3   | F4   | F5   |      |      |  |      |      | F6   | F7   | F8   | F9   | F10  |        |
 // `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 //                        |      |      |      |      |      |  |      |      |      |      |      |
 //                        |      |      |      |      |      |  |      |      |      |      |      |
 //                        `----------------------------------'  `----------------------------------'
```

Access to the number and function as well as the arrow keys. Got use
to the number row after using [ErgoDox](https://www.ergodox.io/)
keyboards for a few years. Do not feel I need a numpad layer, which
seems to be quite common with small keyboards like this.

# Adjust Layer: RGB
```
 //
 // ,-------------------------------------------.                              ,-------------------------------------------.
 // |        |      |      |      |      |      |                              |      |      |      |      |      |        |
 // |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 // |        | TOG  | SAI  | HUI  | VAI  | MOD  |                              |      |      |      |      |      |        |
 // |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 // |        |      | SAD  | HUD  | VAD  | RMOD |      |      |  |      |      |      |      |      |      |      |        |
 // `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 //                        |      |      |      |      |      |  |      |      |      |      |      |
 //                        |      |      |      |      |      |  |      |      |      |      |      |
 //                        `----------------------------------'  `----------------------------------'
```

Right now it only contains adjustment to the underglow. Activated by
holding down `RAISE` and `LOWER` at the same time.

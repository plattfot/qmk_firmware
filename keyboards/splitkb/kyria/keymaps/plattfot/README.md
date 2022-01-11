# plattfot's keymap for [Kyria](https://github.com/splitkb/kyria)

![Keyboard](https://i.imgur.com/mcefoHnh.jpg)

Designed to be ease of use when programming, typing in both English
and Swedish and navigating around in a tiling window manager, in my
case [sway](https://swaywm.org/). Uses the two rotary encoders (lower left/right thumb
row) as two palm buttons.

This keymap avoids [Mod-tap](https://docs.qmk.fm/#/mod_tap) as they do not work for me. [Kyria](https://github.com/splitkb/kyria)
has enough thumb keys to make it work without them.

The symbols are split into two layers, one for each hand. Then the
layers are activated by the opposite thumb. Found that having all
symbols on one layer then have one thumb activate them made it awkward
to press keys with the index finger on the same hand.

Custom feature I call the close tap (Clotap) key, I based on a code
snippet from a [reddit post](https://www.reddit.com/r/olkb/comments/citkbx/double_key_press_modifier_qmkwould_work_like/ev9cue8). When pressed, it will insert the
closing equivivalent key and press `←` (left arrow). For example
tapping Clotap then press `(` will result in the keypresses `()←`, if
pressing `"` will result in `""←`, if pressing `)` will result in
`)←(`. Really nice to have when programming, it is editor agnostic and
saves me two keypresses (need to press NAV+j for `←`). It also removes
the need for having specific macros for these as I had before.

# Base Layer: Default
```
//
// ,-------------------------------------------.                              ,-------------------------------------------.
// |  Esc   |   Q  |   W  |   E  |   R  |   T  |                              |   Y  |   U  |   I  |   O  |   P  | BSpace |
// |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
// |  Tab   |   A  |   S  |  D   |   F  |   G  |                              |   H  |   J  |   K  |   L  |   ;  |   '    |
// |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
// | LShift |   Z  |   X  |   C  |   V  |   B  |      | RAISE|  | LOWER|      |   N  |   M  |   ,  |   .  |   /  | RShift |
// `----------------------+------+------+------| Space|------|  |------| Enter|------+------+------+----------------------'
//                        | MPlay| AltGr| LGUI |      | LCtrl|  | LAlt |      | RGUI | AltGr| Mic  |
//                        |      |      |      |      |      |  |      |      |      |      | Mute |
//                        `----------------------------------'  `----------------------------------'
```

Setup for using the [EurKey](https://eurkey.steffen.bruentjen.eu/layout.html) layout. As it's annoying to have to
toggle us and swedish layout which shifts symbols around.

AltGr is used to access the extra keys in the [EurKey](https://eurkey.steffen.bruentjen.eu/layout.html) layout. Have
one on each hand to make it easier to type, by following the same
principle as the split symbol layers. I.e hold down AltGr on the
opposite hand that's typing.

Combos are enable to easier type the three extra Swedish characters.

`o`+`e` → ö
`a`+`.` → ä
`w`+`.` → å

## Notable features on this layer

Left rotary encoder
- Press: play/pause
- Rotate: Volume control

Right rotary encoder
- Press: Mic Mute (F20)
- Rotate: Page up/Page down. Used mouse scrolling at first. But
          scrolling only works in the window where the mouse pointer
          is. Which kind of defeated the purpose of having the scroll
          on the keyboard, as I still needed to move my hand to the
          mouse and then I could just use the scroll on the mouse.

# Lower Layer: Left symbols | Right number/nav/function keys
```
// ,-------------------------------------------.                              ,-------------------------------------------.
// |        |  !   |  @   |  #   |  $   |  %   |                              |  6   |  7   |  8   |  9   |  0   |        |
// |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
// |        |  |   |  _   |  \   |  -   |  +   |                              |CLOTAP|  ←   |  ↑   |  ↓   |  →   | RCtrl  |
// |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
// | Insert |  °   |  :   |  (   |  )   |  ×   |      |ADJUST|  |      |      |  F6  |  F7  |  F8  |  F9  | F10  |        |
// `----------------------+------+------+------|      |------|  |------|      |------+------+------+----------------------'
//                        |      |      |      |      |      |  |      |      |      |      |      |
//                        |      |      |      |      |      |  |      |      |      |      |      |
//                        `----------------------------------'  `----------------------------------'
```

Symbols for the left hand, number/navigation/function keys for the
right hand.

I merged the navigation layer and the right side of this layer. I need
to reduce the inner keys as my thumbs started to get tired. And this
was the best way I came up with.

A LCtrl key is added on the far right as there is no other Ctrl key on
the right half of the keyboard.

This layer also includes insert.

## Notable features on this layer

Left rotary encoder
- Rotate: Skip next/previous song

Clotap on the right hand.

Has two Eurkey specific symbols `°` and `×` on the left hand.

# Raise Layer: Left number/function | Right symbols
```
// ,-------------------------------------------.                              ,-------------------------------------------.
// |        |  1   |  2   |  3   |  4   |  5   |                              |   ^  |  &   |  *   |  ~   |  ?   |  Del   |
// |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
// | LAlt   |  F11 |  F12 |  F13 |  F14 |CLOTAP|                              |   =  |  {   |  }   |  [   |  ]   |   `    |
// |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
// |        |  F1  |  F2  |  F3  |  F4  |  F5  |      |      |  |ADJUST|      |   …  |  "   |  <   |  >   |  /   |CapsLock|
// `----------------------+------+------+------|      |------|  |------|      |------+------+------+----------------------'
//                        |      |      |      |      |      |  |      |      |      |      | Mute |
//                        |      |      |      |      |      |  |      |      |      |      |      |
//                        `----------------------------------'  `----------------------------------'
```

Number/Function keys for the left hand, symbols for the right hand.

This layer also includes caps lock.

## Notable features on this layer

Right rotary encoder
- Press: mute
- Rotate: Scrolling between workspaces in `sway`.

Clotap on the left hand.

A LAlt key is added on the far left as there is no other Alt key on
the left half of the keyboard.

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

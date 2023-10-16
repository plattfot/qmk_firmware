# plattfot's keymap for [Kyria](https://github.com/splitkb/kyria)

![Keyboard](https://i.imgur.com/mcefoHnh.jpg)

Designed to be ease of use when programming, typing in both English
and Swedish and navigating around in a tiling window manager (in my
case [sway](https://swaywm.org/)). Uses the two rotary encoders (lower left/right thumb
row) as two palm buttons.

The base layout is [Colemak DH](https://colemakmods.github.io/mod-dh/).

This keymap avoids [Mod-tap](https://docs.qmk.fm/#/mod_tap) as they do not work for me.

This being a 38 key keyboard using [homerow mods](https://precondition.github.io/home-row-mods) would be
suitable.  But similar to mod-tap, they don't work for me as, having
keys activate when release instead of when pressed feels laggy to me.
Instead I found homerow combos works really well for modifiers.  They
need to be sticky to avoid finger fatigue.

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
,----------------------------------.                              ,----------------------------------.
|   Q  |   W  |   F  |   P  |   B  |                              |   J  |   L  |   U  |   Y  |   ;  |
|-LGui-+-LAlt-+-LCtl-+-LSft-+--Clr-|                              |-RSrt-+-LSft-+-RCtl-+-RAlt-+-RGui-|
|   A  |   R  |   S  |   T  |   G  Caps                        Word   M  |   N  |   E  |   I  |   O  |
|------+------+-AltGr+-Nav--+------+-------------.  ,-------------+------+-Nav--+-AltGr+------+------|
|   Z  |   X  |   C  |   D  |   V  |      |      |  |      |      |   K  |   H  |   ,  |   .  |   /  |
`-------------+------+------+------| Space| Tab  |  | BS   | ENTER|------+------+------+-------------'
              | MPlay|      | LSYMF|      |      |  |      |      | RSYMF|      | MMute|
              |      |      |      |      |      |  |      |      |      |      |      |
              `------+      +---------Esc--------'  `--------Esc---------+      +------'
```

Setup for using the [EurKey](https://eurkey.steffen.bruentjen.eu/layout.html) layout. As it's annoying to have to
toggle us and swedish layout which shifts symbols around.

AltGr is used to access the extra keys in the [EurKey](https://eurkey.steffen.bruentjen.eu/layout.html) layout. Have
one on each hand to make it easier to type, by following the same
principle as the split symbol layers. E.g. press AltGr on the
opposite hand that's typing.


## Notable features on this layer

Left rotary encoder
- Press: play/pause
- Rotate: Volume control

Right rotary encoder
- Press: Mic Mute (F20)
- Rotate: Ctrl + Page up/Page down.  Allows for easy scroll between
  tabs in the webbrowser.

**Note**: I Used mouse scrolling at first for the right rotary
encoder. But scrolling only works in the window where the mouse
pointer is. Which kind of defeated the purpose of having the scroll on
the keyboard, as I still needed to move my hand to the mouse and then
I could just use the scroll on the mouse.

# Lower Layer: Left symbols | Right number keys
```
,----------------------------------.                              ,----------------------------------.
|  °   |  @   |  *   |  #   |  %   |                              |      |  7   |  8   |  9   |      |
|------+------+------+------+------|                              |------+------+------+------+------|
|  |   |  _   |  -   |  (   |  )   |                              |      |  1   |  2   |  3   |  0   |
|------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------|
|  !   |  \   |  +   |  =   |  &   |      |      |  |      |      |CLOTAP|  4   |  5   |  6   |      |
`-------------+------+------+------|      |      |  |      |      |------+------+------+-------------'
              |      |      |      |      |      |  |      |      |      |      |      |
              |      |      |      |      |      |  |      |      |      |      |      |
              `------+      +--------------------'  `--------------------+      +------'
```

Symbols for the left hand, numbers for the right.

## Notable features on this layer

Left rotary encoder
- Rotate: Skip next/previous song

Clotap on the right hand.

Has one Eurkey specific symbols `°` on the left hand corner.

# Raise Layer: Left function | Right symbols
```
,----------------------------------.                              ,----------------------------------.
|      |  F9  |  F8  |  F7  | F12  |                              |   [  |  ]   |  `   |  $   |  …   |
|------+------+------+------+------|                              |------+------+------+------+------|
|  F10 |  F3  |  F2  |  F1  | F11  |                              |   {  |  }   |  '   |  :   |  ^   |
|------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------|
|      |  F6  |  F5  |  F4  |CLOTAP|      |      |  |      |      |   <  |  >   |  "   |  ~   |  ?   |
`-------------+------+------+------|      |      |  |      |      |------+------+------+-------------'
              |      |      |      |      |      |  |      |      |      |      |      |
              |      |      |      |      |      |  |      |      |      |      |      |
              `------+      +--------------------'  `--------------------+      +------'
```

Number/Function keys for the left hand, symbols for the right hand.

## Notable features on this layer

Right rotary encoder
- Rotate: Page Up/Down

Clotap on the left hand.

Has one Eurkey specific symbols `…` on the right hand corner.

# Nav Layer

```
,----------------------------------.                              ,----------------------------------.
|      |      |   →  |   ↑  |   ←  |                              |      |      |      |      |      |
|------+------+------+------+------|                              |------+------+------+------+------|
|      |      |      |      |      |                              |      |  ↓   |      |      |      |
|------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------|
|      |      |      |      |      |      |      |  |      |      |      |      |      |      |      |
`-------------+------+------+------|      |      |  |      |      |------+------+------+-------------'
              |      |      |      |      |      |  |      |      |      |      |      |
              |      |      |      |      |      |  |      |      |      |      |      |
              `------+      +--------------------'  `--------------------+      +------'
```

It might look a bit weird but it follows the navigation keys in Emacs.

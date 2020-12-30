# plattfot's keymap for [Kyria](https://github.com/splitkb/kyria)

![Keyboard](https://i.imgur.com/Pvsm973l.jpg)

Designed to be ease of use when programming, typing in both English
and Swedish and navigating around in a tiling window manager, in my
case [sway](https://swaywm.org/). Uses the two rotary encoders (lower
left/right thumb row) as two palm buttons.

This keymap avoids [Mod-tap](https://docs.qmk.fm/#/mod_tap) as they do
not work for me. [Kyria](https://github.com/splitkb/kyria) has enough
thumb keys to make it work without them.


# Base Layer: Default
```
 // ,-------------------------------------------.                              ,-------------------------------------------.
 // |  Esc   |   Q  |   W  |   E  |   R  |   T  |                              |   Y  |   U  |   I  |   O  |   P  | Del    |
 // |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 // |  Tab   |   A  |   S  |  D   |   F  |   G  |                              |   H  |   J  |   K  |   L  | ;  : | RCtl   |
 // |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 // | LShift |   Z  |   X  |   C  |   V  |   B  | Lead | RAISE|  | LOWER|BSpace|   N  |   M  | ,  < | . >  | /  ? | RShift |
 // `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 //                        | MPlay| GUI  | LCtrl| Space| LALT |  | Enter|RShift| NAV  | AltGr|LCTL+ |
 //                        |      |      |      |      |      |  |      |      |      |      | Space|
 //                        `----------------------------------'  `----------------------------------'
```

Setup for using the
[EurKey](https://eurkey.steffen.bruentjen.eu/layout.html) layout. As
it's annoying to have to toggle us and swedish layout.

Modifiers are mostly on the left hand, to make it comfortable when
require keyboard and mouse. For example working in a DCC (Digital
Content Creation tool) like [Houdini](https://www.sidefx.com/) and
[Maya](https://www.autodesk.com/products/maya/overview).

Right control key is on the right pinky, to make less awkward to use
key-combinations that involves pressing ctrl and alt.

AltGr is used to access the extra keys in the
[EurKey](https://eurkey.steffen.bruentjen.eu/layout.html) layout.

## Notable features on this layer

Left rotary encoder
- Press: play/pause
- Rotate: Volume control

Right rotary encoder
- Press: Ctrl + Space: which is used to activate a region in emacs.
  It's not super awkward to press with the left hand, but this makes
  it a lot easier.

- Rotate: Page up/Page down. Used mouse scrolling at first. But
          scrolling only works in the window where the mouse pointer
          is. Which kind of defeated the purpose of having the scroll
          on the keyboard, as I still needed to move my hand to the
          mouse and then I could just use the scroll on the mouse.

[Leader key](https://docs.qmk.fm/#/feature_leader_key) is mainly used
for jumping between workspaces. Otherwise I would need to use both
hands everytime I need to switch. With the leader key I can jump
between 1-5 with just the left hand. The right rotary encoder also
helps jumping back and forth between two workspaces by just pressing
down my right palm.

# Lower Layer: Symbols
```
 // ,-------------------------------------------.                              ,-------------------------------------------.
 // |        |  !   |  @   |  #   |  $   |  %   |                              |   ^  |  &   |  *   |      |      |        |
 // |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 // |        |  |   |  _   |  \   |  -   |  +   |                              |   =  |  {   |  }   |  [   |  ]   |        |
 // |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 // |        |  ~   |      |  `   |  (   |  '   |      |ADJUST|  |      |      |   "  |  )   |  <   |  >   |  ?   |        |
 // `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 //                        |      |      |      |      |      |  |      |      |      |      |      |
 //                        |      |      |      |      |      |  |      |      |      |      |      |
 //                        `----------------------------------'  `----------------------------------'
```

Contains most of the symbols, only exceptions are those that are
already on the default US base layer e.g. punctuation and forward
slash.

## Notable features on this layer

Left rotary encoder
- Rotate: Skip next/previous song

# Raise Layer: Function keys
```
 // ,-------------------------------------------.                              ,-------------------------------------------.
 // |        |  F1  |  F2  |  F3  |  F4  |  F5  |                              |  F6  |  F7  |  F8  |  F9  | F10  |        |
 // |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 // |        |      |      |      |      | F11  |                              | F12  |  {}  |      |  []  |      |        |
 // |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 // |        |      |      |      |  ()  |  ''  |      |      |  |ADJUST|      |  ""  |      |  <>  |      |      |CapsLock|
 // `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 //                        | Mute |      |      |      |      |  |      |      |      |      |Insert|
 //                        |      |      |      |      |      |  |      |      |      |      |      |
 //                        `----------------------------------'  `----------------------------------'
```

Access to the functional keys, which I mostly use to run `emacs`
compilation mode.

This layer also includes caps lock and insert. They are not heavily
used in my day to day workflow.


## Notable features on this layer

Left rotary encoder
- Press: mute

Right rotary encoder
- Press: Toggle insert mode
- Rotate: Scrolling between workspaces in `sway`.

Contains macros to quickly type the different types of brackets and
move the cursor to be inside. For example raise+v will type `()←`,
where `←` is pressing the left arrow. Really nice to have when
programming, and it is editor agnostic.

# Navigation Layer: Number keys, navigation
```
 // ,-------------------------------------------.                              ,-------------------------------------------.
 // |        |   1  |  2   |  3   |  4   |  5   |                              |  6   |  7   |  8   |  9   |  0   |        |
 // |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 // |        |      |      |      |      |      |                              |      | Left | Up   | Down | Right|        |
 // |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 // |        |      |      |      |      |      |      |ADJUST|  |      |      |      |      |      |      |      |        |
 // `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 //                        |      |      |      |      |      |  |      |      |      |      |      |
 //                        |      |      |      |      |      |  |      |      |      |      |      |
 //                        `----------------------------------'  `----------------------------------'
```

Access to the number as well as the arrow keys. Got use to the number
row after using [ErgoDox](https://www.ergodox.io/) keyboards for a few
years. Do not feel I need a numpad layer, which seems to be quite
common with small keyboards like this.

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

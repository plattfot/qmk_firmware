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
 // |   `    |   Q  |   W  |   E  |   R  |   T  |                              |   Y  |   U  |   I  |   O  |   P  |   Å    |
 // |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 // |  Tab   |   A  |   S  |  D   |   F  |   G  |                              |   H  |   J  |   K  |   L  | ;  : |  ' "   |
 // |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 // | LShift |   Z  |   X  |   C  |   V  |   B  | Lead | RAISE|  | LOWER|BSpace|   N  |   M  | ,  < | . >  | /  ? | RShift |
 // `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 //                        | MPlay| GUI  | LCtrl| Space| LALT |  | Enter|RShift| NAV  | LCTL+|Scroll|
 //                        |      |      |      |      |      |  |      |      |      | LALT | lock |
 //                        `----------------------------------'  `----------------------------------'
```

Setup for typing in both English and Swedish (hence the Å in the top
right corner, which is just [ on an US layout).

Modifiers are mostly on the left hand, to make it comfortable when
require keyboard and mouse. For example working in a DCC (Digital
Content Creation tool) like [Houdini](https://www.sidefx.com/) and
[Maya](https://www.autodesk.com/products/maya/overview).

## Notable features on this layer

Left rotary encoder
- Press: play/pause
- Rotate: Volume control

Right rotary encoder
- Press: Scroll lock. Which for me toggles keyboard layout between
         English and Swedish.

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
 //
 // ,-------------------------------------------.                              ,-------------------------------------------.
 // |   ~    |  !   |  @   |  #   |  $   |  %   |                              |   ^  |  &   |  *   |  (   |  )   |        |
 // |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 // |        |  |   |  _   |  \   |  -   |  +   |                              |   =  |  {   |  }   |  [   |  ]   |   ''   |
 // |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 // |        |  []  |  {}  |  ()  |  <>  |      |      |      |  |      |      |      |      |  <   |  >   |  ?   |        |
 // `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 //                        | Mute |      |      |      |      |  |      |      |      |      | LCTL+|
 //                        |      |      |      |      |      |  |      |      |      |      | Space|
 //                        `----------------------------------'  `----------------------------------'
```

Contains most of the symbols, only exceptions are those that are
already on the default US base layer i.e. quotes, punctuation and
forward slash.

## Notable features on this layer

Left rotary encoder
- Press: mute
- Rotate: Skip next/previous song

The left letter bottom row contains macros to quickly type the
different types of brackets and move the cursor to be inside. For
example lower+c will type `()←`, where `←` is pressing the left arrow.
Same principle for the `''` macro. Really nice to have when
programming, and it is editor agnostic.

Right hand side contains a combo key for pressing `C-SPC`, which is
used heavily in emacs to mark regions, and is a bit awkward to use
on this layout otherwise.

# Raise Layer: Function keys
```
 // ,-------------------------------------------.                              ,-------------------------------------------.
 // |        |  F1  |  F2  |  F3  |  F4  |  F5  |                              |  F6  |  F7  |  F8  |  F9  | F10  |        |
 // |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 // |        |      |      |      |      | F11  |                              | F12  |      |      |      |      |        |
 // |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 // |        |      |      |      |      |      |      |      |  |ADJUST| Del  |      |      |      |      |      |CapsLock|
 // `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 //                        |      |      | RCtrl|      | RAlt |  | Esc  |      |      |      |Insert|
 //                        |      |      |      |      |      |  |      |      |      |      |      |
 //                        `----------------------------------'  `----------------------------------'
```

Access to the functional keys, which I mostly use to run `emacs`
compilation mode.

This layer also includes caps lock, the right alternatives to the ctrl
and alt modifiers. Esc and delete is also on this layer. This are not
heavily used in my day to day workflow.


## Notable features on this layer

Right rotary encoder
- Press: Toggle insert mode
- Rotate: Scrolling between workspaces in `sway`.

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

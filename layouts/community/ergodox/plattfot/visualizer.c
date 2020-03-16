/*
Note: this is a modified copy of ../333fred/visualizer.c, originally licensed GPL.
*/

#include "simple_visualizer.h"

// This function should be implemented by the keymap visualizer Don't
// change anything else than state->target_lcd_color and
// state->layer_text as that's the only thing that the
// simple_visualizer assumes that you are updating Also make sure that
// the buffer passed to state->layer_text remains valid until the
// previous animation is stopped. This can be done by either double
// buffering it or by using constant strings
static void get_visualizer_layer_and_color(visualizer_state_t* state) {
  uint8_t saturation = 0;
  if (state->status.leds & (1u << USB_LED_CAPS_LOCK)) {
    saturation = 255;
  }

  state->target_lcd_color = LCD_COLOR(150, saturation, 0xFF);

  if (state->status.layer & 0x10) {
#ifdef MASTER_IS_ON_RIGHT
    state->layer_text = "Backlight";
#else
    state->layer_text = "Mouse";
#endif
    state->target_lcd_color = LCD_COLOR(0, saturation, 0xFF);
  } else if (state->status.layer & 0x8) {
    state->layer_text = "Media";
  } else if (state->status.layer & 0x4) {
    state->layer_text = "Symbol";
  } else if (state->status.layer & 0x2) {
    state->layer_text = "Game";
  } else {
    state->layer_text = "Default";
  }
}

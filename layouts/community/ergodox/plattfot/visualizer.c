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
    state->layer_text = "Adjust";
    state->target_lcd_color = LCD_COLOR(0, saturation, 0xFF);
  } else if (state->status.layer & 0x8) {
    state->layer_text = "Num/Nav";
  } else if (state->status.layer & 0x4) {
#ifdef MASTER_IS_ON_RIGHT
    state->layer_text = "Symbol";
#else
    state->layer_text = "Function";
#endif
  } else if (state->status.layer & 0x2) {
#ifdef MASTER_IS_ON_RIGHT
    state->layer_text = "Function";
#else
    state->layer_text = "Symbol";
#endif
  } else {
    state->layer_text = "Default";
  }
}

#pragma once

#include <stdbool.h>
#include <stdint.h>

/* Keyboard status passed to the oled_task_keymap function and used by the
 * various keyboard pet implementations.
 */
typedef struct {
    uint8_t mods;
    uint8_t wpm;
} oled_keyboard_state_t;

// TODO: Quizas lo podemos mover a otro .h mas generico?
enum layer_number {
  _QWERTY = 0,
  _LOWER,
  _RAISE,
  _ADJUST,
};

/* Note: Functions below assume a vertical OLED that is 32px (5 chars) wide. */

/* Renders layer status at the cursor. Occupies 5x1 character cells. */
void render_oled_layers(void);


/* Renders calculated WPM count at the cursor. Occupies 5x2 character cells. */
void render_oled_wpm(uint8_t wpm);

// #if defined(BCAT_OLED_PET)
/* Renders an animated critter at the cursor that can respond to keystrokes,
 * typing speed, etc. Should be about 5 character cells wide, but exact height
 * varies depending on the specific OLED pet implementation linked in.
 *
 * The rendered image will be one line taller than the OLED pet's animation
 * frame height to accommodate pets that "jump" when the spacebar is pressed.
 */
void render_oled_pet(uint8_t col, uint8_t line, const oled_keyboard_state_t *keyboard_state);
// #endif

/* Copyright 2022 Simon Sommer
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H

enum layers {
    _CANARY = 0,
    _SERTAIN,
    _NUMBERS,
    _SYMBOLS,
    _FUNCTIONS,
};


// Aliases for readability
#define CANARY   DF(_CANARY)
#define SERTAIN  DF(_SERTAIN)
#define SYMBOLS  LT(_SYMBOLS, KC_ENTER)  // https://docs.qmk.fm/#/feature_layers?id=switching-and-toggling-layers
#define NUMBERS  OSL(_NUMBERS)
#define FKEYS    OSL(_FUNCTIONS)

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_CANARY] = LAYOUT(
     KC_LEFT_ALT      , KC_W     , KC_L         , KC_Y       , KC_P          , KC_B             ,                                                             KC_Z             , KC_F                , KC_O                 , KC_U            , KC_BACKSPACE  , KC_DELETE      ,
     KC_TAB           , KC_C     , KC_R         , KC_S       , KC_T          , KC_G             ,                                                             KC_M             , KC_N                , KC_E                 , KC_I            , KC_A          , KC_RIGHT_ALT   ,
     KC_LEFT_SHIFT    , KC_Q     , KC_J         , KC_V       , KC_D          , KC_K             , KC_LBRC , KC_SLASH ,           KC_F12 , KC_RBRC           , KC_X             , KC_H                , KC_COMMA             , KC_DOT          , KC_QUOTE      , KC_RIGHT_SHIFT ,
                                                  XXXXXXX    , KC_LGUI       , LSFT_T(KC_ENTER) , KC_SPC  , NUMBERS  ,           FKEYS  , RCTL_T(KC_ESCAPE) , SYMBOLS          , KC_UNDERSCORE       , XXXXXXX
    ),

    [_SERTAIN] = LAYOUT(
     KC_LEFT_ALT      , KC_X     , KC_L         , KC_D       , KC_K          , KC_V             ,                                                             KC_Z             , KC_W                , KC_O                 , KC_U            , KC_BACKSPACE  , KC_DELETE      ,
     KC_TAB           , KC_S     , KC_R         , KC_T       , KC_N          , KC_F             ,                                                             KC_G             , KC_Y                , KC_E                 , KC_I            , KC_A          , KC_RIGHT_ALT   ,
     KC_LEFT_SHIFT    , KC_Q     , KC_J         , KC_M       , KC_H          , KC_B             , KC_LBRC , KC_SLASH ,           KC_F12 , KC_RBRC           , KC_P             , KC_C                , KC_COMMA             , KC_DOT          , KC_QUOTE      , KC_RIGHT_SHIFT ,
                                                  XXXXXXX    , KC_LGUI       , LSFT_T(KC_ENTER) , KC_SPC  , NUMBERS  ,           FKEYS  , RCTL_T(KC_ESCAPE) , SYMBOLS          , KC_UNDERSCORE       , XXXXXXX
    ),

    [_SYMBOLS] = LAYOUT(
     _______          , KC_GRAVE , KC_EXCLAIM   , KC_PERCENT , KC_CIRCUMFLEX , KC_ASTERISK  ,                                                                KC_UNDERSCORE    , KC_LEFT_CURLY_BRACE , KC_RIGHT_CURLY_BRACE , KC_EQUAL        , _______       , _______          ,
     _______          , KC_TILDE , KC_AT        , KC_HASH    , KC_DOLLAR     , KC_AMPERSAND ,                                                                KC_COLON         , KC_LEFT_PAREN       , KC_RIGHT_PAREN       , KC_DOUBLE_QUOTE , _______       , _______          ,
     _______          , _______  , KC_SEMICOLON , KC_MINUS   , KC_PLUS       , KC_PIPE      , _______     , _______  ,           _______         , _______ , KC_BACKSLASH     , KC_LEFT_BRACKET     , KC_RIGHT_BRACKET     , KC_SLASH        , _______       , _______          ,
                                                  XXXXXXX    , _______       , _______      , _______     , _______  ,           _______         , _______ , _______          , _______             , XXXXXXX
    ),

    [_NUMBERS] = LAYOUT(
      _______         , _______  , _______    , KC_UP      , KC_CIRCUMFLEX , KC_ASTERISK      ,                                                            _______          , KC_7                , KC_8                 , KC_9            , _______       , _______          ,
      _______         , _______  , KC_LEFT    , KC_DOWN    , KC_RIGHT      , _______          ,                                                            _______          , KC_4                , KC_5                 , KC_6            , _______       , _______          ,
      _______         , _______  , _______    , KC_MINUS   , KC_PLUS       , KC_DOT           , _______         , _______   ,          _______ , _______ , KC_0             , KC_1                , KC_2                 , KC_3            , _______       , _______          ,
                                                XXXXXXX    , _______       , _______          , _______         , _______   ,          _______ , _______ , _______          , KC_0                , XXXXXXX
    ),

    [_FUNCTIONS] = LAYOUT(
      _______         , KC_F9    , KC_F10     , KC_F11     , KC_F12        , CANARY           ,                                                            _______          , _______             , _______              , _______         , _______       , _______          ,
      _______         , KC_F5    , KC_F6      , KC_F7      , KC_F8         , SERTAIN          ,                                                            _______          , _______             , _______              , _______         , _______       , _______          ,
      _______         , KC_F1    , KC_F2      , KC_F3      , KC_F4         , _______          , _______         , _______   ,          _______ , _______ , _______          , _______             , _______              , _______         , _______       , _______          ,
                                                XXXXXXX    , _______       , _______          , _______         , _______   ,          _______ , _______ , _______          , _______             , XXXXXXX
    ),

};

/* The default OLED and rotary encoder code can be found at the bottom of qmk_firmware/keyboards/splitkb/kyria/rev2/rev2.c
 * These default settings can be overriden by your own settings in your keymap.c
 * For your convenience, here's a copy of those settings so that you can uncomment them if you wish to apply your own modifications.
 * DO NOT edit the rev2.c file; instead override the weakly defined default functions by your own.
 */

#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) { return OLED_ROTATION_180; }

static void render_kyria_logo(void) {
    static const char PROGMEM kyria_logo[] = {
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,128,128,192,224,240,112,120, 56, 60, 28, 30, 14, 14, 14,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7, 14, 14, 14, 30, 28, 60, 56,120,112,240,224,192,128,128,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,192,224,240,124, 62, 31, 15,  7,  3,  1,128,192,224,240,120, 56, 60, 28, 30, 14, 14,  7,  7,135,231,127, 31,255,255, 31,127,231,135,  7,  7, 14, 14, 30, 28, 60, 56,120,240,224,192,128,  1,  3,  7, 15, 31, 62,124,240,224,192,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,240,252,255, 31,  7,  1,  0,  0,192,240,252,254,255,247,243,177,176, 48, 48, 48, 48, 48, 48, 48,120,254,135,  1,  0,  0,255,255,  0,  0,  1,135,254,120, 48, 48, 48, 48, 48, 48, 48,176,177,243,247,255,254,252,240,192,  0,  0,  1,  7, 31,255,252,240,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,255,255,255,  0,  0,  0,  0,  0,254,255,255,  1,  1,  7, 30,120,225,129,131,131,134,134,140,140,152,152,177,183,254,248,224,255,255,224,248,254,183,177,152,152,140,140,134,134,131,131,129,225,120, 30,  7,  1,  1,255,255,254,  0,  0,  0,  0,  0,255,255,255,  0,  0,  0,  0,255,255,  0,  0,192,192, 48, 48,  0,  0,240,240,  0,  0,  0,  0,  0,  0,240,240,  0,  0,240,240,192,192, 48, 48, 48, 48,192,192,  0,  0, 48, 48,243,243,  0,  0,  0,  0,  0,  0, 48, 48, 48, 48, 48, 48,192,192,  0,  0,  0,  0,  0,
        0,  0,  0,255,255,255,  0,  0,  0,  0,  0,127,255,255,128,128,224,120, 30,135,129,193,193, 97, 97, 49, 49, 25, 25,141,237,127, 31,  7,255,255,  7, 31,127,237,141, 25, 25, 49, 49, 97, 97,193,193,129,135, 30,120,224,128,128,255,255,127,  0,  0,  0,  0,  0,255,255,255,  0,  0,  0,  0, 63, 63,  3,  3, 12, 12, 48, 48,  0,  0,  0,  0, 51, 51, 51, 51, 51, 51, 15, 15,  0,  0, 63, 63,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 48, 48, 63, 63, 48, 48,  0,  0, 12, 12, 51, 51, 51, 51, 51, 51, 63, 63,  0,  0,  0,  0,  0,
        0,  0,  0,  0, 15, 63,255,248,224,128,  0,  0,  3, 15, 63,127,255,239,207,141, 13, 12, 12, 12, 12, 12, 12, 12, 30,127,225,128,  0,  0,255,255,  0,  0,128,225,127, 30, 12, 12, 12, 12, 12, 12, 12, 13,141,207,239,255,127, 63, 15,  3,  0,  0,128,224,248,255, 63, 15,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,  3,  7, 15, 62,124,248,240,224,192,128,  1,  3,  7, 15, 30, 28, 60, 56,120,112,112,224,224,225,231,254,248,255,255,248,254,231,225,224,224,112,112,120, 56, 60, 28, 30, 15,  7,  3,  1,128,192,224,240,248,124, 62, 15,  7,  3,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  1,  3,  7, 15, 14, 30, 28, 60, 56,120,112,112,112,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,112,112,112,120, 56, 60, 28, 30, 14, 15,  7,  3,  1,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0
    };
    oled_write_raw_P(kyria_logo, sizeof(kyria_logo));
}

static void render_qmk_logo(void) {
    static const char PROGMEM qmk_logo[] = {
        0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8a,0x8b,0x8c,0x8d,0x8e,0x8f,0x90,0x91,0x92,0x93,0x94,
        0xa0,0xa1,0xa2,0xa3,0xa4,0xa5,0xa6,0xa7,0xa8,0xa9,0xaa,0xab,0xac,0xad,0xae,0xaf,0xb0,0xb1,0xb2,0xb3,0xb4,
        0xc0,0xc1,0xc2,0xc3,0xc4,0xc5,0xc6,0xc7,0xc8,0xc9,0xca,0xcb,0xcc,0xcd,0xce,0xcf,0xd0,0xd1,0xd2,0xd3,0xd4,0
    };
    oled_write_P(qmk_logo, false);
}

static void render_status(void) {

    oled_write_P(PSTR("Kyria rev2.1\n\n"), false);

    // Host Keyboard Layer Status
    oled_write_P(PSTR("Layer: "), false);
    switch (get_highest_layer(layer_state|default_layer_state)) {
        case _SERTAIN:
            oled_write_P(PSTR("SERTAIN\n"), false);
            break;
        case _NUMBERS:
            oled_write_P(PSTR("NUMBERS\n"), false);
            break;
        case _SYMBOLS:
            oled_write_P(PSTR("SYMBOLS\n"), false);
            break;
        case _FUNCTIONS:
            oled_write_P(PSTR("FUNCTIONS\n"), false);
            break;
        default:
            oled_write_P(PSTR("UNDEFINED\n"), false);
    }

    // Write host Keyboard LED Status to OLEDs
    led_t led_usb_state = host_keyboard_led_state();
    oled_write_P(led_usb_state.num_lock    ? PSTR("NUMLCKBER ") : PSTR("       "), false);
    oled_write_P(led_usb_state.caps_lock   ? PSTR("CAPLCK ") : PSTR("       "), false);
    oled_write_P(led_usb_state.scroll_lock ? PSTR("SCRLCK ") : PSTR("       "), false);
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        render_qmk_logo();
        render_status();
    } else {
        render_kyria_logo();
    }
    return false;
}
#endif

#ifdef ENCODER_ENABLE
bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        // Volume control
        if (clockwise) {
            tap_code(KC_RIGHT);
        } else {
            tap_code(KC_LEFT);
        }
    } else if (index == 1) {
        // Page up/Page down
        if (clockwise) {
            tap_code(KC_UP);
        } else {
            tap_code(KC_DOWN);
        }
    }
    return false;
}
#endif

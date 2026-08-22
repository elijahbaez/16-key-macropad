#include QMK_KEYBOARD_H

// Layer definitions
enum my_layers {
    _BASE,
    _TESTING_1,
    _TESTING_2
};

// Custom macro definitions
enum custom_keycodes {
    MC_HWINF = SAFE_RANGE, // Hardware Info/Telemetry Launcher
    MC_PING,               // Network Ping Test
    MC_TASKM               // Task Manager Launcher
};

// The 3 Macro Layers
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT(
        KC_1, KC_2, KC_3, KC_4,
        KC_5, KC_6, KC_7, KC_8,
        KC_9, KC_A, KC_B, KC_C,
        KC_D, KC_E, KC_F, TO(_TESTING_1) // Switch to Testing Layer 1
    ),
    [_TESTING_1] = LAYOUT(
        MC_HWINF, MC_PING,  MC_TASKM, KC_TRNS,
        KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
        KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
        KC_TRNS,  KC_TRNS,  KC_TRNS,  TO(_TESTING_2) // Switch to Testing Layer 2
    ),
    [_TESTING_2] = LAYOUT(
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, TO(_BASE) // Return to Base Layer
    )
};

// C++ Macro Implementation
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        switch (keycode) {
            case MC_HWINF:
                // Automates: Win+R -> cmd -> Launch Telemetry/Hardware Monitor
                SEND_STRING(SS_LGUI("r"));
                SEND_STRING(SS_DELAY(200));
                SEND_STRING("cmd\n");
                SEND_STRING(SS_DELAY(500));
                SEND_STRING("echo Launching C++ System Telemetry Logger...\n");
                return false;
            
            case MC_PING:
                // Automates: Win+R -> cmd -> ping 8.8.8.8
                SEND_STRING(SS_LGUI("r"));
                SEND_STRING(SS_DELAY(200));
                SEND_STRING("cmd\n");
                SEND_STRING(SS_DELAY(500));
                SEND_STRING("ping 8.8.8.8 -t\n");
                return false;
            
            case MC_TASKM:
                // Automates: Ctrl + Shift + Esc to instantly open Task Manager
                SEND_STRING(SS_LCTL(SS_LSFT(SS_TAP(X_ESC))));
                return false;
        }
    }
    return true;
}
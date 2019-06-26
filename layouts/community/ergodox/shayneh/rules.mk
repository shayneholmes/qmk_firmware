TAP_DANCE_ENABLE := no       # Tap dance (+1034)
MOUSEKEY_ENABLE  := no       # Mouse keys(+4700)
CONSOLE_ENABLE   := yes      # Console for debug(+400)
UNICODE_ENABLE   := no       # Unicode
ONEHAND_ENABLE   := no       # Allow swapping hands of keyboard (+436)
RGBLIGHT_ENABLE  := no

BACKLIGHT_ENABLE := no       # Enable keyboard backlight functionality
MIDI_ENABLE := no            # MIDI controls
AUDIO_ENABLE := no           # Audio output on port C6
UNICODE_ENABLE := no         # Unicode
BLUETOOTH_ENABLE := no       # Enable Bluetooth with the Adafruit EZ-Key HID
RGBLIGHT_ENABLE := no        # Enable WS2812 RGB underlight.  Do not enable this with audio at the same time.
SLEEP_LED_ENABLE := no       # Breathing sleep LED during USB suspend
LEADER_ENABLE := yes         # Leader keys

UNICODEMAP_ENABLE := no
UNICODE_ENABLE := no

ifneq ("$(wildcard $(LAYOUT_KEYMAP_PATH)/macro.h)","")
$(info "Found a customized macro file.")
OPT_DEFS+=-DSHAYNEH_MACROS_H
else
$(info "No customized macro file found; falling back to example file.")
endif

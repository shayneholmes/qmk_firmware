# Shayne Holmes's ergodox layout

## Information

[Up-to-date version](https://github.com/shayneholmes/qmk_firmware/tree/shayneholmes/layouts/community/ergodox/shayneh) (with latest tweaks)

## Priorities:

* Software Dvorak (so my laptop keyboard works still)

* Easy access to punctuation - the number row is reverse shifted, so pressing `9` yields `(`.

* Numbers are predominantly accessed via a numpad layer, since I find ten-key a lot easier to manage than the number row anyway

* Aggressive use of QMK's inline functions

* Plover layer, including emitting chords to enable Plover when the layer is triggered

* Private macros - the macro.h file is ignored by git so your macros won't be stored in the repo. (There's a fallback example macro.h to show you the ropes.)

## Layers

Layers are organized with modal layers on the bottom, followed by layers I tap-toggle (they're 'sticky'), and finally layers that I only use in chorded presses

Of note, the `FKEYS` layer is interesting because it is invoked with _two_ (adjacent) layer keys, any single one of which will invoke a different layer. There is some special handling required (see `action_two_layer_switch()`), but I find this works well in practice to increase access to more layers without layer keys proliferating across my keymap.

## Functions with richer parameters

To get more parameters for some key functions, we swap the uses of `action_function`'s `opt` and `id`:

 - `id` is 8 bits and therefore is useful for passing bigger parameters, like keycodes and pairs of 4-bit layers.

 - `opt` is limited to 3 bits (the MSB is used by TMK to indicate tappability as `FUNC_TAP`), so we use it to identify which function to call.

An example of why this is useful: This lets us make functions like `TOGGLE_SHIFT`, which takes a keycode for a parameter and prints the shifted version when shift isn't pressed (`%` for `KC_5`, etc.) and vice versa. Putting the keycode in the parameter removes a layer of indirection (yet another enum) and makes the keymaps a little more readable.

Although using 3-bit `opt` to distinguish functions seems to limit us to just eight functions (which we might need more of, in theory), we work around that somewhat with a special namespacing function, `FUNCTION_NULLARY`, which uses its 8-bit parameter to specify one of up to 256 functions to call (without parameters).

This could be extended to make another namespace, e.g. for 16 functions that can each take 4-bit parameters.

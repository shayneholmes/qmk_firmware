# Shayne Holmes's ergodox layout

* Software Dvorak (so my laptop keyboard works still)

* Easy access to punctuation - the number row is reverse shifted, so pressing `9` yields `(`.

* Numbers are predominantly accessed via a numpad layer, since I find ten-key a lot easier to manage than the number row anyway

* Aggressive use of QMK's inline functions

* Plover layer, including emitting chords to enable Plover when the layer is triggered

* Password macros - I have ignored Jack's warnings and accept my fate. At least the passwords.h file is ignored by git so the passwords aren't on this repo.

## Layers

Layers are organized with modal layers on the bottom, followed by layers I tap-toggle (they're 'sticky'), and finally layers that I only use in chorded presses

Of note, the `FKEYS` layer is interesting because it is invoked with _two_ modifier keys, any single one of which will invoke a separate layer. Releasing them out-of-order takes some special handling code (see `action_fkey`), but I find this works well in practice to increase the power of my layer buttons without increasing the number of them.

## Pretty keymaps

I've included some `#define`s to make my keymap layers look prettier. In particular, I like representing transparency as `_______` and blocking keys with `XXXXXXX`; it makes it easy to see at a glance where a given layer's relevant keys are.

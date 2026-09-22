# Shayne Holmes's ergodox layout

## Information

[Up-to-date version](https://github.com/shayneholmes/qmk_firmware/tree/shayneholmes/layouts/community/ergodox/shayneholmes)
(with latest tweaks)

## Priorities:

* Software Dvorak (so my laptop keyboard works still)

* Easy access to punctuation - the number row is reverse shifted, so pressing
  `9` yields `(`.

* Numbers are predominantly accessed via a numpad layer, since I find ten-key a
  lot easier to manage than the number row anyway

* Aggressive use of QMK's inline functions

* Plover layer, including emitting chords to enable Plover when the layer is
  triggered

* Private macros - the macro.h file is ignored by git so your macros won't be
  stored in the repo. (There's a fallback example macro.h to show you the
  ropes.)

## Layers

Layers are organized with modal layers on the bottom, followed by layers I
tap-toggle (they're 'sticky'), and finally layers that I only use in chorded
presses

Of note, the `FKEYS` layer is interesting because it is invoked with _two_
(adjacent) layer keys, any single one of which will invoke a different layer.
There is some special handling required (see `action_two_layer_switch()`), but
I find this works well in practice to increase access to more layers without
layer keys proliferating across my keymap.

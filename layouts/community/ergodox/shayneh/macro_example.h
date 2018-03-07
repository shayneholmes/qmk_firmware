/**
 * Use this file privately by copying it to macro.h and changing it there.
 * It will get ignored by git.
 */

#define SEND_STRING_DELAY(str) send_string_with_delay_P(PSTR(str), 15)

#define MACRO_DEF_Q     SEND_STRING_DELAY("Example!\n"); return

#define MACRO_DEF_P     SEND_STRING_DELAY("Another example... "); return

#define MACRO_DEF_K     SEND_STRING_DELAY("And a third"); return

/**
 * Use this file privately by copying it to passwords.h and changing it there.
 * It will get ignored by git.
 */

#define SEND_STRING_DELAY(str) send_string_with_delay_P(PSTR(str), 15)

#define MACRO_PASSWORD1     SEND_STRING_DELAY("Example!\n"); return

#define MACRO_PASSWORD2     SEND_STRING_DELAY("Another example... "); return

#define MACRO_PASSWORD3     SEND_STRING_DELAY("And a third"); return
/*
These VIM commands make this easier to generate
-- Dvorak decipher (for a QWERTY layout on a machine with software Dvorak set):
call setline(line('.'), tr(getline('.'), 'axje.uidchtnmbrl poygk,qf;svwAXJE.UIDCHTNMBRL POYGK,QF;SVW', 'abcdefghijklmnopqrstuvwxyz;.,ABCDEFGHIJKLMNOPQRSTUVWXYZ:<>'))
-- Convert plaintext into a one-line macro:
s/./T(&), /g|s/T([A-Z])/D(LSFT), &, U(LSFT)/|s/[a-z]/\U&/g|norm A\
*/

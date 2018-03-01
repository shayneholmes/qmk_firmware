/**
 * Use this file privately by copying it to passwords.h and changing it there.
 * It will get ignored by git.
 */

#define SEND_STRING_DELAY(str) send_string_with_delay_P(PSTR(str), 15)

#define MACRO_PASSWORD1     SEND_STRING_DELAY("Example!\n"); return false

#define MACRO_PASSWORD2     SEND_STRING_DELAY("Another example... "); return false

#define MACRO_PASSWORD3     return MACRO( \
                                I(15), \
                                D(LCTL), D(LALT), T(F2), W(255), U(LALT), U(LCTL), W(255), \
                                T(X), T(M), T(O), T(N), T(UP), T(ENT), W(255), \
                                D(LCTL), D(LALT), T(F5), W(255), U(LALT), U(LCTL), W(255), \
                            END) \

/*
These VIM commands make this easier to generate
-- Dvorak decipher (for a QWERTY layout on a machine with software Dvorak set):
call setline(line('.'), tr(getline('.'), 'axje.uidchtnmbrl poygk,qf;svwAXJE.UIDCHTNMBRL POYGK,QF;SVW', 'abcdefghijklmnopqrstuvwxyz;.,ABCDEFGHIJKLMNOPQRSTUVWXYZ:<>'))
-- Convert plaintext into a one-line macro:
s/./T(&), /g|s/T([A-Z])/D(LSFT), &, U(LSFT)/|s/[a-z]/\U&/g|norm A\
*/

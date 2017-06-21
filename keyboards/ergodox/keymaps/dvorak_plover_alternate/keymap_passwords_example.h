#define MACRO_XMONAD_RESET  MACRO( \
                                I(15), \
                                D(LCTL), D(LALT), T(F2), W(255), U(LALT), U(LCTL), W(255), \
                                T(X), T(M), T(O), T(N), T(UP), T(ENT), W(255), \
                                D(LCTL), D(LALT), T(F5), W(255), U(LALT), U(LCTL), W(255), \
                            END) \

#define MACRO_PASSWORD1     MACRO( \
                                I(15), \
                                T(E), T(X), T(A), T(M), T(P), T(L), T(E), \
                            END) \

#define MACRO_PASSWORD2     MACRO( \
                                I(15), \
                                T(E), T(X), T(A), T(M), T(P), T(L), T(E), \
                            END) \

#define MACRO_PASSWORD2     MACRO( \
                                I(15), \
                                T(E), T(X), T(A), T(M), T(P), T(L), T(E), \
                            END) \

/*
These VIM commands make this easier to generate
-- Dvorak decipher (for a QWERTY layout on a machine with software Dvorak set):
call setline(line('.'), tr(getline('.'), 'axje.uidchtnmbrl poygk,qf;svwAXJE.UIDCHTNMBRL POYGK,QF;SVW', 'abcdefghijklmnopqrstuvwxyz;.,ABCDEFGHIJKLMNOPQRSTUVWXYZ:<>'))
-- Convert plaintext into a one-line macro:
s/./T(&), /g|s/T([A-Z])/D(LSFT), &, U(LSFT)/|s/[a-z]/\U&/g|norm A\
*/

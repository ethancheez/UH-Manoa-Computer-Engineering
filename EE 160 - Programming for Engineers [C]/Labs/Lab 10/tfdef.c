#include "tfdef.h"

char to_lower(char c) {
    if(IS_UPPER(c)) return c - 'A' + 'a';
    return c;
}
#define TRUE 1
#define FALSE 0

#define IS_LOWER(c) ((c) >= 'a' && (c) <= 'z')

#define tolower(c) (IS_LOWER(c) ? c : c - 'A' + 'a')
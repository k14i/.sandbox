typedef struct {
  const int min;
  const int max;
} Range;

typedef struct {
  int top;
  const size_t size;
  int * const pBuf;
  const Range *const pRange;
} Stack;

#define newStack(buf) {                         \
    0, sizeof(buf) / sizeof(int), (buf),        \
      NULL                                      \
}

#define newStackWithRangeCheck(buf, min, max) { \
    0, sizeof(buf) / sizeof(int), (buf),        \
      pRange                                    \
}

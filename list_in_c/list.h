typedef int (*Member_int_0)(void*);
typedef void (*Member_void_1_List)(void*, void*);
typedef void (*Member_void_0)(void*);

typedef struct
{
  void *data;
  void *next;
  Member_void_1_List append;
  Member_int_0 terminate;
  Member_void_0 parse;
} List;

#define newList() { \
    NULL, NULL, \
      (void*)&List_append,    \
      (void*)&List_terminate, \
      (void*)&List_parse,     \
}

static void List_append(List *self, List *list);
static int List_terminate(List *self);
static void List_parse(List *self);


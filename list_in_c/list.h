typedef int (*Member_int_0)(void*);
typedef void (*Member_void_1_List)(void*, void*);

typedef struct
{
  void *data;
  void *next;
  Member_int_0 terminate;
  Member_void_1_List append;
} List;

#define newList() { \
    NULL, NULL, \
      (void*)&List_terminate, \
      (void*)&List_append \
}

static int List_terminate(List *self);
static void List_append(List *self, List *list);


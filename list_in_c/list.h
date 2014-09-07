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
  Member_void_0 destroy;
} List;

#define newList() { \
    malloc(sizeof(void*)),    \
      malloc(sizeof(void*)),  \
      (void*)&List_append,    \
      (void*)&List_terminate, \
      (void*)&List_parse,     \
      (void*)&List_destroy,   \
}

#define destroyList(self) { \
    free(self->data);       \
    free(self->next);       \
}

static void List_append(List *self, List *list);
static int List_terminate(List *self);
static void List_parse(List *self);
static void List_destroy(List *self);

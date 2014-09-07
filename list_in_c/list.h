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
  Member_void_0 initialize;
  Member_void_0 destroy;
} List;

#define newList() {                             \
    NULL, NULL,                                 \
      (void*)&List_append,                      \
      (void*)&List_terminate,                   \
      (void*)&List_parse,                       \
      (void*)&List_initialize,                  \
      (void*)&List_destroy,                     \
}

#define initializeList(self) {                  \
    self->data = malloc(sizeof(void*));         \
    memset(self->data, 0, sizeof(self->data));  \
}

#define destroyList(self) {                     \
    if(self->data) free(self->data);            \
    if(self->next) free(self->next);            \
}

static void List_append(List *self, List *list);
static int List_terminate(List *self);
static void List_parse(List *self);
static void List_initialize(List *self);
static void List_destroy(List *self);

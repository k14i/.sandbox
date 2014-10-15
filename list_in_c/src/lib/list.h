#ifndef LIST_H
#define LIST_H

//typedef struct {} List;

/*
 * List Object
 */

typedef int  (*Member_int_0)(void*);
typedef void (*Member_void_1_List)(void*, void*);
typedef void (*Member_void_0)(void*);
typedef void (*Member_void_1_void)(void*, void*);
typedef void (*Member_void_1_int)(void*, int);
typedef void (*Member_void_2_void_int)(void*, void*, int);

typedef struct
{
	void                   *data;
	void                   *next;
	void                   *prev;
	int                    tag;
	Member_void_1_List     append;
	Member_void_1_List     add;
	Member_void_1_int      set_tag;
	Member_void_1_int      add_tag;
	Member_void_2_void_int add_with_tag;
	Member_int_0           terminate;
	Member_void_1_List     dump;
	Member_void_1_void     foreach;
	Member_void_1_void     reverse;
	Member_void_0          initialize;
	Member_void_0          destroy;
} List;

#define newList() {                             \
		NULL, NULL, NULL, 0,					\
		(void*)&List_append,					\
			(void*)&List_add,					\
			(void*)&List_set_tag,				\
			(void*)&List_add_tag,				\
			(void*)&List_add_with_tag,			\
			(void*)&List_terminate,				\
			(void*)&List_dump,					\
			(void*)&List_foreach,				\
			(void*)&List_reverse,				\
			(void*)&List_initialize,			\
			(void*)&List_destroy,				\
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
static void List_add(List *self, List *list);
static void List_set_tag(List *self, int tag);
static void List_add_tag(List *self, int tag);
static void List_add_with_tag(List *self, void *target, int tag);
static int  List_terminate(List *self);
static void List_dump(List *self, List *list);
static void List_foreach(List *self, void *fun);
static void List_reverse(List *self, void *fun);
static void List_initialize(List *self);
static void List_destroy(List *self);


/*
 * ListHelper Object
 */

typedef List *(*Member_List_2_List_int)(void*, List *list, int number);
typedef List *(*Member_List_1_List)(void*, List *list);
//typedef int (*Member_List_0)(void*);

typedef struct
{
	Member_List_2_List_int  find_by_tag;
	Member_List_1_List      last;
} ListHelper;

#define newListHelper() {							\
		(void*)&ListHelper_find_by_tag,				\
			(void*)&ListHelper_last,				\
}

static List *ListHelper_find_by_tag(ListHelper *self, List *list, int tag);
static List *ListHelper_last(ListHelper *self, List *list);

#endif


/*
 * Function Type Definition
 */

#ifndef FUNC_TYPE
#define FUNC_TYPE

typedef void (*Func)(void*, void*);

#endif

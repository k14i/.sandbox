#ifndef MEM_HELPER_H
#define MEM_HELPER_H

#define MEM_STATUS_PRESERVED   0
#define MEM_STATUS_ALLOCATED   1
#define MEM_STATUS_TO_BE_FREED 2
#define MEM_STATUS_FREED       3

/*
 * Mem Object
 */

typedef void (*Member_void_0)      (void*);
typedef int  (*Member_int_0)       (void*);
typedef void (*Member_void_1_void) (void*, void*);
typedef void (*Member_void_1_int)  (void*, int num);

typedef struct
{
	void               *ptr;
	void               *prev;
    void               *next;
    int                ref_count;
    int                status;
	Member_void_0      initialize;
	Member_void_1_void append;
	Member_int_0       increment;
    Member_int_0       decrement;
	Member_void_1_int  set_status;
	Member_void_0      dump;
} Mem;

#define newMem() {									\
		NULL, NULL, NULL, 0, 0,						\
			(void*)&Mem_initialize,					\
			(void*)&Mem_append,						\
			(void*)&Mem_increment,					\
			(void*)&Mem_decrement,					\
			(void*)&Mem_set_status,					\
}

/*
 * MemHelper Object
 */

typedef void      (*Member_void_0)      (void*);
typedef int       (*Member_int_0)       (void*);
typedef Mem       (*Member_Mem_0)       (void*);
typedef MemHelper (*Member_MemHelper_0) (void*);
typedef int       (*Member_int_1_Mem)   (void*, Mem *mem);
typedef Mem       (*Member_Mem_1_void)  (void*, void*);
typedef Mem       (*Member_Mem_1_int)   (void*, int num);

typedef struct
{
	void               *mem;
	Member_MemHelper_0 new;
	Member_void_0      destroy;
	Member_int_0       initialize;
	Member_int_1_Mem   append;
	Member_int_0       destroy_all;
	Member_int_1_void  foreach;
	Member_Mem_1_void  find_by_ptr;
	Member_Mem_1_int   find_by_ref_count;
	Member_Mem_1_int   find_by_status;
	Member_int_0       dump;
} MemHelper;

#define newMemHelper() {							\
		NULL,										\
			(void*)&MemHelper_new,					\
			(void*)&MemHelper_destroy,				\
			(void*)&MemHelper_initialize,			\
			(void*)&MemHelper_append,				\
			(void*)&MemHelper_destroy_all,			\
			(void*)&MemHelper_foreach,				\
			(void*)&MemHelper_find_by_ptr,			\
			(void*)&MemHelper_find_by_ref_count,	\
			(void*)&MemHelper_find_by_status,		\
			(void*)&MemHelper_dump,					\
}

#endif

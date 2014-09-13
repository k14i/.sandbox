#ifndef MEM_HELPER_H
#define MEM_HELPER_H

#define MEM_STATUS_PRESERVED   0
#define MEM_STATUS_ALLOCATED   1
#define MEM_STATUS_TO_BE_FREED 2
#define MEM_STATUS_FREED       3

/*
 * Mem Class
 */

typedef struct
{
	void         *ptr;
	void         *prev;
    void         *next;
    int          ref_count;
    int          status;
	Member_int_0 initialize;
	Member_int_0 increment;
    Member_int_0 decrement;
	Member_int_0 set_status;
	Member_int_0 dump;
} Mem;

#define newMem() {									\
		NULL, NULL, NULL, 0, 0,						\
			(void*)&MemHelper_set_status,			\
			(void*)&MemHelper_increment,			\
			(void*)&MemHelper_decrement,			\
}

/*
 * MemHelper Class
 */

typedef struct
{
	Member_int_0 initialize;
	Member_int_0 add;
	Member_int_0 destroy;
	Member_int_0 destroy_all;
	Member_int_0 foreach;
	Member_Mem_0 find_by_ptr;
	Member_Mem_0 find_by_ref_count;
	Member_Mem_0 find_by_status;
	Member_int_0 dump;
} MemHelper;

#define newMemHelper() {							\
		(void*)&MemHelper_initialize,				\
			(void*)&MemHelper_add,					\
			(void*)&MemHelper_destroy,				\
			(void*)&MemHelper_destroy_all,			\
			(void*)&MemHelper_foreach,				\
			(void*)&MemHelper_find_by_ptr,			\
			(void*)&MemHelper_find_by_ref_count,	\
			(void*)&MemHelper_find_by_status,		\
			(void*)&MemHelper_dump,					\
}

#endif

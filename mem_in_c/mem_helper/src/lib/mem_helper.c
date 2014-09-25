#include <stdlib.h> //NOTE: free
#include <string.h> //NOTE: memcpy
#include "mem_helper.h"

/*
 * Prototypes for private methods
 */



/*
 * Mem Object
 */

static void Mem_initialize(Mem *self) {
	self->ptr  = malloc(sizeof(self->ptr));
	self->prev = malloc(sizeof(self->prev));
	self->next = malloc(sizeof(self->next));
	self->ref_count = 0;
	self->status = MEM_STATUS_PRESERVED;
	return;
}

static void Mem_append(Mem *self, void *target) {
	self->next   = target;
	//target->prev = self;
	return;
}

static int Mem_increment(Mem *self) {
	return self->ref_count++;
}

static int Mem_decrement(Mem *self) {
	return self->ref_count--;
}

static void Mem_set_status(Mem *self, int mem_status) {
	self->status = mem_status;
	return;
}

static void Mem_dump(Mem *self) {
	return;
}


/*
 * MemHelper Object
 */

static void MemHelper_new(MemHelper *self) {
	/*
	char buf[2];
	//size_t size = sizeof(MemHelper);
	MemHelper mem_helper = newMemHelper();
	//MemHelper *mem_helper = malloc(size);
	//memset(mem_helper, 0, size);
	//mem_helper = newMemHelper();
	//MemHelper _mem_helper = newMemHelper();
	//memcpy(mem_helper, _mem_helper, sizeof(_mem_helper));
	buf[0] = 0;
	//buf[1] = (char)mem_helper;
	memcpy(buf[1], &mem_helper, sizeof(mem_helper));
	char *ret = malloc(sizeof(buf));
	memcpy(ret, buf, sizeof(buf));
	*/
	return;
}

static void MemHelper_destroy(MemHelper *self) {
	free(self);
	return;
}

static int MemHelper_initialize(MemHelper *self) {
}

static int MemHelper_append(MemHelper *self, Mem *mem) {
}

static int MemHelper_destroy_all(MemHelper *self) {
}

static int MemHelper_foreach(MemHelper *self, void *function) {
}

static int MemHelper_find_by_ptr(MemHelper *self, Mem *mem, void *target) {
	int i = 0;
	int ret = 0;
	Mem *ptr = mem->ptr;
	while(ptr == target) {
		if(ptr == target) {
			i = 1;
			break;
		}
		ptr = ptr->next;
	}
	return ret;
}

static char *MemHelper_find_by_ref_count(MemHelper *self, Mem *mem, int target) {
	int i = 0;
	char list[DEFAULT_ARRAY_SIZE];
	Mem *ptr = mem->ptr;
	while(ptr) {
		if(ptr->ref_count == target) {
			list[i] = (char)ptr;
			i++;
		}
		ptr = ptr->next;
	}

	char *list_ret = malloc(DEFAULT_ARRAY_SIZE); //TODO: free()
	memcpy(list_ret, list, sizeof(list));
	return list_ret;
}

static char *MemHelper_find_by_status(MemHelper *self, Mem *mem, int target) {
	int i = 0;
	char list[DEFAULT_ARRAY_SIZE];
	Mem *ptr = mem->ptr;
	while(ptr) {
		if(ptr->status == target) {
			list[i] = (char)ptr;
			i++;
		}
		ptr = ptr->next;
	}

	char *list_ret = malloc(DEFAULT_ARRAY_SIZE); //TODO: free()
	memcpy(list_ret, list, sizeof(list));
	return list_ret;
}

static int MemHelper_dump(MemHelper *self) {
}


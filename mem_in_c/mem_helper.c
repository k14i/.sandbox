#include "mem_helper.h"

/*
 * Prototypes for private methods
 */


/*
 * Mem Object
 */

static Mem *Mem_initialize(Mem *self) {
	self->ptr  = malloc(sizeof(self->ptr));
	self->prev = malloc(sizeof(self->prev));
	self->next = malloc(sizeof(self->next));
	self->ref_count = 0;
	self->status = MEM_STATUS_PRESERVED;
	return self;
}

static void Mem_append(Mem *self, Mem *target) {
	self->next   = target;
	target->prev = self;
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

static MemHelper *MemHelper_new(MemHelper *self) {
	size_t size = sizeof(MemHelper);
	MemHelper *mem_helper = malloc(size);
	memset(mem_helper, 0, size);
	mem_helper = newMemHelper();
	return mem_helper;
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

static Mem *MemHelper_find_by_ptr(MemHelper *self, void *ptr) {
}

static Mem *MemHelper_find_by_ref_count(MemHelper *self, int count) {
}

static Mem *MemHelper_find_by_status(MemHelper *self, int status) {
}

static int MemHelper_dump(MemHelper *self) {
}


#include "common.h"
#include "mem_helper.h"


/*
 * Mem Class
 */

static Mem *Mem_initialize(Mem *self) {
	self->ptr  = malloc(sizeof(self->ptr));
	self->prev = malloc(sizeof(self->prev));
	self->next = malloc(sizeof(self->next));
	self->ref_count = 0;
	self->status = MEM_STATUS_PRESERVED;
	return self;
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

static int Mem_dump(Mem *self) {
}

/*
 * MemHelper Class
 */

static int MemHelper_initialize(MemHelper *self) {
}

static int MemHelper_add(MemHelper *self, Mem *mem) {
}

static int MemHelper_destroy(MemHelper *self, Mem *mem) {
}

static int MemHelper_destroy_all(MemHelper *self) {
}

static int MemHelper_foreach(MemHelper *self) {
}

static Mem *MemHelper_find_by_ptr(MemHelper *self, void *ptr) {
}

static Mem *MemHelper_find_by_ref_count(MemHelper *self, int count) {
}

static Mem *MemHelper_find_by_status(MemHelper *self, int status) {
}

static int MemHelper_dump(MemHelper *self) {
}


#include "common.h"
#include "mem_helper.h"


/*
 * Mem Class
 */

static int Mem_initialize(Mem *self) {
}

static int Mem_increment(Mem *self) {
}

static int Mem_decrement(Mem *self) {
}

static int Mem_set_status(Mem *self) {
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


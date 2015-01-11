#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

#include "list.h"


/*
 * List Object
 */

static void List_append(List *self, List *target);
static void List_add(List *self, List *target);
static void List_set_tag(List *self, int tag);
static void List_add_tag(List *self, int tag);
static void List_add_with_tag(List *self, void *target, int tag);
static int  List_terminate(List *self);
static void List_dump(List *self, List *list);
static void List_foreach(List *self, void *function, void *arg);
static void List_reverse(List *self, void *function);
static void List_initialize(List *self);
static void List_destroy(List *self);


static void List_append(List *self, List *target) {
	List *ptr;

	ptr = self;

	for(int i=0; ptr->next; i++) ptr = ptr->next;

	ptr->next = target;

	ptr = ptr->next;
	ptr->prev = self;
	return;
}

static void List_add(List *self, List *target) {
	List list = ListElements;
	list.initialize(&list);
	memcpy(list.data, &target, sizeof(target));
	self->append(self, &list);
	return;
}

static void List_set_tag(List *self, int tag) {
	self->tag = tag;
	return;
}

static void List_add_tag(List *self, int tag) {
	List *ptr;

	ptr = self;

	while(ptr->next) ptr = ptr->next;

	self->set_tag(self, tag);
	return;
}

static void List_add_with_tag(List *self, void *target, int tag) {
	self->add(self, target);
	self->add_tag(self, tag);
	return;
}

static int List_terminate(List *self) {
	void *buf = malloc(sizeof(List));
	List list = ListElements;
	memcpy(buf, &list, sizeof(list));
	self->append(self, &list);

	list.destroy(&list);
	return 0;
}

static void List_dump(List *self, List *list) {
	printf("list(%p)->data(%p) is %s\n", list, list->data, (char *)list->data);
	printf("list(%p)->prev is %p\n", list, list->prev);
	printf("list(%p)->next is %p\n", list, list->next);
	return;
}

static void List_foreach(List *self, void *function, void *arg) {
	List *ptr;
	ptr = self;

	for(int i=0; ptr->next; i++) {
		if(!arg) {
			Func_0 *fun = function;
			(*fun)(self, ptr);
		} else {
			Func_1 *fun = function;
			(*fun)(self, ptr, arg);
		}
		ptr = ptr->next;
	}

	return;
}

static void List_reverse(List *self, void *function) {
	/*
	ListHelper *list_helper = newListHelper();
	List *ptr = self;
	Func *fun = function;

	//memcpy(ptr, self->last(self), sizeof(ptr));
	//printf("ListHelper_last(&list_helper, ptr) is %p\n", ListHelper_last(&list_helper, ptr));
	//printf("self->last(self) is %p\n", self->last(self));
	//ptr = self->last(self);
	ptr = ListHelper_last(list_helper, ptr);

	for(int i=0; ptr->prev; i++) {
	//printf("i = %d\n", i);
	(*fun)(self, ptr);
	ptr = ptr->prev;
	}
	//printf("======== %s ======== \n", __func__);*/
	return;
}

static void List_initialize(List *self) {
	self->data = malloc(sizeof(void*));
	memset(self->data, 0, sizeof(void*));
	return;
}

static void List_destroy(List *self) {
	if(self->data) free(self->data);
	if(self->next) free(self->next);
	return;
}


/*
 * ListHelper Object
 */

// TODO: Delete all the list recursively.
static void ListHelper_destroy_list(ListHelper *self, List *list) {
	memset(list, 0, sizeof(List));
	free(list);
}

static List *ListHelper_new_list(ListHelper *self) {
	void *buf = malloc(sizeof(List));
	List list = ListElements;
	memcpy(buf, &list, sizeof(list));
	return buf;
}

static List *ListHelper_last(ListHelper *self, List *list) {
	List *ptr;
	ptr = list;
	while (ptr->next) {
		ptr = ptr->next;
	}

	return ptr;
}

static List *ListHelper_find_by_tag(ListHelper *self, List *list, int tag) {
	List *ptr;
	ptr = list;

	while (ptr->next) {
		if(ptr->tag == tag) break;
		ptr = ptr->next;
		continue;
	}
	return ptr;
}

static void ListHelper_destroy(ListHelper *self) {
	memset(self, 0, sizeof(ListHelper));
	free(self);
}

ListHelper *newListHelper() {
	void *buf = malloc(sizeof(ListHelper));
	ListHelper list_helper = ListHelperElements;
	memcpy(buf, &list_helper, sizeof(list_helper));
	return buf;
}


#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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
static void List_foreach(List *self, void *function);
static void List_reverse(List *self, void *function);
static void List_initialize(List *self);
static void List_destroy(List *self);
static void List_destroy_all(List *self);


static void List_append(List *self, List *target) {
  //printf("\n/* ---- %s ----\n", __func__);
  List *ptr;

  //printf("target(%p)->data(%p) is %s\n", target, target->data, target->data);
  //printf("target(%p)->next is %p\n", target, target->next);

  ptr = self;

  for(int i=0; ptr->next; i++) {
    //printf("i = %d\n", i);
    //printf("ptr(%p)->next(%p)\n", ptr, ptr->next);
    //printf("... ptr(%p)->next(%p) is not NULL. Go ahead.\n", ptr, ptr->next);
    //printf("ptr->data is %s\n", ptr->data);
	if(!ptr->prev) ptr->prev = ptr;
	//printf("ptr->prev is %p\n", ptr->prev);
    ptr = ptr->next;
    //printf("ptr->data is %s\n", ptr->data);
  }
  //printf("... ptr(%p)->next(%p) is NULL. Append target(%p) to ptr->next(%p)\n", ptr, ptr->next, target, ptr->next);
  //printf("target(%p)->data(%p) is %s\n", target, target->data, target->data);

  ptr->next = malloc(sizeof(void*));
  memcpy(ptr->next, target, sizeof(void*));
  //ptr->next = target;

  //printf("Now, ptr->next has become %p\n", ptr->next);

  ptr = ptr->next;
  //printf("ptr->next(%p)->data(%p) is %s\n", ptr, ptr->data, ptr->data);
  //printf("ptr->next(%p)->next is %p\n", ptr, ptr->next);

  //printf("---- %s ---- */\n", __func__);
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
  //printf("\n/* ---- %s ----\n", __func__);
  List null_list = ListElements;
  //printf("Terminate %p with null_list(%p)\n", self, &null_list);
  self->append(self, &null_list);

  null_list.destroy(&null_list);
  //printf("---- %s ---- */\n", __func__);
  return 0;
}

static void List_dump(List *self, List *list) {
	//printf("\n/* ---- %s ----\n", __func__);
	printf("list(%p)->data(%p) is %s\n", list, list->data, (char *)list->data);
	printf("list(%p)->prev is %p\n", list, list->prev);
	printf("list(%p)->next is %p\n", list, list->next);
	//printf("---- %s ---- */\n", __func__);
	return;
}

static void List_foreach(List *self, void *function) {
  //printf("\n/* ======== %s ========\n", __func__);
  List *ptr;
  Func *fun = function;
  ptr = self;

  for(int i=0; ptr->next; i++) {
    //printf("i = %d\n", i);
	(*fun)(self, ptr);
    ptr = ptr->next;
  }
  //printf("... ptr(%p)->next(%p) is NULL. break.\n", ptr, ptr->next);

  //printf("======== %s ======== */\n", __func__);
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

static void List_destroy_all(List *self) {
	//List *ptr;
}


/*
 * ListHelper Object
 */

static List *ListHelper_new_list(ListHelper *self) {
	void *buf = malloc(sizeof(List));
	List list = ListElements;
	memcpy(buf, &list, sizeof(list));
	return buf;
}

static List *ListHelper_last(ListHelper *self, List *list) {
  //printf("\n/* ======== %s ========\n", __func__);
  List *ptr;
  ptr = list;
  while (ptr->next) {
	ptr = ptr->next;
  }

  //printf("ptr is %p\n", ptr);
  //printf("======== %s ======== */\n", __func__);
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
	free(self);
}

ListHelper *newListHelper() {
	void *buf = malloc(sizeof(ListHelper));
	ListHelper list_helper = ListHelperElements;
	memcpy(buf, &list_helper, sizeof(list_helper));
	return buf;
}


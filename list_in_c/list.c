#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "list.h"

static void List_append(List *self, List *target) {
  printf("\n/* ---- %s ----\n", __func__);
  List *ptr;

  printf("target(%p)->data(%p) is %s\n", target, target->data, target->data);
  printf("target(%p)->next is %p\n", target, target->next);

  ptr = self;

  for(int i=0; ptr->next; i++) {
    printf("i = %d\n", i);
    printf("ptr(%p)->next(%p)\n", ptr, ptr->next);
    printf("... ptr(%p)->next(%p) is not NULL. Go ahead.\n", ptr, ptr->next);
    printf("ptr->data is %s\n", ptr->data);
    ptr = ptr->next;
    printf("ptr->data is %s\n", ptr->data);
  }
  printf("... ptr(%p)->next(%p) is NULL. Append target(%p) to ptr->next(%p)\n", ptr, ptr->next, target, ptr->next);
  printf("target(%p)->data(%p) is %s\n", target, target->data, target->data);

  ptr->next = malloc(sizeof(void*));
  memcpy(ptr->next, target, sizeof(void*));
  //ptr->next = target;

  printf("Now, ptr->next has become %p\n", ptr->next);

  ptr = ptr->next;
  printf("ptr->next(%p)->data(%p) is %s\n", ptr, ptr->data, ptr->data);
  printf("ptr->next(%p)->next is %p\n", ptr, ptr->next);

  printf("---- %s ---- */\n", __func__);
  return;
}

static void List_add(List *self, List *target) {
	List list = newList();
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
  printf("\n/* ---- %s ----\n", __func__);
  List null_list = newList();
  printf("Terminate %p with null_list(%p)\n", self, &null_list);
  self->append(self, &null_list);

  null_list.destroy(&null_list);
  printf("---- %s ---- */\n", __func__);
  return 0;
}

static void List_dump(List *self, List *list) {
	printf("\n/* ---- %s ----\n", __func__);
	printf("list(%p)->data(%p) is %s\n", list, list->data, list->data);
	printf("list(%p)->prev is %p\n", list, list->prev);
	printf("list(%p)->next is %p\n", list, list->next);
	printf("---- %s ---- */\n", __func__);
	return;
}

static List *List_find_by_tag(List *self, int tag) {
	List *ptr;
	ptr = self;
	
	while (ptr->next) {
		if(ptr->tag == tag) break;
		ptr = ptr->next;
		continue;
	}
	return ptr;
}

static void List_foreach(List *self, void *function) {
  printf("\n/* ======== %s ========\n", __func__);
  List *ptr;
  Func *fun = function;
  ptr = self;

  for(int i=0; ptr->next; i++) {
    printf("i = %d\n", i);
	(*fun)(self, ptr);
    ptr = ptr->next;
    continue;
  }
  printf("... ptr(%p)->next(%p) is NULL. break.\n", ptr, ptr->next);

  printf("======== %s ======== */\n", __func__);
  return;
}

static void List_initialize(List *self) {
  initializeList(self);
  return;
}

static void List_destroy(List *self) {
  destroyList(self);
  return;
}

int main(int argc, char *argv[]) {
  int exit_status = 0;
  void *buf;
  char strbuf[256];

  // 1
  List list1 = newList();
  list1.initialize(&list1);
  sprintf(strbuf, "foo");
  memcpy(list1.data, strbuf, sizeof(strbuf));

  // 2
  List list2 = newList();
  list2.initialize(&list2);
  sprintf(strbuf, "bar");
  memcpy(list2.data, strbuf, sizeof(strbuf));

  list1.foreach(&list1, &(list1.dump));

  list1.append(&list1, &list2);
  list1.foreach(&list1, &(list1.dump));

  if(list1.terminate(&list1) != 0) goto err;

  list1.foreach(&list1, &(list1.dump));

  exit_status = EXIT_SUCCESS;
  goto clean_up_and_exit;

err:
  exit_status = EXIT_FAILURE;
  goto clean_up_and_exit;

clean_up_and_exit:
  list1.destroy(&list1);
  list2.destroy(&list2);
  printf("Exit with exit_status(%d)\n", exit_status);
  return exit_status;
}


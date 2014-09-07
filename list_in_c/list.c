#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "list.h"

static void List_append(List *self, List *target) {
  printf("\n/* ---- %s ----\n", __func__);
  List *ptr;

  printf("target(%p)->data(%p) is %s\n", target, target->data, target->data);

  ptr = self;
  for (int i=0;;i++) {
	printf("i = %d\n", i);
	printf("ptr(%p)->next(%p)\n", ptr, ptr->next);
	while(ptr->next) {
	  printf("... ptr(%p)->next(%p) is not NULL. Go ahead.\n", ptr, ptr->next);
	  printf("ptr->data is %s\n", ptr->data);
	  ptr = ptr->next;
	  printf("ptr->data is %s\n", ptr->data);
	}
	printf("... ptr(%p)->next(%p) is NULL. Append target(%p) to ptr->next(%p)\n", ptr, ptr->next, target, ptr->next);
	printf("target(%p)->data(%p) is %s\n", target, target->data, target->data);
	ptr->next = malloc(sizeof(void*));
	memcpy(ptr->next, target, sizeof(void*));
    printf("Now, ptr->next has become %p\n", ptr->next);
    ptr = ptr->next;
    printf("ptr->next(%p)->data(%p) is %s\n", ptr, ptr->data, ptr->data);
	break;
  }

  printf("---- %s ---- */\n", __func__);
  return;
}

static int List_terminate(List *self) {
  printf("\n/* ---- %s ----\n", __func__);
  List null_list = newList();
  printf("Terminate %p with null_list(%p)\n", self, &null_list);
  self->append(self, &null_list);

  printf("---- %s ---- */\n", __func__);
  return 0;
}

static void List_parse(List *self) {
  printf("\n/* ---- %s ----\n", __func__);
  List *ptr;

  ptr = self;
  for (int i=0;;i++) {
	printf("i = %d\n", i);
    printf("ptr(%p)->data(%p) = %s\n", ptr, ptr->data, ptr->data);
    printf("ptr(%p)->next(%p) = %p\n", ptr, ptr->next, ptr->next);
    if(!ptr->next) {
	  printf("... ptr(%p)->next(%p) is NULL. break.\n", ptr, ptr->next);
      break;
	};
	printf("... ptr(%p)->next(%p) is not NULL. continue.\n", ptr, ptr->next);
    ptr = ptr->next;
  }

  printf("---- %s ---- */\n", __func__);
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

  printf("list1(%p).data(%p) is %s\n", &list1, list1.data, list1.data);
  printf("list1(%p).next is %p\n", &list1, list1.next);
  printf("list2(%p).data(%p) is %s\n", &list2, list2.data, list2.data);
  printf("list2(%p).next is %p\n", &list2, list2.next);

  list1.append(&list1, &list2);
  printf("list1(%p).data(%p) is %s\n", &list1, list1.data, list1.data);
  printf("list1(%p).next is %p\n", &list1, list1.next);
  printf("list2(%p).data(%p) is %s\n", &list2, list2.data, list2.data);
  printf("list2(%p).next is %p\n", &list2, list2.next);

  if(list1.terminate(&list1) != 0) goto err;
  printf("list1(%p).data(%p) is %s\n", &list1, list1.data, list1.data);
  printf("list1(%p).next is %p\n", &list1, list1.next);
  printf("list2(%p).data(%p) is %s\n", &list2, list2.data, list2.data);
  printf("list2(%p).next is %p\n", &list2, list2.next);

  list1.parse(&list1);

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


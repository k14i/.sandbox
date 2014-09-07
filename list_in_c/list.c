#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "list.h"

static void List_append(List *self, List *target) {
  printf("---- %s ----\n", __func__);
  List *ptr;
  
  ptr = self;
  for (int i=0;;i++) {
	printf("i = %d\n", i);
	printf("ptr(%p)->next(%p)\n", ptr, ptr->next);
	if(ptr->next) {
	  printf("ptr(%p)->next(%p) is not NULL\n", ptr, ptr->next);
	  printf("ptr->data is %s\n", ptr->data);
	  ptr = ptr->next;
	  printf("ptr->data is %s\n", ptr->data);
	}
	printf("Append target(%p) to ptr->next(%p)\n", target, ptr->next);
    ptr->next = target;
    printf("Now, ptr->next is %p\n", ptr->next);
	break;
  }

  return;
}

static int List_terminate(List *self) {
  printf("---- %s ----\n", __func__);
  List null_list = newList();
  printf("Terminate %p\n", self);
  self->append(self, &null_list);
  return 0;
}

static void List_parse(List *self) {
  printf("---- %s ----\n", __func__);
  List *ptr;

  ptr = self;
  for (int i=0;;i++) {
	printf("i = %d\n", i);
    printf("ptr->data = %s\n", ptr->data);
    printf("ptr->next = %p\n", ptr->next);
    if(!ptr->next) break;
    printf("ptr->data = %s\n", ptr->data);
    ptr = ptr->next;
    printf("ptr->data = %s\n", ptr->data);
  }

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
  sprintf(strbuf, "foo");
  memcpy(list1.data, strbuf, sizeof(strbuf));

  printf("list1(%p)->data(%p) = %s\n", &list1, &(list1.data), list1.data);

  // 2
  List list2 = newList();
  sprintf(strbuf, "bar");
  memcpy(list2.data, strbuf, sizeof(strbuf));

  printf("list1(%p).data(%p) = %s\n", &list1, &(list1.data), list1.data);
  printf("list2(%p).data(%p) = %s\n", &list2, &(list2.data), list2.data);

  //list1->append(list1, list2);

/*
  if(list1->terminate(&list1) != 0) goto err;
  printf("list1->data = %s\n", list1->data);

  list1->parse(list1);
*/

  exit_status = EXIT_SUCCESS;
  goto clean_up_and_exit;

err:
  exit_status = EXIT_FAILURE;
  goto clean_up_and_exit;

clean_up_and_exit:
  list1.destroy(&list1);
  list2.destroy(&list2);
  return exit_status;
}


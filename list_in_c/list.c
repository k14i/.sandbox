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

int main(int argc, char *argv[]) {
  void *buf;
  char strbuf[256];

  //void *list = malloc(sizeof(List));
  //memset(list, 0, sizeof(list));
  //(List *)list = newList();
  List list = newList();

  // 1
  char *strbuf1 = malloc(sizeof(strbuf));
  memset(strbuf1, 0, sizeof(strbuf1));
  sprintf(strbuf1, "foo");
  
  List *list1 = malloc(sizeof(list));
  //memset(list1, 0, sizeof(list1));
  memcpy(list1, &list, sizeof(list));

  //list1->data = &strbuf;
  //sprintf(list1->data, strbuf);
  memcpy(list1->data, strbuf1, sizeof(strbuf1));
  printf("list1(%p)->data(%p) = %s\n", list1, list1->data, list1->data);
  //

/*
  // 2
  memset(strbuf, 0, sizeof(strbuf));
  sprintf(strbuf, "bar");
  List *list2 = malloc(sizeof(list));
  memcpy(list2, &list, sizeof(list));

  //list2->data = &strbuf;
  sprintf(list2->data, strbuf);
  printf("list1(%p)->data(%p) = %s\n", list1, list1->data, list1->data);
  printf("list2(%p)->data(%p) = %s\n", list2, list2->data, list2->data);
  //

  list1->append(list1, list2);
*/

/*
  if(list1->terminate(&list1) != 0) goto err;
  printf("list1->data = %s\n", list1->data);

  list1->parse(list1);
*/

  free(list1);
  return 0;

err:
  free(list1);
  return -1;
}


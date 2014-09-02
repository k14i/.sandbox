#include <stdio.h>
#include <string.h>

typedef struct
{
  void *data;
  void *next;
} List;

#define newList() { \
    NULL, NULL \
      }

int main(int argc, char *argv[]) {
  char foo[256];
  char bar[256];
  List *ptr;

  sprintf(foo, "foo");
  List list1 = newList();
  list1.data = &foo;
  //printf("%s\n", list1.data);
  
  sprintf(bar, "bar");
  List list2 = newList();
  list2.data = &bar;
  //printf("%s\n", list2.data);
  
  list1.next = &list2;
  //memcpy(ptr, &list1, sizeof(&list1));
  ptr = &list1;
  
  List list3 = newList();
  list2.next = &list3;
  
  //printf("%p, %p\n", ptr, &list1);
  printf("%p\n", ptr->next);
  
  for (int i=0;;i++) {
    printf("%p\n", ptr);
    if(!ptr->next) break;
    printf("%s\n", ptr->data);
    ptr = ptr->next;
  }

  return 0;
}

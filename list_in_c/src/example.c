#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "lib/list.h"

int main(int argc, char *argv[]) {
  printf("---- BEGIN main() ----\n");
  for (int i=0; i<1; i++) {
    ListHelper *list_helper = newListHelper();
    // NOTE: 'warning: expression result unused [-Wunused-value]' without cast.
    (void)list_helper->destroy(list_helper);
  }
  printf("---- END main() ----\n");

  /*
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

  //list1.foreach(&list1, &(list1.dump));
  list1.reverse(&list1, &(list1.dump));
  //List *ptr;
  //list1.last(&list1);
  //memcpy(ptr, list1.last(&list1), sizeof(List*));

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
  */
}


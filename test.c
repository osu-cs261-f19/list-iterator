#include <stdio.h>
#include <stdlib.h>

#include "list.h"

int main(int argc, char** argv) {
  int i, n = 16;
  int* data;
  struct list* list;

  /*
   * Create array of integer data and insert into a new list.
   */
  data = malloc(n * sizeof(int));
  list = list_create();
  for (i = 0; i < n; i++) {
    data[i] = 2 * i;
    list_insert(list, &data[i]);
  }

  /*
   * The code below generates compiler errors because I don't have access to
   * the internals of struct list or to struct link.  Without those things,
   * how do I print the values from the list?
   */
  printf("== List contents:\n");
  struct link* curr = list->head;
  while (curr) {
    printf("  - %d\n", *((int*)curr->val));
  }

  list_free(list);
  free(data);

  return 0;
}

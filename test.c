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
   * How do I print the values from the list??
   */

  list_free(list);
  free(data);

  return 0;
}

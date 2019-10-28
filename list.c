/*
 * This file contains a simple implementation of a singly-linked list.  See
 * the documentation below for more information on the individual functions in
 * this implementation.
 */

#include <stdlib.h>
#include <assert.h>

#include "list.h"

/*
 * This structure is used to represent a single link in a singly-linked list.
 * It is not defined in ll.h, so it is not visible to the user.
 */
struct link {
  void* val;
  struct link* next;
};

/*
 * This structure is used to represent an entire singly-linked list.  Note that
 * we're keeping track of just the head of the list here, for simplicity.
 */
struct list {
  struct link* head;
};

/*
 * This function allocates and initializes a new, empty linked list and
 * returns a pointer to it.
 */
struct list* list_create() {
  struct list* list = malloc(sizeof(struct list));
  list->head = NULL;
  return list;
}

/*
 * This function frees the memory associated with a linked list.  Freeing any
 * memory associated with values still stored in the list is the responsibility
 * of the caller.
 *
 * Params:
 *   list - the linked list to be destroyed.  May not be NULL.
 */
void list_free(struct list* list) {
  assert(list);

  /*
   * Free all individual links.
   */
  struct link* next, * curr = list->head;
  while (curr != NULL) {
    next = curr->next;
    free(curr);
    curr = next;
  }

  free(list);
}

/*
 * This function inserts a new value into a given linked list.  The new element
 * is always inserted as the head of the list.
 *
 * Params:
 *   list - the linked list into which to insert an element.  May not be NULL.
 *   val - the value to be inserted.  Note that this parameter has type void*,
 *     which means that a pointer of any type can be passed.
 */
void list_insert(struct list* list, void* val) {
  assert(list);

  /*
   * Create new link and insert at head.
   */
  struct link* link = malloc(sizeof(struct link));
  link->val = val;
  link->next = list->head;
  list->head = link;
}

/**************************************************************************
 **
 ** Iterator implementation
 **
 **************************************************************************/

/*
 * This is the structure used to represent a lined list iterator.  The way we
 * typically iterate through a linked list is to keep a pointer to the current
 * link, starting with the head of the list, and move that pointer from link
 * to link, via `next` pointers.  The structure here is designed to do exactly
 * that, keeping track of the current link in the pointer `curr`.
 */
struct list_iterator {
  struct link* curr;
};

/*
 * This function creates a new list iterator.  The iterator is tied to a
 * a specific list (the parameter `list`).  The iterator is specifically
 * initialized to start iterating at the head of this list.
 */
struct list_iterator* list_iterator_create(struct list* list) {
  struct list_iterator* iter = malloc(sizeof(struct list_iterator));
  iter->curr = list->head;
  return iter;
}

/*
 * This function frees a list iterator, undoing the memory allocation from
 * list_iterator_create().
 */
void list_iterator_free(struct list_iterator* iter) {
  free(iter);
}

/*
 * This function implements the iterator's next() function.  It specifically
 * returns the value of the current link and then updates the iterator to
 * point to the next link in the list.
 */
void* list_iterator_next(struct list_iterator* iter) {
  void* val = iter->curr->val;
  iter->curr = iter->curr->next;
  return val;
}

/*
 * This function implements the iterator's has_next() function.  It returns
 * "true" (i.e. 1) if there is at least one more value to examine in the
 * iteration and "false" (i.e. 0) when the iteration is over (i.e. when the
 * `curr` pointer has reached the end of the list and points to NULL).
 */
int list_iterator_has_next(struct list_iterator* iter) {
  return iter->curr != NULL;
}

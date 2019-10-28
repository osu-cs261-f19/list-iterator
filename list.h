/*
 * This file contains the definition of the interface for a linked list.  You
 * can find descriptions of the linked list functions, including their
 * parameters and their return values, in list.c.
 */

#ifndef __LIST_H
#define __LIST_H

/*
 * Structure used to represent a singly-linked list.
 */
struct list;

/*
 * Linked list interface function prototypes.  Refer to list.c for
 * documentation about each of these functions.
 */
struct list* list_create();
void list_free(struct list* list);
void list_insert(struct list* list, void* val);

/*
 * The linked list iterator interface is defined below.  Refer to list.c for
 * documentation about each of these structures and functions.
 */
struct list_iterator;

struct list_iterator* list_iterator_create(struct list* list);
void list_iterator_free(struct list_iterator* iter);
void* list_iterator_next(struct list_iterator* iter);
int list_iterator_has_next(struct list_iterator* iter);

#endif

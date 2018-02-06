/* Melanie Chow
   CS152, Winter 2018
   HW#4 - String Doubly-linked list
*/

#include "sdll.h"
#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include "string.h"

/* Create a new empty list. It is a container struct with two NULL pointers. */
sdll *list_new()
{
	sdll *retlist = malloc(sizeof(sdll));
	node *list_first=malloc(sizeof(node));
	node *list_last=malloc(sizeof(node));
	list_first=NULL;
	list_last=NULL;
	retlist->first = list_first;
	retlist->last = list_last;
	return retlist;
}

/* Free the whole list, including all strings and the container. */
void list_free(sdll *list)
{
	node *tempNode = list->first;
	char *val = malloc(sizeof(char));
	while (tempNode != NULL){
		node *toFree = tempNode;
		tempNode=tempNode->next;

		val=strdup(toFree->value);
		free(val);
		free(toFree);
	}
	free(tempNode);
	free(list);
}

/* Display a reasonable textual version of the node to f. */
void node_show(FILE *f, node *nd)
{
	if (nd == NULL){
		fprintf(f, "[ ]");
	}
	else {
		fprintf(f, "[%s]", nd->value);
	}
}

/* Display a reasonable textual version of the list to f, with sep between nodes. */
void list_show(FILE *f, sdll *list, char sep)
{
	if (list == NULL){
		fprintf(f, "[ ]");
	}
	else {
		node *tempNode = list->first;
		while (tempNode != NULL){
			node_show(f,tempNode);
			if (tempNode->next != NULL){
				putchar(sep);
			}
			tempNode=tempNode->next;
		}
	}
}

/* Return the first occurrence of the node containing the string, or NULL. */
node *find_first(sdll *list, char *val)
{
	node *tempNode = list->first;
	while(tempNode != NULL){
		if (strcmp(tempNode->value,val) == 0){
			return tempNode;
		}
		else {
			tempNode = tempNode->next;
		}
	}
	return NULL;
}

/* Return the first node in the list. */
node *get_first(sdll *list)
{
	return list->first;
}

/* Return the last node in the list. */
node *get_last(sdll *list)
{
	return list->last;
}

/* Return a pointer to the next node, or NULL.
 * Note: the list pointer need not be used in the implementation.
 */
node *get_next(sdll *list, node *nd)
{
	return nd->next;
}

/* Return a pointer to the previous node, or NULL.
 * Note: the list pointer need not be used in the implementation.
 */
node *get_previous(sdll *list, node *nd)
{
	return nd->prev;
}

/* Return a pointer to the node at the given index, starting at 0. */
node *get_at_index(sdll *list, size_t index)
{
	node *tempNode = list->first;
	for (int i = 0; i<index ; i++){
		if (tempNode == NULL){
			return NULL;
		}
		tempNode=tempNode->next;
	}
	return tempNode;
}

/* Insert a new node pointing to a duplicate of new_val after the first
 * occurrence of the sought_val, if sought_val occurs in the list;
 * otherwise return NULL.
 */
sdll *insert_after(sdll *list, char *sought_val, char *new_val)
{
	node *to_be_inserted=malloc(sizeof(node));
	to_be_inserted->value = new_val;
	node *tempNode=list->first;
	while (tempNode != NULL){
		if (strcmp(tempNode->value,sought_val)==0){
			//if inserting after last element
			if (tempNode->next == NULL){
				tempNode->next=to_be_inserted;
				to_be_inserted->prev=tempNode;
				to_be_inserted->next = NULL;
				list->last = to_be_inserted;
			}
			else{
				node *oldNext = tempNode->next;
				tempNode->next = to_be_inserted;
				to_be_inserted->next = oldNext;
				to_be_inserted->prev = tempNode;
				oldNext->prev = to_be_inserted;
			}
			return list;
		}
		tempNode=tempNode->next;
	}
	return NULL;
}


/* Insert a new node pointing to a duplicate of new_val before the first
 * occurrence of the sought_val, if sought_val occurs in the list;
 * otherwise return NULL.
 */
sdll *insert_before(sdll *list, char *sought_val, char *new_val)
{
	node *to_be_inserted=malloc(sizeof(node));
        to_be_inserted->value = new_val;
        node *tempNode=list->first;
        while (tempNode != NULL){
                if (strcmp(tempNode->value,sought_val)==0){
			//if inserting before the 1st element
			if (tempNode->prev == NULL){
				to_be_inserted->next=tempNode;
				to_be_inserted->prev=NULL;
				tempNode->prev = to_be_inserted;
				list->first = to_be_inserted;
			}
			else {
                        	node *oldPrev = tempNode->prev;
                        	oldPrev->next = to_be_inserted;
				to_be_inserted->next = tempNode;
				to_be_inserted->prev = oldPrev;
				tempNode->prev = to_be_inserted;
        		}
			return list;
		}
		tempNode=tempNode->next;
	}
	return NULL;
}
/* Insert a new node pointing to a duplicate of new_val in the given position.
 * Return NULL if the list has no such position.
 */
sdll *insert_at_index(sdll *list, size_t index, char *new_val)
{
	node *tempNode = get_at_index(list, index);
	//if list does not have such postion
	if (tempNode == NULL){
		return NULL;
	}

	node *to_be_inserted=malloc(sizeof(node));
        to_be_inserted->value = new_val;
	//inserting at front
	if (tempNode->prev == NULL){
		to_be_inserted->next=tempNode;
                to_be_inserted->prev=NULL;
                tempNode->prev = to_be_inserted;
		list->first = to_be_inserted;
	}
	else {
		node *oldPrev = tempNode->prev;
		oldPrev->next = to_be_inserted;
		to_be_inserted->next = tempNode;
		to_be_inserted->prev = oldPrev;
		tempNode->prev = to_be_inserted;
	}
	return list;
}

/* Remove the first node containing an occurrence of sought_val,
 * if one exists, freeing it and its string.  If there is no such occurrence,
 * return NULL.
 */
sdll *remove_first(sdll *list, char *sought_val)
{
	node *tempNode = list->first;
	char *val=malloc(sizeof(val));
	while (tempNode != NULL){
                if (strcmp(tempNode->value,sought_val)==0){
			node *tempPrev = tempNode->prev;
			node *tempNext = tempNode->next;
			//if removing first item
			if (tempPrev == NULL){
				list->first = tempNext;
				tempNext->prev = NULL;
			}
			else if (tempNext == NULL){
				list->last = tempPrev;
				tempPrev->next = NULL;
			}
			else {
				tempPrev->next = tempNext;
				tempNext->prev = tempPrev;
			}
			val=strdup(tempNode->value);
			free(val);
			free(tempNode);
			return list;
		}
		tempNode = tempNode->next;
	}
	return NULL;
}

/* Remove all nodes containing an occurrence of sought_val,
 * if they exist, freeing them and their strings. If there is no such occurrence,
 * return NULL.
 */
sdll *remove_all(sdll *list, char *sought_val)
{
	if (remove_first(list,sought_val) == NULL){
		return NULL;
	}
	//recusively calling remove_first, updating the list everytime
	while (remove_first(list, sought_val) != NULL){
		remove_first(list, sought_val);
	}
	return list;
}


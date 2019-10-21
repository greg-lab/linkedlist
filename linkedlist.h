#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct List_t {
	struct Element_t {
		char * str;
		struct Element_t * next;
	};

	size_t len;
	struct Element_t * head;
};

typedef struct List_t List;
typedef struct Element_t Element;

// Creates new linked list and returns pointer to it.
struct List_t * lcreateList();

// Adds element to the list.		
int lpush(struct List_t * list, const char * str);


// Checks whether there is an element with the same value as passed argument 'str'.
int lfind(struct List_t * list, const char * str);

// Removes the element with the same value as passed argument 'str' (first occurence).
void ldrop(struct List_t * list, const char * str);

// Returns the first element.
struct Element_t * lhead(struct List_t * list);

// Returns next element.
struct Element_t * lnext(struct Element_t * element);

// Returns the string which is stored by the element.
char * lvalue(struct Element_t * element);

// Returns the number of elements.
size_t llen(struct List_t * list);

// Pointer to a function.
typedef void (*func)(char *, void *);

// Calls function passed in the second argument for every element in the list.
// Function must accept argument of type char * and argument of type void *.
void lforeach(struct List_t * list, func foo, void * param);

// Removes all elements.
void lclear(struct List_t * list);
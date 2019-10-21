#include "linkedList.h"


struct List_t * lcreateList() {
	struct List_t * newList = malloc(sizeof(struct List_t));
	if (newList == NULL)
		return NULL;

	newList->head = NULL;
	newList->len = 0;
	return newList;
}


int lpush(struct List_t * list, const char * str) {
	struct Element_t * newElement = malloc(sizeof(struct Element_t));
	if (newElement == NULL)
		return 1;

	size_t bufSize = strlen(str);
	newElement->str = malloc(bufSize + 1);
	if (newElement->str == NULL) {
		free(newElement);
		return 1;
	}

	strncpy(newElement->str, str, bufSize);
	newElement->str[bufSize] = '\0';

	newElement->next = list->head;
	list->head = newElement;
	list->len++;
	return 0;
}


int lfind(struct List_t * list, const char * str) {
	struct Element_t * ptr = list->head;

	while (ptr) {
		if (strcmp(ptr->str, str) == 0)
			return 1;
		ptr = ptr->next;
	}

	return 0;
}


void ldrop(struct List_t * list, const char * str) {
	struct Element_t * ptr = list->head;

	if (llen(list) == 0) {
		return;
	} else if (strcmp(ptr->str, str) == 0) {
		list->head = ptr->next;
		free(ptr->str);
		free(ptr);
		list->len--;
	} else {
		struct Element_t * tmp = ptr;
		ptr = ptr->next;

		while (ptr) {
			if (strcmp(ptr->str, str) == 0) {
				tmp->next = ptr->next;
				free(ptr->str);
				free(ptr);
				list->len--;
				return;
			}
			tmp = ptr;
			ptr = ptr->next;
		}
	}
}


struct Element_t * lhead(struct List_t * list) {
	return list->head;
}


struct Element_t * lnext(struct Element_t * element) {
	return element->next;
}


char * lvalue(struct Element_t * element) {
	return element->str;
}


size_t llen(struct List_t * list) {
	return list->len;
}


void lforeach(struct List_t * list, func foo, void * param) {
	struct Element_t * ptr = list->head;

	while (ptr) {
		foo(ptr->str, param);
		ptr = ptr->next;
	}
}

void lclear(struct List_t * list) {
	list->len = 0;

	struct Element_t * ptr = list->head;
	while (ptr) {
		struct Element_t * tmp = ptr;
		ptr = ptr->next;
		free(tmp->str);
		free(tmp);
	}

	list->head = NULL;
}
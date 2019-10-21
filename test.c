#include "linkedlist.h"

void print(char * str, void * param) {
	printf("From print: %s\n", str);
}

int main(void) {

	List * myList = lcreateList();
	if (myList == NULL)
		return 1;

	lpush(myList, "hello world");
	lpush(myList, "hello world1");
	lpush(myList, "hello world2");

	Element * iter = myList->head;

	while (iter) {
		printf("From printf: %s\n", lvalue(iter));
		iter = iter->next;
	}

	// You can use the last argument to pass arguments to your function.
	lforeach(myList, print, NULL);

	lclear(myList);
	free(myList);

	return 0;
}
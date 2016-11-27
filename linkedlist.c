#include <stdio.h>
#include <stdlib.h>

typedef char BOOL;
#define true 	1
#define false	0

int cmpfunc (const void * a, const void * b)
{
   return *((int*)a) - *((int*)b);
}

BOOL isDuplicate(int* array, int size);
BOOL isDuplicate(int* array, int size) {
	qsort(array, size, sizeof(int), cmpfunc);
	for (int i = 0; i < size-1; ++i) {
		if (array[i] == array[i+1]) {
			return true;
		}
	}
	
	return false;
	
}

typedef struct Node {
	int val;
	struct Node* next;
} Node;

Node* g_head = NULL;
Node* g_current = NULL;

BOOL listExists();
inline BOOL listExists() {
	return g_head != NULL ? true : false;
}

void insert(int val);
void insert(int val) {
	if (!listExists()) {
		g_head = (Node*)malloc(sizeof(Node));
		g_head->next = (Node*)malloc(sizeof(Node));
		g_head->next->val = val;
		g_current = g_head->next;
		g_current->next = NULL;
		g_head->val = 1;
	} else {
		g_current->next = (Node*)malloc(sizeof(Node));
		g_current->next->val = val;
		g_current = g_current->next;
		g_current->next = NULL;
		g_head->val++;
	}
}

void delete(int val);
void delete(int val) {
	if (listExists()) {
		Node* current = g_head;
		Node* previous = g_head;
	
		for (; (((current = current->next) != NULL) && (current->val != val)); previous = current);
	
		if (current != NULL) {
			previous->next = current->next;
			free(current);
			g_head->val--;
		}
	}
}

BOOL find(int val);
BOOL find(int val) {
	if (listExists()) {
		Node* current = g_head;
		while (((current = current->next) != NULL) && (current->val != val));
			
		if (current != NULL) {
			return true;
		}
	}
	
	return false;
}

void reverse();
void reverse() {
	if (listExists()) {
		Node* current = g_head->next->next, *prev = g_head->next;
		Node* next = current->next;
	
		prev->next = NULL;
		g_current = prev;
	
		while (next != NULL) {
			current->next = prev;
			prev = current;
			current = next;
			next = current->next;
		}
	
		current->next = prev;
	
		free(g_head);
		g_head = (Node*)malloc(sizeof(Node));
		g_head->next = current;
	}
}

void destroy();
void destroy() {
	if (listExists()) {
		Node* current = g_head;
		Node* previous = g_head;
		while ((current = current->next) != NULL) {
			previous = current;
			free(previous);
		}
		
		free(g_head);
		g_head = NULL;
		g_current = NULL;
	}
}

unsigned int length();
unsigned int length() {
	return listExists() ? g_head->val : 0;
}

void printList();
void printList() {
	if (listExists()) {
		Node* current = g_head;;
		while ((current = current->next) != NULL) {
			printf("%d\n", current->val);
		}
		printf("\n");
	}
}

void reverseString(char* string, int length) {
	if (length < 0) {
		return;
	} else {
		printf("%c", string[length]);
		reverseString(string, length-1);
	}
}


int main(int argc, char *argv[]) {
	//printf("%d\n %s\n", argc, *argv);
	
	//int array[] = {10,4,2,3,6,7,9,0,1,12,11,8,5};
	//printf ("%d", isDuplicate(array, 13));
	
	insert(1);
	insert(3);
	insert(5);
	insert(0);
	insert(9);
	//printList();
	//delete(5);
	//printList();
	//delete(9);
	printList();
	delete(9);
	printList();
	destroy();
	printf("%d\n\n", length());
	printList();
	insert(1);
	insert(3);
	insert(5);
	insert(0);
	insert(9);
	printList();
	reverse();
	printList();
	insert(2);
	insert(10);
	printList();
	reverse();
	printList();
	delete(10);
	reverse();
	printList();
	printf("%d\n\n", length());
	printf("%d\n\n", find(3));
	printf("%d\n\n", find(10));
	
	reverseString("Christian", 9);
	
	return 0;
}

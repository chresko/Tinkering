#include <stdio.h>
#include <stdlib.h>

int fibr(int n) {
	static double i = 0;
	printf("call %f\n", ++i);
	int r = 0;
	if (n == 1 || n == 2) {
		return 1;
	} else {
		r = fibr(n-1) + fibr(n-2);
	}
	
	return r;
}

int fibi(int n) {
	int r = 0;
	if (n == 1 || n == 2) {
		return 1;
	} else {
		int p1 = 1;
		int p2 = 1;
		for (int i = 2; i < n; ++i) {
			r = p1 + p2;
			p2 = p1;
			p1 = r;
		}
	}
	
	return r;
}

typedef struct Node {
	int val;
	struct Node* next;
} Node;

static Node* head = NULL;
static Node* current = NULL;

void insert(int val) {
	if (head == NULL) {
		head = (Node*)malloc(sizeof(Node));
		head->val = val;
		current = head;
	} else {
		current->next = (Node*)malloc(sizeof(Node));
		current = current->next;
		current->val = val;
	}
}

void printList() {
	Node* i = head;
	while (i != NULL) {
		printf("%d\n", i->val);
		i = i->next;
	}
}

void clearList() {
	Node* i = head;
	while (i != NULL) {
		Node* j = i->next;
		free(i);
		i = j;
	}
	head = NULL;
	current = NULL;
}

typedef char bool;
#define false	0
#define true	1

bool binsearchr(int* array, int low, int high, int val) {
	if (low > high) {
		return false;
	}
	bool found = false;
	int mid = (low+high)/2;
	if (val < array[mid]) {
		found = binsearchr(array, low, mid-1, val);
	} else if (val > array[mid]) {
		found = binsearchr(array, mid+1, high, val);
	} else {
		found = true;
	}
	
	return found;
}

bool binsearchi(int* array, int high, int val) {
	int found = false;
	int low = 0;
	int mid = 0;
	while(low <= high) {
		mid = (low+high)/2;
		if (val < array[mid]) {
			high = mid - 1;
		} else if (val > array[mid]) {
			low = mid + 1;
		} else {
			found = true;
			break;
		}
	}
	
	return found;
}

typedef struct TreeNode {
	struct TreeNode* left;
	struct TreeNode* right;
	int val;
} TreeNode;

static TreeNode* root = NULL;

void _add(int, TreeNode**);
void add(int val) {
	_add(val, &root);
}

void _add(int val, TreeNode** node) {
	if (*node == NULL) {
		*node = (TreeNode*)malloc(sizeof(TreeNode));
		(*node)->left = NULL;
		(*node)->right = NULL;
		(*node)->val = val;
	} else {
		if (val < (*node)->val) {
			_add(val, &((*node)->left));
		} else if (val > (*node)->val) {
			_add(val, &((*node)->right));
		}
	}
}

bool _find(int, TreeNode*);
bool find(int val) {
	bool found = false;
	if (root != NULL) {
		found = _find(val, root);
	}
	
	return found;
}

bool _find(int val, TreeNode* node) {
	bool found = false;
	if (node == NULL) {
		found = false;
	} else {
		if (val == node->val) {
			found = true;
		} else if (val < node->val) {
			found = _find(val, node->left);
		} else if (val > node->val) {
			found = _find(val, node->right);
		}
	}
	
	return found;
}

// 1 2 4 8 16 32 64 128 256
bool isPowerOf2(unsigned int n) {
	return !(n & n-1);
}


typedef int int64[2];

int main() {
	//int r = fibr(26);
	//printf("%d\n", r);
	//int r = fibi(76);
	//printf("%d\n", r);
	//for (int i = 0; i < 1076; ++i) {
		//insert(i);
	//}
	//printList();
	//clearList();
	//printList();
	
	//int array[] = {1,2,3,4,5,6,7,8,9};
	//bool found = binsearchr(array, 0, 8, 9);
	//printf("%d", found);
	
	//add(10);
	//add(5);
	//add(20);
	//add(8);
	//add(7);
	//add(4);
	//add(15);
	//add(17);
	//add(25);
	
	//bool found = find(15);
	//printf("%d", found);
	
	//printf("%d\n", isPowerOf2(8));
	//printf("%d\n", isPowerOf2(7));
	//printf("%d\n", isPowerOf2(4));
	//printf("%d\n", isPowerOf2(1));
	
	int64* ptr = NULL;
	++ptr;
	printf("%d", ptr);
	
	int64 a;
	a[0] = 12345;
	a[1] = 12345;
	//int array[] = {1,2,3,4,5,6,7,8,9};
	//bool found = binsearchi(array, 8, 1);
	//printf("%d", found);
	
	return 0;
	
}
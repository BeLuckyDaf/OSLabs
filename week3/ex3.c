#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int data;
	struct Node* next;
} Node;

typedef struct LinkedList {
	Node* head;
} LinkedList;

LinkedList* create_linked_list() {
	LinkedList *list = (LinkedList*)malloc(sizeof(LinkedList));
	list->head = NULL;
	return list;
}

void print_list(LinkedList* list) {
	if (!list || !list->head) return;
	Node* item = list->head;
	while(item) {
		printf("%d ", item->data);
		item = item->next;
	}
	printf("\n");
}

void insert_node(LinkedList* list, int data) {
	if (!list) return;

	Node* node = (Node*)malloc(sizeof(Node));
	node->data = data;
	node->next = NULL;

	if (!list->head) list->head = node;
	else {
		Node* item = list->head;
		while(item->next) item = item->next;
		item->next = node;
	}
}

void delete_node(LinkedList* list, int data) {
	if (!list || !list->head) return;
	Node* node = list->head;
	if (node->data == data) {
		list->head = node->next;
		free(node);
	} else {
		while(!node->next || node->next->data != data) node = node->next;
		if (!node->next) return;
		Node* deleted = node->next;
		node->next = deleted->next;
		free(deleted);
	}
}

int main() {
	LinkedList* list = create_linked_list();
	insert_node(list, 2);
	insert_node(list, 5);
	insert_node(list, 4);
	insert_node(list, 7);
	insert_node(list, 3);

	print_list(list);

	delete_node(list, 4);

	print_list(list);

	delete_node(list, 3);

	print_list(list);

	return 0;
}

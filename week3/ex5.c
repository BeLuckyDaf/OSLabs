#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int data;
	struct Node* next;
	struct Node* prev;
} Node;

typedef struct LinkedList {
	Node* head;
	Node* tail;
} LinkedList;

LinkedList* create_linked_list() {
	LinkedList *list = (LinkedList*)malloc(sizeof(LinkedList));
	list->head = NULL;
	list->tail = NULL;
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
	node->prev = list->tail;
	if (list->tail) list->tail->next = node;
	list->tail = node;

	if (!list->head) list->head = node;
}

void delete_node(LinkedList* list, int data) {
	if (!list || !list->head) return;
	if (list->head == list->tail) {
		if (list->head->data != data) return;
		free(list->head);
		list->head = list->tail = NULL;
	} else {
		Node* item = list->head;
		while(item && item->data != data) item = item->next;
		if(!item) return;
		item->prev->next = item->next;
		list->tail = item->prev;
		free(item);
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

#include <stdio.h>
#include <stdlib.h>

void* my_realloc(void* ptr, size_t bytes) {
	if (bytes <= 0) {
		free(ptr);
		return NULL;
	}

	void* new_ptr = malloc(bytes);
	if (ptr != NULL) {
		for(int i = 0; i < bytes; i++) {
			((char*)new_ptr)[i] = ((char*)ptr)[i];
		}
		free(ptr);
	}

	return new_ptr;
}

int main() {
	int *a = malloc(10 * sizeof(int));
	for(int i = 0; i < 10; i++) {
		a[i] = i;
		printf("%d ", a[i]);
	}
	printf("\n");

	a = my_realloc(a, sizeof(int) * 20);
	for(int i = 0; i < 20; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");

	return 0;
}



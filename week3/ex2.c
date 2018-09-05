#include <stdio.h>

void swap(int *a, int *b) {
	int t = *a;
	*a = *b;
	*b = t;
}

void bubble_sort(int *a, size_t s) {
	for (int i = 0; i < s; i++)
		for (int j = 0; j < s-1; j++)
			if (a[j] > a[j+1]) swap(&a[j], &a[j+1]);
}

void print_array(int *a, size_t s) {
	for (int i = 0; i < s; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");
}

int main() {
	int array[5] = {1, 6, 3, 4, 2};
	print_array(array, 5);
	bubble_sort(array, 5);
	print_array(array, 5);

	return 0;
}

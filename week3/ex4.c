#include <stdio.h>

void swap(int *a, int i, int j) {
	int t = a[i];
	a[i] = a[j];
	a[j] = t;
}

void qsort(int *a, int f, int t) {
	if (f >= t) return; 
	int p = a[t];
	int i = f;
	for(int j = f; j < t; j++) {
		if (a[j] <= p) {
			swap(a, i, j);
			i++;
		}
	}
	swap(a, i, t);
	qsort(a, f, i-1);
	qsort(a, i+1, t);
}

void printar(int *a, size_t s) {
	for(int i = 0; i < s; i++) printf("%d ", a[i]);
	printf("\n");
}

void quick_sort(int *a, size_t s) {
	qsort(a, 0, s-1);
}

int main() {
	int arr[10] = { 2, 4, 3, 6, 5, 10, 3, 1, 5, 9 };
	printar(arr, 10);
	quick_sort(arr, 10);
	printar(arr, 10);
	
	return 0;
}

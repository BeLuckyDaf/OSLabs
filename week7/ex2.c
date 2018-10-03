#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define INPUT_SIZE 12

int main() {
	int N;
	char input[INPUT_SIZE];
	
	printf("Please enter a value for N: ");
	fgets(input, INPUT_SIZE, stdin);
	N = atoi(input);

	if (N <= 0) return 1;

	int * const array = (int*)malloc(N * sizeof(int));
	for (int i = 0; i < N; i++) array[i] = i;
	for (int i = 0; i < N; i++) printf("%d ", array[i]);
	printf("\n");
	free(array);

	return 0;
}

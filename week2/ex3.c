#include <stdio.h>

void print_slope(int n) {
	for (int i = n-1; i >= 0; i--) {
		for (int j = n-i; j > 0; j--) printf("*");
		printf("\n");
	}
}

void print_side_pyramide(int n) {
	for (int i = 0; i <= n/2 + n%2; i++) {
		for (int j = 0; j < i; j++) printf("*");
		printf("\n");
	}
	for (int i = n/2; i >= 0; i--) {
		for (int j = i; j > 0; j--) printf("*");
		printf("\n");
	}
}

void print_default(int n) {
	for (int i = n-1; i >= 0; i--) {
		for (int j = i; j > 0; j--) printf(" ");
		for (int j = 2*(n-i) - 1; j > 0; j--) printf("*");
		printf("\n");
	}
}

void print_wall(int n) {
	for(int i = 0; i < n; i++)  {
		for(int j = 0; j < n; j++) printf("*");
		printf("\n");
	}
}

int main(int argc, char** argv) {
	int n, c;
	printf("Please make your printing choice:\n");
	printf("1. Slope\n2. Side Pyramide\n3. Default\n4. Wall\n");
	sscanf(argv[1], "%d", &n);
	scanf("%d", &c);
	
	switch(c) {
		case 1:
			print_slope(n);
			break;
		case 2:
			print_side_pyramide(n);
			break;
		case 3:
			print_default(n);
			break;
		case 4:
			print_wall(n);
			break;
	}

	return 0;
}

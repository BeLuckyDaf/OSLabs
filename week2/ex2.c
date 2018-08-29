#include <stdio.h>
#include <string.h>

int main() {
	char string[256];
	fgets(string, 256, stdin);
	
	for (int i = strlen(string); i >= 0; i--) {
		printf("%c", string[i]);
	}

	printf("\n");

	return 0;
}

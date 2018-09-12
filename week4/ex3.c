#include <stdio.h>

int main() {
	char command[256];
	while(1) {
		fgets(command, 256, stdin);
		system(command);
	}

	return 0;
}

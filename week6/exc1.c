#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#define STRING_SIZE 128

int main() {
	int pipefd[2];
	char s1[STRING_SIZE] = "This is a sample string.";
	char s2[STRING_SIZE];

	if (pipe(pipefd) == -1) {
		printf("Error creating a pipe.\n");
		exit(1);
	}

	write(pipefd[1], s1, STRING_SIZE);
	read(pipefd[0], s2, STRING_SIZE);
	
	printf("String 1: %s\nString 2: %s\n", s1, s2);
	
	return 0;
}

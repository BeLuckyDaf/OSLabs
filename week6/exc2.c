#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

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
	close(pipefd[1]);
	printf("String 1: %s\n", s1);

	pid_t pid = fork();

	if (pid == 0) {
		read(pipefd[0], s2, STRING_SIZE+1);
		printf("String 2: %s\n", s2);
	} else {
		int status = 0;
		wait(&status);
	}
		
	return 0;
}

#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include <string.h>

int main() {	// whatever you type will be executed in a separate child process
	char command[200];	// and printed to /dev/null unless you specify a different place
	pid_t pid = getpid();	// for example use "pstree > output.txt" to print into a file
	while(1) {		// then the process will go zombie
		char message[256];
		printf("BackgroundShell~$: ");

		fgets(command, 200, stdin);
		strcat(message, command);

		message[strcspn(message, "\n")] = 0;
		strcat(message, " > /dev/null\n");	// add /dev/null to avoid receiving the output

		pid = fork();
		if (pid == 0) {	// execute the command if the process is the child process
			system(message);	// continue otherwise
			exit(0);
		}
	}

	return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
	int pipefd[2];
	if (pipe(pipefd) == -1) printf("Error creating a pipe.\n");

	char pidm[32];

	pid_t pid1, pid2;

	pid1 = fork();
	if (pid1 == 0) {
		read(pipefd[0], pidm, 32);
		close(pipefd[0]);
		pid2 = atoi(pidm);
		sleep(2);
		kill(pid2, SIGSTOP);
		printf("SIGSTOP sent to child 2\n");
		sleep(2);
		kill(pid2, SIGCONT);
		printf("SIGCONT sent to child 2\n");
		sleep(2);
		kill(pid2, SIGTERM);
		printf("Killed child 2.\n");
	} else {
		pid2 = fork();
		if (pid2 == 0) {
			while(1) { }
		} else {
			snprintf(pidm, 32, "%d", pid2);
			write(pipefd[1], pidm, 32);
			close(pipefd[1]);
			
			int status = 0;
			int pid = 0;
			while(1) {
				while((pid = waitpid(pid2, &status, WNOHANG)) == 0);
				printf("Child 2 changed status to %d.\n", status);
				if(pid == -1) break;
			}
		}
	}

	return 0;
}

#include <stdio.h>
#include <signal.h>
#include <sys/types.h>
#include <stdlib.h>

static void handler(int signum) {
	switch(signum) {
	case SIGINT:
		printf("\n---\nUser-Interrupted. Cleaning up...\nExiting...\n---\n");
		exit(0);
		break;
	case SIGSTOP:
		printf("\n---\nSTOPPED.\n---\n");
		break;
	case SIGKILL:
		printf("\n---\nKILLED.\n---\n");
		break;
	case SIGUSR1:
		printf("\n---\nCUSTOM USER SIGNAL RECEIVED.\n---\n");
		break;
	default:
		printf("\n---\nUNHADLED SIGNAL RECEIVED.\n---\n");
	}
}

int main() {
	struct sigaction sa;
	sa.sa_handler = handler;
	
	sigaction(SIGINT, &sa, NULL);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGKILL, &sa, NULL);
	sigaction(SIGSTOP, &sa, NULL);

	while(1) { }

	return 0;
}

#include <stdio.h>
#include <signal.h>
#include <sys/types.h>
#include <stdlib.h>

static void handler(int signum) {
	if (signum == SIGINT) {
		printf("\n---\nUser-Interrupted. Cleaning up...\nExiting...\n---\n");
		exit(0);
	}
}

int main() {
	struct sigaction sa;
	sa.sa_handler = handler;
	
	sigaction(SIGINT, &sa, NULL);

	while(1) { }
}

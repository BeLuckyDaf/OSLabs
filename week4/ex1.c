#include <sys/types.h>
#include <stdio.h>

int main() {
	pid_t n;
	switch(n = fork()) {
	case 0:
		printf("Hello from child [PID - %d]\n", getpid());
		break;
	default:
		printf("Hello from parent [PID - %d]\n", getpid());
		break;
	}
	return 0;
}

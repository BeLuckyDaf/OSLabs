#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/resource.h>

#define MB 10

int main() {
	size_t s = MB * 1024 * 1024;
	struct rusage usage;
	
	printf("- - - - - -\n");
	for (int i = 0; i < 10; i++) {
		void *p = malloc(s);
		memset(p, 0, s);
		getrusage(RUSAGE_SELF, &usage);
		
		printf("Memory Usage: %ld\n", usage.ru_maxrss);
		printf("- - - - - -\n");

		sleep(1);
	}

	return 0;
}

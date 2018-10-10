#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#define MB 10

int main() {

	size_t s = MB * 1024 * 1024;
	for (int i = 0; i < 10; i++) {
		void *p = malloc(s);
		memset(p, 0, s);
		sleep(1);
	}

	return 0;
}

#include <stdio.h>
#include <limits.h>
#include <float.h>

int main() {
	int i;
	float f;
	double d;

	i = INT_MAX;
	f = FLT_MAX;
	d = DBL_MAX;

	printf("Int: %d\nIntSize: %ld\nFloat: %f\nFloatSize: %ld\nDouble: %lf\nDoubleSize: %ld\n", i, sizeof i, f, sizeof f, d, sizeof d);

	return 0;
}

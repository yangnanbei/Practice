#include <stdio.h>

typedef struct mem1_ {
	double a;
	char b;
	char c[16];
} mem1;

int main() {
	mem1 mem_1;
	mem_1.a = 3;
	printf("a is %f\n", mem_1.a);
	return 0;
}

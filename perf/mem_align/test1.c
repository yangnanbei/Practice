#include <stdio.h>
#define MAX_LOOP 1000000000
typedef struct mem_unalign_{
	char a;
	int b;
	short c;
	char d;
} mem_unalign;

typedef struct mem_align{
	char a;
	char d;
	short b;
	int c;
}mem_align;

void test_unalign() {
	mem_unalign mem_un;
	mem_un.a = 1;
	mem_un.b = 2;
	mem_un.c = 3;
	mem_un.d = 4;
}

void test_align() {
	mem_align mem_al;
	mem_al.a = 1;
	mem_al.b = 2;
	mem_al.c = 3;
	mem_al.d = 4;
}

int main() {
	int i = 0;
	while (i++ < MAX_LOOP) {
		test_align();
		//test_unalign();
	}
	return 0;
}

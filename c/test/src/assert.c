#include <stdio.h>
#include <assert.h>

int main()
{
	printf("Bug on!\n");
	assert(1);
	printf("assert 1 finish\n");
	assert(0);
	printf("assert 0 finish\n");
	return 0;
}


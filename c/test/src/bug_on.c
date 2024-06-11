#include <stdio.h>

int main()
{
	printf("Bug on!\n");
	*((int *)NULL) = 1;
	printf("Bug on finish!\n");
	return 0;
}


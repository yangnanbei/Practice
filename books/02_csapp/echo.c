#include <stdio.h>
#include "gets.h"

/* Echo Line */
void echo() {
	char buf[8]; /* Way too small */
	gets(buf);
	puts(buf);
}

void call_echo() {
	echo();
}

int main() {
	echo();
	return 0;
}

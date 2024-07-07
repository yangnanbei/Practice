/* Get string from stadin */
char *gets(char *dest)
{
	int c = getchar();
	char *p = dest;
	while (c != EOF && c != '\n') {
		*p++ = c;
		c = getchar();
	}
	*p = '\0';
	return dest;
}

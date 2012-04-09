#include <stdio.h>

char * strkat(char *s, char *t);

int main()
{
	char *s = "hello";
	char *t = "world";
	strkat(s, t);
	printf("%s\n",s);
	return 0;
}

char * strkat(char *s, char *t)
{
	printf("strkat(%s, %s)\n", s, t);
	// calculate length
	int slen=0;
	int tlen = 0;
	char *a = s;
	while (*a++ != '\0'){
		printf("0 %s\n",a);
		slen++;
	}
	printf("slen = %d\n", slen);
	a = t;
	while (*a++ != '\0'){
		printf("0 %s\n",a);		
		tlen++;
	}
	printf("tlen = %d\n", tlen);
	char x[slen + tlen];
	char *y = x;
	a = s;
	while (*a != '\0'){
		*y++ = *a++;
	}
	y--;
	a = t;
	while (*a != '\0'){
		*y++ = *a++;
	}
	*y = '\0';
	return y;
}
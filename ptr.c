#include <ctype.h>
#include "getch.c"

int getint(int *pn);
int getfloat(float *pf);

int main()
{
	float x = 4.0f;
	int y;
	while ( (y=getfloat(&x)) != 0){;
		printf("%g\n", x);
	}
	return 0;
}

int getint(int *pn)
{
	int c, sign;

	while (isspace(c = getch()));

	if (!isdigit(c) && c != EOF && c != '+' && c != '-'){
		ungetch(c);
		return 0;
	}
	sign = (c == '-') ? -1 : 1;
	if (c == '+' || c == '-'){
		c = getch();
		if (!isdigit(c)){
			ungetch(c);
			return 0;
		}
	}

	for (*pn = 0; isdigit(c); c = getch()){
		*pn = 10 * *pn + (c - '0');
	}
	*pn *= sign;
	if (c != EOF){
		ungetch(c);
	}
	return c;
}

int getfloat(float *pn)
{
	int c;
	int infrac = 0;
	float sign = 1.0f;
	float power = 1.0f;

	while (isspace(c = getch()));


	if (!isdigit(c) && c != EOF && c != '+' && c != '-' && c != '.'){
		ungetch(c);
		return 0;
	}

	sign = (c == '-') ? -1.0f : 1.0f;

	if (c == '.'){
		infrac = 1;
	} else if (c == '+' || c == '-'){
		c = getch();
		if (!isdigit(c)){
			ungetch(c);
			return 0;
		}
	}

	for (*pn = 0.0f; c == '.' || isdigit(c); c = getch()){
		if (c == '.'){
			infrac = 1;
		} else {
			*pn = 10 * *pn + (c - '0');
			if (infrac > 0){
				power *= 10.0f;
			}
		}
	}
	*pn = sign*(*pn)/power;
	if (c != EOF){
		ungetch(c);
	}
	return c;

}
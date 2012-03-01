#include <stdio.h>
#include <limits.h>
#include <float.h>

#define INF 1.0/0.0

char calcMinChar();
char calcMaxChar();
unsigned char calcMaxUnsignedChar();
float calcMinFloat();
float calcFloatErr();
float calcMaxFloat();

int main()
{
	char ch;
	unsigned char uch;

	short sh;
	unsigned ush;

	int i;
	unsigned int ui;

	long l;
	unsigned long ul;

	float f;

	ch = SCHAR_MIN;
	printf("Minimum signed char %d\n", ch);

	ch = calcMinChar();
	printf("Min char calculated %d\n", ch);

	ch = SCHAR_MAX;
	printf("Maximum signed char %d\n", ch);

	ch = calcMaxChar();
	printf("Max char calculated %d\n", ch);

	uch = UCHAR_MAX;
	printf("Maximum value for an unsigned char %d\n", uch);

	uch = calcMaxUnsignedChar();
	printf("Max unsigned char calculated %d\n", uch);

	sh = SHRT_MIN;
	printf("Minimum signed short %d\n", sh);

	sh = SHRT_MAX;
	printf("Maximum signed short %d\n", sh);

	ush = USHRT_MAX;
	printf("Maximum unsigned short %d\n", ush);

	i = INT_MIN;
	printf("Minimum signed int %d\n", i);

	i = INT_MAX;
	printf("Maximum singed int %d\n", i);

	ui = UINT_MAX;
	printf("Maximium unsigned int %u\n", ui);

	l = LONG_MIN;
	printf("Min long %ldl\n", l);

	l = LONG_MAX;
	printf("Max long %ld\n", l);

	ul = ULONG_MAX;
	printf("Max unsigned long %lu\n", ul);

	f = FLT_MIN;
	printf("Min float %e\n", f);
	f = calcMinFloat();
	printf("Min float calculated %e\n", f);
	f = calcFloatErr();
	printf("Float epsilon = %e\n",f);

	f = FLT_MAX;
	printf("Max float %e\n", f);
	f = calcMaxFloat();
	printf("Max float calculated %e\n", f);

	return 0;
}

char calcMinChar()
{
	char ch, min;

	ch = -1;
	while (ch < 0){
		min = ch;
		ch = ch - 1;
	}
	return min;
}

char calcMaxChar()
{
	char ch, max;
	ch = 1;
	while (ch > 0){
		max = ch;
		ch = ch + 1;
	}
	return max;
}

unsigned char calcMaxUnsignedChar()
{
	unsigned char ch, max;
	ch = 1;
	while (ch > 0){
		max = ch;
		ch = ch + 1;
	}
	return max;
}

float calcMinFloat()
{
	float a,b,c;

	a = 1.0;
	b = 0.0;
	while (a - b != 0.0){
		c = 0.5*(a - b);
		if (c < 0.0){
			b = b - c;
		} else if (c == 0.0) {
			b = a;
		} else {
			a = a -c;
		}
	}
	b = calcFloatErr();
	return a/b;
}

float calcFloatErr()
{
	float err;
	err = 1.0/2.0;
	while ((float) (1.0 + err/2.0) != 1.0){
		err = err / 2.0;
	}

	return err;
}

float calcMaxFloat()
{
	float a, b, err;

	a = b = err = 1.0 + calcFloatErr();
	b = a * err;

	while (b != a && b != INF){
		a = a * err;
		b = a * err;
	}
	return a;
}
#include <stdio.h>

#define swap(t,x,y) {t temp = y; y = x; x = temp;}

int main()
{
	int x = 4;
	int y = 2;
	swap(int,x,y);
	printf("x=%d y=%d\n",x,y);
}
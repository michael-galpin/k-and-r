#include <stdio.h>

#define swap(t,x,y) {t z = y; y = x; x = z;}

int main()
{
	int x = 4;
	int y = 2;
	swap(int,x,y)
	printf("x=%d y=%d\n",x,y);
}
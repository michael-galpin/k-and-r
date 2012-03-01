#include <stdio.h>

int binsearch(int x, int v[], int n);

int main()
{
	int x[8] = {2,4,6,8,10,12,14,16};
	int y = binsearch(5, x, 8);
	if (y >= 0){
		printf("Index = %d; x[%d]=%d\n", y, y, x[y]);
	} else {
		printf("Not found");
	}
	return 0;
}

// does not work for no matches
int binsearch(int x, int v[], int n)
{
	int low, high, mid;
    low = mid = 0;
    high = n - 1;
    while (low <= high && v[mid] != x) {
    	mid = (low+high)/2;
        if (x < v[mid])
        	high = mid + 1;
        else if (x  > v[mid])
        	low = mid + 1;
	}
	if (v[mid] != x){
		mid = -1;
	}
    return mid;   /* no match */
}
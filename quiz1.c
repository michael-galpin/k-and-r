#include <stdio.h>
#include <stdlib.h>

#define TOTAL 100000
#define PATH "/Users/galpin/Desktop/IntegerArray.txt"

long countInversions(int nums[], int len);

int main()
{
	FILE *file;
	char str[7];
	int num, i = 0;
	int nums[TOTAL];

	file = fopen(PATH, "r");
	while (fgets(str, 7, file) != NULL && i < TOTAL){
		num = atoi(str);
		if (num > 0){
			nums[i++] = num;
		}
	}

	printf("Number of inversions=%ld\n", countInversions(nums, TOTAL));

	return 0;
}

long countInversions(int nums[], int len)
{
	long num = 0;
	int i, j, k;
	if (len > 1){
		int half = len/2;
		int rest = len - half;
		int left[half];
		int right[rest];
		for (i=0;i<half;i++){
			left[i] = nums[i];
		}
		for (i=0;i<rest;i++){
			right[i] = nums[half + i];
		}
		num = countInversions(left, half) + countInversions(right, rest);
		i = j = k = 0;
		while (i < len){
			if (k >= rest){
				nums[i++] = left[j++];
			} else if (j >= half) {
				nums[i++] = right[k++];
				num += (half - j);
			} else if (left[j] <= right[k]){
				nums[i++] = left[j++];
			} else {
				nums[i++] = right[k++];
				num += (half - j);
			}
		}
	}
	return num;
}
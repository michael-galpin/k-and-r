#include <stdio.h>
#include <stdlib.h>

#define TOTAL 10000
#define PATH "/Users/michael/Desktop/qs.txt"

void quicksort(int nums[], int len);
void _quicksort(int nums[], int start, int end);
void swap(int nums[], int i, int j);
int partition(int nums[], int start, int end);
int choosePivot(int nums[], int start, int end);

int tn = 0;

int main()
{
	FILE *file;
	char str[6];
	int num, i = 0;
	int nums[TOTAL];

	file = fopen(PATH, "r");
	if (file != NULL){
		printf("Got file\n");
	} else {
		printf("Got NULL file\n");
		return 0;
	}
	while (fgets(str, 6, file) != NULL && i < TOTAL){
		num = atoi(str);
		if (num > 0){
			nums[i++] = num;
		}
	}
	quicksort(nums, i);
	// for (num=0;num<i;num++){
	// 	printf("%d\n", nums[num]);
	// }
	printf("tn=%d\n",tn);
	return 0;
}

void quicksort(int nums[], int len)
{
	_quicksort(nums, 1, len -1);
}

void _quicksort(int nums[], int start, int end)
{
	int len = end - start + 1;
	tn += (len -1);
	if (len < 1){
		return;
	} else if (len == 1){
		if (nums[start] > nums[end]){
			swap(nums, start, end);
		}
	} else {
		int pivotIndex = choosePivot(nums, start, end);
		swap(nums, start, pivotIndex);
		pivotIndex = partition(nums, start, end);
        if (pivotIndex > 0){
            _quicksort(nums, start, pivotIndex - 1);
        }
        if (pivotIndex < end - 1){
            _quicksort(nums, pivotIndex + 1, end);     
        }		
	}
}

void swap(int nums[], int i, int j)
{
	int temp = nums[i];
	nums[i] = nums[j];
	nums[j] = temp;
}

int partition(int nums[], int start, int end)
{
	int pivotBoundary = start + 1;
	int partitionBoundary = start + 1;
	int pivot = nums[start];
	while(partitionBoundary <= end){
		if (nums[partitionBoundary] < pivot){
			swap(nums, pivotBoundary++, partitionBoundary);
		}
		partitionBoundary++;
	}
	swap(nums, start, pivotBoundary - 1);
	return pivotBoundary - 1;
}

int choosePivot(int nums[], int start, int end)
{
	int len = end - start + 1;
	int mid = start + (end - start)/2;
	int value = mid;
	if ( (nums[start] > nums[mid] && nums[start] < nums[end]) || (nums[start] < nums[mid] && nums[start] > nums[end]) ){
		value = start;
	} else if ( (nums[end] > nums[mid] && nums[end] < nums[start]) || (nums[end] < nums[mid] && nums[end] > nums[start]) ){
		value = end;
	}
	return value;
}
#include <stdio.h>

void squeeze(char s1[], char s2[]);
int any(char a[], char b[]);

int main(int argc, char *argv[])
{
	printf("any(%s, %s)=%d\n", argv[1], argv[2], any(argv[1], argv[2]));
}

void squeeze(char s1[], char s2[])
{
	int i,j,k;
	i = 0;
	while (s2[i] != '\0'){
		j = k =0;
		while (s1[j] != '\0'){
			if (s1[j] != s2[i]){
				s1[k++] = s1[j];
			}
			j++;
		}
		s1[k] = '\0';
		i++;
	}
}

int any(char a[], char b[])
{
	int z = 0;
	int i = 0;
	int found = 0; 
	while (!found && a[z] != '\0'){
		i = 0;
		while (b[i] != '\0'){
			if (a[z] == b[i++]){
				found = 1;
			}
		}
		if (!found) z++;
	}
	if (!found){
		z = -1;
	}
	return z;
}
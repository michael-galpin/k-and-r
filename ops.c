#include <stdio.h>

int htoi(char s[]);

int main(int argc, char* argv[])
{
	int j;
    for (j = 1; j < argc; j++){
    	printf("htoi(%s)=%d\n", argv[j], htoi(argv[j]));
    }
}

int htoi(char s[])
{
	int len = 0;
	while (s[len] != '\0'){
		len++;
	}
	// ignore 0x and 0X
	if (s[0] =='0' && (s[1] == 'x' || s[1] == 'X')){
		int i;
		for (i=0;i<len-2;i++){
			s[i] = s[i+2];
		}
		s[len-2] = '\0';
		len = len - 2;
	}
	
	int n = 0;
	int b = 1;
	int i;
	for (i=len-1;i>=0;i--){
		int d = 0;
		char temp[1];
		temp[0] = s[i];
		if (s[i]>='0' && s[i]<='9'){
			d = s[i] - '0';
		} else if (s[i] >= 'A' && s[i] <= 'B'){
			d = 10 + s[i] - 'A';
		} else {
			d = 10 + s[i] - 'a';
		}
		n += d*b;
		b *= 16;
	}

	return n;
}
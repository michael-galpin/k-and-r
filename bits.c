#include <stdio.h>

unsigned int setbits(unsigned int x, int p, int n, unsigned int y);
unsigned int invert(unsigned int x, int p, int n);
unsigned int rightrot(unsigned int x, int n);
int bitcount(unsigned int x);
void itob(char s[], unsigned int n);

int main()
{
	/*
		121 = 1111001
		21 = 10101 3 most right bits = 101
		setbits(121,4, 3, 21) =  1111011 = 123
	*/
	char s[100];
	itob(s, 121);
	printf("s=%s\n",s);
	itob(s, 21);
	printf("s=%s\n",s);
	int z = setbits(121, 4, 3, 21);
	printf("%d\n", z);
	itob(s, z);
	printf("s=%s\n",s);
	itob(s, ~121);
	printf("s=%s\n",s);	
	z = invert(121, 4, 3);
	printf("%d\n", z);
	itob(s, z);
	printf("s=%s\n",s);	

	z = 121;
	itob(s,z);
	printf("######\n");
	printf("%s\n",s);
	z = rightrot(z,20);
	itob(s,z);
	printf("%s\n",s);

	printf("bitcount(121)=%d\n", bitcount(121));

	return 0;
}

unsigned int setbits(unsigned int x, int p, int n, unsigned int y)
{
	// get n right-most bits of y only
	y = ~(~0 << n) & y;
	// shift those n bits p-n bits to the left
	y = y << (p-n);
	// zero out n bits of x starting at p
	x = x & ~((~(~0 << n)) << (p - n));
	return x | y;
}

unsigned int invert(unsigned int x, int p, int n)
{
	return setbits(x, p, n, ~x >> (p-n));
}

unsigned int rightrot(unsigned int x, int n)
{
	int i;
	for (i=0;i<n;i++){
		x = setbits(x >> 1, 16, 1, x);
	}
	return x;
}

int bitcount(unsigned int x)
{
	int cnt = x > 0 ? 1 : 0;
	while ((x &= x-1) != 0) cnt++;
	return cnt;
}

void itob(char s[], unsigned int n)
{
	int i = 2;
	int cnt = 0;
	s[cnt] = '\0';
	while (n > 0){
		int r = n % i;
		cnt++;
		int j = 0;
		for (j=0;j<cnt;j++){
			s[cnt - j] = s[cnt - j -1];
		}
		s[0] = '0' + r;
		n = n/i;
	}
}
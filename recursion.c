#include <stdio.h>
#include <stdlib.h>

int itoa(int n, char s[]);
void reverse(char s[]);

int main(int argc, char* argv[])
{
    int input = 123;
    if (argc >= 2){
        input = atoi(argv[1]);
    }
    char s[10] = "";
    itoa(input, s);
    printf("%s\n", s);
    reverse(s);
    printf("reversed %s\n",s);
    return 0;
}

int itoa(int n, char s[])
{
    int i = 0;
    int pn = n;
    if (n < 0){
        s[i++] = '-';
        pn *= -1;
    }
    if (n/10){
        i = itoa(n/10, s);
    } 
    s[i++] = (pn % 10) + '0';
    s[i] = '\0';
    return i;
}

void reverse(char s[])
{
  int i, j;

  // i = length of string
  for (i=0; s[i] != '\0'; i++);

  // if length is 2 or more
  if (i > 1) {
    // rotate string (and null byte) to the left
    s[i] = s[0];
    for (j=0; j < i-1; j++) {
      s[j] = s[j+1];
    }
    s[i-1] = '\0';

    // recursively reverse
    reverse(s);

    // bubble up null byte to the right
    s[i-1] = s[i];
    s[i] = '\0';
  }
}

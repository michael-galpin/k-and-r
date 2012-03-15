#include <stdio.h>

void itoa(int n, char s[]);
void itoa_(int n, int i, char s[]);

int main()
{
    char s[10] = "";
    itoa(123, s);
    printf("%s\n", s);
    return 0;
}

void itoa(int n, char s[]){
    itoa_(n, 0, s);
}

void itoa_(int n, int i, char s[])
{
    printf("itoa_(%d, %d, %s)\n", n,  i, s);
    if (n < 0){
        s[i++] = '-';
    }
    if (n/10){
        itoa_(n/10, ++i, s);
        s[i++] = n % 10 + '0';
        printf("s=%s\n",s);
    } else {
        s[i] = '\0';
    }
}
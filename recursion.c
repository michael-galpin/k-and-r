#include <stdio.h>
#include <stdlib.h>

int itoa(int n, char s[]);

int main(int argc, char* argv[])
{
    int input = 123;
    if (argc >= 2){
        input = atoi(argv[1]);
    }
    char s[10] = "";
    itoa(input, s);
    printf("%s\n", s);
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
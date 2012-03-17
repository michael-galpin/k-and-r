#include <stdio.h>
#include <stdlib.h>

int itoa(int n, char s[]);
void reverse(char s[]);
void reverse_(char s[], int start, int end);

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
    int i;
    for (i=0;s[i] != '\0'; i++);
    reverse_(s,0,i);
}

void reverse_(char s[], int start, int end)
{
    int len = end - start;
    if (len > 1){
        int temp = s[end-1];
        s[end-1] = s[start];
        s[start] = temp;
        if (len > 2){
            reverse_(s, start+1, end-1);
        }
    }
}
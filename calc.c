/**
 * Exercise 4-3, 4-4
*/
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

#define MAXOP       100
#define NUMBER      '0'
#define PRINTCMD    'p'
#define SWAP        's'
#define CLEAR       'c'
#define SINE        'S'
#define MAXVAL      100
#define BUFSISZE    100

int getop(char []);
void push(double);
double pop(void);
int getch(void);
void ungetch(int);
void printstack(void);
void swap(void);
void clear(void);

int sp = 0;
double val[MAXVAL];
char buf[BUFSISZE];
int bufp = 0;

int main()
{
    int type, n, m;
    double op2;
    char s[MAXOP];
    char dbg[MAXOP];
    dbg[1] = '\0';

    while ( (type = getop(s)) != EOF){
        dbg[0] = type;
        switch (type){
            case NUMBER:
                push(atof(s));
                break;
            case '+':
                push(pop() + pop());
                break;
            case '*':
                push(pop() * pop());
                break;
            case '-':
                op2 = pop();
                push(pop() - op2);
                break;
            case '/':
                op2 = pop();
                if (op2 != 0.0){
                    push(pop() / op2);
                } else {
                    printf("Divide by zero error\n");
                }
                break;
            case '%':
                m = pop();
                n = pop();
                push(n % m);
                break;
            case '\n':
                printf("\t%.8g\n", pop());
                break;
            case PRINTCMD:
                printstack();
                break;
            case SWAP:
                swap();
                break;
            case CLEAR:
                clear();
                break;
            case SINE:
                push(sin(pop()));
            default:
                printf("Error unknown command %s\n", s);
                break;
        }
    }
    return 0;
}

void push(double f)
{
    if (sp < MAXVAL){
        val[sp++] = f;
    } else {
        printf("Stock overflow!\n");
    }
}

double pop(void)
{
    if (sp > 0){
        return val[--sp];
    } else {
        printf("Stock empty!\n");
        return 0.0;
    }
}

int getop(char s[])
{
    int i,c, sgn;
    char msg[100];
    msg[1] = '\0';
    sgn = 1;
    while ((s[0]= c = getch()) == ' ' || c == '\t');
    s[1] = '\0';
    if (!isdigit(c) && c != '.' && c != '-' && c != 's'){
        msg[0] = c;
        printf("not a digit or . or - or s, got %s\n", msg);
        return c;
    }
    if (c == '-'){
        sgn = -1;
        c = getch();
        ungetch(c);
        if (!isdigit(c)){
            sgn = 1;
            return '-';
        }
    } else if (c == 's'){
        printf("Got an s\n");
        if ((c = getch()) != 'i'){
            printf("But no i\n");
            ungetch(c);
            return 's';
        } else {
            printf("Got an si\n");
            if ((c = getch()) != 'n'){
                printf("But not a sin\n");
                ungetch(c);
                ungetch('s');
                return 's';
            } else {
                printf("Got a sin\n");
                return SINE;
            }
        }
    }
    i = 0;
    if (isdigit(c)){
        while (isdigit(s[++i] = c = getch()));
    }
    if (c == '.'){
        while (isdigit(s[++i] = c = getch()));
    }
    s[i] = '\0';
    if (c != EOF){
        ungetch(c);
    }
    return NUMBER;
}

int getch(void)
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)
{
    if (bufp >= BUFSISZE){
        printf("ungetch too many characters\n");
    } else {
        buf[bufp++] = c;
    }
}

void printstack(void)
{
    int i;
    for (i=sp-1;i>=0;i--){
        printf("%.8g\n", val[i]);
    }
}

void swap(void)
{
    float temp = val[sp -1];
    val[sp - 1] = val[sp -2];
    val[sp -2] = temp;
}

void clear(void)
{
    sp = 0;
}
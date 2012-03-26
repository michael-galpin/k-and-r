#include "getch.h"
#define BUFSISZE    100

static char buf[BUFSISZE];
static int bufp = 0;

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
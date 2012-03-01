#include <stdio.h>

#define SPACE ' '
#define NEW_LINE '\n'
#define TAB '\t'
#define BUFFER_SIZE 100
#define TAB_SIZE 4

void copy(char to[], char from[]);
int getLine(char line[], int bufSize);

int main()
{
	int len;
	char line[BUFFER_SIZE];

	len = getLine(line, BUFFER_SIZE);
	while (len != 0)
	{
		printf("Got line: %s\n", line);
		len = getLine(line, BUFFER_SIZE);
	}

	return 0;
}

void copy(char to[], char from[])
{
	int i;

	i = 0;
	while(from[i] != '\0')
	{
		to[i] = from[i++];
	}
}

int getLine(char line[], int bufSize)
{
	int c,len;

	len = 0;
	c = getchar();
	while (c != EOF && c != NEW_LINE)
	{
		if (len == bufSize)
		{
			bufSize += BUFFER_SIZE;
			char temp[bufSize];
			copy(temp, line);
			line = temp;
		}
		if (c == TAB)
		{
			int i;
			for (i=0;i<TAB_SIZE;i++)
			{
				line[len++] = SPACE;
			}
		}
		else 
		{
			line[len++] = c;
		}
		c = getchar();
	}
	if (c == NEW_LINE)
	{
		line[len++] = c;
	}
	line[len] = '\0';

	return len;
}
#include <stdio.h>

void escape(char s[], char t[]);
void expand(char s[], char t[]);
int isalphanum(char ch);

int main()
{
	char a[30] = "test c-x 2-3 -4 M-U";
	char b[30];
	escape(a,b);
	printf("%s\n", b);
	expand(a, b);
	printf("%s\n",b);
	return 0;
}

void escape(char s[], char t[])
{
	int i = 0;
	int j = 0;
	while (s[i] != '\0'){
		switch (s[i]){
			case '\n' :
				t[j++] = '\\';
				t[j++] = 'n';
				break;
			case '\t' :
				t[j++] = '\\';
				t[j++] = 't';
				break;
			default:
				t[j++] = s[i];
		}
		i++;
	}
	t[j] = '\0';
}

void expand(char s[], char t[])
{
	int i,j,k, u;
	i = j = u = 0;
	while (s[i] != '\0'){
		if (i > 0 && s[i] == '-' && s[i-1] != ' ' && s[i+1] != '\0' && isalphanum(s[i-1])){
			k = s[i+1];
			for (u=1;u<=s[i+1] - s[i-1];u++){
				t[j++] = s[i-1] + u;
			}
			i++;
		} else {
			t[j++] = s[i];
		}
		i++;
	}
	t[j] = '\0';
}

int isalphanum(char ch){
	return (ch >= 'a' && ch <='z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9');
}
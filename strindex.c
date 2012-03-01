#include <stdio.h>
#include <ctype.h>

int strindex(char s[], char t[]);
double atof(char s[]);

int main()
{
	printf("atof(1.2)=%e\n", atof("1.2"));
	printf("atof(-1.2)=%e\n", atof("-1.2"));	
	printf("atof(-1.2e3)=%e\n", atof("-1.2e+03"));	
	printf("atof(1.2e-4)=%e\n", atof("1.2e-04"));				
	return 0;
}

int strindex(char s[], char t[])
{
	int i,j,k, last;

	last = -1;
	for (i=0; s[i] != '\0'; i++){
		for (j=i, k=0; t[k] != '\0' && s[j]==t[k]; j++,k++);
		if (k >0 && t[k] == '\0'){
			last = i;
		}
	}
	return last;
}

double atof(char s[])
{
	double val, power, dbl;
	int i, sign, expo;

	for (i=0; isspace(s[i]); i++);
	sign = (s[i] == '-') ? -1 : 1;
	if (s[i] == '+' || s[i] == '-'){
		i++;
	}
	for (val = 0.0; isdigit(s[i]); i++){
		val = 10.0*val + (s[i] - '0');
	}
	if (s[i] == '.') i++;
	for (power = 1.0; isdigit(s[i]);i++){
		val = 10.0*val + (s[i] - '0');
		power *= 10.0;
	}
	dbl = sign*val/power;
	if (s[i] == 'e' || s[i] == 'E'){
		printf("has exponent\n");
		i++;
		switch (s[i]){
			case '+' : 
				sign = 1.0;
				break;
			case '-' :
				sign = -1.0;
				break;
			default:
				printf("bad exponent\n");
				return dbl;
		}
		i++;
		for (expo=0; isdigit(s[i]); i++){
			expo = 10*expo + (s[i] - '0');
		}
		printf("exponent = %d\n",expo);
		for (i=0;i<expo;i++){
			if (sign < 0){
				dbl = dbl /10.0;
			} else if (sign > 0){
				dbl = dbl * 10.0;
			}
		}
	}
	printf("done\n");
	return dbl;
}
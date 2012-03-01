#include <stdio.h>
#include <float.h>

float calcMinFloat();

int main()
{
    float f;

    f = FLT_MIN;
    printf("Min float %e\n", f);
    f = calcMinFloat();
    printf("Min float calculated %e\n", f);

    printf("Epsilon %e\n", FLT_EPSILON);

    f = FLT_MIN * FLT_EPSILON;
    printf("Ah ha! %e\n", f);

    return 0;
}

float calcMinFloat()
{
    float a,b,c;
    a = 1.0;
    b = 0.0;
    while (a - b != 0.0){
	c = 0.5*(a - b);
	if (c < 0.0){
		b = b - c;
	} else if (c == 0.0) {
		b = a;
	} else {
		a = a -c;
	}
    }
    return a; // should be FLT_MIN?
}
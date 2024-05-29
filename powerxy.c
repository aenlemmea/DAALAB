#include <stdio.h>

/*
T(n) = T(n/2) + c1 if n is even
T(n) = T(n/2) + c2 if n is odd
*/
double powerdc(double x, int y) {
	if (y == 0) return 1.0d;
	double half = powerdc(x, y/2);
	
	if (y % 2 == 1) {
		return (half * half * x);
	}
	else return (half * half);
}

// T(n) = T(n - 1) + C
// T(0) = 1
double power(double x, int y) {
	if (y == 0) return 1.0d;
	return (x * power(x, y - 1));
}

int main(void) {
	double x;
	int y;
	
	printf("\nEnter x and y: ");
	scanf("%lf %d", &x, &y);
	
	printf("x^y non dc: %lf\n", power(x, y));
	printf("x^y with dc: %lf\n", powerdc(x, y));
}

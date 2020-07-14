// math 헤더파일의 sin, cos 써보기
#include <stdio.h>
#include <math.h>

int main() {
	double x, result;
	printf("X 값을 입력하앍: ");
	scanf("%lf", &x);
	result = sin(x)*sin(x) + cos(x)*cos(x);
	printf("sin(%lf) = %lf\ncos(%lf) = %lf\n", x, sin(x), x, cos(x));
	printf("sin(%lf)^2 + cos(%lf)^2 = %lf\n", x, x, result);
	return 0;
}
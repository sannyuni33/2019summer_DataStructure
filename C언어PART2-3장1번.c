// 변수타입 알아보기
#include <stdio.h>

int main() {
	char a = 'A';
	int b = 10;
	double c = 3.14;
	
	char* cp = NULL;
	int* ip = NULL;
	double* dp = NULL;

	cp = &a;
	ip = &b;
	dp = &c;

	printf("char형 포인터의 크기: %d, char형 변수의 크기: %d, char형 변수값: %c\n", sizeof(cp), sizeof(a), *cp);
	printf("int형 포인터의 크기: %d, int형 변수의 크기: %d, int형 변수값: %d\n", sizeof(ip), sizeof(b), *ip);
	printf("double형 포인터의 크기: %d, double형 변수의 크기: %d, double형 변수값: %lf\n", sizeof(dp), sizeof(c), &dp);
}
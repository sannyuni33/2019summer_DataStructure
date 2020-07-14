// 포인터 사용법 익히기
#include <stdio.h>

int main() {
	int a = 0, b = 0, c = 0;
	int* p1 = NULL;
	int* p2 = NULL;
	int** pp = NULL;

	p1 = &a;
	*p1 = 10;
	pp = &p2;
	printf("a=%d, b=%d, c=%d\n", a, b, c);
	
	p1 = &b;
	*p1 = 20;
	printf("a=%d, b=%d, c=%d\n", a, b, c);

	p2 = &c;
	**pp = 30;
	printf("a=%d, b=%d, c=%d\n", a, b, c);

	return 0;
}